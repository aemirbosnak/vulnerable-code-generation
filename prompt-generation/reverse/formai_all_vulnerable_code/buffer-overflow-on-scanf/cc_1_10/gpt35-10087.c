//FormAI DATASET v1.0 Category: Music Library Management System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define maximum number of songs in the library
#define MAX_SONGS 100

// Define structure for song
typedef struct Song {
    char title[50];
    char artist[50];
    double duration;
} Song;

// Declare global variables
Song library[MAX_SONGS];
int num_songs = 0;

// Function to add a song to the library
void add_song() {
    // Check if the library is full
    if (num_songs >= MAX_SONGS) {
        printf("Error: library is full.\n");
        return;
    }

    // Prompt for details of the song
    printf("Enter title of song: ");
    scanf("%s", library[num_songs].title);
    printf("Enter artist of song: ");
    scanf("%s", library[num_songs].artist);
    printf("Enter duration of song (in minutes): ");
    scanf("%lf", &library[num_songs].duration);

    // Increment number of songs in the library
    num_songs++;

    // Print success message
    printf("Song added successfully.\n");
}

// Function to search for songs by artist
void search_by_artist() {
    // Prompt for name of artist
    char artist_name[50];
    printf("Enter name of artist: ");
    scanf("%s", artist_name);

    // Loop through library and print songs by artist
    int i;
    int found = 0;
    for (i = 0; i < num_songs; i++) {
        if (strcmp(library[i].artist, artist_name) == 0) {
            printf("%s - %s (%.2f minutes)\n", library[i].artist, library[i].title, library[i].duration);
            found = 1;
        }
    }

    // Print message if artist not found
    if (!found) {
        printf("No songs found by artist %s.\n", artist_name);
    }
}

// Function to display all songs in the library
void display_library() {
    // Loop through library and print details of all songs
    int i;
    for (i = 0; i < num_songs; i++) {
        printf("%s - %s (%.2f minutes)\n", library[i].artist, library[i].title, library[i].duration);
    }
}

// Main function
int main() {
    // Declare variable for user input
    int choice;

    // Loop through options until user selects to exit
    while (1) {
        // Print menu
        printf("\nMusic Library Management System\n");
        printf("1. Add Song\n");
        printf("2. Search Song by Artist\n");
        printf("3. Display Library\n");
        printf("4. Exit\n");
        printf("Please enter your choice: ");
        scanf("%d", &choice);

        // Perform action based on user choice
        switch (choice) {
            case 1:
                add_song();
                break;
            case 2:
                search_by_artist();
                break;
            case 3:
                display_library();
                break;
            case 4:
                printf("Goodbye.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}