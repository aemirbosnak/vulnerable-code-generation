//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: peaceful
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

void initLibrary(MusicLibrary *library) {
    library->count = 0;
}

void addSong(MusicLibrary *library) {
    if (library->count >= MAX_SONGS) {
        printf("Library is full, cannot add more songs.\n");
        return;
    }
    
    Song newSong;
    
    printf("Enter song title: ");
    getchar(); // to consume newline left by previous input
    fgets(newSong.title, sizeof(newSong.title), stdin);
    newSong.title[strcspn(newSong.title, "\n")] = 0; // Remove newline
    
    printf("Enter artist name: ");
    fgets(newSong.artist, sizeof(newSong.artist), stdin);
    newSong.artist[strcspn(newSong.artist, "\n")] = 0; // Remove newline

    library->songs[library->count++] = newSong;
    printf("Song added successfully!\n");
}

void displayLibrary(const MusicLibrary *library) {
    printf("\nMusic Library:\n");
    for (int i = 0; i < library->count; i++) {
        printf("%d. %s by %s\n", i + 1, library->songs[i].title, library->songs[i].artist);
    }
    printf("\n");
}

void searchSong(const MusicLibrary *library) {
    char searchTitle[MAX_TITLE_LENGTH];
    printf("Enter the title of the song to search: ");
    getchar(); // to consume newline left by previous input
    fgets(searchTitle, sizeof(searchTitle), stdin);
    searchTitle[strcspn(searchTitle, "\n")] = 0; // Remove newline

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

void showMenu() {
    printf("---------- Music Library Management System ----------\n");
    printf("1. Add Song\n");
    printf("2. Display Library\n");
    printf("3. Search for Song\n");
    printf("4. Exit\n");
    printf("----------------------------------------------------\n");
}

int main() {
    MusicLibrary myLibrary;
    initLibrary(&myLibrary);

    int choice;

    do {
        showMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addSong(&myLibrary);
                break;
            case 2:
                displayLibrary(&myLibrary);
                break;
            case 3:
                searchSong(&myLibrary);
                break;
            case 4:
                printf("Exiting the Music Library. Peaceful melodies await!\n");
                break;
            default:
                printf("Invalid choice! Please select again.\n");
        }
    } while (choice != 4);

    return 0;
}