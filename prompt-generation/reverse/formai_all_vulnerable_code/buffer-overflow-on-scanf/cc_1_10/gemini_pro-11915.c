//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Music library management system

// Struct to store song details
struct song {
    char title[50];
    char artist[50];
    char album[50];
    int year;
    int duration; // in seconds
};

// Array of songs
struct song library[100];

// Number of songs in the library
int num_songs = 0;

// Function to add a song to the library
void add_song() {
    // Get song details from the user
    printf("Enter song title: ");
    scanf("%s", library[num_songs].title);

    printf("Enter song artist: ");
    scanf("%s", library[num_songs].artist);

    printf("Enter song album: ");
    scanf("%s", library[num_songs].album);

    printf("Enter song year: ");
    scanf("%d", &library[num_songs].year);

    printf("Enter song duration (in seconds): ");
    scanf("%d", &library[num_songs].duration);

    // Increment the number of songs
    num_songs++;
}

// Function to search for a song in the library
void search_song() {
    // Get the search term from the user
    char search_term[50];
    printf("Enter search term: ");
    scanf("%s", search_term);

    // Search for the song in the library
    int found = 0;
    for (int i = 0; i < num_songs; i++) {
        // Check if the song title, artist, or album contains the search term
        if (strstr(library[i].title, search_term) != NULL || strstr(library[i].artist, search_term) != NULL || strstr(library[i].album, search_term) != NULL) {
            // Print the song details
            printf("Song found:\n");
            printf("Title: %s\n", library[i].title);
            printf("Artist: %s\n", library[i].artist);
            printf("Album: %s\n", library[i].album);
            printf("Year: %d\n", library[i].year);
            printf("Duration: %d seconds\n", library[i].duration);

            // Set the found flag to true
            found = 1;
        }
    }

    // If the song was not found, print an error message
    if (!found) {
        printf("Song not found.\n");
    }
}

// Function to print the entire library
void print_library() {
    // Print the songs in the library
    for (int i = 0; i < num_songs; i++) {
        printf("Song %d:\n", i + 1);
        printf("Title: %s\n", library[i].title);
        printf("Artist: %s\n", library[i].artist);
        printf("Album: %s\n", library[i].album);
        printf("Year: %d\n", library[i].year);
        printf("Duration: %d seconds\n\n", library[i].duration);
    }
}

// Main function
int main() {
    // Main menu
    int choice;
    do {
        // Print the menu options
        printf("1. Add a song\n");
        printf("2. Search for a song\n");
        printf("3. Print the entire library\n");
        printf("4. Quit\n");

        // Get the user's choice
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Perform the selected action
        switch (choice) {
            case 1:
                add_song();
                break;
            case 2:
                search_song();
                break;
            case 3:
                print_library();
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 4.\n");
        }
    } while (choice != 4);

    return 0;
}