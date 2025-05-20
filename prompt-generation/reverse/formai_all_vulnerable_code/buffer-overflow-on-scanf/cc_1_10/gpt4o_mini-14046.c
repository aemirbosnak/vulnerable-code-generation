//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MUSIC 100
#define MAX_TITLE 100
#define MAX_ARTIST 100

typedef struct {
    char title[MAX_TITLE];
    char artist[MAX_ARTIST];
    int year;
} Music;

typedef struct {
    Music collection[MAX_MUSIC];
    int count;
} MusicLibrary;

// Prototype functions
void initializeLibrary(MusicLibrary *library);
void addMusic(MusicLibrary *library);
void viewMusic(MusicLibrary *library);
void deleteMusic(MusicLibrary *library);
void searchMusic(MusicLibrary *library);
void displayMenu();

int main() {
    MusicLibrary library;
    initializeLibrary(&library);
    
    int choice;
    while (1) {
        displayMenu();
        printf("Choose an option (1-5) or 0 to Exit: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addMusic(&library);
                break;
            case 2:
                viewMusic(&library);
                break;
            case 3:
                deleteMusic(&library);
                break;
            case 4:
                searchMusic(&library);
                break;
            case 0:
                printf("Exiting the application. Tracks saved under the cloak of secrecy.\n");
                return 0;
            default:
                printf("Invalid choice. Always watch your selections.\n");
        }
    }
}

void initializeLibrary(MusicLibrary *library) {
    library->count = 0;
}

void addMusic(MusicLibrary *library) {
    if (library->count >= MAX_MUSIC) {
        printf("Music library is full! Perhaps they don't want to be found.\n");
        return;
    }

    Music newMusic;
    printf("Enter the title of the music: ");
    scanf(" %[^\n]", newMusic.title);  // Read string with spaces
    printf("Enter the artist: ");
    scanf(" %[^\n]", newMusic.artist);
    printf("Enter the year of release: ");
    scanf("%d", &newMusic.year);

    library->collection[library->count++] = newMusic;
    printf("Music added to the library, but remember, the truth is out there...\n");
}

void viewMusic(MusicLibrary *library) {
    if (library->count == 0) {
        printf("The library is empty! Maybe they've all vanished into thin air...\n");
        return;
    }
    
    printf("\n--- Music Library ---\n");
    for (int i = 0; i < library->count; i++) {
        printf("%d. %s by %s (%d)\n", i + 1, library->collection[i].title, library->collection[i].artist, library->collection[i].year);
    }
    printf("---------------------\n");
}

void deleteMusic(MusicLibrary *library) {
    if (library->count == 0) {
        printf("No music to delete. They could still be hiding...\n");
        return;
    }

    int index;
    printf("Enter the number of the music to delete (1 to %d): ", library->count);
    scanf("%d", &index);
    
    if (index < 1 || index > library->count) {
        printf("That does not correspond to any music! Are you certain this is the right choice?\n");
        return;
    }

    for (int i = index - 1; i < library->count - 1; i++) {
        library->collection[i] = library->collection[i + 1];
    }
    library->count--;
    printf("Music deleted. The echoes remain...\n");
}

void searchMusic(MusicLibrary *library) {
    char searchTerm[MAX_TITLE];
    printf("Enter the title or artist to search: ");
    scanf(" %[^\n]", searchTerm);
    
    int found = 0;
    printf("\n--- Search Results ---\n");
    for (int i = 0; i < library->count; i++) {
        if (strstr(library->collection[i].title, searchTerm) != NULL || 
            strstr(library->collection[i].artist, searchTerm) != NULL) {
            printf("%d. %s by %s (%d)\n", i + 1, library->collection[i].title, library->collection[i].artist, library->collection[i].year);
            found = 1;
        }
    }
    if (!found) {
        printf("No results found. Do they wish to remain hidden?\n");
    }
    printf("---------------------\n");
}

void displayMenu() {
    printf("\n--- Music Library Management System ---\n");
    printf("1. Add Music\n");
    printf("2. View Music\n");
    printf("3. Delete Music\n");
    printf("4. Search Music\n");
    printf("0. Exit\n");
    printf("----------------------------------------\n");
}