//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MUSIC 100

typedef struct {
    char title[100];
    char artist[100];
    char genre[50];
    int year;
} Music;

typedef struct {
    Music collection[MAX_MUSIC];
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

    printf("Enter music title: ");
    getchar(); // to consume leftover newline
    fgets(newMusic.title, 100, stdin);
    newMusic.title[strcspn(newMusic.title, "\n")] = 0;  // remove newline

    printf("Enter artist: ");
    fgets(newMusic.artist, 100, stdin);
    newMusic.artist[strcspn(newMusic.artist, "\n")] = 0; 

    printf("Enter genre: ");
    fgets(newMusic.genre, 50, stdin);
    newMusic.genre[strcspn(newMusic.genre, "\n")] = 0; 

    printf("Enter year: ");
    scanf("%d", &newMusic.year);

    library->collection[library->count++] = newMusic;
    printf("Music added to the library!\n");
}

void displayMusic(const MusicLibrary *library) {
    if (library->count == 0) {
        printf("The music library is empty.\n");
        return;
    }

    printf("\n--- Music Library ---\n");
    for (int i = 0; i < library->count; i++) {
        printf("Title: %s\n", library->collection[i].title);
        printf("Artist: %s\n", library->collection[i].artist);
        printf("Genre: %s\n", library->collection[i].genre);
        printf("Year: %d\n", library->collection[i].year);
        printf("---------------------\n");
    }
}

void searchMusic(const MusicLibrary *library) {
    char searchTitle[100];
    printf("Enter title to search: ");
    getchar(); // consume newline
    fgets(searchTitle, 100, stdin);
    searchTitle[strcspn(searchTitle, "\n")] = 0;

    int found = 0;
    for (int i = 0; i < library->count; i++) {
        if (strcmp(library->collection[i].title, searchTitle) == 0) {
            printf("Music found:\n");
            printf("Title: %s\n", library->collection[i].title);
            printf("Artist: %s\n", library->collection[i].artist);
            printf("Genre: %s\n", library->collection[i].genre);
            printf("Year: %d\n", library->collection[i].year);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Music not found in the library.\n");
    }
}

void removeMusic(MusicLibrary *library) {
    char removeTitle[100];
    printf("Enter title to remove: ");
    getchar(); // consume newline
    fgets(removeTitle, 100, stdin);
    removeTitle[strcspn(removeTitle, "\n")] = 0;

    int found = -1;
    for (int i = 0; i < library->count; i++) {
        if (strcmp(library->collection[i].title, removeTitle) == 0) {
            found = i;
            break;
        }
    }

    if (found != -1) {
        for (int i = found; i < library->count - 1; i++) {
            library->collection[i] = library->collection[i + 1];
        }
        library->count--;
        printf("Music removed from the library.\n");
    } else {
        printf("Music not found, cannot remove.\n");
    }
}

void menu() {
    printf("\n--- Music Library Management System ---\n");
    printf("1. Add Music\n");
    printf("2. Display Music\n");
    printf("3. Search Music\n");
    printf("4. Remove Music\n");
    printf("5. Exit\n");
}

int main() {
    MusicLibrary library;
    initializeLibrary(&library);
    int choice;

    while (1) {
        menu();
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
                removeMusic(&library);
                break;
            case 5:
                printf("Exiting the Music Library Management System. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}