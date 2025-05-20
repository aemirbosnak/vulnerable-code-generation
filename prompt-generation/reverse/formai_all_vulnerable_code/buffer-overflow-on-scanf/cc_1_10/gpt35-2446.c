//FormAI DATASET v1.0 Category: Music Library Management System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONGS 100 // Maximum number of songs that can be stored
#define MAX_NAME_LENGTH 30 // Maximum length of a song or artist name

// Structure for a single song
struct Song {
    char title[MAX_NAME_LENGTH];
    char artist[MAX_NAME_LENGTH];
    int year;
    float duration;
};

// Function prototypes
void addSong(struct Song *library, int *numSongs);
void searchSong(struct Song *library, int numSongs);
void printLibrary(struct Song *library, int numSongs);

int main() {
    struct Song library[MAX_SONGS]; // Array of songs in the library
    int numSongs = 0; // Number of songs currently in the library
    char response;

    printf("Welcome to the C Music Library Management System!\n");

    do {
        printf("\nPlease select an option:\n");
        printf("1. Add a song to the library\n");
        printf("2. Search for a song in the library\n");
        printf("3. Print the entire library\n");
        printf("4. Exit\n");

        scanf(" %c", &response);

        switch (response) {
            case '1':
                addSong(library, &numSongs);
                break;
            case '2':
                searchSong(library, numSongs);
                break;
            case '3':
                printLibrary(library, numSongs);
                break;
            case '4':
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid option.\n");
                break;
        }
    } while (response != '4');

    return 0;
}

// Function to add a song to the library
void addSong(struct Song *library, int *numSongs) {
    if (*numSongs == MAX_SONGS) {
        printf("Library is full.\n");
        return;
    }

    printf("Please enter the song title: ");
    scanf(" %[^\n]s", library[*numSongs].title);

    printf("Please enter the artist name: ");
    scanf(" %[^\n]s", library[*numSongs].artist);

    printf("Please enter the year: ");
    scanf("%d", &library[*numSongs].year);

    printf("Please enter the duration in minutes: ");
    scanf("%f", &library[*numSongs].duration);

    (*numSongs)++;
}

// Function to search for a song in the library
void searchSong(struct Song *library, int numSongs) {
    char title[MAX_NAME_LENGTH];
    int matchFound = 0;

    printf("Please enter the song title: ");
    scanf(" %[^\n]s", title);

    for (int i = 0; i < numSongs; i++) {
        if (strcmp(title, library[i].title) == 0) {
            printf("Match found:\n");
            printf("Title: %s\n", library[i].title);
            printf("Artist: %s\n", library[i].artist);
            printf("Year: %d\n", library[i].year);
            printf("Duration: %.2f minutes\n", library[i].duration);
            matchFound = 1;
            break;
        }
    }

    if (!matchFound) {
        printf("No matches found for \"%s\".\n", title);
    }
}

// Function to print the entire library
void printLibrary(struct Song *library, int numSongs) {
    if (numSongs == 0) {
        printf("Library is empty.\n");
        return;
    }

    printf("Here is the entire library:\n");
    for (int i = 0; i < numSongs; i++) {
        printf("\nSong %d:\n", i+1);
        printf("Title: %s\n", library[i].title);
        printf("Artist: %s\n", library[i].artist);
        printf("Year: %d\n", library[i].year);
        printf("Duration: %.2f minutes\n", library[i].duration);
    }
}