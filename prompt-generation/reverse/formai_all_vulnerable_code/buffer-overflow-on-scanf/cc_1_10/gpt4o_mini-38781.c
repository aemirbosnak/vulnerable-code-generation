//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: Alan Turing
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
        printf("Music library is full. Cannot add more music.\n");
        return;
    }
    
    Music newMusic;
    printf("Enter the title of the music: ");
    getchar(); // To clear the newline character from input buffer
    fgets(newMusic.title, TITLE_LENGTH, stdin);
    newMusic.title[strcspn(newMusic.title, "\n")] = '\0'; // Remove newline character

    printf("Enter the artist of the music: ");
    fgets(newMusic.artist, ARTIST_LENGTH, stdin);
    newMusic.artist[strcspn(newMusic.artist, "\n")] = '\0'; // Remove newline character

    printf("Enter the year of release: ");
    scanf("%d", &newMusic.year);
    
    library->collection[library->count] = newMusic;
    library->count++;
    
    printf("Music added to the library successfully.\n");
}

void displayLibrary(const MusicLibrary *library) {
    if (library->count == 0) {
        printf("The music library is empty.\n");
        return;
    }

    printf("\n--- Music Library ---\n");
    for (int i = 0; i < library->count; i++) {
        Music music = library->collection[i];
        printf("Title: %s, Artist: %s, Year: %d\n", music.title, music.artist, music.year);
    }
}

void searchMusic(const MusicLibrary *library) {
    if (library->count == 0) {
        printf("The music library is empty.\n");
        return;
    }

    char searchTitle[TITLE_LENGTH];
    printf("Enter the title of the music to search: ");
    getchar(); // To clear the newline character from input buffer
    fgets(searchTitle, TITLE_LENGTH, stdin);
    searchTitle[strcspn(searchTitle, "\n")] = '\0'; // Remove newline character

    int found = 0;
    for (int i = 0; i < library->count; i++) {
        if (strcmp(library->collection[i].title, searchTitle) == 0) {
            Music music = library->collection[i];
            printf("Found Music - Title: %s, Artist: %s, Year: %d\n", music.title, music.artist, music.year);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Music with the title '%s' not found in the library.\n", searchTitle);
    }
}

void removeMusic(MusicLibrary *library) {
    if (library->count == 0) {
        printf("The music library is empty. Cannot remove music.\n");
        return;
    }

    char removeTitle[TITLE_LENGTH];
    printf("Enter the title of the music to remove: ");
    getchar(); // To clear the newline character from input buffer
    fgets(removeTitle, TITLE_LENGTH, stdin);
    removeTitle[strcspn(removeTitle, "\n")] = '\0'; // Remove newline character

    int foundIndex = -1;
    for (int i = 0; i < library->count; i++) {
        if (strcmp(library->collection[i].title, removeTitle) == 0) {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex != -1) {
        for (int i = foundIndex; i < library->count - 1; i++) {
            library->collection[i] = library->collection[i + 1];
        }
        library->count--;
        printf("Music '%s' removed from the library successfully.\n", removeTitle);
    } else {
        printf("No music found with the title '%s'.\n", removeTitle);
    }
}

void displayMenu() {
    printf("\n--- Music Library Management System ---\n");
    printf("1. Add Music\n");
    printf("2. Display Music Library\n");
    printf("3. Search Music\n");
    printf("4. Remove Music\n");
    printf("5. Exit\n");
    printf("Select an option: ");
}

int main() {
    MusicLibrary library;
    initializeLibrary(&library);

    int option;
    do {
        displayMenu();
        scanf("%d", &option);
        
        switch (option) {
            case 1:
                addMusic(&library);
                break;
            case 2:
                displayLibrary(&library);
                break;
            case 3:
                searchMusic(&library);
                break;
            case 4:
                removeMusic(&library);
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (option != 5);

    return 0;
}