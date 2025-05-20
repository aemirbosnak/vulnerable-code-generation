//FormAI DATASET v1.0 Category: Music Library Management System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constants
#define MAX_SONGS 100
#define MAX_TITLE_LENGTH 50
#define MAX_ARTIST_LENGTH 30
#define MAX_ALBUM_LENGTH 30

// Define struct for a song
typedef struct {
    char title[MAX_TITLE_LENGTH];
    char artist[MAX_ARTIST_LENGTH];
    char album[MAX_ALBUM_LENGTH];
    int year;
    float duration;
} song_t;

// Define global variables
song_t library[MAX_SONGS];
int num_songs = 0;

// Function prototypes
void add_song();
void remove_song();
void print_library();

int main() {
    int choice;
    do {
        // Display menu options
        printf("\n---C MUSIC LIBRARY MANAGEMENT SYSTEM---\n");
        printf("1. Add Song\n");
        printf("2. Remove Song\n");
        printf("3. Print Library\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_song();
                break;
            case 2:
                remove_song();
                break;
            case 3:
                print_library();
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    } while (choice != 4);
    return 0;
}

// Function to add a song to the library
void add_song() {
    // Check if the library is full
    if (num_songs == MAX_SONGS) {
        printf("Error: library is full. Cannot add more songs.\n");
        return;
    }
    // Get user input for song properties
    char title[MAX_TITLE_LENGTH], artist[MAX_ARTIST_LENGTH], album[MAX_ALBUM_LENGTH];
    int year;
    float duration;
    printf("Enter the song title: ");
    scanf("%s", title);
    printf("Enter the artist name: ");
    scanf("%s", artist);
    printf("Enter the album name: ");
    scanf("%s", album);
    printf("Enter the release year: ");
    scanf("%d", &year);
    printf("Enter the duration in minutes: ");
    scanf("%f", &duration);
    // Add song to library
    strcpy(library[num_songs].title, title);
    strcpy(library[num_songs].artist, artist);
    strcpy(library[num_songs].album, album);
    library[num_songs].year = year;
    library[num_songs].duration = duration;
    num_songs++;
    printf("Song added to library successfully!\n");
}

// Function to remove a song from the library
void remove_song() {
    // Check if the library is empty
    if (num_songs == 0) {
        printf("Error: library is empty. Cannot remove songs.\n");
        return;
    }
    // Get user input for song title
    char title[MAX_TITLE_LENGTH];
    printf("Enter the song title to remove: ");
    scanf("%s", title);
    // Find the song in the library
    int found = 0;
    for (int i = 0; i < num_songs; i++) {
        if (strcmp(library[i].title, title) == 0) {
            // Shift all songs after it one position left
            for (int j = i; j < num_songs-1; j++) {
                library[j] = library[j+1];
            }
            num_songs--;
            printf("Song removed from library successfully!\n");
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Error: song not found in library.\n");
    }
}

// Function to print the entire library
void print_library() {
    // Check if the library is empty
    if (num_songs == 0) {
        printf("Error: library is empty. Nothing to print.\n");
        return;
    }
    // Print all songs in the library
    printf("SONG LIST\n");
    for (int i = 0; i < num_songs; i++) {
        printf("%d. %s - %s (%s) [%d] %.2f mins\n", i+1, library[i].title, library[i].artist, library[i].album, library[i].year, library[i].duration);
    }
}