//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MUSICS 100
#define TITLE_LENGTH 100
#define ARTIST_LENGTH 100
#define ALBUM_LENGTH 100
#define GENRE_LENGTH 50

typedef struct {
    char title[TITLE_LENGTH];
    char artist[ARTIST_LENGTH];
    char album[ALBUM_LENGTH];
    char genre[GENRE_LENGTH];
    int year;
} Music;

void addMusic(Music *library, int *count);
void viewMusic(Music *library, int count);
void searchMusic(Music *library, int count);
void deleteMusic(Music *library, int *count);
void displayMenu();

int main() {
    Music library[MAX_MUSICS];
    int count = 0;
    int choice;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // to consume newline character left by scanf

        switch (choice) {
            case 1:
                addMusic(library, &count);
                break;
            case 2:
                viewMusic(library, count);
                break;
            case 3:
                searchMusic(library, count);
                break;
            case 4:
                deleteMusic(library, &count);
                break;
            case 5:
                printf("Exiting the Music Library Management System...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void displayMenu() {
    printf("\n=== Music Library Management System ===\n");
    printf("1. Add Music\n");
    printf("2. View Music\n");
    printf("3. Search Music\n");
    printf("4. Delete Music\n");
    printf("5. Exit\n");
}

void addMusic(Music *library, int *count) {
    if (*count >= MAX_MUSICS) {
        printf("Music library is full! Cannot add more music.\n");
        return;
    }
    
    Music newMusic;
    printf("Enter title: ");
    fgets(newMusic.title, TITLE_LENGTH, stdin);
    newMusic.title[strcspn(newMusic.title, "\n")] = 0; // Remove newline
    printf("Enter artist: ");
    fgets(newMusic.artist, ARTIST_LENGTH, stdin);
    newMusic.artist[strcspn(newMusic.artist, "\n")] = 0;
    printf("Enter album: ");
    fgets(newMusic.album, ALBUM_LENGTH, stdin);
    newMusic.album[strcspn(newMusic.album, "\n")] = 0;
    printf("Enter genre: ");
    fgets(newMusic.genre, GENRE_LENGTH, stdin);
    newMusic.genre[strcspn(newMusic.genre, "\n")] = 0;
    printf("Enter year: ");
    scanf("%d", &newMusic.year);
    getchar(); // Consume newline

    library[*count] = newMusic;
    (*count)++;
    printf("Music added successfully!\n");
}

void viewMusic(Music *library, int count) {
    if (count == 0) {
        printf("No music in the library yet.\n");
        return;
    }
    
    printf("\n=== Music Library ===\n");
    for (int i = 0; i < count; i++) {
        printf("Music %d:\n", i + 1);
        printf(" Title: %s\n", library[i].title);
        printf(" Artist: %s\n", library[i].artist);
        printf(" Album: %s\n", library[i].album);
        printf(" Genre: %s\n", library[i].genre);
        printf(" Year: %d\n", library[i].year);
        printf("----------------------\n");
    }
}

void searchMusic(Music *library, int count) {
    if (count == 0) {
        printf("No music in the library to search.\n");
        return;
    }

    char searchTitle[TITLE_LENGTH];
    printf("Enter title to search: ");
    fgets(searchTitle, TITLE_LENGTH, stdin);
    searchTitle[strcspn(searchTitle, "\n")] = 0; // Remove newline

    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(library[i].title, searchTitle) == 0) {
            found = 1;
            printf("Found Music:\n");
            printf(" Title: %s\n", library[i].title);
            printf(" Artist: %s\n", library[i].artist);
            printf(" Album: %s\n", library[i].album);
            printf(" Genre: %s\n", library[i].genre);
            printf(" Year: %d\n", library[i].year);
            printf("----------------------\n");
        }
    }

    if (!found) {
        printf("Music with title '%s' not found.\n", searchTitle);
    }
}

void deleteMusic(Music *library, int *count) {
    if (*count == 0) {
        printf("No music in the library to delete.\n");
        return;
    }

    char deleteTitle[TITLE_LENGTH];
    printf("Enter title of music to delete: ");
    fgets(deleteTitle, TITLE_LENGTH, stdin);
    deleteTitle[strcspn(deleteTitle, "\n")] = 0; // Remove newline

    int found = 0;
    for (int i = 0; i < *count; i++) {
        if (strcmp(library[i].title, deleteTitle) == 0) {
            found = 1;
            for (int j = i; j < *count - 1; j++) {
                library[j] = library[j + 1];
            }
            (*count)--;
            printf("Music deleted successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("Music with title '%s' not found.\n", deleteTitle);
    }
}