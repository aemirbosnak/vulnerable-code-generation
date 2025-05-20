//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MUSIC 100
#define MAX_NAME 100

typedef struct {
    char title[MAX_NAME];
    char artist[MAX_NAME];
    char genre[MAX_NAME];
    int year;
} Music;

Music musicLibrary[MAX_MUSIC];
int musicCount = 0;

void addMusic() {
    if (musicCount >= MAX_MUSIC) {
        printf("Music library is full!\n");
        return;
    }

    Music newMusic;
    printf("Enter the title of the music: ");
    scanf(" %[^\n]", newMusic.title);
    printf("Enter the artist of the music: ");
    scanf(" %[^\n]", newMusic.artist);
    printf("Enter the genre of the music: ");
    scanf(" %[^\n]", newMusic.genre);
    printf("Enter the release year of the music: ");
    scanf("%d", &newMusic.year);

    musicLibrary[musicCount] = newMusic;
    musicCount++;
    printf("Music added successfully!\n");
}

void displayMusic() {
    if (musicCount == 0) {
        printf("No music in the library!\n");
        return;
    }
    printf("Music Library:\n");
    printf("-----------------------------------------------------\n");
    for (int i = 0; i < musicCount; i++) {
        printf("Title: %s, Artist: %s, Genre: %s, Year: %d\n",
               musicLibrary[i].title,
               musicLibrary[i].artist,
               musicLibrary[i].genre,
               musicLibrary[i].year);
    }
    printf("-----------------------------------------------------\n");
}

void searchMusic() {
    char searchTitle[MAX_NAME];
    printf("Enter the title of the music to search: ");
    scanf(" %[^\n]", searchTitle);

    int found = 0;
    printf("Search Results:\n");
    printf("-----------------------------------------------------\n");
    for (int i = 0; i < musicCount; i++) {
        if (strstr(musicLibrary[i].title, searchTitle)) {
            printf("Title: %s, Artist: %s, Genre: %s, Year: %d\n",
                   musicLibrary[i].title,
                   musicLibrary[i].artist,
                   musicLibrary[i].genre,
                   musicLibrary[i].year);
            found = 1;
        }
    }
    if (!found) {
        printf("No music found with the title '%s'.\n", searchTitle);
    }
    printf("-----------------------------------------------------\n");
}

void deleteMusic() {
    char deleteTitle[MAX_NAME];
    printf("Enter the title of the music to delete: ");
    scanf(" %[^\n]", deleteTitle);

    int i, found = 0;
    for (i = 0; i < musicCount; i++) {
        if (strcmp(musicLibrary[i].title, deleteTitle) == 0) {
            found = 1;
            break;
        }
    }

    if (found) {
        for (int j = i; j < musicCount - 1; j++) {
            musicLibrary[j] = musicLibrary[j + 1];
        }
        musicCount--;
        printf("Music deleted successfully!\n");
    } else {
        printf("No music found with the title '%s'.\n", deleteTitle);
    }
}

void displayMenu() {
    printf("Welcome to the Music Library Management System!\n");
    printf("1. Add Music\n");
    printf("2. Display Music\n");
    printf("3. Search Music\n");
    printf("4. Delete Music\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
}

int main() {
    int choice;
    do {
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
                searchMusic();
                break;
            case 4:
                deleteMusic();
                break;
            case 5:
                printf("Exiting the Music Library Management System. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}