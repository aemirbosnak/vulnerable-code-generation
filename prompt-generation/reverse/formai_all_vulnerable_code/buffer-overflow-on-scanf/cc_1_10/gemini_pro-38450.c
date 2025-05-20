//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store music library data
typedef struct MusicLibrary {
    char title[100];
    char artist[100];
    char album[100];
    int year;
    int length; // in seconds
} MusicLibrary;

// Function to add a new music entry to the library
void addMusic(MusicLibrary *library, int *size) {
    // Get the music details from the user
    printf("Enter the title: ");
    scanf("%s", library[*size].title);
    printf("Enter the artist: ");
    scanf("%s", library[*size].artist);
    printf("Enter the album: ");
    scanf("%s", library[*size].album);
    printf("Enter the year: ");
    scanf("%d", &library[*size].year);
    printf("Enter the length (in seconds): ");
    scanf("%d", &library[*size].length);

    // Increment the library size
    (*size)++;
}

// Function to search for a music entry in the library
void searchMusic(MusicLibrary *library, int size) {
    // Get the search term from the user
    char searchTerm[100];
    printf("Enter the search term: ");
    scanf("%s", searchTerm);

    // Search for the music entry
    int found = 0;
    for (int i = 0; i < size; i++) {
        if (strstr(library[i].title, searchTerm) || strstr(library[i].artist, searchTerm) || strstr(library[i].album, searchTerm)) {
            // Display the music entry
            printf("Title: %s\n", library[i].title);
            printf("Artist: %s\n", library[i].artist);
            printf("Album: %s\n", library[i].album);
            printf("Year: %d\n", library[i].year);
            printf("Length: %d seconds\n", library[i].length);
            found = 1;
            break;
        }
    }

    // Display a message if the music entry was not found
    if (!found) {
        printf("No matching music entry found.\n");
    }
}

// Function to delete a music entry from the library
void deleteMusic(MusicLibrary *library, int *size) {
    // Get the title of the music entry to be deleted from the user
    char title[100];
    printf("Enter the title of the music entry to be deleted: ");
    scanf("%s", title);

    // Search for the music entry
    int found = 0;
    int index = -1;
    for (int i = 0; i < *size; i++) {
        if (strcmp(library[i].title, title) == 0) {
            found = 1;
            index = i;
            break;
        }
    }

    // Delete the music entry if found
    if (found) {
        for (int i = index; i < *size - 1; i++) {
            library[i] = library[i + 1];
        }
        (*size)--;
        printf("Music entry deleted successfully.\n");
    } else {
        printf("No matching music entry found.\n");
    }
}

// Function to print the music library
void printLibrary(MusicLibrary *library, int size) {
    // Print the music library
    for (int i = 0; i < size; i++) {
        printf("Title: %s\n", library[i].title);
        printf("Artist: %s\n", library[i].artist);
        printf("Album: %s\n", library[i].album);
        printf("Year: %d\n", library[i].year);
        printf("Length: %d seconds\n", library[i].length);
        printf("\n");
    }
}

// Main function
int main() {
    // Create a music library
    MusicLibrary library[100];
    int size = 0;

    // Add some music entries to the library
    addMusic(library, &size);
    addMusic(library, &size);
    addMusic(library, &size);

    // Search for a music entry in the library
    searchMusic(library, size);

    // Delete a music entry from the library
    deleteMusic(library, &size);

    // Print the music library
    printLibrary(library, size);

    return 0;
}