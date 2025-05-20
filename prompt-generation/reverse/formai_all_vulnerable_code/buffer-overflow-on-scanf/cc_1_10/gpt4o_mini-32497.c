//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MUSIC 100

typedef struct {
    char title[50];
    char artist[50];
    char genre[30];
    int year;
} MusicAlbum;

MusicAlbum musicCollection[MAX_MUSIC];
int albumCount = 0;

void addAlbum() {
    if (albumCount >= MAX_MUSIC) {
        printf("Music collection is full!\n");
        return;
    }

    MusicAlbum newAlbum;
    printf("Enter Album Title: ");
    scanf(" %[^\n]s", newAlbum.title);
    printf("Enter Artist Name: ");
    scanf(" %[^\n]s", newAlbum.artist);
    printf("Enter Genre: ");
    scanf(" %[^\n]s", newAlbum.genre);
    printf("Enter Release Year: ");
    scanf("%d", &newAlbum.year);

    musicCollection[albumCount++] = newAlbum;
    printf("Album added successfully!\n");
}

void displayAlbums() {
    if (albumCount == 0) {
        printf("No albums in the collection.\n");
        return;
    }
    
    printf("\nMusic Collection:\n");
    for (int i = 0; i < albumCount; i++) {
        printf("Album %d:\n", i + 1);
        printf("Title: %s\n", musicCollection[i].title);
        printf("Artist: %s\n", musicCollection[i].artist);
        printf("Genre: %s\n", musicCollection[i].genre);
        printf("Year: %d\n\n", musicCollection[i].year);
    }
}

void searchAlbum() {
    char searchTitle[50];
    printf("Enter Album Title to search: ");
    scanf(" %[^\n]s", searchTitle);
    
    int found = 0;
    for (int i = 0; i < albumCount; i++) {
        if (strcmp(musicCollection[i].title, searchTitle) == 0) {
            printf("Album found:\n");
            printf("Title: %s\n", musicCollection[i].title);
            printf("Artist: %s\n", musicCollection[i].artist);
            printf("Genre: %s\n", musicCollection[i].genre);
            printf("Year: %d\n\n", musicCollection[i].year);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Album not found in the collection.\n");
    }
}

void removeAlbum() {
    char titleToRemove[50];
    printf("Enter Album Title to remove: ");
    scanf(" %[^\n]s", titleToRemove);
    
    for (int i = 0; i < albumCount; i++) {
        if (strcmp(musicCollection[i].title, titleToRemove) == 0) {
            // Shift remaining albums down
            for (int j = i; j < albumCount - 1; j++) {
                musicCollection[j] = musicCollection[j + 1];
            }
            albumCount--;
            printf("Album removed successfully!\n");
            return;
        }
    }
    printf("Album not found in the collection.\n");
}

void displayMenu() {
    printf("\n=== Music Library Management System ===\n");
    printf("1. Add Album\n");
    printf("2. Display Albums\n");
    printf("3. Search Album\n");
    printf("4. Remove Album\n");
    printf("5. Exit\n");
}

int main() {
    int choice;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addAlbum();
                break;
            case 2:
                displayAlbums();
                break;
            case 3:
                searchAlbum();
                break;
            case 4:
                removeAlbum();
                break;
            case 5:
                printf("Exiting the Music Library Management System. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}