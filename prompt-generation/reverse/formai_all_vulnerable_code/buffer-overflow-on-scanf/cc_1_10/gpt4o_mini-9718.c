//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: Claude Shannon
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

// Function to initialize the music library
void initializeLibrary(MusicLibrary *library) {
    library->count = 0;
}

// Function to add a song to the library
void addSong(MusicLibrary *library) {
    if (library->count >= MAX_SONGS) {
        printf("Music Library is full! Cannot add more songs.\n");
        return;
    }
    
    Song newSong;
    printf("Enter song title: ");
    getchar(); // Clear newline from previous input
    fgets(newSong.title, TITLE_LENGTH, stdin);
    newSong.title[strcspn(newSong.title, "\n")] = 0; // Remove newline character
    
    printf("Enter artist name: ");
    fgets(newSong.artist, ARTIST_LENGTH, stdin);
    newSong.artist[strcspn(newSong.artist, "\n")] = 0; // Remove newline character
    
    library->songs[library->count++] = newSong;
    printf("Song added successfully!\n");
}

// Function to display all songs in the library
void displaySongs(MusicLibrary *library) {
    if (library->count == 0) {
        printf("No songs in the library.\n");
        return;
    }
    
    printf("\nMusic Library:\n");
    for (int i = 0; i < library->count; i++) {
        printf("%d. %s by %s\n", i + 1, library->songs[i].title, library->songs[i].artist);
    }
}

// Function to delete a song from the library
void deleteSong(MusicLibrary *library) {
    if (library->count == 0) {
        printf("No songs to delete.\n");
        return;
    }
    
    displaySongs(library);
    int index;
    printf("Enter the song number to delete: ");
    scanf("%d", &index);

    if (index < 1 || index > library->count) {
        printf("Invalid song number!\n");
        return;
    }

    for (int i = index - 1; i < library->count - 1; i++) {
        library->songs[i] = library->songs[i + 1];
    }
    library->count--;
    printf("Song deleted successfully!\n");
}

// Function to display the menu
void displayMenu() {
    printf("\nMusic Library Management System\n");
    printf("1. Add Song\n");
    printf("2. Display Songs\n");
    printf("3. Delete Song\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
}

int main() {
    MusicLibrary library;
    initializeLibrary(&library);

    int choice;
    while (1) {
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
                deleteSong(&library);
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}