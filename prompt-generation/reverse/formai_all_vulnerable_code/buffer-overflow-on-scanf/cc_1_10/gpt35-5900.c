//FormAI DATASET v1.0 Category: Music Library Management System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LENGTH 100

// struct for storing information about a song
typedef struct {
    char title[MAX_LENGTH];
    char artist[MAX_LENGTH];
    char album[MAX_LENGTH];
    int year;
    float duration;
} Song;

// function for adding a new song to the library
void addSong(Song* library, int numSongs) {
    // check if we have reached the library's max capacity
    if (numSongs >= MAX_LENGTH) {
        printf("Error: library is full.\n");
        return;
    }

    // prompt user for song information
    printf("Enter song title: ");
    fgets(library[numSongs].title, MAX_LENGTH, stdin);
    strtok(library[numSongs].title, "\n");
    printf("Enter artist name: ");
    fgets(library[numSongs].artist, MAX_LENGTH, stdin);
    strtok(library[numSongs].artist, "\n");
    printf("Enter album name: ");
    fgets(library[numSongs].album, MAX_LENGTH, stdin);
    strtok(library[numSongs].album, "\n");
    printf("Enter year released: ");
    scanf("%d", &library[numSongs].year);
    printf("Enter duration (in minutes): ");
    scanf("%f", &library[numSongs].duration);

    // update number of songs in library
    numSongs++;
    printf("Song added to library.\n");

    return;
}

// function for searching for a song in the library
void searchSong(Song* library, int numSongs) {
    char query[MAX_LENGTH];
    int matchFound = 0;

    // prompt user for search query
    printf("Enter search query: ");
    fgets(query, MAX_LENGTH, stdin);
    strtok(query, "\n");

    // search library for matches
    for (int i = 0; i < numSongs; i++) {
        if (strstr(library[i].title, query) || strstr(library[i].artist, query) || strstr(library[i].album, query)) {
            // match found - print song information
            printf("Song found:\nTitle: %s\nArtist: %s\nAlbum: %s\nYear released: %d\nDuration (in minutes): %.2f\n", library[i].title, library[i].artist, library[i].album, library[i].year, library[i].duration);
            matchFound = 1;
        }
    }

    if (!matchFound) {
        printf("No matches found.\n");
    }

    return;
}

// main function
int main() {
    Song library[MAX_LENGTH];
    int numSongs = 0;
    char choice;

    while (1) {
        // display menu and prompt user for choice
        printf("\n---- Music Library Management System ----\n");
        printf("1. Add new song\n");
        printf("2. Search for song\n");
        printf("3. Exit program\n");
        printf("Enter choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                addSong(library, numSongs);
                break;
            case '2':
                searchSong(library, numSongs);
                break;
            case '3':
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    }

    return 0;
}