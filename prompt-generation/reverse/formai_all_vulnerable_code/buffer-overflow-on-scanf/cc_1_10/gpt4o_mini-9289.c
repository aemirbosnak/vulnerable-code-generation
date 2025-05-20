//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MUSIC 100
#define TITLE_LENGTH 100
#define ARTIST_LENGTH 100

typedef struct {
    char title[TITLE_LENGTH];
    char artist[ARTIST_LENGTH];
    int year;
    char genre[30];
} Music;

typedef struct {
    Music musicList[MAX_MUSIC];
    int count;
} MusicLibrary;

void initializeLibrary(MusicLibrary *library) {
    library->count = 0;
}

void addMusic(MusicLibrary *library) {
    if (library->count >= MAX_MUSIC) {
        printf("Music library is full! Cannot add more music.\n");
        return;
    }

    Music newMusic;
    printf("Enter title: ");
    getchar(); // Clear input buffer
    fgets(newMusic.title, TITLE_LENGTH, stdin);
    newMusic.title[strcspn(newMusic.title, "\n")] = 0; // Remove newline

    printf("Enter artist: ");
    fgets(newMusic.artist, ARTIST_LENGTH, stdin);
    newMusic.artist[strcspn(newMusic.artist, "\n")] = 0; // Remove newline

    printf("Enter year: ");
    scanf("%d", &newMusic.year);
    getchar(); // Clear input buffer

    printf("Enter genre: ");
    fgets(newMusic.genre, 30, stdin);
    newMusic.genre[strcspn(newMusic.genre, "\n")] = 0; // Remove newline

    library->musicList[library->count++] = newMusic;
    printf("Music added successfully!\n");
}

void displayMusic(const MusicLibrary *library) {
    if (library->count == 0) {
        printf("No music in the library.\n");
        return;
    }
    printf("\nMusic Library:\n");
    for (int i = 0; i < library->count; i++) {
        printf("Album %d:\n", i + 1);
        printf("Title: %s\n", library->musicList[i].title);
        printf("Artist: %s\n", library->musicList[i].artist);
        printf("Year: %d\n", library->musicList[i].year);
        printf("Genre: %s\n\n", library->musicList[i].genre);
    }
}

void searchMusic(const MusicLibrary *library) {
    char searchTitle[TITLE_LENGTH];
    printf("Enter title to search: ");
    getchar(); // Clear input buffer
    fgets(searchTitle, TITLE_LENGTH, stdin);
    searchTitle[strcspn(searchTitle, "\n")] = 0; // Remove newline

    int found = 0;
    for (int i = 0; i < library->count; i++) {
        if (strcasecmp(library->musicList[i].title, searchTitle) == 0) {
            printf("\nFound Music:\n");
            printf("Title: %s\n", library->musicList[i].title);
            printf("Artist: %s\n", library->musicList[i].artist);
            printf("Year: %d\n", library->musicList[i].year);
            printf("Genre: %s\n", library->musicList[i].genre);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Music not found.\n");
    }
}

void deleteMusic(MusicLibrary *library) {
    char deleteTitle[TITLE_LENGTH];
    printf("Enter title to delete: ");
    getchar(); // Clear input buffer
    fgets(deleteTitle, TITLE_LENGTH, stdin);
    deleteTitle[strcspn(deleteTitle, "\n")] = 0; // Remove newline

    int found = 0;
    for (int i = 0; i < library->count; i++) {
        if (strcasecmp(library->musicList[i].title, deleteTitle) == 0) {
            for (int j = i; j < library->count - 1; j++) {
                library->musicList[j] = library->musicList[j + 1];
            }
            library->count--;
            printf("Music '%s' deleted successfully.\n", deleteTitle);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Music not found to delete.\n");
    }
}

int main() {
    MusicLibrary library;
    initializeLibrary(&library);

    int choice;
    do {
        printf("\nMusic Library Management System\n");
        printf("1. Add Music\n");
        printf("2. Display Music\n");
        printf("3. Search Music\n");
        printf("4. Delete Music\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMusic(&library);
                break;
            case 2:
                displayMusic(&library);
                break;
            case 3:
                searchMusic(&library);
                break;
            case 4:
                deleteMusic(&library);
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}