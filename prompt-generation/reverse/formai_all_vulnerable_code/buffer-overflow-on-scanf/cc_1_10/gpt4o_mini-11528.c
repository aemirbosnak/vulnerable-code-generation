//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: shocked
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
void viewSongs(MusicLibrary library);
void deleteSong(MusicLibrary *library);
void searchSong(MusicLibrary library);
void displayMenu();

int main() {
    MusicLibrary library;
    library.count = 0;
    int choice;

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addSong(&library);
                break;
            case 2:
                viewSongs(library);
                break;
            case 3:
                deleteSong(&library);
                break;
            case 4:
                searchSong(library);
                break;
            case 0:
                printf("Exiting... Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}

void displayMenu() {
    printf("✨✨✨ Music Library Management System ✨✨✨\n");
    printf("1. Add Song\n");
    printf("2. View Songs\n");
    printf("3. Delete Song\n");
    printf("4. Search Song\n");
    printf("0. Exit\n");
    printf("**********************************\n");
}

void addSong(MusicLibrary *library) {
    if (library->count >= MAX_SONGS) {
        printf("😱 Oops! Library is full! Can't add more songs.\n");
        return;
    }

    Song newSong;
    printf("Enter song title: ");
    getchar(); // consume the newline character left in the buffer
    fgets(newSong.title, MAX_TITLE_LENGTH, stdin);
    newSong.title[strcspn(newSong.title, "\n")] = 0; // remove newline character

    printf("Enter artist name: ");
    fgets(newSong.artist, MAX_ARTIST_LENGTH, stdin);
    newSong.artist[strcspn(newSong.artist, "\n")] = 0; // remove newline character

    library->songs[library->count] = newSong;
    library->count++;
    printf("🎶 Song added successfully!\n");
}

void viewSongs(MusicLibrary library) {
    if (library.count == 0) {
        printf("😱 No songs in the library yet!\n");
        return;
    }

    printf("🎶 Your Music Library 🎶\n");
    for (int i = 0; i < library.count; i++) {
        printf("%d. %s by %s\n", i + 1, library.songs[i].title, library.songs[i].artist);
    }
}

void deleteSong(MusicLibrary *library) {
    if (library->count == 0) {
        printf("😱 No songs in the library to delete!\n");
        return;
    }

    int index;
    printf("Enter the song number to delete (1-%d): ", library->count);
    scanf("%d", &index);

    if (index < 1 || index > library->count) {
        printf("😱 Invalid song number!\n");
        return;
    }

    for (int i = index - 1; i < library->count - 1; i++) {
        library->songs[i] = library->songs[i + 1];
    }
    library->count--;
    printf("🎶 Song deleted successfully!\n");
}

void searchSong(MusicLibrary library) {
    if (library.count == 0) {
        printf("😱 No songs in the library to search!\n");
        return;
    }

    char query[MAX_TITLE_LENGTH];
    printf("Enter the song title to search: ");
    getchar(); // consume leftover newline
    fgets(query, MAX_TITLE_LENGTH, stdin);
    query[strcspn(query, "\n")] = 0; // remove newline character

    int found = 0;
    printf("🔍 Searching for: %s...\n", query);
    for (int i = 0; i < library.count; i++) {
        if (strstr(library.songs[i].title, query) != NULL) {
            printf("Found: %s by %s\n", library.songs[i].title, library.songs[i].artist);
            found = 1;
        }
    }
    
    if (!found) {
        printf("😱 No matching song found!\n");
    }
}