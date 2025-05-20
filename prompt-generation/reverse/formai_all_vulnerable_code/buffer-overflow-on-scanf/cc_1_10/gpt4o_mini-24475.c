//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONGS 100
#define TITLE_LENGTH 100
#define ARTIST_LENGTH 100

typedef struct {
    char title[TITLE_LENGTH];
    char artist[ARTIST_LENGTH];
} Song;

typedef struct {
    Song songs[MAX_SONGS];
    int count;
} MusicLibrary;

void addSong(MusicLibrary *library) {
    if (library->count >= MAX_SONGS) {
        printf("Library is full! Cannot add more songs.\n");
        return;
    }

    Song newSong;
    printf("Enter song title: ");
    getchar();  // to clear the newline from the buffer
    fgets(newSong.title, TITLE_LENGTH, stdin);
    newSong.title[strcspn(newSong.title, "\n")] = 0;  // remove newline

    printf("Enter song artist: ");
    fgets(newSong.artist, ARTIST_LENGTH, stdin);
    newSong.artist[strcspn(newSong.artist, "\n")] = 0;  // remove newline

    library->songs[library->count] = newSong;
    library->count++;
    printf("Song added: %s by %s\n", newSong.title, newSong.artist);
}

void viewSongs(MusicLibrary *library) {
    if (library->count == 0) {
        printf("Your music library is empty!\n");
        return;
    }

    printf("\n--- Music Library ---\n");
    for (int i = 0; i < library->count; i++) {
        printf("%d. %s by %s\n", i + 1, library->songs[i].title, library->songs[i].artist);
    }
    printf("---------------------\n");
}

void deleteSong(MusicLibrary *library) {
    if (library->count == 0) {
        printf("Your music library is empty! Nothing to delete.\n");
        return;
    }

    int songIndex;
    printf("Enter the number of the song to delete: ");
    scanf("%d", &songIndex);
    
    if (songIndex < 1 || songIndex > library->count) {
        printf("Invalid song number!\n");
        return;
    }

    for (int i = songIndex - 1; i < library->count - 1; i++) {
        library->songs[i] = library->songs[i + 1];
    }
    library->count--;
    printf("Song number %d deleted successfully!\n", songIndex);
}

void searchSong(MusicLibrary *library) {
    char searchTitle[TITLE_LENGTH];
    printf("Enter song title to search: ");
    getchar();  // to clear the newline from the buffer
    fgets(searchTitle, TITLE_LENGTH, stdin);
    searchTitle[strcspn(searchTitle, "\n")] = 0;  // remove newline

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
    printf("\n--- Music Library Management System ---\n");
    printf("1. Add Song\n");
    printf("2. View Songs\n");
    printf("3. Delete Song\n");
    printf("4. Search Song\n");
    printf("5. Exit\n");
}

int main() {
    MusicLibrary library;
    library.count = 0;

    int choice;
    do {
        showMenu();
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
                deleteSong(&library);
                break;
            case 4:
                searchSong(&library);
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}