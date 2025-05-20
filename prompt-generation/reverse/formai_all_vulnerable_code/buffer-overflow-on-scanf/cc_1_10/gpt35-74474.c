//FormAI DATASET v1.0 Category: Music Library Management System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LIBRARY_SIZE 1000 // maximum size of library

typedef struct {
    char title[30];
    char artist[30];
    int year;
    int duration;
} Song;

Song library[MAX_LIBRARY_SIZE]; // array to hold library
int librarySize = 0; // current size of library

// function prototypes
void addSong();
void searchByTitle();
void searchByArtist();
void removeSong();
void displayMenu();

int main() {
    int selection;
    do {
        displayMenu();
        printf("Enter your selection: ");
        scanf("%d", &selection);
        switch (selection) {
            case 1:
                addSong();
                break;
            case 2:
                searchByTitle();
                break;
            case 3:
                searchByArtist();
                break;
            case 4:
                removeSong();
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid selection. Please try again.\n");
                break;
        }
    } while (selection != 5);
    return 0;
}

// function to add song to library
void addSong() {
    if (librarySize >= MAX_LIBRARY_SIZE) {
        printf("Error: library is full.\n");
        return;
    }
    Song newSong;
    printf("Enter song title: ");
    scanf("%s", newSong.title);
    printf("Enter song artist: ");
    scanf("%s", newSong.artist);
    printf("Enter release year: ");
    scanf("%d", &newSong.year);
    printf("Enter song duration (in seconds): ");
    scanf("%d", &newSong.duration);
    library[librarySize++] = newSong;
    printf("Song added to library successfully.\n");
}

// function to search for song by title
void searchByTitle() {
    char title[30];
    printf("Enter title to search for: ");
    scanf("%s", title);
    for (int i = 0; i < librarySize; i++) {
        if (strcmp(title, library[i].title) == 0) {
            printf("Match found:\n");
            printf("Title: %s\n", library[i].title);
            printf("Artist: %s\n", library[i].artist);
            printf("Year: %d\n", library[i].year);
            printf("Duration: %d seconds\n", library[i].duration);
            return;
        }
    }
    printf("No match found for title '%s'\n", title);
}

// function to search for song by artist
void searchByArtist() {
    char artist[30];
    printf("Enter artist to search for: ");
    scanf("%s", artist);
    for (int i = 0; i < librarySize; i++) {
        if (strcmp(artist, library[i].artist) == 0) {
            printf("Match found:\n");
            printf("Title: %s\n", library[i].title);
            printf("Artist: %s\n", library[i].artist);
            printf("Year: %d\n", library[i].year);
            printf("Duration: %d seconds\n", library[i].duration);
        }
    }
    printf("No more matches found for artist '%s'\n", artist);
}

// function to remove song from library
void removeSong() {
    char title[30];
    printf("Enter title of song to remove: ");
    scanf("%s", title);
    for (int i = 0; i < librarySize; i++) {
        if (strcmp(title, library[i].title) == 0) {
            for (int j = i; j < librarySize - 1; j++) {
                library[j] = library[j+1];
            }
            librarySize--;
            printf("Song removed from library.\n");
            return;
        }
    }
    printf("No match found for title '%s'. No song removed.\n", title);
}

// function to display menu options
void displayMenu() {
    printf("\n-------------------\n");
    printf("Music Library Menu:\n");
    printf("-------------------\n");
    printf("1. Add song\n");
    printf("2. Search by title\n");
    printf("3. Search by artist\n");
    printf("4. Remove song\n");
    printf("5. Quit\n");
}