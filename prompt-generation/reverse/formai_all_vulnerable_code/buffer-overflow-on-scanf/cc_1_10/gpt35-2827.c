//FormAI DATASET v1.0 Category: Music Library Management System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of songs in the music library
#define MAX_SONGS 100

// Define the maximum length of song titles
#define MAX_TITLE_LENGTH 50

// Define the maximum length of artist names
#define MAX_ARTIST_LENGTH 30

// Define the maximum length of album titles
#define MAX_ALBUM_LENGTH 50

// Define the structure of a song
typedef struct {
    char title[MAX_TITLE_LENGTH];   // The title of the song
    char artist[MAX_ARTIST_LENGTH]; // The name of the artist
    char album[MAX_ALBUM_LENGTH];   // The name of the album
} song;

// Define the music library as an array of songs
song library[MAX_SONGS];

// Define the number of songs currently in the music library
int numSongs = 0;

// Define a function to add a song to the music library
void addSong() {
    // Check if there is enough space for a new song
    if (numSongs >= MAX_SONGS) {
        printf("Error: Music library is full!\n");
        return;
    }
    
    // Get the title of the song from the user
    printf("Enter the title of the song: ");
    fgets(library[numSongs].title, MAX_TITLE_LENGTH, stdin);
    library[numSongs].title[strcspn(library[numSongs].title, "\n")] = 0; // Remove the newline character
    
    // Get the name of the artist from the user
    printf("Enter the name of the artist: ");
    fgets(library[numSongs].artist, MAX_ARTIST_LENGTH, stdin);
    library[numSongs].artist[strcspn(library[numSongs].artist, "\n")] = 0; // Remove the newline character
    
    // Get the name of the album from the user
    printf("Enter the name of the album: ");
    fgets(library[numSongs].album, MAX_ALBUM_LENGTH, stdin);
    library[numSongs].album[strcspn(library[numSongs].album, "\n")] = 0; // Remove the newline character
    
    // Increment the number of songs
    numSongs++;
    
    printf("Song added to the music library!\n");
}

// Define a function to search for a song in the music library
void searchSong() {
    // Get the title of the song from the user
    printf("Enter the title of the song: ");
    char searchTitle[MAX_TITLE_LENGTH];
    fgets(searchTitle, MAX_TITLE_LENGTH, stdin);
    searchTitle[strcspn(searchTitle, "\n")] = 0; // Remove the newline character
    
    // Initialize a counter for the number of matches found
    int numMatches = 0;
    
    // Loop through all songs in the music library
    for (int i = 0; i < numSongs; i++) {
        // Check if the song title contains the search keyword
        if (strstr(library[i].title, searchTitle) != NULL) {
            // Print the details of the song
            printf("Title: %s\nArtist: %s\nAlbum: %s\n", library[i].title, library[i].artist, library[i].album);
            
            // Increment the counter for the number of matches found
            numMatches++;
        }
    }
    
    // Check if any matches were found
    if (numMatches == 0) {
        printf("No matches found.\n");
    } else {
        printf("%d match(es) found.\n", numMatches);
    }
}

int main() {
    // Initialize the music library
    numSongs = 0;
    
    // Loop to display menu options and process user commands
    while (1) {
        printf("Music Library Management System\n");
        printf("================================\n");
        printf("1. Add song\n");
        printf("2. Search song\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        
        // Get the user's choice
        int choice;
        scanf("%d", &choice);
        getchar(); // Remove the newline character from the input buffer
        
        // Process the user's choice
        switch (choice) {
            case 1:
                addSong();
                break;
            case 2:
                searchSong();
                break;
            case 3:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
        
        // Print a separator between the output and input
        printf("\n");
    }
    
    return 0;
}