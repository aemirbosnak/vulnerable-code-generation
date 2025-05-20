//FormAI DATASET v1.0 Category: Music Library Management System ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONGS 100 // Maximum number of songs the library can hold

// Song struct that holds information of a single song
struct Song {
    char title[50];
    char artist[50];
    char album[50];
    int year;
};

// Function prototypes
void add_song(struct Song *library, int *songs_count);
void delete_song(struct Song *library, int *songs_count);
void search_song(struct Song *library, int *songs_count);
void display_library(struct Song *library, int *songs_count);

int main() {
    // Initialize library with maximum number of songs
    struct Song library[MAX_SONGS];
    int songs_count = 0; // Number of songs currently in the library

    int choice;
    while (1) {
        // Display menu
        printf("\nC Music Library Management System\n");
        printf("1. Add song\n");
        printf("2. Delete song\n");
        printf("3. Search song\n");
        printf("4. Display library\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_song(library, &songs_count);
                break;
            case 2:
                delete_song(library, &songs_count);
                break;
            case 3:
                search_song(library, &songs_count);
                break;
            case 4:
                display_library(library, &songs_count);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}

// Function to add a song to the library
void add_song(struct Song *library, int *songs_count) {
    // Check if library is full
    if (*songs_count == MAX_SONGS) {
        printf("Library is full. Cannot add any more songs.\n");
        return;
    }

    printf("\nEnter song details:\n");
    printf("Title: ");
    scanf(" %[^\n]s", library[*songs_count].title);
    printf("Artist: ");
    scanf(" %[^\n]s", library[*songs_count].artist);
    printf("Album: ");
    scanf(" %[^\n]s", library[*songs_count].album);
    printf("Year of release: ");
    scanf("%d", &library[*songs_count].year);

    printf("Song added to library successfully.\n");
    (*songs_count)++;
}

// Function to delete a song from the library
void delete_song(struct Song *library, int *songs_count) {
    // Check if library is empty
    if (*songs_count == 0) {
        printf("Library is empty. Cannot delete any song.\n");
        return;
    }

    char title[50];
    printf("\nEnter title of the song to be deleted: ");
    scanf(" %[^\n]s", title);

    int i;
    for (i = 0; i < *songs_count; i++) {
        if (strcmp(title, library[i].title) == 0) {
            // Delete song by shifting array elements
            int j;
            for (j = i; j < *songs_count - 1; j++) {
                strcpy(library[j].title, library[j+1].title);
                strcpy(library[j].artist, library[j+1].artist);
                strcpy(library[j].album, library[j+1].album);
                library[j].year = library[j+1].year;
            }
            (*songs_count)--;
            printf("Song deleted from library successfully.\n");
            return;
        }
    }
    printf("Song with title '%s' not found in library.\n", title);
}

// Function to search for a song in the library
void search_song(struct Song *library, int *songs_count) {
    // Check if library is empty
    if (*songs_count == 0) {
        printf("Library is empty. Cannot search for any song.\n");
        return;
    }

    char title[50];
    printf("\nEnter title of the song to search: ");
    scanf(" %[^\n]s", title);

    int i;
    for (i = 0; i < *songs_count; i++) {
        if (strcmp(title, library[i].title) == 0) {
            // Display song details
            printf("\nSong details:\n");
            printf("Title: %s\n", library[i].title);
            printf("Artist: %s\n", library[i].artist);
            printf("Album: %s\n", library[i].album);
            printf("Year of release: %d\n", library[i].year);
            return;
        }
    }
    printf("Song with title '%s' not found in library.\n", title);
}

// Function to display the entire library
void display_library(struct Song *library, int *songs_count) {
    // Check if library is empty
    if (*songs_count == 0) {
        printf("Library is empty. Nothing to display.\n");
        return;
    }

    printf("\nC Music Library\n");
    printf("Title\t\tArtist\t\tAlbum\t\tYear\n");
    int i;
    for (i = 0; i < *songs_count; i++) {
        printf("%s\t\t%s\t\t%s\t\t%d\n", library[i].title, library[i].artist, library[i].album, library[i].year);
    }
}