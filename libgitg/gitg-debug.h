/*
 * gitg-debug.h
 * This file is part of gitg - git repository viewer
 *
 * Copyright (C) 2009 - Jesse van den Kieboom
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, 
 * Boston, MA 02111-1307, USA.
 */

#ifndef __GITG_DEBUG_H__
#define __GITG_DEBUG_H__

#include <glib.h>
#include <config.h>

enum
{
	GITG_DEBUG_NONE = 0,
	GITG_DEBUG_SHELL = 1 << 0,
	GITG_DEBUG_SHELL_OUTPUT = 1 << 1,
	GITG_DEBUG_CHARSET_CONVERSION = 1 << 2,
	GITG_DEBUG_CONFIG = 1 << 3
};

#if ENABLE_DEBUG
void gitg_debug_init (void);
gboolean gitg_debug_enabled (guint debug);

void gitg_debug_message (guint level,
                         gchar const *file,
                         gint         line,
                         gchar const *function,
                         gchar const *format,
                         ...);

#define gitg_debug(level,args...) gitg_debug_message (level, __FILE__, __LINE__, G_STRFUNC, args)
#else

#define gitg_debug_init(args...) ;
#define gitg_debug_enabled(x) FALSE
#define gitg_debug(level,args...) ;

#endif

#endif /* __GITG_DEBUG_H__ */

