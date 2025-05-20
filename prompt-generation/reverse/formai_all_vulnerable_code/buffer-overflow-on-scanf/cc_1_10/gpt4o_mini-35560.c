//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: careful
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

void initLibrary(MusicLibrary *library) {
    library->count = 0;
}

void addSong(MusicLibrary *library) {
    if (library->count >= MAX_SONGS) {
        printf("Library is full! Cannot add more songs.\n");
        return;
    }
    Song newSong;
    printf("Enter song title: ");
    getchar(); // To clear the newline character from previous input
    fgets(newSong.title, MAX_TITLE, stdin);
    newSong.title[strcspn(newSong.title, "\n")] = 0; // Remove newline character
    
    printf("Enter artist: ");
    fgets(newSong.artist, MAX_ARTIST, stdin);
    newSong.artist[strcspn(newSong.artist, "\n")] = 0; // Remove newline character

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
        printf("%d. Title: %s | Artist: %s | Year: %d\n", 
               i + 1, library->songs[i].title, library->songs[i].artist, library->songs[i].year);
    }
}

void searchSong(const MusicLibrary *library) {
    char searchTitle[MAX_TITLE];
    printf("Enter song title to search: ");
    getchar(); // To clear the newline character from previous input
    fgets(searchTitle, MAX_TITLE, stdin);
    searchTitle[strcspn(searchTitle, "\n")] = 0; // Remove newline character

    int found = 0;
    for (int i = 0; i < library->count; i++) {
        if (strcasecmp(library->songs[i].title, searchTitle) == 0) {
            printf("Found: Title: %s | Artist: %s | Year: %d\n", 
                   library->songs[i].title, library->songs[i].artist, library->songs[i].year);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Song not found in the library.\n");
    }
}

int main() {
    MusicLibrary library;
    initLibrary(&library);
    int choice;

    do {
        printf("\n--- Music Library Management System ---\n");
        printf("1. Add Song\n");
        printf("2. View Songs\n");
        printf("3. Search Song\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

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
                printf("Exiting the system. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}