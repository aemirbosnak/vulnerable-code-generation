//FormAI DATASET v1.0 Category: Music Library Management System ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define maximum characters for song title and artist name
#define MAX_TITLE_LENGTH 100
#define MAX_ARTIST_NAME_LENGTH 50

// Define maximum number of songs in the library
#define MAX_NUMBER_OF_SONGS 100

// Define a struct for each song
typedef struct Song {
    char title[MAX_TITLE_LENGTH];
    char artist[MAX_ARTIST_NAME_LENGTH];
    int year;
} Song;

// Define the library as an array of songs and a count of the number of songs
Song library[MAX_NUMBER_OF_SONGS];
int number_of_songs = 0;

// Function prototypes
void add_song();
void list_songs();
void search_songs();
void remove_song();

int main() {
    int choice;
    
    printf("Welcome to the Music Library Management System\n\n");
    
    do {
        printf("\nMain Menu\n");
        printf("1. Add a song\n");
        printf("2. List all songs\n");
        printf("3. Search songs\n");
        printf("4. Remove a song\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                add_song();
                break;
            case 2:
                list_songs();
                break;
            case 3:
                search_songs();
                break;
            case 4:
                remove_song();
                break;
            case 5:
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    } while (choice != 5);
    
    return 0;
}

void add_song() {
    // Check if maximum number of songs has been reached
    if (number_of_songs == MAX_NUMBER_OF_SONGS) {
        printf("\nThe library is full. Cannot add new song.\n");
        return;
    }
    
    // Get user input for song title, artist name, and year
    printf("\nEnter the following song details:\n");
    printf("Title: ");
    scanf(" %[^\n]s", library[number_of_songs].title);
    printf("Artist: ");
    scanf(" %[^\n]s", library[number_of_songs].artist);
    printf("Year: ");
    scanf("%d", &library[number_of_songs].year);
    
    // Increment the number of songs in the library
    number_of_songs++;
    
    printf("\nSong added successfully.\n");
}

void list_songs() {
    // Check if there are songs in the library
    if (number_of_songs == 0) {
        printf("\nThe library is empty. No songs to list.\n");
        return;
    }
    
    // Print the header for the song list
    printf("\nSong List:\n");
    printf("Title\t\tArtist\t\tYear\n");
    
    // Print each song in the library
    for (int i = 0; i < number_of_songs; i++) {
        printf("%s\t\t%s\t\t%d\n", library[i].title, library[i].artist, library[i].year);
    }
}

void search_songs() {
    // Check if there are songs in the library
    if (number_of_songs == 0) {
        printf("\nThe library is empty. No songs to search.\n");
        return;
    }
    
    // Get user input for search query
    char search_query[MAX_TITLE_LENGTH];
    printf("\nEnter a search query: ");
    scanf(" %[^\n]s", search_query);
    
    // Search for songs that contain the search query in the title or artist name
    int results_count = 0;
    for (int i = 0; i < number_of_songs; i++) {
        if (strstr(library[i].title, search_query) != NULL ||
            strstr(library[i].artist, search_query) != NULL) {
            if (results_count == 0) {
                // Print the header for the search results
                printf("\nSearch Results:\n");
                printf("Title\t\tArtist\t\tYear\n");
            }
            // Print the matching song
            printf("%s\t\t%s\t\t%d\n", library[i].title, library[i].artist, library[i].year);
            results_count++;
        }
    }
    
    if (results_count == 0) {
        printf("\nNo songs found.\n");
    } else {
        printf("\n%d song(s) found.\n", results_count);
    }
}

void remove_song() {
    // Check if there are songs in the library
    if (number_of_songs == 0) {
        printf("\nThe library is empty. No songs to remove.\n");
        return;
    }
    
    // Get user input for the song title to remove
    char remove_title[MAX_TITLE_LENGTH];
    printf("\nEnter the title of the song you want to remove: ");
    scanf(" %[^\n]s", remove_title);
    
    // Search for the song to remove
    int remove_index = -1;
    for (int i = 0; i < number_of_songs; i++) {
        if (strcmp(library[i].title, remove_title) == 0) {
            remove_index = i;
            break;
        }
    }
    
    if (remove_index == -1) {
        printf("\nSong not found. Cannot remove.\n");
    } else {
        // Shift all songs after the removed song back by one index
        for (int i = remove_index + 1; i < number_of_songs; i++) {
            strcpy(library[i-1].title, library[i].title);
            strcpy(library[i-1].artist, library[i].artist);
            library[i-1].year = library[i].year;
        }
        // Decrement the number of songs in the library
        number_of_songs--;
        printf("\nSong removed successfully.\n");
    }
}