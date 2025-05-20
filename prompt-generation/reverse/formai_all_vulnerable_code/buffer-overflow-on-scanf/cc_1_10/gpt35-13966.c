//FormAI DATASET v1.0 Category: Music Library Management System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Struct to hold music information */
typedef struct {
    char title[50];
    char artist[50];
    char album[50];
    int year;
} Song;

/* Function to add a new song to the library */
void add_song(Song library[], int num_entries) {
    Song new_song;

    /* Prompt user for song information */
    printf("Enter the song title: ");
    fgets(new_song.title, 50, stdin);
    printf("Enter the artist name: ");
    fgets(new_song.artist, 50, stdin);
    printf("Enter the album name: ");
    fgets(new_song.album, 50, stdin);
    printf("Enter the year of release: ");
    scanf("%d", &new_song.year);
    getchar(); /* clear newline character */

    /* Add new song to library */
    library[num_entries] = new_song;
    printf("The song has been added to the library.\n");
}

/* Function to remove a song from the library */
void remove_song(Song library[], int num_entries) {
    char remove_title[50];
    int i, j;
    int found_song = 0;

    /* Prompt user for title of song to remove */
    printf("Enter the title of the song to remove: ");
    fgets(remove_title, 50, stdin);

    /* Loop through library to find song to remove */
    for (i = 0; i < num_entries; i++) {
        if (strcmp(remove_title, library[i].title) == 0) {
            /* Shift all songs after removed song back by one position */
            for (j = i; j < num_entries - 1; j++) {
                library[j] = library[j+1];
            }
            printf("The song has been removed from the library.\n");
            found_song = 1;
        }
    }

    /* Print message if song was not found */
    if (!found_song) {
        printf("The song was not found in the library.\n");
    }
}

/* Function to display the entire music library */
void display_library(Song library[], int num_entries) {
    int i;

    /* Loop through library and print each song */
    printf("\nMusic Library:\n\n");
    for (i = 0; i < num_entries; i++) {
        printf("Title: %s", library[i].title);
        printf("Artist: %s", library[i].artist);
        printf("Album: %s", library[i].album);
        printf("Year: %d\n", library[i].year);
        printf("-------------------------\n");
    }

    /* Print message if library is empty */
    if (num_entries == 0) {
        printf("The music library is empty.\n");
    }
}

int main() {
    Song library[100]; /* Maximum 100 song entries */
    int num_entries = 0;
    int choice;

    /* Loop to display menu and handle user input */
    while (1) {
        printf("\nMusic Library Management System\n");
        printf("1. Add a new song\n");
        printf("2. Remove a song\n");
        printf("3. Display the music library\n");
        printf("4. Quit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); /* clear newline character */

        switch (choice) {
        case 1:
            add_song(library, num_entries);
            num_entries++;
            break;
        case 2:
            remove_song(library, num_entries);
            num_entries--;
            break;
        case 3:
            display_library(library, num_entries);
            break;
        case 4:
            printf("Goodbye!\n");
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
            break;
        }
    }

    return 0;
}