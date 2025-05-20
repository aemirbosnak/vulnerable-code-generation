//FormAI DATASET v1.0 Category: Music Library Management System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct album {
  char title[50];
  char artist[50];
  char genre[20];
  int year;
};

int main() {
  struct album library[100]; // maximum 100 albums allowed in the library
  int num_albums = 0; // number of albums currently in library

  while (1) {
    printf("Library Management System Menu:\n");
    printf("1. Add album\n");
    printf("2. Remove album\n");
    printf("3. Search album\n");
    printf("4. Display all albums\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");

    int choice;
    scanf("%d", &choice);
    getchar(); // consume newline character left by scanf

    switch (choice) {
      case 1: // adding an album
        if (num_albums == 100) { // library is full
          printf("Library is full. You cannot add more albums.\n");
          break;
        }

        printf("Enter title of album: ");
        fgets(library[num_albums].title, 50, stdin);
        library[num_albums].title[strlen(library[num_albums].title) - 1] = '\0'; // remove newline character left by fgets

        printf("Enter artist of album: ");
        fgets(library[num_albums].artist, 50, stdin);
        library[num_albums].artist[strlen(library[num_albums].artist) - 1] = '\0';

        printf("Enter genre of album: ");
        fgets(library[num_albums].genre, 20, stdin);
        library[num_albums].genre[strlen(library[num_albums].genre) - 1] = '\0';

        printf("Enter year of album: ");
        scanf("%d", &library[num_albums].year);
        getchar(); // consume newline character left by scanf

        printf("Album added successfully.\n");
        num_albums++;
        break;

      case 2: // removing an album
        if (num_albums == 0) { // library is empty
          printf("Library is empty. You cannot remove an album.\n");
          break;
        }

        printf("Enter title of album to be removed: ");
        char title_to_remove[50];
        fgets(title_to_remove, 50, stdin);
        title_to_remove[strlen(title_to_remove) - 1] = '\0'; // remove newline character left by fgets

        int i;
        for (i = 0; i < num_albums; i++) {
          if (strcmp(library[i].title, title_to_remove) == 0) { // found matching album title
            num_albums--;
            for (; i < num_albums; i++) {
              library[i] = library[i + 1]; // shift remaining albums left to fill gap
            }
            printf("Album removed successfully.\n");
            break;
          }
        }

        if (i == num_albums) { // album title not found in library
          printf("Album not found in library.\n");
        }
        break;

      case 3: // searching for an album
        if (num_albums == 0) { // library is empty
          printf("Library is empty. You cannot search for an album.\n");
          break;
        }

        printf("Enter title of album to be searched for: ");
        char title_to_search[50];
        fgets(title_to_search, 50, stdin);
        title_to_search[strlen(title_to_search) - 1] = '\0'; // remove newline character left by fgets

        int found = 0;
        for (i = 0; i < num_albums; i++) {
          if (strcmp(library[i].title, title_to_search) == 0) { // found matching album title
            printf("Album found: Title: %s, Artist: %s, Genre: %s, Year: %d\n", library[i].title, library[i].artist, library[i].genre, library[i].year);
            found = 1;
            break;
          }
        }

        if (!found) { // album title not found in library
          printf("Album not found in library.\n");
        }
        break;

      case 4: // displaying all albums
        if (num_albums == 0) { // library is empty
          printf("Library is empty. There are no albums to display.\n");
          break;
        }

        printf("List of all albums in library:\n");
        for (i = 0; i < num_albums; i++) {
          printf("%d. Title: %s, Artist: %s, Genre: %s, Year: %d\n", i+1, library[i].title, library[i].artist, library[i].genre, library[i].year);
        }
        break;

      case 5: // exiting the program
        printf("Exiting Library Management System. Goodbye!\n");
        exit(0);

      default: // invalid choice
        printf("Invalid choice. Please try again.\n");
    }
  }

  return 0;
}