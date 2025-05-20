//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MUSICS 100
#define TITLE_SIZE 100
#define ARTIST_SIZE 100

typedef struct {
    char title[TITLE_SIZE];
    char artist[ARTIST_SIZE];
    int year;
    char genre[30];
} Music;

Music musicLibrary[MAX_MUSICS];
int musicCount = 0;

void addMusic() {
    if (musicCount >= MAX_MUSICS) {
        printf("Oh no! The music library is full!\n");
        return;
    }

    Music newMusic;

    printf("Enter music title: ");
    getchar(); // to consume leftover newline
    fgets(newMusic.title, TITLE_SIZE, stdin);
    newMusic.title[strcspn(newMusic.title, "\n")] = 0; // remove newline

    printf("Enter music artist: ");
    fgets(newMusic.artist, ARTIST_SIZE, stdin);
    newMusic.artist[strcspn(newMusic.artist, "\n")] = 0; // remove newline

    printf("Enter year of release: ");
    scanf("%d", &newMusic.year);

    printf("Enter genre: ");
    getchar(); // to consume leftover newline
    fgets(newMusic.genre, 30, stdin);
    newMusic.genre[strcspn(newMusic.genre, "\n")] = 0; // remove newline

    musicLibrary[musicCount++] = newMusic;
    printf("Music added successfully!\n");
}

void displayMusicLibrary() {
    if (musicCount == 0) {
        printf("The library is empty! How shocking...\n");
        return;
    }

    printf("\n========================\n");
    printf("Music Library:\n");
    for (int i = 0; i < musicCount; i++) {
        printf("Title: %s\n", musicLibrary[i].title);
        printf("Artist: %s\n", musicLibrary[i].artist);
        printf("Year: %d\n", musicLibrary[i].year);
        printf("Genre: %s\n", musicLibrary[i].genre);
        printf("------------------------\n");
    }
}

void searchMusic() {
    if (musicCount == 0) {
        printf("The library is empty! Can't search anything!\n");
        return;
    }

    char searchTitle[TITLE_SIZE];
    printf("Enter music title to search: ");
    getchar();
    fgets(searchTitle, TITLE_SIZE, stdin);
    searchTitle[strcspn(searchTitle, "\n")] = 0; // remove newline

    int found = 0;
    for (int i = 0; i < musicCount; i++) {
        if (strcasecmp(musicLibrary[i].title, searchTitle) == 0) {
            printf("Music found! Title: %s, Artist: %s, Year: %d, Genre: %s\n",
                   musicLibrary[i].title, musicLibrary[i].artist,
                   musicLibrary[i].year, musicLibrary[i].genre);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("No music found with the title '%s'! How sad...\n", searchTitle);
    }
}

void deleteMusic() {
    if (musicCount == 0) {
        printf("The library is empty! Nothing to delete!\n");
        return;
    }

    char deleteTitle[TITLE_SIZE];
    printf("Enter music title to delete: ");
    getchar();
    fgets(deleteTitle, TITLE_SIZE, stdin);
    deleteTitle[strcspn(deleteTitle, "\n")] = 0; // remove newline

    int foundIndex = -1;
    for (int i = 0; i < musicCount; i++) {
        if (strcasecmp(musicLibrary[i].title, deleteTitle) == 0) {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex == -1) {
        printf("No music found to delete with the title '%s'.\n", deleteTitle);
    } else {
        for (int i = foundIndex; i < musicCount - 1; i++) {
            musicLibrary[i] = musicLibrary[i + 1];
        }
        musicCount--;
        printf("Music '%s' deleted successfully! What a shock!\n", deleteTitle);
    }
}

void displayMenu() {
    printf("\n==================================\n");
    printf("Welcome to the Music Library!\n");
    printf("1. Add Music\n");
    printf("2. Display Music Library\n");
    printf("3. Search Music\n");
    printf("4. Delete Music\n");
    printf("5. Exit\n");
    printf("==================================\n");
    printf("Select an option: ");
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
                displayMusicLibrary();
                break;
            case 3:
                searchMusic();
                break;
            case 4:
                deleteMusic();
                break;
            case 5:
                printf("Exiting the Music Library. Bye-bye!\n");
                exit(0);
                break;
            default:
                printf("Invalid choice! How could that happen!?\n");
                break;
        }
    }

    return 0;
}