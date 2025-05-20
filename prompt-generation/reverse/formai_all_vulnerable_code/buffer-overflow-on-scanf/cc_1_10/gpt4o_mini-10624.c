//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONGS 100
#define TITLE_LENGTH 50
#define ARTIST_LENGTH 50

typedef struct {
    char title[TITLE_LENGTH];
    char artist[ARTIST_LENGTH];
} Song;

typedef struct {
    Song songs[MAX_SONGS];
    int count;
} MusicLibrary;

void initializeLibrary(MusicLibrary* library) {
    library->count = 0;
}

void addSong(MusicLibrary* library) {
    if (library->count >= MAX_SONGS) {
        printf("Library is full! Cannot add more songs.\n");
        return;
    }

    Song newSong;
    printf("Enter song title: ");
    getchar(); // Consume newline from previous input
    fgets(newSong.title, TITLE_LENGTH, stdin);
    newSong.title[strcspn(newSong.title, "\n")] = 0; // Remove newline

    printf("Enter artist name: ");
    fgets(newSong.artist, ARTIST_LENGTH, stdin);
    newSong.artist[strcspn(newSong.artist, "\n")] = 0; // Remove newline

    library->songs[library->count++] = newSong;
    printf("Song added successfully!\n");
}

void displaySongs(MusicLibrary* library) {
    if (library->count == 0) {
        printf("No songs in the library.\n");
        return;
    }
    printf("Songs in the music library:\n");
    for (int i = 0; i < library->count; i++) {
        printf("Song %d: %s by %s\n", i + 1, library->songs[i].title, library->songs[i].artist);
    }
}

void searchSong(MusicLibrary* library) {
    char searchTitle[TITLE_LENGTH];
    printf("Enter the song title to search: ");
    getchar(); // Consume newline from previous input
    fgets(searchTitle, TITLE_LENGTH, stdin);
    searchTitle[strcspn(searchTitle, "\n")] = 0; // Remove newline

    printf("Searching for '%s'...\n", searchTitle);
    int found = 0;
    for (int i = 0; i < library->count; i++) {
        if (strcasecmp(library->songs[i].title, searchTitle) == 0) {
            printf("Found: %s by %s\n", library->songs[i].title, library->songs[i].artist);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Song not found in the library.\n");
    }
}

void displayMenu() {
    printf("\n--- Music Library Management System ---\n");
    printf("1. Add Song\n");
    printf("2. Display Songs\n");
    printf("3. Search Song\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
}

int main() {
    MusicLibrary library;
    initializeLibrary(&library);
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addSong(&library);
                break;
            case 2:
                displaySongs(&library);
                break;
            case 3:
                searchSong(&library);
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
    
    return 0;
}