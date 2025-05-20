//FormAI DATASET v1.0 Category: Music Library Management System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constants for max string length and library size
#define MAX_STRING_LENGTH 50
#define MAX_CATALOG_SIZE 50

// Define struct for Song type
typedef struct song {
    char title[MAX_STRING_LENGTH];
    char artist[MAX_STRING_LENGTH];
    char album[MAX_STRING_LENGTH];
    int year;
    int duration;
} Song;

// Define struct for Catalog type
typedef struct catalog {
    Song songs[MAX_CATALOG_SIZE];
    int count;
} Catalog;

// Define function to add a song to the catalog
void addSong(Catalog *catalog, Song song) {
    if (catalog->count < MAX_CATALOG_SIZE) {
        catalog->songs[catalog->count] = song;
        catalog->count++;
        printf("Successfully added %s by %s to the catalog.\n", song.title, song.artist);
    } else {
        printf("Error: Catalog is full and cannot add %s by %s.\n", song.title, song.artist);
    }
}

// Define function to print all songs in the catalog
void printCatalog(Catalog catalog) {
    if (catalog.count == 0) {
        printf("Catalog is empty.\n");
        return;
    }
    printf("Catalog:\n");
    for (int i = 0; i < catalog.count; i++) {
        printf("%d: %s by %s from %s (%d) [%d seconds]\n", i+1, catalog.songs[i].title, catalog.songs[i].artist, catalog.songs[i].album, catalog.songs[i].year, catalog.songs[i].duration);
    }
}

int main() {
    // Declare variables for user input
    char option[MAX_STRING_LENGTH];
    char title[MAX_STRING_LENGTH];
    char artist[MAX_STRING_LENGTH];
    char album[MAX_STRING_LENGTH];
    int year = 0;
    int duration = 0;

    // Initialize catalog
    Catalog catalog;
    catalog.count = 0;

    // Print welcome message and instructions
    printf("Welcome to the C Music Library Management System!\n");
    printf("Type 'add' to add a song to the catalog, 'list' to list all songs in the catalog, or 'exit' to quit.\n");

    // Loop to get user input and execute commands
    while (1) {
        // Get user input
        printf("> ");
        scanf("%s", option);

        // Execute command based on user input
        if (strcmp(option, "add") == 0) {
            printf("Enter title: ");
            scanf("%s", title);
            printf("Enter artist: ");
            scanf("%s", artist);
            printf("Enter album: ");
            scanf("%s", album);
            printf("Enter year: ");
            scanf("%d", &year);
            printf("Enter duration (in seconds): ");
            scanf("%d", &duration);

            // Create new song and add to catalog
            Song song;
            strcpy(song.title, title);
            strcpy(song.artist, artist);
            strcpy(song.album, album);
            song.year = year;
            song.duration = duration;
            addSong(&catalog, song);
        } else if (strcmp(option, "list") == 0) {
            printCatalog(catalog);
        } else if (strcmp(option, "exit") == 0) {
            printf("Goodbye!\n");
            exit(0);
        } else {
            printf("Error: Invalid option '%s'.\n", option);
        }
    }

    return 0;
}