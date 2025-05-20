//FormAI DATASET v1.0 Category: Music Library Management System ; Style: energetic
// Welcome to the Music Library Management System!
// This program helps you manage your music library with ease.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to store information about each song
typedef struct song {
    char title[50];
    char artist[30];
    char album[30];
    int year;
} Song;

// Define a function to add a new song to the library
void addSong(Song* library, int* numSongs) {
    printf("\nEnter the details of the new song:\n");
    printf("Title: ");
    scanf("%s", library[*numSongs].title);
    printf("Artist: ");
    scanf("%s", library[*numSongs].artist);
    printf("Album: ");
    scanf("%s", library[*numSongs].album);
    printf("Year: ");
    scanf("%d", &library[*numSongs].year);

    (*numSongs)++;
    printf("\nSong added successfully to the library!\n");
}

// Define a function to list all songs in the library
void listSongs(Song* library, int numSongs) {
    if (numSongs == 0) {
        printf("\nThe music library is empty!\n");
    } else {
        printf("\nListing all songs in the library:\n");
        for (int i = 0; i < numSongs; i++) {
            printf("%d. %s - %s (%s, %d)\n", i+1, library[i].artist, library[i].title, library[i].album, library[i].year);
        }
    }
}

// Define a function to search for a song in the library by title
void searchSong(Song* library, int numSongs) {
    if (numSongs == 0) {
        printf("\nThe music library is empty!\n");
    } else {
        char searchTitle[50];
        printf("\nEnter the title of the song to search: ");
        scanf("%s", searchTitle);

        for (int i = 0; i < numSongs; i++) {
            if (strcmp(library[i].title, searchTitle) == 0) {
                printf("\nSong found in the library:\n");
                printf("%d. %s - %s (%s, %d)\n", i+1, library[i].artist, library[i].title, library[i].album, library[i].year);
                return;
            }
        }
        printf("\nSong not found in the library.\n");
    }
}

int main() {
    Song musicLibrary[100];
    int numSongs = 0;
    int choice;

    printf("Welcome to the Music Library Management System! \n");

    do {
        printf("\nWhat would you like to do?\n");
        printf("1. Add a new song to the library\n");
        printf("2. List all songs in the library\n");
        printf("3. Search for a song in the library\n");
        printf("4. Quit the program\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addSong(musicLibrary, &numSongs); break;
            case 2: listSongs(musicLibrary, numSongs); break;
            case 3: searchSong(musicLibrary, numSongs); break;
            case 4: break;
            default: printf("\nInvalid choice. Please enter a number between 1 and 4.\n");
        }
    } while (choice != 4);

    printf("\nThank you for using the Music Library Management System!");

    return 0;
}