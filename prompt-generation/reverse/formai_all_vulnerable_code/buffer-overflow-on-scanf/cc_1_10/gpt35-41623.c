//FormAI DATASET v1.0 Category: Music Library Management System ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONGS 100 // Maximum number of songs in the library
#define MAX_NAME_LEN 50 // Maximum length of song name
#define MAX_ARTIST_LEN 50 // Maximum length of artist name

// Structure to hold information about a song
typedef struct Song {
    char name[MAX_NAME_LEN];
    char artist[MAX_ARTIST_LEN];
    float duration;
} Song;

// Function declarations
void menu();
void add_song(Song library[], int *song_count);
void search_song(Song library[], int song_count);
void display_library(Song library[], int song_count);

// Main function
int main() {
    Song library[MAX_SONGS]; // Array to hold songs
    int song_count = 0; // Number of songs currently in library

    printf("Welcome to the Music Library Management System!\n");
    menu();

    // Loop until user exits
    char choice = ' ';
    while (choice != '4') {
        printf("\nEnter your choice: ");
        scanf(" %c", &choice);
        switch (choice) {
            case '1':
                add_song(library, &song_count);
                break;
            case '2':
                search_song(library, song_count);
                break;
            case '3':
                display_library(library, song_count);
                break;
            case '4':
                printf("\nThank you for using the Music Library Management System!\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}

// Function to display menu to user
void menu() {
    printf("\n1. Add a song to the library");
    printf("\n2. Search for a song in the library");
    printf("\n3. Display the entire library");
    printf("\n4. Exit");
}

// Function to add a song to the library
void add_song(Song library[], int *song_count) {
    Song new_song; // Temporary variable to hold new song information

    // Get song information from user
    printf("\nEnter the name of the song: ");
    scanf(" %[^\n]", new_song.name);
    printf("Enter the name of the artist: ");
    scanf(" %[^\n]", new_song.artist);
    printf("Enter the duration of the song (in minutes): ");
    scanf(" %f", &new_song.duration);

    // Add new song to library
    library[*song_count] = new_song;
    (*song_count)++; // Increment song count
    printf("\nSong added to library successfully!\n");
}

// Function to search for a song in the library
void search_song(Song library[], int song_count) {
    char query[MAX_NAME_LEN]; // User's search query
    printf("\nEnter the name of the song you want to search: ");
    scanf(" %[^\n]", query);

    // Loop through library and check if any song names match the query
    int found = 0; // Flag to check if any matches were found
    for (int i = 0; i < song_count; i++) {
        if (strstr(library[i].name, query) != NULL) {
            printf("\nMatch found:\n");
            printf("Name: %s\n", library[i].name);
            printf("Artist: %s\n", library[i].artist);
            printf("Duration: %.2f minutes\n", library[i].duration);
            found = 1;
        }
    }

    if (!found) {
        printf("\nNo matches found.\n");
    }
}

// Function to display the entire library
void display_library(Song library[], int song_count) {
    printf("\nAll songs in the library:\n");
    for (int i = 0; i < song_count; i++) {
        printf("%d. %s - %s (%.2f minutes)\n", i+1, library[i].artist, library[i].name, library[i].duration);
    }
}