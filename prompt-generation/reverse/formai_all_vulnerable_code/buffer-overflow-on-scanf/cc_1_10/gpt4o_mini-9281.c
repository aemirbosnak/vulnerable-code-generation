//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ALBUMS 100
#define TITLE_LEN 100
#define ARTIST_LEN 100

typedef struct {
    char title[TITLE_LEN];
    char artist[ARTIST_LEN];
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
    getchar(); // Clear newline
    fgets(newAlbum.title, TITLE_LEN, stdin);
    newAlbum.title[strcspn(newAlbum.title, "\n")] = 0; // Remove newline
    printf("Enter artist name: ");
    fgets(newAlbum.artist, ARTIST_LEN, stdin);
    newAlbum.artist[strcspn(newAlbum.artist, "\n")] = 0; // Remove newline
    printf("Enter release year: ");
    scanf("%d", &newAlbum.year);
    musicLibrary[albumCount++] = newAlbum;
    printf("Album added successfully!\n");
}

void deleteAlbum() {
    if (albumCount == 0) {
        printf("No albums to delete!\n");
        return;
    }
    char title[TITLE_LEN];
    printf("Enter the title of the album to delete: ");
    getchar(); // Clear newline
    fgets(title, TITLE_LEN, stdin);
    title[strcspn(title, "\n")] = 0; // Remove newline

    for (int i = 0; i < albumCount; i++) {
        if (strcmp(musicLibrary[i].title, title) == 0) {
            for (int j = i; j < albumCount - 1; j++) {
                musicLibrary[j] = musicLibrary[j + 1];
            }
            albumCount--;
            printf("Album deleted successfully!\n");
            return;
        }
    }
    printf("Album not found!\n");
}

void displayAlbums() {
    if (albumCount == 0) {
        printf("Music library is empty!\n");
        return;
    }
    printf("Music Library:\n");
    for (int i = 0; i < albumCount; i++) {
        printf("%d. %s by %s (%d)\n", i + 1, musicLibrary[i].title, musicLibrary[i].artist, musicLibrary[i].year);
    }
}

void searchAlbum() {
    if (albumCount == 0) {
        printf("No albums in the library!\n");
        return;
    }
    char title[TITLE_LEN];
    printf("Enter the title of the album to search: ");
    getchar(); // Clear newline
    fgets(title, TITLE_LEN, stdin);
    title[strcspn(title, "\n")] = 0; // Remove newline

    for (int i = 0; i < albumCount; i++) {
        if (strcmp(musicLibrary[i].title, title) == 0) {
            printf("Found Album: %s by %s (%d)\n", musicLibrary[i].title, musicLibrary[i].artist, musicLibrary[i].year);
            return;
        }
    }
    printf("Album not found!\n");
}

void showMenu() {
    printf("Music Library Management System\n");
    printf("1. Add Album\n");
    printf("2. Delete Album\n");
    printf("3. Display All Albums\n");
    printf("4. Search Album\n");
    printf("5. Exit\n");
}

int main() {
    int choice;
    while (1) {
        showMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: addAlbum(); break;
            case 2: deleteAlbum(); break;
            case 3: displayAlbums(); break;
            case 4: searchAlbum(); break;
            case 5: exit(0); break;
            default: printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}