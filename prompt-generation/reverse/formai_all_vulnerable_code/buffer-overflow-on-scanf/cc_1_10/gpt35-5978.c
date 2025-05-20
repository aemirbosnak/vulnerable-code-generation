//FormAI DATASET v1.0 Category: Music Library Management System ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure definition for the songs
struct song {
    char title[50];
    char artist[50];
    int duration; // In seconds
    float rating;  // Out of 5.0
    char genre[20];
};

// Function prototypes
void displayMenu();
void addSong(struct song *playlist, int *count);
void removeSong(struct song *playlist, int *count);
void searchSong(struct song *playlist, int count);
void sortByRating(struct song *playlist, int count);
void displayAllSongs(struct song *playlist, int count);

int main() {
    struct song playlist[100]; // Maximum of 100 songs allowed in the library
    int count = 0; // Counter for the number of songs in the playlist
    int choice; // Choice variable to hold user's selection from menu

    printf("Welcome to the C Music Library Management System!\n\n");

    do {
        displayMenu(); // Display menu options
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addSong(playlist, &count);
                break;
            case 2:
                removeSong(playlist, &count);
                break;
            case 3:
                searchSong(playlist, count);
                break;
            case 4:
                sortByRating(playlist, count);
                break;
            case 5:
                displayAllSongs(playlist, count);
                break;
            case 6:
                printf("Thanks for using the C Music Library! Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}

// Function to display menu options
void displayMenu() {
    printf("\nAvailable options:\n");
    printf("1. Add a song to the library\n");
    printf("2. Remove a song from the library\n");
    printf("3. Search for a song in the library\n");
    printf("4. Sort songs by rating\n");
    printf("5. Display all songs in the library\n");
    printf("6. Exit the program\n");
}

// Function to add a song to the playlist
void addSong(struct song *playlist, int *count) {
    if (*count == 100) { // Check if maximum number of songs have already been added
        printf("The library is full. No more songs can be added.\n");
        return;
    }

    printf("\nEnter details of the song:\n");
    printf("Title: ");
    scanf(" %[^\n]s", playlist[*count].title);
    printf("Artist: ");
    scanf(" %[^\n]s", playlist[*count].artist);
    printf("Duration (in seconds): ");
    scanf("%d", &playlist[*count].duration);
    printf("Rating (out of 5.0): ");
    scanf("%f", &playlist[*count].rating);
    printf("Genre: ");
    scanf(" %[^\n]s", playlist[*count].genre);

    *count = *count + 1; // Increment song count
    printf("\nThe song was added to the library successfully!\n");
}

// Function to remove a song from the playlist
void removeSong(struct song *playlist, int *count) {
    if (*count == 0) { // Check if there are no songs in the library
        printf("The library is empty. No songs to remove.\n");
        return;
    }

    char searchTitle[50];
    int i;
    int found = 0;

    printf("Enter the title of the song to be removed: ");
    scanf(" %[^\n]s", searchTitle);

    for (i = 0; i < *count; i++) {
        if (strcmp(playlist[i].title, searchTitle) == 0) {
            found = 1;
            break;
        }
    }

    if (found) {
        for (i = i; i < (*count - 1); i++) {
            playlist[i] = playlist[i + 1]; // Shifting the playlist to cover the removed song
        }

        *count = *count - 1; // Decrement song count
        printf("The song was successfully removed from the library!\n");
    } else {
        printf("Song not found in the library. Please try again.\n");
    }
}

// Function to search for a song in the playlist
void searchSong(struct song *playlist, int count) {
    if (count == 0) { // Check if there are no songs in the library
        printf("The library is empty. No songs to search for.\n");
        return;
    }

    char searchTitle[50];
    int i;
    int found = 0;

    printf("Enter the title of the song to search for: ");
    scanf(" %[^\n]s", searchTitle);

    for (i = 0; i < count; i++) {
        if (strcmp(playlist[i].title, searchTitle) == 0) {
            found = 1;
            break;
        }
    }

    if (found) {
        printf("\nSong details:\n");
        printf("Title: %s\n", playlist[i].title);
        printf("Artist: %s\n", playlist[i].artist);
        printf("Duration: %d seconds\n", playlist[i].duration);
        printf("Rating: %0.1f / 5.0\n", playlist[i].rating);
        printf("Genre: %s\n", playlist[i].genre);
    } else {
        printf("Song not found in the library. Please try again.\n");
    }
}

// Function to sort the playlist by rating
void sortByRating(struct song *playlist, int count) {
    if (count == 0) { // Check if there are no songs in the library
        printf("The library is empty. No songs to sort.\n");
        return;
    }

    int i, j;
    struct song temp;

    for (i = 0; i < count - 1; i++) {
        for (j = 0; j < count - 1 - i; j++) {
            if (playlist[j].rating < playlist[j + 1].rating) {
                // Swap the songs if they are in the wrong order
                temp = playlist[j];
                playlist[j] = playlist[j + 1];
                playlist[j + 1] = temp;
            }
        }
    }

    printf("The playlist has been sorted by rating!\n");
}

// Function to display all the songs in the playlist
void displayAllSongs(struct song *playlist, int count) {
    if (count == 0) { // Check if there are no songs in the library
        printf("The library is empty. No songs to display.\n");
        return;
    }

    int i;

    printf("\nThe current library:\n");
    for (i = 0; i < count; i++) {
        printf("%d. Title: %s | Artist: %s | Duration: %d seconds | Rating: %0.1f / 5.0 | Genre: %s\n", i + 1,
                playlist[i].title, playlist[i].artist, playlist[i].duration, playlist[i].rating, playlist[i].genre);
    }
}