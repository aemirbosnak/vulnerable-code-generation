//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: inquisitive
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

void addAlbum();
void viewAlbums();
void searchAlbum();
void deleteAlbum();
void menu();

int main() {
    menu();
    return 0;
}

void menu() {
    int choice;
    do {
        printf("\n=== Music Library Management System ===\n");
        printf("1. Add Album\n");
        printf("2. View Albums\n");
        printf("3. Search Album\n");
        printf("4. Delete Album\n");
        printf("5. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addAlbum();
                break;
            case 2:
                viewAlbums();
                break;
            case 3:
                searchAlbum();
                break;
            case 4:
                deleteAlbum();
                break;
            case 5:
                printf("Exiting the program. Happy listening!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 5);
}

void addAlbum() {
    if (albumCount >= MAX_ALBUMS) {
        printf("Music library is full! Cannot add more albums.\n");
        return;
    }
    
    Album newAlbum;
    
    printf("Enter album title: ");
    getchar(); // to consume newline from previous input
    fgets(newAlbum.title, sizeof(newAlbum.title), stdin);
    newAlbum.title[strcspn(newAlbum.title, "\n")] = 0; // remove newline

    printf("Enter album artist: ");
    fgets(newAlbum.artist, sizeof(newAlbum.artist), stdin);
    newAlbum.artist[strcspn(newAlbum.artist, "\n")] = 0; // remove newline

    printf("Enter album release year: ");
    scanf("%d", &newAlbum.year);

    musicLibrary[albumCount++] = newAlbum;
    printf("Album added successfully!\n");
}

void viewAlbums() {
    if (albumCount == 0) {
        printf("No albums in the music library.\n");
        return;
    }
    
    printf("\n=== List of Albums ===\n");
    for (int i = 0; i < albumCount; i++) {
        printf("Album %d: \"%s\" by %s (%d)\n", i + 1, musicLibrary[i].title, musicLibrary[i].artist, musicLibrary[i].year);
    }
}

void searchAlbum() {
    char searchTitle[MAX_TITLE_LENGTH];
    
    printf("Enter album title to search: ");
    getchar(); // to consume newline
    fgets(searchTitle, sizeof(searchTitle), stdin);
    searchTitle[strcspn(searchTitle, "\n")] = 0; // remove newline

    int found = 0;
    for (int i = 0; i < albumCount; i++) {
        if (strcasecmp(musicLibrary[i].title, searchTitle) == 0) {
            printf("Found Album: \"%s\" by %s (%d)\n", musicLibrary[i].title, musicLibrary[i].artist, musicLibrary[i].year);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Album not found in the library.\n");
    }
}

void deleteAlbum() {
    char deleteTitle[MAX_TITLE_LENGTH];
    
    printf("Enter album title to delete: ");
    getchar(); // to consume newline
    fgets(deleteTitle, sizeof(deleteTitle), stdin);
    deleteTitle[strcspn(deleteTitle, "\n")] = 0; // remove newline

    int found = 0;
    for (int i = 0; i < albumCount; i++) {
        if (strcasecmp(musicLibrary[i].title, deleteTitle) == 0) {
            for (int j = i; j < albumCount - 1; j++) {
                musicLibrary[j] = musicLibrary[j + 1];
            }
            albumCount--;
            printf("Album \"%s\" deleted successfully!\n", deleteTitle);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Album not found for deletion.\n");
    }
}