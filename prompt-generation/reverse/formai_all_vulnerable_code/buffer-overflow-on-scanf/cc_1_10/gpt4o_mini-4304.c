//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: Donald Knuth
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

// Function prototypes
void initializeLibrary(MusicLibrary *library);
void addSong(MusicLibrary *library);
void viewSongs(const MusicLibrary *library);
void searchSong(const MusicLibrary *library);
void deleteSong(MusicLibrary *library);
void displayMenu();

int main(void) {
    MusicLibrary library;
    initializeLibrary(&library);
    
    int choice;
    do {
        displayMenu();
        printf("Select an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: addSong(&library); break;
            case 2: viewSongs(&library); break;
            case 3: searchSong(&library); break;
            case 4: deleteSong(&library); break;
            case 5: printf("Exiting the program.\n"); break;
            default: printf("Invalid choice, please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

void initializeLibrary(MusicLibrary *library) {
    library->count = 0;
}

void addSong(MusicLibrary *library) {
    if (library->count >= MAX_SONGS) {
        printf("Library is full! Can't add more songs.\n");
        return;
    }
    
    Song newSong;
    printf("Enter song title: ");
    getchar(); // To clear the buffer
    fgets(newSong.title, TITLE_LENGTH, stdin);
    newSong.title[strcspn(newSong.title, "\n")] = 0; // Remove newline character
    
    printf("Enter artist name: ");
    fgets(newSong.artist, ARTIST_LENGTH, stdin);
    newSong.artist[strcspn(newSong.artist, "\n")] = 0; // Remove newline character
    
    library->songs[library->count++] = newSong;
    printf("Song added successfully.\n");
}

void viewSongs(const MusicLibrary *library) {
    if (library->count == 0) {
        printf("No songs in the library.\n");
        return;
    }

    printf("Songs in the Music Library:\n");
    for (int i = 0; i < library->count; i++) {
        printf("%d. %s by %s\n", i + 1, library->songs[i].title, library->songs[i].artist);
    }
}

void searchSong(const MusicLibrary *library) {
    char searchTitle[TITLE_LENGTH];
    printf("Enter song title to search: ");
    getchar(); // To clear the buffer
    fgets(searchTitle, TITLE_LENGTH, stdin);
    searchTitle[strcspn(searchTitle, "\n")] = 0; // Remove newline character

    for (int i = 0; i < library->count; i++) {
        if (strcasecmp(library->songs[i].title, searchTitle) == 0) {
            printf("Found: %s by %s\n", library->songs[i].title, library->songs[i].artist);
            return;
        }
    }
    
    printf("Song not found in the library.\n");
}

void deleteSong(MusicLibrary *library) {
    if (library->count == 0) {
        printf("No songs to delete.\n");
        return;
    }

    viewSongs(library);
    int index;
    printf("Enter the number of the song to delete: ");
    scanf("%d", &index);

    if (index < 1 || index > library->count) {
        printf("Invalid selection.\n");
        return;
    }

    for (int i = index - 1; i < library->count - 1; i++) {
        library->songs[i] = library->songs[i + 1];
    }
    
    library->count--;
    printf("Song deleted successfully.\n");
}

void displayMenu() {
    printf("\n----- Music Library Menu -----\n");
    printf("1. Add a Song\n");
    printf("2. View Songs\n");
    printf("3. Search for a Song\n");
    printf("4. Delete a Song\n");
    printf("5. Exit\n");
}