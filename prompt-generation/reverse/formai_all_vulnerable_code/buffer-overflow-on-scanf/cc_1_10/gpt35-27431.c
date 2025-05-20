//FormAI DATASET v1.0 Category: Music Library Management System ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of songs the library can hold
#define MAX_SONGS 100

// Struct to hold the song data
struct song {
    char title[50];
    char artist[50];
    int year;
};

// Function to add a song to the library
void addSong(struct song* library, int* numSongs) {
    // Check if the library is already full
    if (*numSongs == MAX_SONGS) {
        printf("The library is already full!\n");
        return;
    }

    // Get the input for the new song
    printf("Enter the title of the song: ");
    scanf("%s", library[*numSongs].title);
    printf("Enter the artist of the song: ");
    scanf("%s", library[*numSongs].artist);
    printf("Enter the year the song was released: ");
    scanf("%d", &library[*numSongs].year);

    // Increment the number of songs in the library
    (*numSongs)++;

    printf("Song successfully added to the library!\n");
}

// Function to display all songs in the library
void displayLibrary(struct song* library, int numSongs) {
    // Print the header row
    printf("%-20s %-20s %-4s\n", "Title", "Artist", "Year");
    printf("---------------------------------------------\n");

    // Loop through all songs and print their data
    for (int i = 0; i < numSongs; i++) {
        printf("%-20s %-20s %-4d\n", library[i].title, library[i].artist, library[i].year);
    }
}

// Function to search for songs by artist
void searchByArtist(struct song* library, int numSongs) {
    char artist[50];
    int found = 0;  // Flag to indicate if at least one song was found

    // Get the artist to search for
    printf("Enter the artist name to search for: ");
    scanf("%s", artist);

    // Loop through all songs and print the ones that match the search criteria
    for (int i = 0; i < numSongs; i++) {
        if (strcmp(library[i].artist, artist) == 0) {
            // Print the header row if this is the first song found
            if (!found) {
                printf("%-20s %-20s %-4s\n", "Title", "Artist", "Year");
                printf("---------------------------------------------\n");
            }

            // Print the song data
            printf("%-20s %-20s %-4d\n", library[i].title, library[i].artist, library[i].year);

            found = 1;
        }
    }

    // Print a message if no songs were found
    if (!found) {
        printf("No songs found by that artist.\n");
    }
}

int main() {
    // Initialize the library and number of songs to zero
    struct song library[MAX_SONGS];
    int numSongs = 0;

    // Loop to display the menu and get user input
    while (1) {
        printf("---------------------------------------------\n");
        printf("                  MENU\n");
        printf("---------------------------------------------\n");
        printf("1. Add a song to the library\n");
        printf("2. Display all songs in the library\n");
        printf("3. Search for songs by artist\n");
        printf("4. Exit the program\n");
        printf("---------------------------------------------\n");

        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addSong(library, &numSongs);
                break;
            case 2:
                displayLibrary(library, numSongs);
                break;
            case 3:
                searchByArtist(library, numSongs);
                break;
            case 4:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}