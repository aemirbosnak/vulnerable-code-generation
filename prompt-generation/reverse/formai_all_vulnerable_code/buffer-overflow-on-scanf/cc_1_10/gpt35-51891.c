//FormAI DATASET v1.0 Category: Music Library Management System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONGS 1000

struct Song {
    char title[50];
    char artist[50];
    int year;
    char genre[20];
};

struct Library {
    struct Song songs[MAX_SONGS];
    int size;
};

void printMenu();
void addSong(struct Library* library);
void removeSong(struct Library* library);
void displaySongs(struct Library* library);
void searchSongs(struct Library* library);

int main() {
    struct Library library;
    library.size = 0;

    int choice;

    do {
        printMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addSong(&library);
                break;
            case 2:
                removeSong(&library);
                break;
            case 3:
                displaySongs(&library);
                break;
            case 4:
                searchSongs(&library);
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

void printMenu() {
    printf("\n--- Music Library Management System ---\n");
    printf("1. Add a song\n");
    printf("2. Remove a song\n");
    printf("3. Display all songs\n");
    printf("4. Search for a song\n");
    printf("5. Exit\n");
    printf("---------------------------------------\n");
}

void addSong(struct Library* library) {
    if (library->size >= MAX_SONGS) {
        printf("Error: Maximum number of songs reached.\n");
        return;
    }

    struct Song song;

    printf("Enter song title: ");
    scanf(" %[^\n]s", song.title);
    
    printf("Enter artist: ");
    scanf(" %[^\n]s", song.artist);
    
    printf("Enter year: ");
    scanf("%d", &song.year);
    
    printf("Enter genre: ");
    scanf(" %[^\n]s", song.genre);

    library->songs[library->size] = song;

    printf("Song added successfully!\n");

    library->size++;
}

void removeSong(struct Library* library) {
    if (library->size == 0) {
        printf("Error: Music library is empty.\n");
        return;
    }

    char title[50];
    int index = -1;

    printf("Enter the title of the song you want to remove: ");
    scanf(" %[^\n]s", title);

    for (int i = 0; i < library->size; i++) {
        if (strcmp(title, library->songs[i].title) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Error: Song not found.\n");
        return;
    }

    for (int i = index; i < library->size - 1; i++) {
        library->songs[i] = library->songs[i + 1];
    }

    printf("Song removed successfully!\n");

    library->size--;
}

void displaySongs(struct Library* library) {
    if (library->size == 0) {
        printf("Music library is empty!\n");
        return;
    }

    printf("%-30s%-25s%-10s%-20s\n", "Title", "Artist", "Year", "Genre");

    for (int i = 0; i < library->size; i++) {
        printf("%-30s%-25s%-10d%-20s\n", library->songs[i].title, library->songs[i].artist, library->songs[i].year, library->songs[i].genre);
    }
}

void searchSongs(struct Library* library) {
    if (library->size == 0) {
        printf("Music library is empty!\n");
        return;
    }

    char title[50];
    int matches = 0;

    printf("Enter the title of the song you want to search for: ");
    scanf(" %[^\n]s", title);

    printf("%-30s%-25s%-10s%-20s\n", "Title", "Artist", "Year", "Genre");

    for (int i = 0; i < library->size; i++) {
        if (strstr(library->songs[i].title, title) != NULL) {
            printf("%-30s%-25s%-10d%-20s\n", library->songs[i].title, library->songs[i].artist, library->songs[i].year, library->songs[i].genre);
            matches++;
        }
    }

    if (matches == 0) {
        printf("No matches found.\n");
    }
}