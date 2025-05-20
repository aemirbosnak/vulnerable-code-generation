//FormAI DATASET v1.0 Category: Music Library Management System ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Struct for storing information about music albums
typedef struct album {
    char title[50];
    char artist[30];
    int year;
    int rating;
} Album;

// Function to get user input for a new album
Album getNewAlbum() {
    Album newAlbum;
    printf("Enter the title of the album: ");
    scanf("%s", newAlbum.title);
    printf("Enter the name of the artist: ");
    scanf("%s", newAlbum.artist);
    printf("Enter the year the album was released: ");
    scanf("%d", &newAlbum.year);
    printf("Enter your rating of the album (out of 10): ");
    scanf("%d", &newAlbum.rating);
    return newAlbum;
}

// Function to display information about an album
void displayAlbum(Album album) {
    printf("\nTitle: %s\n", album.title);
    printf("Artist: %s\n", album.artist);
    printf("Year: %d\n", album.year);
    printf("Your rating: %d/10\n", album.rating);
}

// Function to search for an album in the library
void searchForAlbum(Album library[], int numAlbums) {
    char searchTitle[50];
    printf("Enter the title of the album to search for: ");
    scanf("%s", searchTitle);

    // Loop through all the albums in the library
    for (int i = 0; i < numAlbums; i++) {
        if (strcmp(library[i].title, searchTitle) == 0) {
            printf("\nAlbum found!\n");
            displayAlbum(library[i]);
            return;
        }
    }
    printf("\nAlbum not found. Sorry!\n");
}

// Function to delete an album from the library
int deleteAlbum(Album library[], int numAlbums) {
    char deleteTitle[50];
    printf("Enter the title of the album to delete: ");
    scanf("%s", deleteTitle);

    // Loop through all the albums in the library
    for (int i = 0; i < numAlbums; i++) {
        if (strcmp(library[i].title, deleteTitle) == 0) {
            printf("\nAlbum deleted!\n");
            // Shift all the albums after the deleted album over
            for (int j = i; j < numAlbums - 1; j++) {
                library[j] = library[j+1];
            }
            return numAlbums - 1;
        }
    }
    printf("\nAlbum not found. Sorry!\n");
    return numAlbums;
}

int main() {
    Album musicLibrary[100];
    int numAlbums = 0;
    bool done = false;
    while (!done) {
        printf("\n\n\t\tWelcome to the Music Library Management System!\n\n");
        printf("What would you like to do?\n");
        printf("1. Add a new album\n");
        printf("2. Search for an album\n");
        printf("3. Delete an album\n");
        printf("4. Display all albums\n");
        printf("5. Exit\n\n");
        printf("Enter your choice (1-5): ");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Add a new album
                musicLibrary[numAlbums++] = getNewAlbum();
                printf("\nAlbum added successfully!\n");
                break;

            case 2: // Search for an album
                searchForAlbum(musicLibrary, numAlbums);
                break;

            case 3: // Delete an album
                numAlbums = deleteAlbum(musicLibrary, numAlbums);
                break;

            case 4: // Display all albums
                printf("\n\nYour music library:\n\n");
                for (int i = 0; i < numAlbums; i++) {
                    displayAlbum(musicLibrary[i]);
                }
                break;

            case 5: // Exit
                printf("\nGoodbye!\n");
                done = true;
                break;

            default: // Invalid choice
                printf("\nInvalid choice. Try again!\n");
        }
    }
    return 0;
}