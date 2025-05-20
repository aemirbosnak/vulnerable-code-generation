//FormAI DATASET v1.0 Category: Music Library Management System ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of songs in the library
#define MAX_SONGS 100

// Define the maximum length of the song name
#define MAX_NAME_LENGTH 50

// Define the maximum length of the artist name
#define MAX_ARTIST_LENGTH 50

// Define a struct to represent a song in the library
typedef struct {
    char name[MAX_NAME_LENGTH];
    char artist[MAX_ARTIST_LENGTH];
} Song;

// Define a struct to represent the library
typedef struct {
    Song songs[MAX_SONGS];
    int num_songs;
} Library;

// Define a function to add a song to the library
void add_song(Library *library, char *name, char *artist) {
    // Create a new song object
    Song new_song;
    strcpy(new_song.name, name);
    strcpy(new_song.artist, artist);

    // Add the new song to the library
    if (library->num_songs < MAX_SONGS) {
        library->songs[library->num_songs++] = new_song;
    } else {
        printf("Error: Library is full\n");
    }
}

// Define a function to print all the songs in the library
void list_songs(Library *library) {
    printf("Songs in Library:\n");
    for (int i = 0; i < library->num_songs; i++) {
        printf("%d. %s - %s\n", i + 1, library->songs[i].artist, library->songs[i].name);
    }
}

int main() {
    // Initialize the library
    Library library;
    library.num_songs = 0;
    
    // Initialize variables for user input
    char name[MAX_NAME_LENGTH], artist[MAX_ARTIST_LENGTH];
    int choice;
    
    // Loop until the user chooses to exit
    do {
        // Print the menu
        printf("\n-- Music Library Management System --\n");
        printf("1. Add a Song\n");
        printf("2. List all Songs\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                // Get user input for the song name and artist
                printf("Enter the Song Name: ");
                scanf("%s", name);
                printf("Enter the Artist Name: ");
                scanf("%s", artist);
                
                // Add the song to the library
                add_song(&library, name, artist);
                break;
            case 2:
                // List all the songs in the library
                list_songs(&library);
                break;
            case 3:
                // Exit the program
                printf("Exiting Music Library Management System...\n");
                break;
            default:
                printf("Error: Invalid choice\n");
                break;
        }
    } while (choice != 3);
    
    return 0;
}