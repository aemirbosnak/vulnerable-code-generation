//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MUSIC 100
#define TITLE_LENGTH 50
#define ARTIST_LENGTH 50

typedef struct {
    char title[TITLE_LENGTH];
    char artist[ARTIST_LENGTH];
    int year;
    int id;
} Music;

Music musicLibrary[MAX_MUSIC];
int musicCount = 0;

void addMusic() {
    if (musicCount >= MAX_MUSIC) {
        printf("Library is full! Can't add more music.\n");
        return;
    }
    
    Music newMusic;
    printf("Enter title: ");
    getchar(); // to consume trailing newline
    fgets(newMusic.title, TITLE_LENGTH, stdin);
    newMusic.title[strcspn(newMusic.title, "\n")] = 0; // remove newline

    printf("Enter artist: ");
    fgets(newMusic.artist, ARTIST_LENGTH, stdin);
    newMusic.artist[strcspn(newMusic.artist, "\n")] = 0; // remove newline

    printf("Enter year: ");
    scanf("%d", &newMusic.year);
    
    newMusic.id = musicCount + 1;
    musicLibrary[musicCount] = newMusic;
    musicCount++;

    printf("Added %s by %s (%d) to the library.\n", newMusic.title, newMusic.artist, newMusic.year);
}

void displayMusic() {
    if (musicCount == 0) {
        printf("No music in the library.\n");
        return;
    }
    printf("\n--- Music Library ---\n");
    for (int i = 0; i < musicCount; i++) {
        printf("%d: %s by %s (%d)\n", musicLibrary[i].id, musicLibrary[i].title, musicLibrary[i].artist, musicLibrary[i].year);
    }
}

void deleteMusic() {
    int id;
    printf("Enter the ID of music to delete: ");
    scanf("%d", &id);
    
    if (id < 1 || id > musicCount) {
        printf("Invalid ID!\n");
        return;
    }
    
    for (int i = id - 1; i < musicCount - 1; i++) {
        musicLibrary[i] = musicLibrary[i + 1];
    }
    musicCount--;
    printf("Deleted music with ID %d from the library.\n", id);
}

void searchMusic() {
    char query[TITLE_LENGTH];
    printf("Enter title or artist to search: ");
    getchar(); // to consume trailing newline
    fgets(query, TITLE_LENGTH, stdin);
    query[strcspn(query, "\n")] = 0; // remove newline

    printf("\n--- Search Results ---\n");
    int found = 0;
    for (int i = 0; i < musicCount; i++) {
        if (strstr(musicLibrary[i].title, query) != NULL || strstr(musicLibrary[i].artist, query) != NULL) {
            printf("%d: %s by %s (%d)\n", musicLibrary[i].id, musicLibrary[i].title, musicLibrary[i].artist, musicLibrary[i].year);
            found = 1;
        }
    }
    if (!found) {
        printf("No results found.\n");
    }
}

void displayMenu() {
    printf("\n--- Music Library Management System ---\n");
    printf("1. Add Music\n");
    printf("2. Display Music\n");
    printf("3. Delete Music\n");
    printf("4. Search Music\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMusic();
                break;
            case 2:
                displayMusic();
                break;
            case 3:
                deleteMusic();
                break;
            case 4:
                searchMusic();
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}