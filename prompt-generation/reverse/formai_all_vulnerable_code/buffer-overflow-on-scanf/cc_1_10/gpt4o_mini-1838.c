//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: creative
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

void initializeLibrary(MusicLibrary *library) {
    library->count = 0;
}

void addSong(MusicLibrary *library) {
    if (library->count >= MAX_SONGS) {
        printf("Library is full! Cannot add more songs.\n");
        return;
    }
    
    Song new_song;
    printf("Enter song title: ");
    scanf(" %[^\n]%*c", new_song.title);
    printf("Enter artist name: ");
    scanf(" %[^\n]%*c", new_song.artist);
   
    library->songs[library->count++] = new_song;
    printf("Song added successfully!\n");
}

void displaySongs(const MusicLibrary *library) {
    if (library->count == 0) {
        printf("No songs in the library.\n");
        return;
    }

    printf("Music Library:\n");
    for (int i = 0; i < library->count; i++) {
        printf("%d. Title: %s, Artist: %s\n", i + 1, library->songs[i].title, library->songs[i].artist);
    }
}

void deleteSong(MusicLibrary *library) {
    if (library->count == 0) {
        printf("No songs in the library to delete.\n");
        return;
    }

    int index;
    printf("Enter the index of the song to delete (1-%d): ", library->count);
    scanf("%d", &index);

    if (index < 1 || index > library->count) {
        printf("Invalid index!\n");
        return;
    }

    for (int i = index - 1; i < library->count - 1; i++) {
        library->songs[i] = library->songs[i + 1];
    }
    library->count--;
    printf("Song deleted successfully!\n");
}

void menu() {
    printf("\n--- Music Library Management System ---\n");
    printf("1. Add Song\n");
    printf("2. Display Songs\n");
    printf("3. Delete Song\n");
    printf("4. Exit\n");
    printf("Choose an option (1-4): ");
}

int main() {
    MusicLibrary library;
    initializeLibrary(&library);
    
    int choice;
    do {
        menu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addSong(&library);
                break;
            case 2:
                displaySongs(&library);
                break;
            case 3:
                deleteSong(&library);
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}