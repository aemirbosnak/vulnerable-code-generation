//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: introspective
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

Song musicLibrary[MAX_SONGS];
int songCount = 0;

// Function declarations
void displayMenu();
void addSong();
void viewSongs();
void editSong();
void deleteSong();
void clearInputBuffer();

int main() {
    int choice;
    while (1) {
        displayMenu();
        scanf("%d", &choice);
        clearInputBuffer();
        
        switch (choice) {
            case 1:
                addSong();
                break;
            case 2:
                viewSongs();
                break;
            case 3:
                editSong();
                break;
            case 4:
                deleteSong();
                break;
            case 5:
                printf("Exiting the Music Library Management System. Thank you!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

void displayMenu() {
    printf("\n--- Music Library Management System ---\n");
    printf("1. Add Song\n");
    printf("2. View Songs\n");
    printf("3. Edit Song\n");
    printf("4. Delete Song\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
}

void addSong() {
    if (songCount >= MAX_SONGS) {
        printf("Library is full! Cannot add more songs.\n");
        return;
    }
    
    printf("Enter song title: ");
    fgets(musicLibrary[songCount].title, TITLE_LENGTH, stdin);
    musicLibrary[songCount].title[strcspn(musicLibrary[songCount].title, "\n")] = 0; // Remove trailing newline
    
    printf("Enter artist name: ");
    fgets(musicLibrary[songCount].artist, ARTIST_LENGTH, stdin);
    musicLibrary[songCount].artist[strcspn(musicLibrary[songCount].artist, "\n")] = 0; // Remove trailing newline
    
    songCount++;
    printf("Song added successfully!\n");
}

void viewSongs() {
    if (songCount == 0) {
        printf("No songs in the library.\n");
        return;
    }
    
    printf("\n--- List of Songs ---\n");
    for (int i = 0; i < songCount; i++) {
        printf("%d. %s by %s\n", i + 1, musicLibrary[i].title, musicLibrary[i].artist);
    }
}

void editSong() {
    if (songCount == 0) {
        printf("No songs to edit.\n");
        return;
    }
    
    viewSongs();

    int songIndex;
    printf("Enter the number of the song you want to edit: ");
    scanf("%d", &songIndex);
    clearInputBuffer();

    if (songIndex < 1 || songIndex > songCount) {
        printf("Invalid song number.\n");
        return;
    }
    
    songIndex--; // Adjust for 0-based index
    printf("Editing song: %s by %s\n", musicLibrary[songIndex].title, musicLibrary[songIndex].artist);
    
    printf("Enter new title (or press ENTER to keep the same): ");
    char newTitle[TITLE_LENGTH];
    fgets(newTitle, TITLE_LENGTH, stdin);
    if (strcmp(newTitle, "\n") != 0) {
        newTitle[strcspn(newTitle, "\n")] = 0; // Remove trailing newline
        strcpy(musicLibrary[songIndex].title, newTitle);
    }
    
    printf("Enter new artist name (or press ENTER to keep the same): ");
    char newArtist[ARTIST_LENGTH];
    fgets(newArtist, ARTIST_LENGTH, stdin);
    if (strcmp(newArtist, "\n") != 0) {
        newArtist[strcspn(newArtist, "\n")] = 0; // Remove trailing newline
        strcpy(musicLibrary[songIndex].artist, newArtist);
    }
    
    printf("Song edited successfully!\n");
}

void deleteSong() {
    if (songCount == 0) {
        printf("No songs to delete.\n");
        return;
    }
    
    viewSongs();
    
    int songIndex;
    printf("Enter the number of the song you want to delete: ");
    scanf("%d", &songIndex);
    clearInputBuffer();

    if (songIndex < 1 || songIndex > songCount) {
        printf("Invalid song number.\n");
        return;
    }

    songIndex--; // Adjust for 0-based index
    for (int i = songIndex; i < songCount - 1; i++) {
        musicLibrary[i] = musicLibrary[i + 1];
    }
    songCount--;
    printf("Song deleted successfully!\n");
}

void clearInputBuffer() {
    while (getchar() != '\n'); // Clear the input buffer
}