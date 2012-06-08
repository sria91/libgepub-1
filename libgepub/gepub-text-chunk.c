/* GepubTextChunk
 *
 * Copyright (C) 2011 Daniel Garcia <danigm@wadobo.com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */

#include <config.h>
#include "gepub-text-chunk.h"


G_DEFINE_TYPE (GepubTextChunk, gepub_text_chunk, G_TYPE_OBJECT)


static void
gepub_text_chunk_finalize (GObject *object)
{
    GepubTextChunk *t = GEPUB_TEXT_CHUNK (object);

    if (t->text) {
        g_free (t->text);
        t->text = NULL;
    }

    G_OBJECT_CLASS (gepub_text_chunk_parent_class)->finalize (object);
}

static void
gepub_text_chunk_init (GepubTextChunk *t)
{
}

static void
gepub_text_chunk_class_init (GepubTextChunkClass *klass)
{
    GObjectClass *object_class = G_OBJECT_CLASS (klass);
    object_class->finalize = gepub_text_chunk_finalize;
}

GepubTextChunk *
gepub_text_chunk_new (GepubTextChunkType type, const guchar *text)
{
    GepubTextChunk *t;

    t = GEPUB_TEXT_CHUNK (g_object_new (GEPUB_TYPE_TEXT_CHUNK, NULL));
    t->type = type;
    t->text = g_strdup (text);

    return t;
}

gchar *
gepub_text_chunk_type_str (GepubTextChunk *chunk)
{
    switch (chunk->type) {
        case GEPUBTextBold:
            return "bold";
        case GEPUBTextItalic:
            return "italic";
        case GEPUBTextHeader:
            return "header";
        default:
            return "normal";
    }
}
