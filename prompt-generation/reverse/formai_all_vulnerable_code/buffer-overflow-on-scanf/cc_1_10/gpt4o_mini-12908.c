//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONGS 100
#define TITLE_LENGTH 50
#define ARTIST_LENGTH 30

typedef struct {
    char title[TITLE_LENGTH];
    char artist[ARTIST_LENGTH];
    int duration; // Duration in seconds
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
    getchar(); // To consume newline left by previous input
    fgets(newSong.title, TITLE_LENGTH, stdin);
    newSong.title[strcspn(newSong.title, "\n")] = '\0'; // Remove newline

    printf("Enter artist name: ");
    fgets(newSong.artist, ARTIST_LENGTH, stdin);
    newSong.artist[strcspn(newSong.artist, "\n")] = '\0'; // Remove newline

    printf("Enter duration (in seconds): ");
    scanf("%d", &newSong.duration);
    
    library->songs[library->count++] = newSong;
    printf("Song added successfully!\n");
}

void displaySongs(const MusicLibrary* library) {
    if (library->count == 0) {
        printf("No songs in the library.\n");
        return;
    }

    printf("\n--- Music Library ---\n");
    for (int i = 0; i < library->count; ++i) {
        printf("Song %d: %s by %s (Duration: %d seconds)\n",
               i + 1, library->songs[i].title, library->songs[i].artist, library->songs[i].duration);
    }
}

void searchSong(const MusicLibrary* library) {
    char title[TITLE_LENGTH];
    printf("Enter the title of the song to search: ");
    getchar(); // To consume newline left by previous input
    fgets(title, TITLE_LENGTH, stdin);
    title[strcspn(title, "\n")] = '\0'; // Remove newline

    for (int i = 0; i < library->count; ++i) {
        if (strcmp(library->songs[i].title, title) == 0) {
            printf("Found: %s by %s (Duration: %d seconds)\n",
                   library->songs[i].title, library->songs[i].artist, library->songs[i].duration);
            return;
        }
    }
    printf("Song with title '%s' not found.\n", title);
}

void deleteSong(MusicLibrary* library) {
    char title[TITLE_LENGTH];
    printf("Enter the title of the song to delete: ");
    getchar(); // To consume newline left by previous input
    fgets(title, TITLE_LENGTH, stdin);
    title[strcspn(title, "\n")] = '\0'; // Remove newline

    for (int i = 0; i < library->count; ++i) {
        if (strcmp(library->songs[i].title, title) == 0) {
            for (int j = i; j < library->count - 1; ++j) {
                library->songs[j] = library->songs[j + 1];
            }
            library->count--;
            printf("Song '%s' deleted successfully.\n", title);
            return;
        }
    }
    printf("Song with title '%s' not found.\n", title);
}

void displayMenu() {
    printf("\n--- Music Library Management System ---\n");
    printf("1. Add Song\n");
    printf("2. Display Songs\n");
    printf("3. Search Song\n");
    printf("4. Delete Song\n");
    printf("5. Exit\n");
    printf("Select an option: ");
}

int main() {
    MusicLibrary library;
    initializeLibrary(&library);
    int choice;

    do {
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
                deleteSong(&library);
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please select a valid option.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}