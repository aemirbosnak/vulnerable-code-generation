//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONGS 100
#define MAX_TITLE 100
#define MAX_ARTIST 100

typedef struct {
    char title[MAX_TITLE];
    char artist[MAX_ARTIST];
    int year;
} Song;

typedef struct {
    Song songs[MAX_SONGS];
    int count;
} MusicLibrary;

void addSong(MusicLibrary *library);
void removeSong(MusicLibrary *library);
void displaySongs(MusicLibrary *library);
void searchSong(MusicLibrary *library);
void clearBuffer();

int main() {
    MusicLibrary library = { .count = 0 };
    int choice;

    do {
        printf("\n=== Music Library Management System ===\n");
        printf("1. Add Song\n");
        printf("2. Remove Song\n");
        printf("3. Display All Songs\n");
        printf("4. Search Song\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearBuffer();

        switch (choice) {
            case 1:
                addSong(&library);
                break;
            case 2:
                removeSong(&library);
                break;
            case 3:
                displaySongs(&library);
                break;
            case 4:
                searchSong(&library);
                break;
            case 5:
                printf("Exiting the Music Library Management System. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

void addSong(MusicLibrary *library) {
    if (library->count >= MAX_SONGS) {
        printf("Library is full! Unable to add more songs.\n");
        return;
    }

    Song newSong;
    printf("Enter song title: ");
    fgets(newSong.title, MAX_TITLE, stdin);
    strtok(newSong.title, "\n"); // Remove trailing newline
    printf("Enter artist name: ");
    fgets(newSong.artist, MAX_ARTIST, stdin);
    strtok(newSong.artist, "\n"); // Remove trailing newline
    printf("Enter release year: ");
    scanf("%d", &newSong.year);
    clearBuffer();

    library->songs[library->count] = newSong;
    library->count++;
    printf("Song added successfully!\n");
}

void removeSong(MusicLibrary *library) {
    if (library->count == 0) {
        printf("No songs to remove!\n");
        return;
    }

    char title[MAX_TITLE];
    printf("Enter the title of the song to remove: ");
    fgets(title, MAX_TITLE, stdin);
    strtok(title, "\n");

    for (int i = 0; i < library->count; i++) {
        if (strcmp(library->songs[i].title, title) == 0) {
            for (int j = i; j < library->count - 1; j++) {
                library->songs[j] = library->songs[j + 1];
            }
            library->count--;
            printf("Song removed successfully!\n");
            return;
        }
    }
    printf("Song not found in the library.\n");
}

void displaySongs(MusicLibrary *library) {
    if (library->count == 0) {
        printf("No songs in the library.\n");
        return;
    }

    printf("\n=== List of Songs ===\n");
    for (int i = 0; i < library->count; i++) {
        printf("Title: %s, Artist: %s, Year: %d\n", library->songs[i].title, library->songs[i].artist, library->songs[i].year);
    }
}

void searchSong(MusicLibrary *library) {
    if (library->count == 0) {
        printf("No songs in the library to search.\n");
        return;
    }

    char query[MAX_TITLE];
    printf("Enter song title or artist name to search: ");
    fgets(query, MAX_TITLE, stdin);
    strtok(query, "\n"); // Remove trailing newline

    printf("\n=== Search Results ===\n");
    int found = 0;
    for (int i = 0; i < library->count; i++) {
        if (strstr(library->songs[i].title, query) != NULL || strstr(library->songs[i].artist, query) != NULL) {
            printf("Title: %s, Artist: %s, Year: %d\n", library->songs[i].title, library->songs[i].artist, library->songs[i].year);
            found = 1;
        }
    }

    if (!found) {
        printf("No songs found matching your query.\n");
    }
}

void clearBuffer() {
    while (getchar() != '\n'); // Clear the input buffer
}