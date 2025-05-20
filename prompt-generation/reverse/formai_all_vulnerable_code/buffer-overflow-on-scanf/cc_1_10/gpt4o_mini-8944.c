//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONGS 100
#define MAX_LENGTH 100

typedef struct {
    char title[MAX_LENGTH];
    char artist[MAX_LENGTH];
    int year;
} Song;

typedef struct {
    Song songs[MAX_SONGS];
    int count;
} MusicLibrary;

// Function Declarations
void addSong(MusicLibrary *library);
void displaySongs(const MusicLibrary *library);
void deleteSong(MusicLibrary *library);
void displayMenu();
void clearInputBuffer();

int main() {
    MusicLibrary library = { .count = 0 };
    int choice;

    do {
        displayMenu();
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            clearInputBuffer();
            choice = 0; // reset choice to allow for menu display
        } else {
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
                    printf("Invalid choice! Please select a valid option.\n");
            }
        }
    } while (choice != 4);
    
    return 0;
}

void addSong(MusicLibrary *library) {
    if (library->count >= MAX_SONGS) {
        printf("Library is full! Cannot add more songs.\n");
        return;
    }
    
    Song newSong;
    printf("Enter song title: ");
    clearInputBuffer(); // clear buffer before reading strings
    fgets(newSong.title, MAX_LENGTH, stdin);
    newSong.title[strcspn(newSong.title, "\n")] = 0; // remove trailing newline
    
    printf("Enter artist: ");
    fgets(newSong.artist, MAX_LENGTH, stdin);
    newSong.artist[strcspn(newSong.artist, "\n")] = 0; // remove trailing newline
    
    printf("Enter year of release: ");
    scanf("%d", &newSong.year);
    
    library->songs[library->count] = newSong;
    library->count++;
    printf("Song added successfully!\n");
}

void displaySongs(const MusicLibrary *library) {
    if (library->count == 0) {
        printf("No songs in the library.\n");
        return;
    }
    
    printf("\nSongs in the Library:\n");
    for (int i = 0; i < library->count; i++) {
        printf("%d. [%d] %s by %s\n", i + 1, library->songs[i].year, library->songs[i].title, library->songs[i].artist);
    }
    printf("\n");
}

void deleteSong(MusicLibrary *library) {
    if (library->count == 0) {
        printf("No songs to delete!\n");
        return;
    }
    
    int index;
    displaySongs(library);
    printf("Select the song number to delete: ");
    scanf("%d", &index);
    
    if (index < 1 || index > library->count) {
        printf("Invalid song number!\n");
        return;
    }
    
    for (int i = index - 1; i < library->count - 1; i++) {
        library->songs[i] = library->songs[i + 1]; // shift songs left
    }
    
    library->count--;
    printf("Song deleted successfully!\n");
}

void displayMenu() {
    printf("\n=== Music Library Management System ===\n");
    printf("1. Add Song\n");
    printf("2. Display Songs\n");
    printf("3. Delete Song\n");
    printf("4. Exit\n");
}

void clearInputBuffer() {
    while (getchar() != '\n'); // clear input buffer
}