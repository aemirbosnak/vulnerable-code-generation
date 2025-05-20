//FormAI DATASET v1.0 Category: Music Library Management System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for holding information about a song
struct Song {
    char title[50];
    char artist[50];
    int year;
};

// Function for adding a song to the library
void addSong(struct Song *library, int *numSongs) {
    printf("Enter the title of the song: ");
    scanf("%s", library[*numSongs].title);
    printf("Enter the artist of the song: ");
    scanf("%s", library[*numSongs].artist);
    printf("Enter the year of release for the song: ");
    scanf("%d", &library[*numSongs].year);
    (*numSongs)++;
}

// Function for printing all songs in the library
void printLibrary(struct Song *library, int numSongs) {
    printf("Library Contents:\n");
    for (int i = 0; i < numSongs; i++) {
        printf("%s - %s (%d)\n", library[i].title, library[i].artist, library[i].year);
    }
}

int main() {
    int numSongs = 0;
    struct Song *library = malloc(sizeof(struct Song) * 100);

    while (1) {
        printf("Enter choice:\n");
        printf("1. Add song to library\n");
        printf("2. Print all songs in library\n");
        printf("3. Quit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addSong(library, &numSongs);
                break;
            case 2:
                printLibrary(library, numSongs);
                break;
            case 3:
                free(library);
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please enter a number 1-3.\n");
        }
    }
}