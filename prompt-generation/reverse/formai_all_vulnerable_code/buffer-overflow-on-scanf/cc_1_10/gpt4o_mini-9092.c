//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONGS 100
#define MAX_TITLE_LEN 100
#define MAX_ARTIST_LEN 100

typedef struct {
    char title[MAX_TITLE_LEN];
    char artist[MAX_ARTIST_LEN];
    int year;
} Song;

typedef struct {
    Song songs[MAX_SONGS];
    int count;
} MusicLibrary;

void addSong(MusicLibrary *library) {
    if (library->count >= MAX_SONGS) {
        printf("Library is full, cannot add more songs.\n");
        return;
    }
    
    Song newSong;
    printf("Enter song title: ");
    getchar(); // to consume the newline character from previous input
    fgets(newSong.title, MAX_TITLE_LEN, stdin);
    newSong.title[strcspn(newSong.title, "\n")] = 0; // remove newline

    printf("Enter artist name: ");
    fgets(newSong.artist, MAX_ARTIST_LEN, stdin);
    newSong.artist[strcspn(newSong.artist, "\n")] = 0; // remove newline

    printf("Enter year of release: ");
    scanf("%d", &newSong.year);

    library->songs[library->count++] = newSong;
    printf("Song added successfully!\n");
}

void viewSongs(const MusicLibrary *library) {
    if (library->count == 0) {
        printf("No songs in the library.\n");
        return;
    }
    printf("\n--- Music Library ---\n");
    for (int i = 0; i < library->count; i++) {
        printf("%d. '%s' by %s (%d)\n", i + 1, library->songs[i].title, library->songs[i].artist, library->songs[i].year);
    }
    printf("---------------------\n");
}

void deleteSong(MusicLibrary *library) {
    if (library->count == 0) {
        printf("No songs to delete.\n");
        return;
    }

    viewSongs(library);
    int index;
    printf("Enter the song number to delete: ");
    scanf("%d", &index);
    index--; // Convert to zero-based index

    if (index < 0 || index >= library->count) {
        printf("Invalid song number.\n");
        return;
    }

    for (int i = index; i < library->count - 1; i++) {
        library->songs[i] = library->songs[i + 1];
    }
    library->count--;
    printf("Song deleted successfully!\n");
}

void searchSong(const MusicLibrary *library) {
    char searchTerm[MAX_TITLE_LEN];
    printf("Enter song title or artist to search: ");
    getchar(); // to consume the newline
    fgets(searchTerm, MAX_TITLE_LEN, stdin);
    searchTerm[strcspn(searchTerm, "\n")] = 0; // remove newline

    printf("\n--- Search Results ---\n");
    int found = 0;
    for (int i = 0; i < library->count; i++) {
        if (strstr(library->songs[i].title, searchTerm) != NULL || strstr(library->songs[i].artist, searchTerm) != NULL) {
            printf("%d. '%s' by %s (%d)\n", i + 1, library->songs[i].title, library->songs[i].artist, library->songs[i].year);
            found = 1;
        }
    }
    if (!found) {
        printf("No songs found matching the search term.\n");
    }
    printf("---------------------\n");
}

void displayMenu() {
    printf("----- Music Library Menu -----\n");
    printf("1. Add Song\n");
    printf("2. View Songs\n");
    printf("3. Delete Song\n");
    printf("4. Search Song\n");
    printf("5. Exit\n");
    printf("Select an option: ");
}

int main() {
    MusicLibrary library = { .count = 0 };
    int choice;

    do {
        displayMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1: addSong(&library); break;
            case 2: viewSongs(&library); break;
            case 3: deleteSong(&library); break;
            case 4: searchSong(&library); break;
            case 5: printf("Exiting the program...\n"); break;
            default: printf("Invalid option! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}