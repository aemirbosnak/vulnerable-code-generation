//FormAI DATASET v1.0 Category: Music Library Management System ; Style: statistical
/* C Music Library Management System Example Program */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONGS 100
#define MAX_CHARS 100

/* Define a structure to store song information */
struct song {
   char title[MAX_CHARS];
   char artist[MAX_CHARS];
   int duration;
   char genre[MAX_CHARS];
};

/* Function to print a menu of options to the user */
void print_menu() {
   printf("1 - Add a Song\n");
   printf("2 - Remove a Song\n");
   printf("3 - Search by Artist\n");
   printf("4 - Search by Genre\n");
   printf("5 - Print All Songs\n");
   printf("6 - Exit\n");
}

int main() {
   /* Declare variables */
   struct song songs[MAX_SONGS];
   int num_songs = 0;
   int choice;

   /* Main loop */
   do {
      /* Print the menu */
      print_menu();

      /* Get the user's choice */
      printf("Enter your selection: ");
      scanf("%d", &choice);

      /* Process the user's choice */
      switch (choice) {
         case 1: /* Add a Song */
            if (num_songs < MAX_SONGS) {
               printf("Enter the Song Title: ");
               scanf(" %[^\n]", songs[num_songs].title);

               printf("Enter the Artist Name: ");
               scanf(" %[^\n]", songs[num_songs].artist);

               printf("Enter the Song Duration (in seconds): ");
               scanf("%d", &songs[num_songs].duration);

               printf("Enter the Song Genre: ");
               scanf(" %[^\n]", songs[num_songs].genre);

               num_songs++;
            } else {
               printf("Error: Maximum number of songs reached.\n");
            }
            break;

         case 2: /* Remove a Song */
            if (num_songs > 0) {
               int index = -1;
               char keyword[MAX_CHARS];

               printf("Enter a keyword to search for in song titles: ");
               scanf(" %[^\n]", keyword);

               for (int i = 0; i < num_songs; i++) {
                  if (strstr(songs[i].title, keyword) != NULL) {
                     printf("%d: %s by %s\n", i+1, songs[i].title, songs[i].artist);
                  }
               }

               printf("Enter the index of the song to remove: ");
               scanf("%d", &index);

               if (index >= 1 && index <= num_songs) {
                  for (int i = index-1; i < num_songs-1; i++) {
                     strcpy(songs[i].title, songs[i+1].title);
                     strcpy(songs[i].artist, songs[i+1].artist);
                     songs[i].duration = songs[i+1].duration;
                     strcpy(songs[i].genre, songs[i+1].genre);
                  }

                  num_songs--;
                  printf("Song removed.\n");
               } else {
                  printf("Error: Invalid song index.\n");
               }
            } else {
               printf("Error: No songs to remove.\n");
            }
            break;

         case 3: /* Search by Artist */
            if (num_songs > 0) {
               char keyword[MAX_CHARS];

               printf("Enter an artist name to search for: ");
               scanf(" %[^\n]", keyword);

               for (int i = 0; i < num_songs; i++) {
                  if (strstr(songs[i].artist, keyword) != NULL) {
                     printf("%s by %s\n", songs[i].title, songs[i].artist);
                  }
               }
            } else {
               printf("Error: No songs to search.\n");
            }
            break;

         case 4: /* Search by Genre */
            if (num_songs > 0) {
               char keyword[MAX_CHARS];

               printf("Enter a genre to search for: ");
               scanf(" %[^\n]", keyword);

               for (int i = 0; i < num_songs; i++) {
                  if (strstr(songs[i].genre, keyword) != NULL) {
                     printf("%s by %s (%d seconds)\n", songs[i].title, songs[i].artist, songs[i].duration);
                  }
               }
            } else {
               printf("Error: No songs to search.\n");
            }
            break;

         case 5: /* Print All Songs */
            if (num_songs > 0) {
               printf("Title | Artist | Duration (s) | Genre\n");

               for (int i = 0; i < num_songs; i++) {
                  printf("%s | %s | %d | %s\n", songs[i].title, songs[i].artist, songs[i].duration, songs[i].genre);
               }
            } else {
               printf("Error: No songs to print.\n");
            }
            break;

         case 6: /* Exit */
            printf("Goodbye!\n");
            break;

         default: /* Invalid Choice */
            printf("Error: Invalid choice.\n");
      }
   } while (choice != 6);

   return 0;
}