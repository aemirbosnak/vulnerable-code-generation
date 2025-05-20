//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MUSIC 100
#define TITLE_LENGTH 100
#define ARTIST_LENGTH 100

typedef struct {
    char title[TITLE_LENGTH];
    char artist[ARTIST_LENGTH];
    int year;
    char genre[TITLE_LENGTH];
} Music;

typedef struct {
    Music collection[MAX_MUSIC];
    int count;
} MusicLibrary;

void initializeLibrary(MusicLibrary *library) {
    library->count = 0;
}

void addMusic(MusicLibrary *library) {
    if (library->count >= MAX_MUSIC) {
        printf("Music library is full!\n");
        return;
    }

    Music newMusic;
    
    printf("Enter Music Title: ");
    fgets(newMusic.title, TITLE_LENGTH, stdin);
    newMusic.title[strcspn(newMusic.title, "\n")] = 0; // Remove newline

    printf("Enter Artist Name: ");
    fgets(newMusic.artist, ARTIST_LENGTH, stdin);
    newMusic.artist[strcspn(newMusic.artist, "\n")] = 0;

    printf("Enter Year of Release: ");
    scanf("%d", &newMusic.year);
    getchar(); // Clear newline from input buffer

    printf("Enter Genre: ");
    fgets(newMusic.genre, TITLE_LENGTH, stdin);
    newMusic.genre[strcspn(newMusic.genre, "\n")] = 0;

    library->collection[library->count++] = newMusic;

    printf("Music added successfully!\n");
}

void displayAllMusic(const MusicLibrary *library) {
    if (library->count == 0) {
        printf("No music in the library.\n");
        return;
    }

    printf("\nMusic Library:\n");
    for (int i = 0; i < library->count; i++) {
        printf("%d. [%d] %s by %s - Genre: %s\n",
               i + 1,
               library->collection[i].year,
               library->collection[i].title,
               library->collection[i].artist,
               library->collection[i].genre);
    }
}

void searchMusicByArtist(const MusicLibrary *library) {
    char artist[ARTIST_LENGTH];
    int found = 0;

    printf("Enter artist name to search: ");
    fgets(artist, ARTIST_LENGTH, stdin);
    artist[strcspn(artist, "\n")] = 0; // Remove newline

    printf("Search Results:\n");
    for (int i = 0; i < library->count; i++) {
        if (strcasecmp(library->collection[i].artist, artist) == 0) {
            printf("%d. [%d] %s - Genre: %s\n",
                   i + 1,
                   library->collection[i].year,
                   library->collection[i].title,
                   library->collection[i].genre);
            found = 1;
        }
    }
    if (!found) {
        printf("No music found for artist: %s\n", artist);
    }
}

void removeMusic(MusicLibrary *library) {
    int index;

    printf("Enter the index of the music to remove (1 to %d): ", library->count);
    scanf("%d", &index);
    getchar(); // Clear newline from input buffer

    if (index < 1 || index > library->count) {
        printf("Invalid index!\n");
        return;
    }

    for (int i = index - 1; i < library->count - 1; i++) {
        library->collection[i] = library->collection[i + 1];
    }
    library->count--;

    printf("Music removed successfully!\n");
}

int main() {
    MusicLibrary library;
    initializeLibrary(&library);
    
    int choice;

    while (1) {
        printf("\n--- Music Library Management System ---\n");
        printf("1. Add Music\n");
        printf("2. Display All Music\n");
        printf("3. Search Music by Artist\n");
        printf("4. Remove Music\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear newline from input buffer

        switch (choice) {
            case 1:
                addMusic(&library);
                break;
            case 2:
                displayAllMusic(&library);
                break;
            case 3:
                searchMusicByArtist(&library);
                break;
            case 4:
                removeMusic(&library);
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}