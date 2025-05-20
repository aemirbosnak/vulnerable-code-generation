//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONGS 100
#define NAME_LENGTH 50
#define ARTIST_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    char artist[ARTIST_LENGTH];
    char genre[NAME_LENGTH];
    int year;
} Song;

Song library[MAX_SONGS];
int songCount = 0;

void addSong() {
    if (songCount >= MAX_SONGS) {
        printf("Library is full! Can't add more songs.\n");
        return;
    }

    printf("Enter song name: ");
    scanf(" %[^\n]", library[songCount].name);
    printf("Enter artist name: ");
    scanf(" %[^\n]", library[songCount].artist);
    printf("Enter genre: ");
    scanf(" %[^\n]", library[songCount].genre);
    printf("Enter year of release: ");
    scanf("%d", &library[songCount].year);
    
    songCount++;
    printf("Song added successfully!\n");
}

void displaySongs() {
    if (songCount == 0) {
        printf("No songs in the library yet!\n");
        return;
    }

    printf("\nMusic Library:\n");
    for (int i = 0; i < songCount; i++) {
        printf("Song %d: %s by %s, Genre: %s, Year: %d\n", 
                i+1, library[i].name, library[i].artist, library[i].genre, library[i].year);
    }
}

void searchSong() {
    char searchName[NAME_LENGTH];
    printf("Enter song name to search: ");
    scanf(" %[^\n]", searchName);

    for (int i = 0; i < songCount; i++) {
        if (strcmp(library[i].name, searchName) == 0) {
            printf("Found: %s by %s, Genre: %s, Year: %d\n", 
                    library[i].name, library[i].artist, library[i].genre, library[i].year);
            return;
        }
    }

    printf("Song not found in the library.\n");
}

void showMenu() {
    printf("\n--- Music Library Management System ---\n");
    printf("1. Add Song\n");
    printf("2. Display Songs\n");
    printf("3. Search Song\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
}

int main() {
    int option;

    do {
        showMenu();
        scanf("%d", &option);

        switch (option) {
            case 1:
                addSong();
                break;
            case 2:
                displaySongs();
                break;
            case 3:
                searchSong();
                break;
            case 4:
                printf("Exiting the Music Library Management System. Goodbye!\n");
                break;
            default:
                printf("Invalid option! Please try again.\n");
        }
    } while (option != 4);

    return 0;
}