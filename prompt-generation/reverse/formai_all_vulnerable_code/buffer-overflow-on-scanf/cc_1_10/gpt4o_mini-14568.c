//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONGS 100
#define MAX_TITLE_LENGTH 50
#define MAX_ARTIST_LENGTH 50

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char artist[MAX_ARTIST_LENGTH];
    int year;
} Song;

typedef struct {
    Song songs[MAX_SONGS];
    int count;
} MusicLibrary;

void addSong(MusicLibrary *library);
void displaySongs(MusicLibrary library);
void searchSong(MusicLibrary library);

int main() {
    MusicLibrary library;
    library.count = 0;
    int choice;

    do {
        printf("\n=== Music Library Management System ===\n");
        printf("1. Add New Song\n");
        printf("2. Display All Songs\n");
        printf("3. Search for a Song\n");
        printf("4. Exit\n");
        printf("Please enter your choice (1-4): ");
        scanf("%d", &choice);
        getchar(); // consume newline

        switch (choice) {
            case 1:
                addSong(&library);
                break;
            case 2:
                displaySongs(library);
                break;
            case 3:
                searchSong(library);
                break;
            case 4:
                printf("Exiting the program! 🎶\n");
                break;
            default:
                printf("Invalid choice! Please choose between 1 and 4.\n");
        }
    } while (choice != 4);

    return 0;
}

void addSong(MusicLibrary *library) {
    if (library->count >= MAX_SONGS) {
        printf("Library is full! Unable to add more songs.\n");
        return;
    }
    Song newSong;

    printf("Enter the song title: ");
    fgets(newSong.title, MAX_TITLE_LENGTH, stdin);
    // Remove newline character if present
    newSong.title[strcspn(newSong.title, "\n")] = 0;

    printf("Enter the artist name: ");
    fgets(newSong.artist, MAX_ARTIST_LENGTH, stdin);
    // Remove newline character if present
    newSong.artist[strcspn(newSong.artist, "\n")] = 0;

    printf("Enter the release year: ");
    scanf("%d", &newSong.year);
    getchar(); // consume newline

    library->songs[library->count] = newSong;
    library->count++;

    printf("Song '%s' by '%s' added to the library! 🎵\n", newSong.title, newSong.artist);
}

void displaySongs(MusicLibrary library) {
    if (library.count == 0) {
        printf("No songs in the library! 🎧\n");
        return;
    }
    printf("\n=== List of Songs in the Library ===\n");
    for (int i = 0; i < library.count; i++) {
        printf("%d. '%s' by '%s' (%d)\n", i + 1, library.songs[i].title, library.songs[i].artist, library.songs[i].year);
    }
}

void searchSong(MusicLibrary library) {
    if (library.count == 0) {
        printf("The library is empty! Cannot search for songs.\n");
        return;
    }
    char searchTitle[MAX_TITLE_LENGTH];
    printf("Enter the title of the song to search: ");
    fgets(searchTitle, MAX_TITLE_LENGTH, stdin);
    searchTitle[strcspn(searchTitle, "\n")] = 0; // remove newline character

    int found = 0;
    for (int i = 0; i < library.count; i++) {
        if (strcasecmp(library.songs[i].title, searchTitle) == 0) {
            printf("Song found: '%s' by '%s' (%d)\n", library.songs[i].title, library.songs[i].artist, library.songs[i].year);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("No song found with the title '%s'. 🎤\n", searchTitle);
    }
}