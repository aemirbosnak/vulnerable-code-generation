//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MUSIC 100
#define MAX_TITLE 100
#define MAX_ARTIST 50

typedef struct {
    char title[MAX_TITLE];
    char artist[MAX_ARTIST];
    int year;
    char genre[MAX_ARTIST];
} Music;

Music musicLibrary[MAX_MUSIC];
int musicCount = 0;

void addMusic();
void viewMusic();
void searchMusic();
void deleteMusic();
void menu();
void clearInputBuffer();

int main() {
    menu();
    return 0;
}

void menu() {
    int choice;

    do {
        printf("\n--- Music Library Management System ---\n");
        printf("1. Add Music\n");
        printf("2. View All Music\n");
        printf("3. Search Music\n");
        printf("4. Delete Music\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearInputBuffer();

        switch(choice) {
            case 1:
                addMusic();
                break;
            case 2:
                viewMusic();
                break;
            case 3:
                searchMusic();
                break;
            case 4:
                deleteMusic();
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice != 5);
}

void addMusic() {
    if (musicCount >= MAX_MUSIC) {
        printf("Music library is full! Unable to add more music.\n");
        return;
    }

    Music newMusic;
    printf("Enter music title: ");
    fgets(newMusic.title, MAX_TITLE, stdin);
    newMusic.title[strcspn(newMusic.title, "\n")] = 0; // Remove newline character

    printf("Enter artist name: ");
    fgets(newMusic.artist, MAX_ARTIST, stdin);
    newMusic.artist[strcspn(newMusic.artist, "\n")] = 0;

    printf("Enter release year: ");
    scanf("%d", &newMusic.year);
    clearInputBuffer();

    printf("Enter genre: ");
    fgets(newMusic.genre, MAX_ARTIST, stdin);
    newMusic.genre[strcspn(newMusic.genre, "\n")] = 0;

    musicLibrary[musicCount] = newMusic;
    musicCount++;
    printf("Music added successfully!\n");
}

void viewMusic() {
    if (musicCount == 0) {
        printf("No music available in the library.\n");
        return;
    }

    printf("\n--- Music Library ---\n");
    for (int i = 0; i < musicCount; i++) {
        printf("Title: %s, Artist: %s, Year: %d, Genre: %s\n",
               musicLibrary[i].title, musicLibrary[i].artist,
               musicLibrary[i].year, musicLibrary[i].genre);
    }
}

void searchMusic() {
    char searchTitle[MAX_TITLE];
    int found = 0;

    printf("Enter music title to search for: ");
    fgets(searchTitle, MAX_TITLE, stdin);
    searchTitle[strcspn(searchTitle, "\n")] = 0;

    printf("\n--- Search Results ---\n");
    for (int i = 0; i < musicCount; i++) {
        if (strcasecmp(musicLibrary[i].title, searchTitle) == 0) {
            printf("Title: %s, Artist: %s, Year: %d, Genre: %s\n",
                   musicLibrary[i].title, musicLibrary[i].artist,
                   musicLibrary[i].year, musicLibrary[i].genre);
            found = 1;
        }
    }

    if (!found) {
        printf("No music found with title \"%s\".\n", searchTitle);
    }
}

void deleteMusic() {
    char deleteTitle[MAX_TITLE];
    int i, found = -1;

    printf("Enter music title to delete: ");
    fgets(deleteTitle, MAX_TITLE, stdin);
    deleteTitle[strcspn(deleteTitle, "\n")] = 0;

    for (i = 0; i < musicCount; i++) {
        if (strcasecmp(musicLibrary[i].title, deleteTitle) == 0) {
            found = i;
            break;
        }
    }

    if (found != -1) {
        for (i = found; i < musicCount - 1; i++) {
            musicLibrary[i] = musicLibrary[i + 1];
        }
        musicCount--;
        printf("Music titled \"%s\" deleted successfully!\n", deleteTitle);
    } else {
        printf("No music found with title \"%s\" to delete.\n", deleteTitle);
    }
}

void clearInputBuffer() {
    while (getchar() != '\n');
}