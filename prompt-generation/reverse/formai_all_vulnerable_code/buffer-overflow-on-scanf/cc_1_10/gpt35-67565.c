//FormAI DATASET v1.0 Category: Music Library Management System ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONGS 50
#define MAX_NAME_LEN 100

// Song struct
typedef struct song {
   char name[MAX_NAME_LEN];
   int year;
} Song;

// Playlist struct
typedef struct playlist {
   char name[MAX_NAME_LEN];
   Song songs[MAX_SONGS];
   int count;
} Playlist;

// Music library struct
typedef struct library {
   Song songs[MAX_SONGS];
   int count;
} Library;

// Function to add song to library
void add_song_to_library(Library* lib, char* name, int year) {
   Song new_song;
   strcpy(new_song.name, name);
   new_song.year = year;
   lib->songs[lib->count] = new_song;
   lib->count++;
}

// Function to add song to playlist
void add_song_to_playlist(Playlist* pl, char* name, int year) {
   Song new_song;
   strcpy(new_song.name, name);
   new_song.year = year;
   pl->songs[pl->count] = new_song;
   pl->count++;
}

// Function to display library
void display_library(Library* lib) {
   printf("Songs in library:\n");
   for (int i = 0; i < lib->count; i++) {
      printf("%d: %s (%d)\n", i+1, lib->songs[i].name, lib->songs[i].year);
   }
}

// Function to display playlist
void display_playlist(Playlist* pl) {
   printf("Songs in playlist '%s':\n", pl->name);
   for (int i = 0; i < pl->count; i++) {
      printf("%d: %s (%d)\n", i+1, pl->songs[i].name, pl->songs[i].year);
   }
}

int main() {
   Library lib;
   lib.count = 0;

   char input[100];
   while (1) {
      printf("Enter command: ");
      scanf("%s", input);
      if (strcmp(input, "add_song") == 0) {
         printf("Enter song name: ");
         char name[MAX_NAME_LEN];
         scanf("%s", name);
         printf("Enter song year: ");
         int year;
         scanf("%d", &year);
         add_song_to_library(&lib, name, year);
      }
      else if (strcmp(input, "show_library") == 0) {
         display_library(&lib);
      }
      else if (strcmp(input, "create_playlist") == 0) {
         printf("Enter playlist name: ");
         char name[MAX_NAME_LEN];
         scanf("%s", name);
         Playlist new_pl;
         strcpy(new_pl.name, name);
         new_pl.count = 0;
         char input2[100];
         while (1) {
            printf("Enter command: ");
            scanf("%s", input2);
            if (strcmp(input2, "add_song") == 0) {
               printf("Enter song name: ");
               char name2[MAX_NAME_LEN];
               scanf("%s", name2);
               printf("Enter song year: ");
               int year2;
               scanf("%d", &year2);
               add_song_to_playlist(&new_pl, name2, year2);
            }
            else if (strcmp(input2, "show_playlist") == 0) {
               display_playlist(&new_pl);
            }
            else if (strcmp(input2, "exit") == 0) {
               break;
            }
         }
      }
      else if (strcmp(input, "exit") == 0) {
         break;
      }
   }

   return 0;
}