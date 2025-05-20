//FormAI DATASET v1.0 Category: Music Library Management System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct to hold data for each song in the music library
struct Song {
    char title[50];
    char artist[50];
    int yearReleased;
};

// Function to search for a song by its title in the library
void searchByTitle(struct Song *library, int librarySize) {
    char title[50];
    printf("Enter the title of the song: ");
    fflush(stdin);
    fgets(title, 50, stdin);
    strtok(title, "\n"); // Remove trailing newline from input
    
    // Check if the song is in the library and print its details
    int foundSong = 0;
    for (int i = 0; i < librarySize; i++) {
        if (strcmp(title, library[i].title) == 0) {
            printf("Title: %s\n", library[i].title);
            printf("Artist: %s\n", library[i].artist);
            printf("Year released: %d\n", library[i].yearReleased);
            foundSong = 1;
        }
    }
    
    if (!foundSong) {
        printf("Song not found in library.\n");
    }
}

// Function to add a new song to the library
void addSong(struct Song *library, int *librarySize) {
    printf("Enter the title of the song: ");
    fflush(stdin);
    fgets(library[*librarySize].title, 50, stdin);
    strtok(library[*librarySize].title, "\n"); // Remove trailing newline from input
    
    printf("Enter the artist of the song: ");
    fflush(stdin);
    fgets(library[*librarySize].artist, 50, stdin);
    strtok(library[*librarySize].artist, "\n"); // Remove trailing newline from input
    
    printf("Enter the year the song was released: ");
    scanf("%d", &library[*librarySize].yearReleased);
    
    (*librarySize)++; // Increment library size to indicate new song has been added
    printf("Song added to library.\n");
}

// Function to print all songs in the library
void printLibrary(struct Song *library, int librarySize) {
    printf("Music Library:\n");
    for (int i = 0; i < librarySize; i++) {
        printf("Title: %s\n", library[i].title);
        printf("Artist: %s\n", library[i].artist);
        printf("Year released: %d\n\n", library[i].yearReleased);
    }
}

int main() {
    int choice, librarySize = 0;
    struct Song *library = malloc(10 * sizeof(struct Song)); // Allocate memory for library array
    
    do {
        // Print menu options
        printf("\n----- Music Library Management System -----\n");
        printf("1. Search for a song by title\n");
        printf("2. Add a new song to the library\n");
        printf("3. Print all songs in the library\n");
        printf("4. Exit program\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        // Execute menu choice
        switch (choice) {
            case 1:
                searchByTitle(library, librarySize);
                break;
            case 2:
                addSong(library, &librarySize);
                break;
            case 3:
                printLibrary(library, librarySize);
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 4);
    
    free(library); // Free memory used by library array
    return 0;
}