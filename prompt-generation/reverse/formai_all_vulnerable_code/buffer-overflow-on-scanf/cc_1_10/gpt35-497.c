//FormAI DATASET v1.0 Category: Music Library Management System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of songs in the library
#define MAX_SONGS 100

// Define the maximum length of song titles
#define MAX_TITLE_LENGTH 50

// Define the maximum length of artist names
#define MAX_ARTIST_LENGTH 30

// Define the maximum length of genres
#define MAX_GENRE_LENGTH 20

// Define the song structure
typedef struct Song {
    char title[MAX_TITLE_LENGTH];
    char artist[MAX_ARTIST_LENGTH];
    char genre[MAX_GENRE_LENGTH];
    int year;
} Song;

// Define the music library structure
typedef struct MusicLibrary {
    Song songs[MAX_SONGS];
    int numSongs;
} MusicLibrary;

// Function prototypes
void printMenu();
void addSong(MusicLibrary* library);
void removeSong(MusicLibrary* library);
void viewSongs(MusicLibrary* library);
void searchTitle(MusicLibrary* library);
void searchArtist(MusicLibrary* library);
void searchGenre(MusicLibrary* library);

int main() {
    MusicLibrary library;
    library.numSongs = 0;
    int choice;

    // Display the main menu and prompt the user for input
    do {
        printMenu();
        printf("Enter your choice (1-6): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addSong(&library);
                break;

            case 2:
                removeSong(&library);
                break;

            case 3:
                viewSongs(&library);
                break;

            case 4:
                searchTitle(&library);
                break;

            case 5:
                searchArtist(&library);
                break;

            case 6:
                searchGenre(&library);
                break;

            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (choice != 0);

    return 0;
}

void printMenu() {
    printf("--------------------\n");
    printf(" Music Library Menu\n");
    printf("--------------------\n");
    printf("1. Add Song\n");
    printf("2. Remove Song\n");
    printf("3. View Songs\n");
    printf("4. Search by Title\n");
    printf("5. Search by Artist\n");
    printf("6. Search by Genre\n");
    printf("0. Exit\n");
}

void addSong(MusicLibrary* library) {
    // Check if the library is full
    if (library->numSongs == MAX_SONGS) {
        printf("Cannot add song. The music library is full.\n");
        return;
    }

    // Prompt the user to enter song details
    Song song;
    printf("Enter song title: ");
    scanf("%s", song.title);

    printf("Enter artist name: ");
    scanf("%s", song.artist);

    printf("Enter genre: ");
    scanf("%s", song.genre);

    printf("Enter year: ");
    scanf("%d", &song.year);

    // Add the song to the library
    library->songs[library->numSongs] = song;
    library->numSongs++;

    printf("Song added to music library successfully.\n");
}

void removeSong(MusicLibrary* library) {
    // Check if the library is empty
    if (library->numSongs == 0) {
        printf("Cannot remove song. The music library is empty.\n");
        return;
    }

    // Prompt the user to enter the title of the song to be removed
    char title[MAX_TITLE_LENGTH];
    printf("Enter title of song to remove: ");
    scanf("%s", title);

    // Search for the song in the library
    int i;
    for (i = 0; i < library->numSongs; i++) {
        if (strcmp(library->songs[i].title, title) == 0) {
            // Delete the song from the library
            int j;
            for (j = i; j < library->numSongs - 1; j++) {
                library->songs[j] = library->songs[j+1];
            }
            library->numSongs--;

            printf("Song removed from music library successfully.\n");
            return;
        }
    }

    printf("Song not found in music library.\n");
}

void viewSongs(MusicLibrary* library) {
    // Check if the library is empty
    if (library->numSongs == 0) {
        printf("The music library is empty.\n");
        return;
    }

    // Print the songs in the library
    printf("Title\t\tArtist\t\tGenre\t\tYear\n");
    int i;
    for (i = 0; i < library->numSongs; i++) {
        printf("%s\t\t%s\t\t%s\t\t%d\n", library->songs[i].title, library->songs[i].artist, library->songs[i].genre, library->songs[i].year);
    }
}

void searchTitle(MusicLibrary* library) {
    // Check if the library is empty
    if (library->numSongs == 0) {
        printf("The music library is empty.\n");
        return;
    }

    // Prompt the user to enter the title of the song to search for
    char title[MAX_TITLE_LENGTH];
    printf("Enter title of song to search for: ");
    scanf("%s", title);

    // Search for the song in the library
    int i;
    for (i = 0; i < library->numSongs; i++) {
        if (strcmp(library->songs[i].title, title) == 0) {
            // Print the details of the song
            printf("Title\t\tArtist\t\tGenre\t\tYear\n");
            printf("%s\t\t%s\t\t%s\t\t%d\n", library->songs[i].title, library->songs[i].artist, library->songs[i].genre, library->songs[i].year);
            return;
        }
    }

    printf("Song not found in music library.\n");
}

void searchArtist(MusicLibrary* library) {
    // Check if the library is empty
    if (library->numSongs == 0) {
        printf("The music library is empty.\n");
        return;
    }

    // Prompt the user to enter the name of the artist to search for
    char artist[MAX_ARTIST_LENGTH];
    printf("Enter name of artist to search for: ");
    scanf("%s", artist);

    // Search for the songs in the library with the specified artist
    printf("Title\t\tArtist\t\tGenre\t\tYear\n");
    int i;
    for (i = 0; i < library->numSongs; i++) {
        if (strcmp(library->songs[i].artist, artist) == 0) {
            // Print the details of the song
            printf("%s\t\t%s\t\t%s\t\t%d\n", library->songs[i].title, library->songs[i].artist, library->songs[i].genre, library->songs[i].year);
        }
    }
}

void searchGenre(MusicLibrary* library) {
    // Check if the library is empty
    if (library->numSongs == 0) {
        printf("The music library is empty.\n");
        return;
    }

    // Prompt the user to enter the genre to search for
    char genre[MAX_GENRE_LENGTH];
    printf("Enter genre to search for: ");
    scanf("%s", genre);

    // Search for the songs in the library with the specified genre
    printf("Title\t\tArtist\t\tGenre\t\tYear\n");
    int i;
    for (i = 0; i < library->numSongs; i++) {
        if (strcmp(library->songs[i].genre, genre) == 0) {
            // Print the details of the song
            printf("%s\t\t%s\t\t%s\t\t%d\n", library->songs[i].title, library->songs[i].artist, library->songs[i].genre, library->songs[i].year);
        }
    }
}