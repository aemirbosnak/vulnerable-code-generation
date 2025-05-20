//FormAI DATASET v1.0 Category: Music Library Management System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store song information
struct Song {
    char title[50];
    char artist[50];
    char album[50];
    int year;
};

// Function to print all songs in library
void print_library(struct Song library[], int num_songs) {
    printf("Library contains %d songs:\n", num_songs);
    for (int i = 0; i < num_songs; i++) {
        printf("Song %d:\n", i+1);
        printf("\tTitle: %s\n", library[i].title);
        printf("\tArtist: %s\n", library[i].artist);
        printf("\tAlbum: %s\n", library[i].album);
        printf("\tYear: %d\n", library[i].year);
    }
}

// Function to add a song to the library
void add_song(struct Song library[], int *num_songs) {
    printf("Enter song title: ");
    fflush(stdin);      // clear input buffer
    gets(library[*num_songs].title);
    printf("Enter song artist: ");
    fflush(stdin);
    gets(library[*num_songs].artist);
    printf("Enter song album: ");
    fflush(stdin);
    gets(library[*num_songs].album);
    printf("Enter song year: ");
    scanf("%d", &library[*num_songs].year);
    (*num_songs)++;     // increment number of songs in library
    printf("Song added to library.\n");
}

// Function to search for a song by title
void search_by_title(struct Song library[], int num_songs) {
    char title[50];
    printf("Enter title to search for: ");
    fflush(stdin);
    gets(title);
    for (int i = 0; i < num_songs; i++) {
        if (strcmp(library[i].title, title) == 0) {
            printf("Song found:\n");
            printf("\tTitle: %s\n", library[i].title);
            printf("\tArtist: %s\n", library[i].artist);
            printf("\tAlbum: %s\n", library[i].album);
            printf("\tYear: %d\n", library[i].year);
            return;
        }
    }
    printf("Song not found.\n");
}

int main() {
    int choice;
    int num_songs = 0;
    struct Song library[100];

    // Main menu loop
    do {
        // Display menu options
        printf("\nMusic Library Management System\n");
        printf("1. Print all songs in library\n");
        printf("2. Add a song to the library\n");
        printf("3. Search for a song by title\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Handle user choice
        switch (choice) {
            case 1:
                print_library(library, num_songs);
                break;
            case 2:
                add_song(library, &num_songs);
                break;
            case 3:
                search_by_title(library, num_songs);
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 4);

    return 0;
}