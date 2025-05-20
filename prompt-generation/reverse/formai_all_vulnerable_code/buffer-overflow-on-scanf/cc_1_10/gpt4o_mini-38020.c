//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ALBUMS 100
#define TITLE_LENGTH 50
#define ARTIST_LENGTH 50

typedef struct {
    char title[TITLE_LENGTH];
    char artist[ARTIST_LENGTH];
    int year;
} Album;

Album musicLibrary[MAX_ALBUMS];
int albumCount = 0;

void addAlbum() {
    if (albumCount >= MAX_ALBUMS) {
        printf("Music library is full!\n");
        return;
    }
    
    Album newAlbum;
    printf("Enter album title: ");
    getchar(); // Clear newline from input buffer
    fgets(newAlbum.title, TITLE_LENGTH, stdin);
    newAlbum.title[strcspn(newAlbum.title, "\n")] = '\0'; // Remove newline
    
    printf("Enter artist name: ");
    fgets(newAlbum.artist, ARTIST_LENGTH, stdin);
    newAlbum.artist[strcspn(newAlbum.artist, "\n")] = '\0'; // Remove newline
    
    printf("Enter release year: ");
    scanf("%d", &newAlbum.year);
    
    musicLibrary[albumCount++] = newAlbum;
    printf("Album added successfully!\n");
}

void viewAlbums() {
    if (albumCount == 0) {
        printf("No albums in the library!\n");
        return;
    }
    
    printf("\n--- Music Library ---\n");
    for (int i = 0; i < albumCount; i++) {
        printf("Album %d: %s by %s (%d)\n", 
               i + 1, musicLibrary[i].title, musicLibrary[i].artist, musicLibrary[i].year);
    }
    printf("---------------------\n");
}

void updateAlbum() {
    int index;
    printf("Enter the album number to update: ");
    scanf("%d", &index);
    if (index < 1 || index > albumCount) {
        printf("Invalid album number.\n");
        return;
    }

    index--; // To convert to zero-based index
    Album updatedAlbum = musicLibrary[index];

    printf("Updating album: %s by %s (%d)\n", updatedAlbum.title, updatedAlbum.artist, updatedAlbum.year);
    
    // Update title
    printf("Enter new title (leave blank to keep current): ");
    getchar(); // Clear newline from input buffer
    char newTitle[TITLE_LENGTH];
    fgets(newTitle, TITLE_LENGTH, stdin);
    if (strcmp(newTitle, "\n") != 0) {
        newTitle[strcspn(newTitle, "\n")] = '\0'; // Remove newline
        strcpy(updatedAlbum.title, newTitle);
    }

    // Update artist
    printf("Enter new artist (leave blank to keep current): ");
    char newArtist[ARTIST_LENGTH];
    fgets(newArtist, ARTIST_LENGTH, stdin);
    if (strcmp(newArtist, "\n") != 0) {
        newArtist[strcspn(newArtist, "\n")] = '\0'; // Remove newline
        strcpy(updatedAlbum.artist, newArtist);
    }

    // Update year
    printf("Enter new release year (0 to keep current): ");
    int newYear;
    scanf("%d", &newYear);
    if (newYear != 0) {
        updatedAlbum.year = newYear;
    }

    musicLibrary[index] = updatedAlbum;
    printf("Album updated successfully!\n");
}

void deleteAlbum() {
    int index;
    printf("Enter the album number to delete: ");
    scanf("%d", &index);
    if (index < 1 || index > albumCount) {
        printf("Invalid album number.\n");
        return;
    }

    index--; // To convert to zero-based index
    for (int i = index; i < albumCount - 1; i++) {
        musicLibrary[i] = musicLibrary[i + 1];
    }
    albumCount--;
    printf("Album deleted successfully!\n");
}

void displayMenu() {
    printf("\n--- Music Library Management System ---\n");
    printf("1. Add Album\n");
    printf("2. View Albums\n");
    printf("3. Update Album\n");
    printf("4. Delete Album\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
}

int main() {
    int choice;
    while (1) {
        displayMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addAlbum();
                break;
            case 2:
                viewAlbums();
                break;
            case 3:
                updateAlbum();
                break;
            case 4:
                deleteAlbum();
                break;
            case 5:
                printf("Exiting the program...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}