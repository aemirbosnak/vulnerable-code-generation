//FormAI DATASET v1.0 Category: Music Library Management System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Maximum number of songs in the library
#define MAX_SONGS 100

// Song struct definition
typedef struct {
    char title[50];
    char artist[50];
    int year;
    double duration;
} Song;

// Function prototypes
void add_song(Song library[], int *num_songs);
void remove_song(Song library[], int *num_songs);
void print_library(Song library[], int num_songs);
void search_library(Song library[], int num_songs);
void save_library(Song library[], int num_songs);
void load_library(Song library[], int *num_songs);

int main() {
    Song library[MAX_SONGS];
    int num_songs = 0;
    char choice;

    // Load existing library from file
    load_library(library, &num_songs);

    // Display menu and handle user input
    do {
        printf("\nC Music Library Management System\n");
        printf("1. Add a song\n");
        printf("2. Remove a song\n");
        printf("3. Display library\n");
        printf("4. Search library\n");
        printf("5. Save library\n");
        printf("6. Quit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1': add_song(library, &num_songs); break;
            case '2': remove_song(library, &num_songs); break;
            case '3': print_library(library, num_songs); break;
            case '4': search_library(library, num_songs); break;
            case '5': save_library(library, num_songs); break;
            case '6': printf("Goodbye!\n"); break;
            default: printf("Invalid choice\n");
        }
    } while (choice != '6');

    return 0;
}

// Function to add a song to the library
void add_song(Song library[], int *num_songs) {
    if (*num_songs == MAX_SONGS) {
        printf("Library is full\n");
        return;
    }

    Song s;
    printf("\nEnter song title: ");
    scanf(" %[^\n]", s.title);
    printf("Enter artist name: ");
    scanf(" %[^\n]", s.artist);
    printf("Enter year: ");
    scanf(" %d", &s.year);
    printf("Enter duration (in minutes): ");
    scanf(" %lf", &s.duration);

    library[*num_songs] = s;
    (*num_songs)++;
    printf("Song added to library\n");
}

// Function to remove a song from the library
void remove_song(Song library[], int *num_songs) {
    // Display all songs in the library with their index number
    printf("\nSelect a song to remove:\n");
    for (int i = 0; i < *num_songs; i++) {
        printf("%d. %s - %s\n", i + 1, library[i].artist, library[i].title);
    }

    // Get user input for song to remove
    int index;
    printf("Enter song number: ");
    scanf(" %d", &index);

    if (index < 1 || index > *num_songs) {
        printf("Invalid song number\n");
        return;
    }

    // Shift songs to the left to remove the selected song
    for (int i = index - 1; i < *num_songs - 1; i++) {
        library[i] = library[i + 1];
    }

    (*num_songs)--;
    printf("Song removed from library\n");
}

// Function to print all songs in the library
void print_library(Song library[], int num_songs) {
    printf("\nC Music Library\n");
    printf("%-25s %-25s %-10s %-10s\n", "Title", "Artist", "Year", "Duration");
    for (int i = 0; i < num_songs; i++) {
        printf("%-25s %-25s %-10d %-10.2f\n", library[i].title, library[i].artist, library[i].year, library[i].duration);
    }
}

// Function to search the library for a specific song
void search_library(Song library[], int num_songs) {
    char search_term[50];
    int found = 0;

    printf("\nEnter search term: ");
    scanf(" %[^\n]", search_term);

    for (int i = 0; i < num_songs; i++) {
        if (strstr(library[i].title, search_term) || strstr(library[i].artist, search_term)) {
            if (!found) {
                printf("\nSearch results:\n");
                printf("%-25s %-25s %-10s %-10s\n", "Title", "Artist", "Year", "Duration");
                found = 1;
            }

            printf("%-25s %-25s %-10d %-10.2f\n", library[i].title, library[i].artist, library[i].year, library[i].duration);
        }
    }

    if (!found) {
        printf("No matching songs found\n");
    }
}

// Function to save the library to a file
void save_library(Song library[], int num_songs) {
    FILE *f = fopen("library.dat", "wb");

    if (!f) {
        printf("Error saving library\n");
        return;
    }

    fwrite(library, sizeof(Song), num_songs, f);
    fclose(f);

    printf("Library saved\n");
}

// Function to load an existing library from a file
void load_library(Song library[], int *num_songs) {
    FILE *f = fopen("library.dat", "rb");

    if (!f) {
        printf("No existing library found\n");
        return;
    }

    fread(library, sizeof(Song), MAX_SONGS, f);
    fclose(f);

    for (int i = 0; i < MAX_SONGS; i++) {
        if (library[i].year != 0 && library[i].duration != 0) {
            (*num_songs)++;
        } else {
            break;
        }
    }

    printf("Library loaded\n");
}