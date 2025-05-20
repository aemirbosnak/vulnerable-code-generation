//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: retro
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
    int duration; // Duration in seconds
} Album;

Album library[MAX_ALBUMS];
int albumCount = 0;

void addAlbum();
void listAlbums();
void findAlbum();
void deleteAlbum();
void saveLibrary();
void loadLibrary();

void displayMenu() {
    printf("\n*** Music Library Management System ***\n");
    printf("1. Add Album\n");
    printf("2. List Albums\n");
    printf("3. Find Album\n");
    printf("4. Delete Album\n");
    printf("5. Save Library\n");
    printf("6. Load Library\n");
    printf("0. Exit\n");
    printf("Select an option: ");
}

int main() {
    loadLibrary();
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addAlbum();
                break;
            case 2:
                listAlbums();
                break;
            case 3:
                findAlbum();
                break;
            case 4:
                deleteAlbum();
                break;
            case 5:
                saveLibrary();
                break;
            case 6:
                loadLibrary();
                break;
            case 0:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

void addAlbum() {
    if(albumCount >= MAX_ALBUMS) {
        printf("Library is full! Cannot add more albums.\n");
        return;
    }
    Album newAlbum;
    printf("Enter album title: ");
    scanf(" %[^\n]", newAlbum.title);
    printf("Enter artist name: ");
    scanf(" %[^\n]", newAlbum.artist);
    printf("Enter release year: ");
    scanf("%d", &newAlbum.year);
    printf("Enter duration (in seconds): ");
    scanf("%d", &newAlbum.duration);

    library[albumCount] = newAlbum;
    albumCount++;
    printf("Album added successfully!\n");
}

void listAlbums() {
    if(albumCount == 0) {
        printf("No albums in the library.\n");
        return;
    }

    printf("\n*** Album List ***\n");
    for (int i = 0; i < albumCount; i++) {
        printf("Album %d:\n", i + 1);
        printf("Title: %s\n", library[i].title);
        printf("Artist: %s\n", library[i].artist);
        printf("Year: %d\n", library[i].year);
        printf("Duration: %d seconds\n\n", library[i].duration);
    }
}

void findAlbum() {
    char searchTitle[MAX_TITLE_LENGTH];
    printf("Enter album title to search: ");
    scanf(" %[^\n]", searchTitle);

    for (int i = 0; i < albumCount; i++) {
        if (strcmp(library[i].title, searchTitle) == 0) {
            printf("Album found!\n");
            printf("Title: %s\n", library[i].title);
            printf("Artist: %s\n", library[i].artist);
            printf("Year: %d\n", library[i].year);
            printf("Duration: %d seconds\n", library[i].duration);
            return;
        }
    }
    printf("Album not found in the library.\n");
}

void deleteAlbum() {
    char deleteTitle[MAX_TITLE_LENGTH];
    printf("Enter album title to delete: ");
    scanf(" %[^\n]", deleteTitle);

    for (int i = 0; i < albumCount; i++) {
        if (strcmp(library[i].title, deleteTitle) == 0) {
            for (int j = i; j < albumCount - 1; j++) {
                library[j] = library[j + 1];
            }
            albumCount--;
            printf("Album deleted successfully!\n");
            return;
        }
    }
    printf("Album not found in the library.\n");
}

void saveLibrary() {
    FILE *file = fopen("music_library.txt", "w");
    if (!file) {
        printf("Failed to open the file for saving.\n");
        return;
    }
    for (int i = 0; i < albumCount; i++) {
        fprintf(file, "%s|%s|%d|%d\n", library[i].title, library[i].artist, library[i].year, library[i].duration);
    }
    fclose(file);
    printf("Library saved successfully!\n");
}

void loadLibrary() {
    FILE *file = fopen("music_library.txt", "r");
    if (!file) {
        printf("No library file found. Starting with an empty library.\n");
        return;
    }
    while (fscanf(file, "%[^|]|%[^|]|%d|%d\n", library[albumCount].title, library[albumCount].artist, &library[albumCount].year, &library[albumCount].duration) == 4) {
        albumCount++;
    }
    fclose(file);
    printf("Library loaded successfully! Total albums: %d\n", albumCount);
}