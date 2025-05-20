//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE_LENGTH 100
#define MAX_ARTIST_LENGTH 100
#define INITIAL_CAPACITY 10

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char artist[MAX_ARTIST_LENGTH];
    int duration; // duration in seconds
} Song;

typedef struct {
    Song *songs;
    int size;
    int capacity;
} MusicLibrary;

void initializeLibrary(MusicLibrary *library) {
    library->size = 0;
    library->capacity = INITIAL_CAPACITY;
    library->songs = (Song *)malloc(library->capacity * sizeof(Song));
    if (!library->songs) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
}

void freeLibrary(MusicLibrary *library) {
    free(library->songs);
}

void addSong(MusicLibrary *library, const char *title, const char *artist, int duration) {
    if (library->size >= library->capacity) {
        library->capacity *= 2;
        library->songs = (Song *)realloc(library->songs, library->capacity * sizeof(Song));
        if (!library->songs) {
            fprintf(stderr, "Memory allocation failed\n");
            exit(1);
        }
    }
    strncpy(library->songs[library->size].title, title, MAX_TITLE_LENGTH);
    strncpy(library->songs[library->size].artist, artist, MAX_ARTIST_LENGTH);
    library->songs[library->size].duration = duration;
    library->size++;
}

void displayLibrary(const MusicLibrary *library) {
    if (library->size == 0) {
        printf("No songs available in the library.\n");
        return;
    }
    printf("Music Library:\n");
    for (int i = 0; i < library->size; i++) {
        printf("%d. Title: %s, Artist: %s, Duration: %d seconds\n", 
               i + 1, library->songs[i].title, library->songs[i].artist, library->songs[i].duration);
    }
}

void searchSong(const MusicLibrary *library, const char *title) {
    for (int i = 0; i < library->size; i++) {
        if (strcasecmp(library->songs[i].title, title) == 0) {
            printf("Found: Title: %s, Artist: %s, Duration: %d seconds\n", 
                   library->songs[i].title, library->songs[i].artist, library->songs[i].duration);
            return;
        }
    }
    printf("Song titled '%s' not found in the library.\n", title);
}

void deleteSong(MusicLibrary *library, const char *title) {
    for (int i = 0; i < library->size; i++) {
        if (strcasecmp(library->songs[i].title, title) == 0) {
            for (int j = i; j < library->size - 1; j++) {
                library->songs[j] = library->songs[j + 1];
            }
            library->size--;
            printf("Deleted song titled '%s' from the library.\n", title);
            return;
        }
    }
    printf("Song titled '%s' not found for deletion.\n", title);
}

int main() {
    MusicLibrary library;
    initializeLibrary(&library);

    int choice;
    char title[MAX_TITLE_LENGTH];
    char artist[MAX_ARTIST_LENGTH];
    int duration;

    do {
        printf("\nMusic Library Management System\n");
        printf("1. Add Song\n");
        printf("2. Display Library\n");
        printf("3. Search Song\n");
        printf("4. Delete Song\n");
        printf("5. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);
        getchar(); // to consume newline

        switch (choice) {
            case 1:
                printf("Enter song title: ");
                fgets(title, MAX_TITLE_LENGTH, stdin);
                title[strcspn(title, "\n")] = '\0'; // remove newline
                printf("Enter artist name: ");
                fgets(artist, MAX_ARTIST_LENGTH, stdin);
                artist[strcspn(artist, "\n")] = '\0'; // remove newline
                printf("Enter duration in seconds: ");
                scanf("%d", &duration);
                addSong(&library, title, artist, duration);
                break;
            case 2:
                displayLibrary(&library);
                break;
            case 3:
                printf("Enter song title to search: ");
                fgets(title, MAX_TITLE_LENGTH, stdin);
                title[strcspn(title, "\n")] = '\0'; // remove newline
                searchSong(&library, title);
                break;
            case 4:
                printf("Enter song title to delete: ");
                fgets(title, MAX_TITLE_LENGTH, stdin);
                title[strcspn(title, "\n")] = '\0'; // remove newline
                deleteSong(&library, title);
                break;
            case 5:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while (choice != 5);

    freeLibrary(&library);
    return 0;
}