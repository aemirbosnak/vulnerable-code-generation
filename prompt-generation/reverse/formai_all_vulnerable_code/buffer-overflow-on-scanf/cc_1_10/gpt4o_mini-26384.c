//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ALBUMS 100
#define MAX_TITLE_LENGTH 100
#define MAX_ARTIST_LENGTH 100

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char artist[MAX_ARTIST_LENGTH];
    int year;
} Album;

Album musicLibrary[MAX_ALBUMS];
int albumCount = 0;

void clearBuffer(void) {
    while (getchar() != '\n');
}

void addAlbum() {
    if (albumCount >= MAX_ALBUMS) {
        printf("Music library is full!\n");
        return;
    }
    Album newAlbum;
    
    printf("Enter album title: ");
    if (fgets(newAlbum.title, sizeof(newAlbum.title), stdin) == NULL) {
        printf("Invalid input.\n");
        clearBuffer();
        return;
    }
    newAlbum.title[strcspn(newAlbum.title, "\n")] = 0; // Remove newline character

    printf("Enter artist name: ");
    if (fgets(newAlbum.artist, sizeof(newAlbum.artist), stdin) == NULL) {
        printf("Invalid input.\n");
        clearBuffer();
        return;
    }
    newAlbum.artist[strcspn(newAlbum.artist, "\n")] = 0; // Remove newline character

    printf("Enter release year: ");
    if (scanf("%d", &newAlbum.year) != 1) {
        printf("Invalid year input.\n");
        clearBuffer();
        return;
    }
    clearBuffer(); // Clear newline character from input buffer

    musicLibrary[albumCount++] = newAlbum;
    printf("Album added successfully!\n");
}

void viewAlbums() {
    if (albumCount == 0) {
        printf("No albums in library.\n");
        return;
    }
    printf("\n--- Music Library ---\n");
    for (int i = 0; i < albumCount; i++) {
        printf("Album %d:\n", i + 1);
        printf("Title: %s\n", musicLibrary[i].title);
        printf("Artist: %s\n", musicLibrary[i].artist);
        printf("Year: %d\n\n", musicLibrary[i].year);
    }
}

void deleteAlbum() {
    if (albumCount == 0) {
        printf("No albums to delete.\n");
        return;
    }
    int index;
    printf("Enter the album number to delete (1-%d): ", albumCount);
    if (scanf("%d", &index) != 1 || index < 1 || index > albumCount) {
        printf("Invalid album number.\n");
        clearBuffer();
        return;
    }
    clearBuffer(); // Clear newline character from input buffer
    index--; // Adjust for 0-based index
    for (int i = index; i < albumCount - 1; i++) {
        musicLibrary[i] = musicLibrary[i + 1];
    }
    albumCount--;
    printf("Album deleted successfully!\n");
}

int main() {
    int choice;
    while (1) {
        printf("\n--- Music Library Management System ---\n");
        printf("1. Add Album\n");
        printf("2. View Albums\n");
        printf("3. Delete Album\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            clearBuffer();
            continue;
        }
        clearBuffer(); // Clear newline character from input buffer

        switch (choice) {
            case 1:
                addAlbum();
                break;
            case 2:
                viewAlbums();
                break;
            case 3:
                deleteAlbum();
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}