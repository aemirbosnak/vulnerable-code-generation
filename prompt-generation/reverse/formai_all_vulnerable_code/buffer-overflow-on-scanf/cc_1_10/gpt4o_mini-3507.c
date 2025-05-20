//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ALBUMS 100
#define MAX_NAME_LENGTH 50
#define MAX_ARTIST_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    char artist[MAX_ARTIST_LENGTH];
    int year;
} Album;

Album musicLibrary[MAX_ALBUMS];
int albumCount = 0;

void addAlbum() {
    if (albumCount < MAX_ALBUMS) {
        printf("Enter album name: ");
        fgets(musicLibrary[albumCount].name, MAX_NAME_LENGTH, stdin);
        musicLibrary[albumCount].name[strcspn(musicLibrary[albumCount].name, "\n")] = 0; // Remove newline

        printf("Enter artist name: ");
        fgets(musicLibrary[albumCount].artist, MAX_ARTIST_LENGTH, stdin);
        musicLibrary[albumCount].artist[strcspn(musicLibrary[albumCount].artist, "\n")] = 0; // Remove newline

        printf("Enter year of release: ");
        scanf("%d", &musicLibrary[albumCount].year);
        getchar(); // Clear the newline character from input buffer

        albumCount++;
        printf("Album added successfully!\n");
    } else {
        printf("Library is full, cannot add more albums.\n");
    }
}

void displayAlbums() {
    if (albumCount == 0) {
        printf("No albums in the library.\n");
        return;
    }

    printf("\nMusic Library:\n");
    for (int i = 0; i < albumCount; i++) {
        printf("Album %d:\n", i + 1);
        printf("Name: %s\n", musicLibrary[i].name);
        printf("Artist: %s\n", musicLibrary[i].artist);
        printf("Year: %d\n\n", musicLibrary[i].year);
    }
}

void searchAlbum() {
    char searchCriteria[MAX_NAME_LENGTH];
    printf("Enter album name or artist to search: ");
    fgets(searchCriteria, MAX_NAME_LENGTH, stdin);
    searchCriteria[strcspn(searchCriteria, "\n")] = 0; // Remove newline

    int found = 0;
    for (int i = 0; i < albumCount; i++) {
        if (strstr(musicLibrary[i].name, searchCriteria) || strstr(musicLibrary[i].artist, searchCriteria)) {
            printf("Found Album:\n");
            printf("Name: %s\n", musicLibrary[i].name);
            printf("Artist: %s\n", musicLibrary[i].artist);
            printf("Year: %d\n\n", musicLibrary[i].year);
            found = 1;
        }
    }
    if (!found) {
        printf("No albums found matching your search.\n");
    }
}

void deleteAlbum() {
    if (albumCount == 0) {
        printf("No albums to delete.\n");
        return;
    }

    int index;
    displayAlbums();

    printf("Enter the album number to delete: ");
    scanf("%d", &index);
    getchar(); // Clear the newline character

    if (index < 1 || index > albumCount) {
        printf("Invalid album number!\n");
        return;
    }

    for (int i = index - 1; i < albumCount - 1; i++) {
        musicLibrary[i] = musicLibrary[i + 1];
    }
    albumCount--;
    printf("Album deleted successfully!\n");
}

void displayMenu() {
    printf("\nMusic Library Management System\n");
    printf("1. Add Album\n");
    printf("2. Display Albums\n");
    printf("3. Search Album\n");
    printf("4. Delete Album\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
}

int main() {
    int choice;
    
    while (1) {
        displayMenu();
        scanf("%d", &choice);
        getchar(); // Clear the newline character

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
                deleteAlbum();
                break;
            case 5:
                printf("Exiting the program. Thanks for using it!\n");
                exit(0);
            default:
                printf("Invalid option, please try again.\n");
        }
    }
    return 0;
}