//FormAI DATASET v1.0 Category: Music Library Management System ; Style: unmistakable
// C Music Library Management System

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define maximum values for arrays
#define MAX_SONG_LENGTH 50
#define MAX_ARTIST_LENGTH 30
#define MAX_ALBUM_LENGTH 30
#define MAX_GENRE_LENGTH 10

// Define a struct for songs
struct Song {
    char title[MAX_SONG_LENGTH];
    char artist[MAX_ARTIST_LENGTH];
    char album[MAX_ALBUM_LENGTH];
    char genre[MAX_GENRE_LENGTH];
    int duration;
};

// Define the maximum number of songs in the library
#define MAX_SONGS 100

// Declare the global song library array
struct Song library[MAX_SONGS];

// Define the current number of songs in the library as zero
int num_songs = 0;

// Function prototypes
void add_song();
void remove_song();
void display_library();
void search_library();
void sort_library();

int main() {
    // Declare variables for receiving user input
    int choice;
    
    // Loop to display menu options and retrieve user choice
    do {
        // Display menu options
        printf("\n--- C Music Library Management System ---\n");
        printf("1. Add a song\n");
        printf("2. Remove a song\n");
        printf("3. Display library\n");
        printf("4. Search library\n");
        printf("5. Sort library\n");
        printf("6. Quit\n");
        printf("----------------------------------------\n");
        
        // Retrieve user choice
        printf("Enter your choice (1-6): ");
        scanf("%d", &choice);
        
        // Process user's choice
        switch (choice) {
            case 1:
                add_song();
                break;
            case 2:
                remove_song();
                break;
            case 3:
                display_library();
                break;
            case 4:
                search_library();
                break;
            case 5:
                sort_library();
                break;
            case 6:
                printf("Exiting system...\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
        
    } while (choice != 6); // Continue looping as long as user choice is not 6
    
    return 0;
}

// Function for adding a song to the library
void add_song() {
    // Check if library is full
    if (num_songs == MAX_SONGS) {
        printf("Library is full, cannot add more songs.\n");
        return;
    }
    
    // Declare variables for receiving user input
    char title[MAX_SONG_LENGTH], artist[MAX_ARTIST_LENGTH], album[MAX_ALBUM_LENGTH], genre[MAX_GENRE_LENGTH];
    int duration;
    
    // Retrieve user input for song details
    printf("--- Add a new song ---\n");
    printf("Enter song title: ");
    scanf("%s", title);
    printf("Enter artist name: ");
    scanf("%s", artist);
    printf("Enter album name: ");
    scanf("%s", album);
    printf("Enter genre: ");
    scanf("%s", genre);
    printf("Enter duration in seconds: ");
    scanf("%d", &duration);
    
    // Add new song to library
    strcpy(library[num_songs].title, title);
    strcpy(library[num_songs].artist, artist);
    strcpy(library[num_songs].album, album);
    strcpy(library[num_songs].genre, genre);
    library[num_songs].duration = duration;
    
    // Increment number of songs counter
    num_songs++;
    
    // Display success message
    printf("Song added to library.\n");
}

// Function for removing a song from the library
void remove_song() {
    // Check if library is empty
    if (num_songs == 0) {
        printf("Library is empty, nothing to remove.\n");
        return;
    }
    
    // Declare variables for receiving user input
    char title[MAX_SONG_LENGTH];
    int i, found = 0;
    
    // Retrieve user input for song title to remove
    printf("--- Remove a song ---\n");
    printf("Enter song title: ");
    scanf("%s", title);
    
    // Look for song with the given title and remove it
    for (i = 0; i < num_songs; i++) {
        if (strcmp(title, library[i].title) == 0) {
            // Song found, shift library elements to remove song
            found = 1;
            for (; i < num_songs - 1; i++) {
                library[i] = library[i+1];
            }
            // Decrement number of songs counter
            num_songs--;
            break;
        }
    }
    
    if (found) {
        // Display success message
        printf("Song removed from library.\n");
    } else {
        // Display error message if song not found
        printf("Song not found in library.\n");
    }
}

// Function for displaying the entire library
void display_library() {
    // Check if library is empty
    if (num_songs == 0) {
        printf("Library is empty, nothing to display.\n");
        return;
    }
    
    // Display the header row
    printf("--- Library ---\n");
    printf("%-25s %-20s %-20s %-12s %s\n", "Title", "Artist", "Album", "Genre", "Duration");
    
    // Loop through all songs in the library and display details
    int i;
    for (i = 0; i < num_songs; i++) {
        printf("%-25s %-20s %-20s %-12s %d\n", library[i].title, library[i].artist, library[i].album, library[i].genre, library[i].duration);
    }
}

// Function for searching the library for a song
void search_library() {
    // Check if library is empty
    if (num_songs == 0) {
        printf("Library is empty, nothing to search.\n");
        return;
    }
    
    // Declare variables for receiving user input
    char title[MAX_SONG_LENGTH];
    int i, found = 0;
    
    // Retrieve user input for song title to search
    printf("--- Search library ---\n");
    printf("Enter song title: ");
    scanf("%s", title);
    
    // Look for song with the given title and display its details
    for (i = 0; i < num_songs; i++) {
        if (strcmp(title, library[i].title) == 0) {
            // Song found, display details
            found = 1;
            printf("--- Song found ---\n");
            printf("Title: %s\n", library[i].title);
            printf("Artist: %s\n", library[i].artist);
            printf("Album: %s\n", library[i].album);
            printf("Genre: %s\n", library[i].genre);
            printf("Duration: %d\n", library[i].duration);
            break;
        }
    }
    
    if (!found) {
        // Display error message if song not found
        printf("Song not found in library.\n");
    }
}

// Function for sorting the library by song title
void sort_library() {
    // Check if library is empty
    if (num_songs == 0) {
        printf("Library is empty, nothing to sort.\n");
        return;
    }
    
    // Sort the library using bubble sort algorithm
    int i, j;
    struct Song temp;
    for (i = 0; i < num_songs-1; i++) {
        for (j = 0; j < num_songs-i-1; j++) {
            if (strcmp(library[j].title, library[j+1].title) > 0) {
                temp = library[j];
                library[j] = library[j+1];
                library[j+1] = temp;
            }
        }
    }
    
    // Display success message
    printf("Library sorted by song title.\n");
}