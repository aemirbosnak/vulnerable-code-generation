//FormAI DATASET v1.0 Category: Music Library Management System ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*
 * C Music Library Management System Example Program
 * Designed and implemented by [Your Name]
 * University of [Your University]
 * Date: [Date here]
 * This program manages a music library consisting of songs
 * with various attributes (title, artist, genre, etc.)
 */

// Define constants for the size of various arrays
#define MAX_SONGS 100
#define MAX_LENGTH 50
#define MAX_GENRE 20
#define MAX_ARTIST 30

// Define a struct to hold information about a song
typedef struct {
    char title[MAX_LENGTH];
    char artist[MAX_ARTIST];
    char genre[MAX_GENRE];
    int year;
} Song;

// Declare global variables
int num_songs = 0;
Song song_list[MAX_SONGS];

// Function prototypes
void display_menu();
void add_song();
void remove_song();
void search_songs();
void display_all_songs();


int main()
{
    // Display the menu and wait for user input
    char selection;
    do {
        display_menu();
        scanf(" %c", &selection);

        // Process the user's selection
        switch (tolower(selection)) {
            case 'a':
                add_song();
                break;
            case 'r':
                remove_song();
                break;
            case 's':
                search_songs();
                break;
            case 'd':
                display_all_songs();
                break;
            case 'q':
                printf("Exiting Music Library Management System...\n");
                break;
            default:
                printf("Invalid selection. Try again.\n");
                break;
        }
    } while (selection != 'q');

    return 0;
}

/*
 * Display the main menu
 */
void display_menu()
{
    printf("\n");
    printf("Music Library Management System\n");
    printf("--------------------------------\n");
    printf("a. Add a song\n");
    printf("r. Remove a song\n");
    printf("s. Search for a song\n");
    printf("d. Display all songs\n");
    printf("q. Quit\n");
    printf("Enter a selection: ");
}

/*
 * Add a song to the library
 */
void add_song()
{
    // Check if there is space in the song list
    if (num_songs >= MAX_SONGS) {
        printf("Unable to add song. Maximum number of songs (%d) reached.\n", MAX_SONGS);
        return;
    }

    // Get the title, artist, genre, and year from the user
    Song new_song;
    printf("\nEnter the song title: ");
    scanf(" %[^\n]", new_song.title);
    printf("Enter the artist name: ");
    scanf(" %[^\n]", new_song.artist);
    printf("Enter the genre: ");
    scanf(" %[^\n]", new_song.genre);
    printf("Enter the year: ");
    scanf(" %d", &new_song.year);

    // Assign the new song to the next available slot in the song list
    song_list[num_songs] = new_song;
    num_songs++;

    printf("\nSong added successfully.\n");
}

/*
 * Remove a song from the library
 */
void remove_song()
{
    // Get the title of the song to remove from the user
    char title[MAX_LENGTH];
    printf("\nEnter the title of the song to remove: ");
    scanf(" %[^\n]", title);

    // Find the song in the song list
    int remove_index = -1;
    for (int i = 0; i < num_songs; i++) {
        if (strcmp(title, song_list[i].title) == 0) {
            remove_index = i;
            break;
        }
    }

    // If the song is found, remove it
    if (remove_index >= 0) {
        for (int i = remove_index; i < num_songs-1; i++) {
            song_list[i] = song_list[i+1];
        }
        num_songs--;
        printf("\nSong removed successfully.\n");
    } else {
        printf("\nSong not found in library.\n");
    }
}

/*
 * Search for a song in the library
 */
void search_songs()
{
    // Get the search term from the user
    char search_term[MAX_LENGTH];
    printf("\nEnter a search term: ");
    scanf(" %[^\n]", search_term);

    // Search for the term in the title, artist, and genre of each song
    int num_results = 0;
    for (int i = 0; i < num_songs; i++) {
        if (strstr(song_list[i].title, search_term) ||
            strstr(song_list[i].artist, search_term) ||
            strstr(song_list[i].genre, search_term)) {
            // Print the song if it matches the search term
            printf("\n%d.\nTitle: %s\nArtist: %s\nGenre: %s\nYear: %d\n", i+1,
                song_list[i].title, song_list[i].artist, song_list[i].genre, song_list[i].year);
            num_results++;
        }
    }

    // If no results were found, indicate so
    if (num_results == 0) {
        printf("\nNo songs found matching the search term.\n");
    }
}

/*
 * Display all songs in the library
 */
void display_all_songs()
{
    // Iterate over each song in the list and print its attributes
    printf("\n");
    for (int i = 0; i < num_songs; i++) {
        printf("%d.\nTitle: %s\nArtist: %s\nGenre: %s\nYear: %d\n", i+1,
            song_list[i].title, song_list[i].artist, song_list[i].genre, song_list[i].year);
    }

    // Indicate if there are no songs in the library
    if (num_songs == 0) {
        printf("No songs in library.\n");
    }
}