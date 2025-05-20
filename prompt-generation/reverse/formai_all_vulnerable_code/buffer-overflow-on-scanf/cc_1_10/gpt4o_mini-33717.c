//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MUSICS 100
#define TITLE_LENGTH 50
#define ARTIST_LENGTH 50

typedef struct {
    char title[TITLE_LENGTH];
    char artist[ARTIST_LENGTH];
    int year;
    char genre[TITLE_LENGTH];
} Music;

typedef struct {
    Music musicCollection[MAX_MUSICS];
    int count;
} MusicLibrary;

void initializeLibrary(MusicLibrary* library) {
    library->count = 0;
}

void addMusic(MusicLibrary* library) {
    if (library->count >= MAX_MUSICS) {
        printf("Music library is full!\n");
        return;
    }
    
    Music newMusic;
    
    printf("Enter the title of the music: ");
    getchar(); // clear the newline character from buffer
    fgets(newMusic.title, TITLE_LENGTH, stdin);
    newMusic.title[strcspn(newMusic.title, "\n")] = 0; // removing newline character

    printf("Enter the artist of the music: ");
    fgets(newMusic.artist, ARTIST_LENGTH, stdin);
    newMusic.artist[strcspn(newMusic.artist, "\n")] = 0; // removing newline character

    printf("Enter the year of release: ");
    scanf("%d", &newMusic.year);
    getchar(); // clear the newline character from buffer
    
    printf("Enter the genre of the music: ");
    fgets(newMusic.genre, TITLE_LENGTH, stdin);
    newMusic.genre[strcspn(newMusic.genre, "\n")] = 0; // removing newline character

    library->musicCollection[library->count++] = newMusic;
    printf("Music added successfully!\n");
}

void displayMusic(const MusicLibrary* library) {
    if (library->count == 0) {
        printf("No music in the library!\n");
        return;
    }
    
    printf("\n--- Music Library ---\n");
    for (int i = 0; i < library->count; i++) {
        printf("Music %d:\n", i + 1);
        printf("Title: %s\n", library->musicCollection[i].title);
        printf("Artist: %s\n", library->musicCollection[i].artist);
        printf("Year: %d\n", library->musicCollection[i].year);
        printf("Genre: %s\n", library->musicCollection[i].genre);
        printf("---------------------\n");
    }
}

void searchMusic(const MusicLibrary* library) {
    if (library->count == 0) {
        printf("No music to search for!\n");
        return;
    }

    char searchTitle[TITLE_LENGTH];
    printf("Enter the title of the music to search: ");
    getchar();
    fgets(searchTitle, TITLE_LENGTH, stdin);
    searchTitle[strcspn(searchTitle, "\n")] = 0; // removing newline character

    int found = 0;
    
    for (int i = 0; i < library->count; i++) {
        if (strstr(library->musicCollection[i].title, searchTitle) != NULL) {
            printf("Found Music:\n");
            printf("Title: %s\n", library->musicCollection[i].title);
            printf("Artist: %s\n", library->musicCollection[i].artist);
            printf("Year: %d\n", library->musicCollection[i].year);
            printf("Genre: %s\n", library->musicCollection[i].genre);
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("No music found with the title \"%s\".\n", searchTitle);
    }
}

void deleteMusic(MusicLibrary* library) {
    if (library->count == 0) {
        printf("No music to delete!\n");
        return;
    }

    char deleteTitle[TITLE_LENGTH];
    printf("Enter the title of the music to delete: ");
    getchar();
    fgets(deleteTitle, TITLE_LENGTH, stdin);
    deleteTitle[strcspn(deleteTitle, "\n")] = 0; // removing newline character

    int found = 0;

    for (int i = 0; i < library->count; i++) {
        if (strcmp(library->musicCollection[i].title, deleteTitle) == 0) {
            found = 1;
            for (int j = i; j < library->count - 1; j++) {
                library->musicCollection[j] = library->musicCollection[j + 1];
            }
            library->count--;
            printf("Music \"%s\" deleted successfully.\n", deleteTitle);
            break;
        }
    }
    
    if (!found) {
        printf("No music found with the title \"%s\".\n", deleteTitle);
    }
}

int main() {
    MusicLibrary library;
    int choice;

    initializeLibrary(&library);

    do {
        printf("\n--- Music Library Management System ---\n");
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
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}