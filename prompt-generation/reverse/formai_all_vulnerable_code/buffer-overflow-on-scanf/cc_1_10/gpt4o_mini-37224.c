//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ALBUMS 100
#define MAX_STRING_LENGTH 100

typedef struct {
    char title[MAX_STRING_LENGTH];
    char artist[MAX_STRING_LENGTH];
    int year;
} Album;

typedef struct {
    Album albums[MAX_ALBUMS];
    int totalAlbums;
} MusicLibrary;

void initializeLibrary(MusicLibrary* library) {
    library->totalAlbums = 0;
}

void addAlbum(MusicLibrary* library) {
    if (library->totalAlbums == MAX_ALBUMS) {
        printf("Library is full! Cannot add more albums.\n");
        return;
    }
    
    Album newAlbum;
    
    printf("Enter album title: ");
    fgets(newAlbum.title, MAX_STRING_LENGTH, stdin);
    newAlbum.title[strcspn(newAlbum.title, "\n")] = 0; // Remove newline

    printf("Enter album artist: ");
    fgets(newAlbum.artist, MAX_STRING_LENGTH, stdin);
    newAlbum.artist[strcspn(newAlbum.artist, "\n")] = 0; // Remove newline

    printf("Enter album year: ");
    while (scanf("%d", &newAlbum.year) != 1 || newAlbum.year < 1880 || newAlbum.year > 2023) {
        printf("Invalid year. Enter a valid year (1880-2023): ");
        while(getchar() != '\n'); // Clear invalid input
    }
    while(getchar() != '\n'); // Clear input buffer

    library->albums[library->totalAlbums++] = newAlbum;
    printf("Album added successfully!\n");
}

void viewAlbums(const MusicLibrary* library) {
    if (library->totalAlbums == 0) {
        printf("No albums in the library.\n");
        return;
    }
    
    printf("List of Albums:\n");
    for (int i = 0; i < library->totalAlbums; i++) {
        printf("%d. Title: %s | Artist: %s | Year: %d\n", 
               i + 1, library->albums[i].title, library->albums[i].artist, library->albums[i].year);
    }
}

void searchAlbum(const MusicLibrary* library) {
    char searchTitle[MAX_STRING_LENGTH];

    printf("Enter album title to search: ");
    fgets(searchTitle, MAX_STRING_LENGTH, stdin);
    searchTitle[strcspn(searchTitle, "\n")] = 0; // Remove newline

    for (int i = 0; i < library->totalAlbums; i++) {
        if (strcmp(library->albums[i].title, searchTitle) == 0) {
            printf("Album found: Title: %s | Artist: %s | Year: %d\n", 
                   library->albums[i].title, library->albums[i].artist, library->albums[i].year);
            return;
        }
    }
    printf("Album not found in the library.\n");
}

void displayMenu() {
    printf("\n---- Music Library Management System ----\n");
    printf("1. Add Album\n");
    printf("2. View Albums\n");
    printf("3. Search Album\n");
    printf("4. Exit\n");
    printf("Select an option: ");
}

int main() {
    MusicLibrary library;
    initializeLibrary(&library);
    
    int choice;
    while (1) {
        displayMenu();
        scanf("%d", &choice);
        while(getchar() != '\n'); // Clear input buffer

        switch (choice) {
            case 1:
                addAlbum(&library);
                break;
            case 2:
                viewAlbums(&library);
                break;
            case 3:
                searchAlbum(&library);
                break;
            case 4:
                printf("Exiting the program. Bye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please choose again.\n");
        }
    }
    return 0;
}