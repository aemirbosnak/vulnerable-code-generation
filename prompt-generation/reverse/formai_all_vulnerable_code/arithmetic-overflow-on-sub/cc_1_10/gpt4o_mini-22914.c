//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Song {
    char title[100];
    char artist[100];
    char genre[50];
    int year;
} Song;

typedef struct MusicLibrary {
    Song *songs;
    int count;
    int capacity;
} MusicLibrary;

void initializeLibrary(MusicLibrary *library) {
    library->count = 0;
    library->capacity = 2; // Start with initial capacity
    library->songs = (Song *)malloc(library->capacity * sizeof(Song));
    if (!library->songs) {
        perror("Failed to allocate memory for songs");
        exit(EXIT_FAILURE);
    }
}

void freeLibrary(MusicLibrary *library) {
    free(library->songs);
}

void addSong(MusicLibrary *library, const char *title, const char *artist, const char *genre, int year) {
    if (library->count == library->capacity) {
        library->capacity *= 2; // Double the capacity
        library->songs = (Song *)realloc(library->songs, library->capacity * sizeof(Song));
        if (!library->songs) {
            perror("Failed to reallocate memory for songs");
            exit(EXIT_FAILURE);
        }
    }
    strcpy(library->songs[library->count].title, title);
    strcpy(library->songs[library->count].artist, artist);
    strcpy(library->songs[library->count].genre, genre);
    library->songs[library->count].year = year;
    library->count++;
}

void viewSongs(const MusicLibrary *library) {
    if (library->count == 0) {
        printf("No songs in the library.\n");
        return;
    }
    
    printf("Songs in Library:\n");
    for (int i = 0; i < library->count; i++) {
        printf("%d. Title: %s | Artist: %s | Genre: %s | Year: %d\n", 
            i + 1, library->songs[i].title, library->songs[i].artist, library->songs[i].genre, library->songs[i].year);
    }
}

void deleteSong(MusicLibrary *library, int index) {
    if (index < 0 || index >= library->count) {
        printf("Invalid song index.\n");
        return;
    }
    
    for (int i = index; i < library->count - 1; i++) {
        library->songs[i] = library->songs[i + 1];
    }
    library->count--;    
}

int main() {
    MusicLibrary library;
    initializeLibrary(&library);
    int choice;
    
    while (1) {
        printf("\nMusic Library Management System\n");
        printf("1. Add Song\n");
        printf("2. View Songs\n");
        printf("3. Delete Song\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline character
        
        if (choice == 1) {
            char title[100], artist[100], genre[50];
            int year;
            printf("Enter Song Title: ");
            fgets(title, sizeof(title), stdin);
            title[strcspn(title, "\n")] = '\0'; // Remove newline
            printf("Enter Artist Name: ");
            fgets(artist, sizeof(artist), stdin);
            artist[strcspn(artist, "\n")] = '\0'; // Remove newline
            printf("Enter Genre: ");
            fgets(genre, sizeof(genre), stdin);
            genre[strcspn(genre, "\n")] = '\0'; // Remove newline
            printf("Enter Year: ");
            scanf("%d", &year);
            addSong(&library, title, artist, genre, year);
            printf("Song added successfully!\n");
        } else if (choice == 2) {
            viewSongs(&library);
        } else if (choice == 3) {
            int index;
            printf("Enter the song index to delete: ");
            scanf("%d", &index);
            deleteSong(&library, index - 1); // Adjust for 0-based index
            printf("Song deleted successfully!\n");
        } else if (choice == 4) {
            break;
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }
    
    freeLibrary(&library);
    return 0;
}