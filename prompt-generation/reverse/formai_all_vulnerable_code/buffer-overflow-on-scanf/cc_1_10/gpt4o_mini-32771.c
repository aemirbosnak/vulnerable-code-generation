//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONGS 100
#define TITLE_LEN 50
#define ARTIST_LEN 50

typedef struct {
    char title[TITLE_LEN];
    char artist[ARTIST_LEN];
    int year;
} Song;

Song musicLibrary[MAX_SONGS];
int songCount = 0;

void addSong();
void displaySongs();
void searchSong();
void deleteSong();
void menu();

int main() {
    menu();
    return 0;
}

void menu() {
    int choice;
    while (1) {
        printf("\n--- Music Library Management System ---\n");
        printf("1. Add Song\n");
        printf("2. Display Songs\n");
        printf("3. Search Song\n");
        printf("4. Delete Song\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addSong();
                break;
            case 2:
                displaySongs();
                break;
            case 3:
                searchSong();
                break;
            case 4:
                deleteSong();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}

void addSong() {
    if (songCount < MAX_SONGS) {
        printf("Enter song title: ");
        getchar(); // To consume newline left by previous input
        fgets(musicLibrary[songCount].title, TITLE_LEN, stdin);
        musicLibrary[songCount].title[strcspn(musicLibrary[songCount].title, "\n")] = 0; // Remove newline

        printf("Enter artist name: ");
        fgets(musicLibrary[songCount].artist, ARTIST_LEN, stdin);
        musicLibrary[songCount].artist[strcspn(musicLibrary[songCount].artist, "\n")] = 0; // Remove newline

        printf("Enter year of release: ");
        scanf("%d", &musicLibrary[songCount].year);

        songCount++;
        printf("Song added successfully!\n");
    } else {
        printf("Library full! Cannot add more songs.\n");
    }
}

void displaySongs() {
    if (songCount == 0) {
        printf("No songs in the library.\n");
        return;
    }

    printf("\n--- Music Library ---\n");
    for (int i = 0; i < songCount; i++) {
        printf("Song %d: '%s' by %s (%d)\n", i + 1, musicLibrary[i].title, musicLibrary[i].artist, musicLibrary[i].year);
    }
}

void searchSong() {
    char searchTitle[TITLE_LEN];
    printf("Enter song title to search: ");
    getchar(); // To consume newline left by previous input
    fgets(searchTitle, TITLE_LEN, stdin);
    searchTitle[strcspn(searchTitle, "\n")] = 0; // Remove newline

    int found = 0;
    for (int i = 0; i < songCount; i++) {
        if (strcmp(musicLibrary[i].title, searchTitle) == 0) {
            printf("Found: '%s' by %s (%d)\n", musicLibrary[i].title, musicLibrary[i].artist, musicLibrary[i].year);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Song not found in the library.\n");
    }
}

void deleteSong() {
    char deleteTitle[TITLE_LEN];
    printf("Enter song title to delete: ");
    getchar(); // To consume newline left by previous input
    fgets(deleteTitle, TITLE_LEN, stdin);
    deleteTitle[strcspn(deleteTitle, "\n")] = 0; // Remove newline

    int i, found = 0;
    for (i = 0; i < songCount; i++) {
        if (strcmp(musicLibrary[i].title, deleteTitle) == 0) {
            found = 1;
            break;
        }
    }

    if (found) {
        for (int j = i; j < songCount - 1; j++) {
            musicLibrary[j] = musicLibrary[j + 1];
        }
        songCount--;
        printf("Song '%s' deleted successfully!\n", deleteTitle);
    } else {
        printf("Song not found in the library.\n");
    }
}