//FormAI DATASET v1.0 Category: Music Library Management System ; Style: light-weight
#include <stdio.h>
#include <string.h>

#define MAX_ALBUMS 10
#define MAX_TITLE_LENGTH 100
#define MAX_ARTIST_LENGTH 50

struct album {
   char title[MAX_TITLE_LENGTH];
   char artist[MAX_ARTIST_LENGTH];
   int tracks;
   float duration;
};

struct library {
   struct album albums[MAX_ALBUMS];
   int count;
};

void add_album(struct library *lib) {
   struct album new_album;
   printf("Enter the title of the album: ");
   scanf("%s", new_album.title);
   printf("Enter the artist of the album: ");
   scanf("%s", new_album.artist);
   printf("Enter the number of tracks on the album: ");
   scanf("%d", &new_album.tracks);
   printf("Enter the duration of the album in minutes: ");
   scanf("%f", &new_album.duration);
   lib->albums[lib->count] = new_album;
   lib->count++;
}

void print_album(struct album a) {
   printf("Title: %s\n", a.title);
   printf("Artist: %s\n", a.artist);
   printf("Number of Tracks: %d\n", a.tracks);
   printf("Duration (mins): %f\n\n", a.duration);
}

void print_library(struct library lib) {
   printf("-----Library-----\n");
   for (int i = 0; i < lib.count; i++) {
      print_album(lib.albums[i]);
   }
}

void search_library(struct library lib, char *keyword) {
   printf("-----Search Results-----\n");
   for (int i = 0; i < lib.count; i++) {
      if (strstr(lib.albums[i].title, keyword) != NULL || strstr(lib.albums[i].artist, keyword) != NULL) {
         print_album(lib.albums[i]);
      }
   }
}

int main() {
   struct library my_library;
   my_library.count = 0;

   int choice;
   char input[MAX_TITLE_LENGTH];
   do {
      printf("Enter 1 to add an album to the library, 2 to print the library, 3 to search for an album, or 0 to quit: ");
      scanf("%d", &choice);
      switch (choice) {
         case 1:
            add_album(&my_library);
            break;
         case 2:
            print_library(my_library);
            break;
         case 3:
            printf("Enter a keyword to search for: ");
            scanf("%s", input);
            search_library(my_library, input);
            break;
         case 0:
            printf("Goodbye!\n");
            break;
         default:
            printf("Invalid input. Please try again.\n");
      }
   } while (choice != 0);

   return 0;
}