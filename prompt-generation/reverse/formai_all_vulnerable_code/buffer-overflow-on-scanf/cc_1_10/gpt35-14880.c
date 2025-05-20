//FormAI DATASET v1.0 Category: Music Library Management System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SONGS 100

typedef struct {
    char* title;
    char* artist;
    char* album;
    char* genre;
    int year;
} Song;

// Function declarations
void add_song(Song* library[], int* num_songs);
void display_library(Song* library[], int num_songs);
void search_library(Song* library[], int num_songs);

int main() {
    Song* music_library[MAX_SONGS];
    int num_songs = 0;
    char option;

    printf("----------------------------------------\n");
    printf("Welcome to the C Music Library Manager!\n");
    printf("----------------------------------------\n\n");

    // Main menu loop
    do {
        printf("MAIN MENU\n");
        printf("---------\n");
        printf("A) Add a song\n");
        printf("D) Display library\n");
        printf("S) Search library\n");
        printf("Q) Quit\n\n");
        printf("Please enter the letter corresponding to your choice: ");
        scanf(" %c", &option);
        printf("\n");

        switch (option) {
            case 'A':
                add_song(music_library, &num_songs);
                break;
            case 'D':
                display_library(music_library, num_songs);
                break;
            case 'S':
                search_library(music_library, num_songs);
                break;
            case 'Q':
                printf("Thank you for using the C Music Library Manager!\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }

        printf("\n");

    } while (option != 'Q');

    return 0;
}

// Add a song to the library
void add_song(Song* library[], int* num_songs) {
    // Check if the library is full
    if (*num_songs == MAX_SONGS) {
        printf("ERROR: The library is full. No more songs can be added.\n");
        return;
    }

    printf("ADD A SONG\n");
    printf("-----------\n");

    // Allocate memory for the new song
    Song* new_song = malloc(sizeof(Song));
    if (!new_song) {
        printf("ERROR: Memory allocation failed.\n");
        return;
    }

    // Get user input for the new song
    new_song->title = malloc(100 * sizeof(char));
    new_song->artist = malloc(100 * sizeof(char));
    new_song->album = malloc(100 * sizeof(char));
    new_song->genre = malloc(50 * sizeof(char));

    printf("Title: ");
    scanf(" %[^\n]s", new_song->title);
    printf("Artist: ");
    scanf(" %[^\n]s", new_song->artist);
    printf("Album: ");
    scanf(" %[^\n]s", new_song->album);
    printf("Genre: ");
    scanf(" %[^\n]s", new_song->genre);
    printf("Year: ");
    scanf(" %d", &new_song->year);

    // Add the new song to the library
    library[*num_songs] = new_song;
    *num_songs += 1;

    printf("The song has been added to the library.\n");
}

// Display the entire library
void display_library(Song* library[], int num_songs) {
    if (num_songs == 0) {
        printf("The library is empty.\n");
        return;
    }

    printf("MUSIC LIBRARY\n");
    printf("-------------\n");

    for (int i = 0; i < num_songs; i++) {
        printf("Title: %s\n", library[i]->title);
        printf("Artist: %s\n", library[i]->artist);
        printf("Album: %s\n", library[i]->album);
        printf("Genre: %s\n", library[i]->genre);
        printf("Year: %d\n", library[i]->year);
        printf("\n");
    }
}

// Search the library by title, artist, or album
void search_library(Song* library[], int num_songs) {
    if (num_songs == 0) {
        printf("The library is empty.\n");
        return;
    }

    char query[100];
    printf("SEARCH LIBRARY\n");
    printf("--------------\n");
    printf("Please enter a search query (title, artist, or album): ");
    scanf(" %[^\n]s", query);
    printf("\n");

    for (int i = 0; i < num_songs; i++) {
        if (strstr(library[i]->title, query) != NULL ||
            strstr(library[i]->artist, query) != NULL ||
            strstr(library[i]->album, query) != NULL) {
            printf("Title: %s\n", library[i]->title);
            printf("Artist: %s\n", library[i]->artist);
            printf("Album: %s\n", library[i]->album);
            printf("Genre: %s\n", library[i]->genre);
            printf("Year: %d\n", library[i]->year);
            printf("\n");
        }
    }
}