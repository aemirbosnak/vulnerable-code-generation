//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: peaceful
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
    char genre[MAX_TITLE_LENGTH];
} Album;

Album musicLibrary[MAX_ALBUMS];
int albumCount = 0;

void addAlbum() {
    if (albumCount >= MAX_ALBUMS) {
        printf("Music library is full. Cannot add more albums.\n");
        return;
    }
    
    Album newAlbum;
    printf("Enter album title: ");
    scanf(" %[^\n]", newAlbum.title);
    printf("Enter artist name: ");
    scanf(" %[^\n]", newAlbum.artist);
    printf("Enter release year: ");
    scanf("%d", &newAlbum.year);
    printf("Enter genre: ");
    scanf(" %[^\n]", newAlbum.genre);
    
    musicLibrary[albumCount++] = newAlbum;
    printf("Album added successfully!\n");
}

void viewAlbums() {
    if (albumCount == 0) {
        printf("No albums in the library.\n");
        return;
    }
    
    printf("\n---- Music Library ----\n");
    for (int i = 0; i < albumCount; i++) {
        printf("Album %d:\n", i + 1);
        printf("Title: %s\n", musicLibrary[i].title);
        printf("Artist: %s\n", musicLibrary[i].artist);
        printf("Year: %d\n", musicLibrary[i].year);
        printf("Genre: %s\n", musicLibrary[i].genre);
        printf("---------------------\n");
    }
}

void searchAlbum() {
    char query[MAX_TITLE_LENGTH];
    printf("Enter the album title to search: ");
    scanf(" %[^\n]", query);
    
    int found = 0;
    for (int i = 0; i < albumCount; i++) {
        if (strcasecmp(musicLibrary[i].title, query) == 0) {
            printf("Album found!\n");
            printf("Title: %s\n", musicLibrary[i].title);
            printf("Artist: %s\n", musicLibrary[i].artist);
            printf("Year: %d\n", musicLibrary[i].year);
            printf("Genre: %s\n", musicLibrary[i].genre);
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("Album not found in the library.\n");
    }
}

void deleteAlbum() {
    char query[MAX_TITLE_LENGTH];
    printf("Enter the album title to delete: ");
    scanf(" %[^\n]", query);
    
    int index = -1;
    for (int i = 0; i < albumCount; i++) {
        if (strcasecmp(musicLibrary[i].title, query) == 0) {
            index = i;
            break;
        }
    }
    
    if (index == -1) {
        printf("Album not found! Deletion failed.\n");
        return;
    }
    
    for (int i = index; i < albumCount - 1; i++) {
        musicLibrary[i] = musicLibrary[i + 1]; // Shift albums left
    }
    albumCount--;
    printf("Album deleted successfully!\n");
}

void displayMenu() {
    printf("\n--- Music Library Management System ---\n");
    printf("1. Add Album\n");
    printf("2. View Albums\n");
    printf("3. Search Album\n");
    printf("4. Delete Album\n");
    printf("5. Exit\n");
    printf("Please choose an option (1-5): ");
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
                searchAlbum();
                break;
            case 4:
                deleteAlbum();
                break;
            case 5:
                printf("Exiting the Music Library Management System. Have a great day!\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
    
    return 0;
}