//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MUSIC 100
#define TITLE_LEN 50
#define ARTIST_LEN 50

typedef struct {
    char title[TITLE_LEN];
    char artist[ARTIST_LEN];
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
    printf("Enter music title: ");
    fgets(newMusic.title, TITLE_LEN, stdin);
    strtok(newMusic.title, "\n");  // Removing newline character

    printf("Enter artist name: ");
    fgets(newMusic.artist, ARTIST_LEN, stdin);
    strtok(newMusic.artist, "\n");  // Removing newline character

    printf("Enter release year: ");
    scanf("%d", &newMusic.year);
    getchar();  // Clear newline from input buffer

    musicLibrary[musicCount] = newMusic;
    musicCount++;
    printf("Music added successfully!\n");
}

void displayMusic() {
    if (musicCount == 0) {
        printf("No music in the library!\n");
        return;
    }

    printf("\n--- Music Library ---\n");
    for (int i = 0; i < musicCount; i++) {
        printf("Music %d:\n", i + 1);
        printf("Title: %s\n", musicLibrary[i].title);
        printf("Artist: %s\n", musicLibrary[i].artist);
        printf("Year: %d\n", musicLibrary[i].year);
        printf("--------------------\n");
    }
}

void searchMusic() {
    char searchTitle[TITLE_LEN];
    printf("Enter title to search: ");
    fgets(searchTitle, TITLE_LEN, stdin);
    strtok(searchTitle, "\n");  // Removing newline character

    int found = 0;
    for (int i = 0; i < musicCount; i++) {
        if (strcasecmp(musicLibrary[i].title, searchTitle) == 0) {
            printf("Found Music:\n");
            printf("Title: %s\n", musicLibrary[i].title);
            printf("Artist: %s\n", musicLibrary[i].artist);
            printf("Year: %d\n", musicLibrary[i].year);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Music not found in the library!\n");
    }
}

void deleteMusic() {
    char deleteTitle[TITLE_LEN];
    printf("Enter title to delete: ");
    fgets(deleteTitle, TITLE_LEN, stdin);
    strtok(deleteTitle, "\n");  // Removing newline character

    int found = 0;
    for (int i = 0; i < musicCount; i++) {
        if (strcasecmp(musicLibrary[i].title, deleteTitle) == 0) {
            for (int j = i; j < musicCount - 1; j++) {
                musicLibrary[j] = musicLibrary[j + 1];
            }
            musicCount--;
            found = 1;
            printf("Music deleted successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("Music not found in the library!\n");
    }
}

void displayMenu() {
    printf("\n--- Music Library Management System ---\n");
    printf("1. Add Music\n");
    printf("2. Display All Music\n");
    printf("3. Search Music\n");
    printf("4. Delete Music\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
}

int main() {
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);
        getchar();  // Clear newline from input buffer

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
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option! Please try again.\n");
        }
    }

    return 0;
}