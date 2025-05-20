//FormAI DATASET v1.0 Category: Music Library Management System ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define song struct
typedef struct Song {
    char title[50];
    char artist[50];
    char album[50];
    int year;
    char genre[20];
} Song;

// Define function to add new song to library
void addSong(Song library[], int *count) {
    printf("\nAdd a Song\n----------\n");
    printf("Title: ");
    scanf("%s", library[*count].title);
    printf("Artist: ");
    scanf("%s", library[*count].artist);
    printf("Album: ");
    scanf("%s", library[*count].album);
    printf("Year: ");
    scanf("%d", &library[*count].year);
    printf("Genre: ");
    scanf("%s", library[*count].genre);
    (*count)++;
    printf("Song added to library!\n\n");
}

// Define function to print out all songs in library
void printLibrary(Song library[], int count) {
    printf("\nCurrent Library\n---------------\n");
    for (int i = 0; i < count; i++) {
        printf("Title: %s\n", library[i].title);
        printf("Artist: %s\n", library[i].artist);
        printf("Album: %s\n", library[i].album);
        printf("Year: %d\n", library[i].year);
        printf("Genre: %s\n\n", library[i].genre);
    }
}

int main() {
    // Define library and count variables
    int count = 0;
    Song library[100];

    // User interaction loop
    while(1) {
        char choice;
        printf("What would you like to do?\n");
        printf("\tA) Add a new song to the library\n");
        printf("\tP) Print out all songs in the library\n");
        printf("\tQ) Quit\n");
        scanf(" %c", &choice);

        // Execute appropriate function based on user choice
        switch(choice) {
            case 'A':
                addSong(library, &count);
                break;
            case 'P':
                printLibrary(library, count);
                break;
            case 'Q':
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n\n");
                break;
        }
    }
}