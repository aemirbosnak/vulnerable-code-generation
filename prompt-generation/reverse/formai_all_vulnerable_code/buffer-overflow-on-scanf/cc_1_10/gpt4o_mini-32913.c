//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONGS 100
#define MAX_TITLE_LENGTH 100
#define MAX_ARTIST_LENGTH 100

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char artist[MAX_ARTIST_LENGTH];
} Song;

typedef struct {
    Song songs[MAX_SONGS];
    int count;
} MusicLibrary;

void addSong(MusicLibrary *library);
void viewSongs(const MusicLibrary *library);
void searchSong(const MusicLibrary *library);
void displayMenu();

int main() {
    MusicLibrary library;
    library.count = 0;
    int choice;

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline

        switch (choice) {
            case 1:
                addSong(&library);
                break;
            case 2:
                viewSongs(&library);
                break;
            case 3:
                searchSong(&library);
                break;
            case 4:
                printf("Exiting the Music Library Management System. Goodbye!\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}

void displayMenu() {
    printf("\n=== Music Library Management System ===\n");
    printf("1. Add Song\n");
    printf("2. View Songs\n");
    printf("3. Search Song\n");
    printf("4. Exit\n");
}

void addSong(MusicLibrary *library) {
    if (library->count >= MAX_SONGS) {
        printf("Library is full, can't add more songs.\n");
        return;
    }

    Song newSong;
    printf("Enter song title: ");
    fgets(newSong.title, MAX_TITLE_LENGTH, stdin);
    strtok(newSong.title, "\n"); // Remove newline

    printf("Enter artist name: ");
    fgets(newSong.artist, MAX_ARTIST_LENGTH, stdin);
    strtok(newSong.artist, "\n"); // Remove newline

    library->songs[library->count] = newSong;
    library->count++;
    printf("Song added successfully!\n");
}

void viewSongs(const MusicLibrary *library) {
    if (library->count == 0) {
        printf("No songs in the library!\n");
        return;
    }

    printf("\n=== List of Songs ===\n");
    for (int i = 0; i < library->count; i++) {
        printf("%d. %s by %s\n", i + 1, library->songs[i].title, library->songs[i].artist);
    }
}

void searchSong(const MusicLibrary *library) {
    if (library->count == 0) {
        printf("No songs in the library to search!\n");
        return;
    }

    char query[MAX_TITLE_LENGTH];
    printf("Enter song title to search: ");
    fgets(query, MAX_TITLE_LENGTH, stdin);
    strtok(query, "\n"); // Remove newline

    printf("\n=== Search Results ===\n");
    int found = 0;
    for (int i = 0; i < library->count; i++) {
        if (strcasecmp(library->songs[i].title, query) == 0) {
            printf("Found: %s by %s\n", library->songs[i].title, library->songs[i].artist);
            found = 1;
        }
    }

    if (!found) {
        printf("No songs found with the title \"%s\".\n", query);
    }
}