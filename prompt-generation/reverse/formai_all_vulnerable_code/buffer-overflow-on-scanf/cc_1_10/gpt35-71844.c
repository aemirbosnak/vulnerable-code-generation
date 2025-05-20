//FormAI DATASET v1.0 Category: Music Library Management System ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LENGTH 100 // max length of album name or artist name
#define MAX_ALBUMS 100 // max number of albums in the library
#define MAX_ARTISTS 50 // max number of artists in the library
#define PASSWORD "p@ssw0rd" // password to access the library

// define a struct for each album in the library
typedef struct album {
    char name[MAX_LENGTH];
    char artist[MAX_LENGTH];
    int year;
} Album;

// function to search for an album in the library
void searchLibrary(Album albums[], int albumCount) {
    char searchTerm[MAX_LENGTH];
    printf("\nEnter the name of the album you want to search for: ");
    scanf("%s", searchTerm);
    printf("\nSearch results:\n");
    for (int i = 0; i < albumCount; i++) {
        if (strstr(albums[i].name, searchTerm)) {
            printf("%s by %s (%d)\n", albums[i].name, albums[i].artist, albums[i].year);
        }
    }
}

// function to add a new album to the library
void addAlbum(Album albums[], int *albumCount) {
    if (*albumCount >= MAX_ALBUMS) {
        printf("\nCannot add more albums. Library is full.\n");
        return;
    }
    char name[MAX_LENGTH];
    char artist[MAX_LENGTH];
    int year;
    printf("\nEnter the name of the album: ");
    scanf("%s", name);
    printf("Enter the name of the artist: ");
    scanf("%s", artist);
    printf("Enter the year of release: ");
    scanf("%d", &year);
    Album newAlbum;
    strcpy(newAlbum.name, name);
    strcpy(newAlbum.artist, artist);
    newAlbum.year = year;
    albums[*albumCount] = newAlbum;
    (*albumCount)++;
    printf("\nAlbum added to the library successfully.\n");
}

// function to remove an album from the library
void removeAlbum(Album albums[], int *albumCount) {
    if (*albumCount == 0) {
        printf("\nCannot remove album. Library is empty.\n");
        return;
    }
    char name[MAX_LENGTH];
    printf("\nEnter the name of the album you want to remove: ");
    scanf("%s", name);
    for (int i = 0; i < *albumCount; i++) {
        if (strcmp(albums[i].name, name) == 0) {
            for (int j = i; j < *albumCount - 1; j++) {
                albums[j] = albums[j+1];
            }
            (*albumCount)--;
            printf("\nAlbum removed from the library successfully.\n");
            return;
        }
    }
    printf("\nAlbum not found in the library.\n");
}

int main() {
    // initialize variables
    int albumCount = 0;
    Album albums[MAX_ALBUMS];
    char passwordCheck[MAX_LENGTH];

    // welcome message
    printf("*** C MUSIC LIBRARY MANAGEMENT SYSTEM ***\n");
    printf("\nThis program is password protected. Enter password to continue.\n");
    scanf("%s", passwordCheck);

    // check password
    if (strcmp(passwordCheck, PASSWORD) != 0) {
        printf("\nIncorrect password. Exiting program.\n");
        return 0;
    }

    // main menu
    int choice = 0;
    while (choice != 4) {
        printf("\nMAIN MENU\n");
        printf("1. Search for an album\n");
        printf("2. Add a new album\n");
        printf("3. Remove an album\n");
        printf("4. Exit program\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                searchLibrary(albums, albumCount);
                break;
            case 2:
                addAlbum(albums, &albumCount);
                break;
            case 3:
                removeAlbum(albums, &albumCount);
                break;
            case 4:
                printf("\nExiting program. Goodbye!\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }

    return 0;
}