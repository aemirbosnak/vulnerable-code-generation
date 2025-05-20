//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MUSICS 100
#define MAX_TITLE_LENGTH 100
#define MAX_ARTIST_LENGTH 100

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char artist[MAX_ARTIST_LENGTH];
    int year;
    char genre[MAX_TITLE_LENGTH];
} Music;

Music musicLibrary[MAX_MUSICS];
int numMusics = 0;

void addMusic() {
    if (numMusics >= MAX_MUSICS) {
        printf("Library is full! Can't add more music.\n");
        return;
    }
    
    Music newMusic;
    printf("Enter the title of the music: ");
    getchar(); // consume newline
    fgets(newMusic.title, MAX_TITLE_LENGTH, stdin);
    newMusic.title[strcspn(newMusic.title, "\n")] = '\0'; // remove newline

    printf("Enter the artist of the music: ");
    fgets(newMusic.artist, MAX_ARTIST_LENGTH, stdin);
    newMusic.artist[strcspn(newMusic.artist, "\n")] = '\0'; // remove newline

    printf("Enter the year of release: ");
    scanf("%d", &newMusic.year);

    printf("Enter the genre: ");
    getchar(); // consume newline
    fgets(newMusic.genre, MAX_TITLE_LENGTH, stdin);
    newMusic.genre[strcspn(newMusic.genre, "\n")] = '\0'; // remove newline

    musicLibrary[numMusics++] = newMusic;
    printf("Music added successfully!\n");
}

void displayMusicLibrary() {
    if (numMusics == 0) {
        printf("No music in the library.\n");
        return;
    }
    
    printf("\nMusic Library:\n");
    for (int i = 0; i < numMusics; i++) {
        printf("Music %d:\n", i + 1);
        printf("Title: %s\n", musicLibrary[i].title);
        printf("Artist: %s\n", musicLibrary[i].artist);
        printf("Year: %d\n", musicLibrary[i].year);
        printf("Genre: %s\n\n", musicLibrary[i].genre);
    }
}

void searchMusic() {
    char searchTitle[MAX_TITLE_LENGTH];
    printf("Enter the title of the music to search: ");
    getchar(); // consume newline
    fgets(searchTitle, MAX_TITLE_LENGTH, stdin);
    searchTitle[strcspn(searchTitle, "\n")] = '\0'; // remove newline

    int found = 0;
    for (int i = 0; i < numMusics; i++) {
        if (strcasecmp(musicLibrary[i].title, searchTitle) == 0) {
            printf("\nFound Music:\n");
            printf("Title: %s\n", musicLibrary[i].title);
            printf("Artist: %s\n", musicLibrary[i].artist);
            printf("Year: %d\n", musicLibrary[i].year);
            printf("Genre: %s\n\n", musicLibrary[i].genre);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Music not found in the library.\n");
    }
}

void removeMusic() {
    char removeTitle[MAX_TITLE_LENGTH];
    printf("Enter the title of the music to remove: ");
    getchar(); // consume newline
    fgets(removeTitle, MAX_TITLE_LENGTH, stdin);
    removeTitle[strcspn(removeTitle, "\n")] = '\0'; // remove newline

    int found = 0;
    for (int i = 0; i < numMusics; i++) {
        if (strcasecmp(musicLibrary[i].title, removeTitle) == 0) {
            for (int j = i; j < numMusics - 1; j++) {
                musicLibrary[j] = musicLibrary[j + 1];
            }
            numMusics--;
            printf("Music '%s' removed from the library successfully!\n", removeTitle);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Music not found in the library.\n");
    }
}

void displayMenu() {
    printf("\nMusic Library Management System\n");
    printf("1. Add Music\n");
    printf("2. Display Music Library\n");
    printf("3. Search Music\n");
    printf("4. Remove Music\n");
    printf("5. Exit\n");
}

int main() {
    int choice;
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: addMusic(); break;
            case 2: displayMusicLibrary(); break;
            case 3: searchMusic(); break;
            case 4: removeMusic(); break;
            case 5: printf("Exiting the program...\n"); break;
            default: printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}