//FormAI DATASET v1.0 Category: Music Library Management System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LIB_SIZE 100
#define MAX_SONG_SIZE 50

/* Song structure */
struct Song {
    char title[MAX_SONG_SIZE];
    char artist[MAX_SONG_SIZE];
    char album[MAX_SONG_SIZE];
    int year;
};

/* Music library structure */
struct Library {
    struct Song songs[MAX_LIB_SIZE];
    int size;
};

/* Function to add a song to the library */
void addSong(struct Song newSong, struct Library *lib) {
    if (lib->size < MAX_LIB_SIZE) {
        lib->songs[lib->size] = newSong;
        lib->size++;
    } else {
        printf("Library is full\n");
    }
}

/* Function to display all the songs in the library */
void displaySongs(struct Library lib) {
    if (lib.size == 0) {
        printf("Library is empty\n");
        return;
    }

    printf("------------------------------------------------------------------\n");
    printf("%-30s %-20s %-20s %-10s\n", "Song", "Artist", "Album", "Year");
    printf("------------------------------------------------------------------\n");

    for (int i = 0; i < lib.size; i++) {
        printf("%-30s %-20s %-20s %-10d\n", lib.songs[i].title, lib.songs[i].artist, lib.songs[i].album, lib.songs[i].year);
    }

    printf("------------------------------------------------------------------\n");
}

/* Function to search for songs in the library by title */
void searchByTitle(char title[MAX_SONG_SIZE], struct Library lib) {
    int found = 0;

    printf("------------------------------------------------------------------\n");
    printf("%-30s %-20s %-20s %-10s\n", "Song", "Artist", "Album", "Year");
    printf("------------------------------------------------------------------\n");

    for (int i = 0; i < lib.size; i++) {
        if (strcmp(title, lib.songs[i].title) == 0) {
            printf("%-30s %-20s %-20s %-10d\n", lib.songs[i].title, lib.songs[i].artist, lib.songs[i].album, lib.songs[i].year);
            found = 1;
        }
    }

    if (!found) {
        printf("No results found for '%s'\n", title);
    }

    printf("------------------------------------------------------------------\n");
}

int main() {
    struct Library myLibrary;
    myLibrary.size = 0;

    int choice, year;
    char title[MAX_SONG_SIZE], artist[MAX_SONG_SIZE], album[MAX_SONG_SIZE];

    do {
        printf("Music Library Management System\n");
        printf("--------------------------------\n");
        printf("1. Add song to library\n");
        printf("2. Display all songs in library\n");
        printf("3. Search for songs by title\n");
        printf("4. Quit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter song title: ");
                scanf("%s", title);
                printf("Enter artist name: ");
                scanf("%s", artist);
                printf("Enter album name: ");
                scanf("%s", album);
                printf("Enter release year: ");
                scanf("%d", &year);

                struct Song newSong;
                strcpy(newSong.title, title);
                strcpy(newSong.artist, artist);
                strcpy(newSong.album, album);
                newSong.year = year;

                addSong(newSong, &myLibrary);

                printf("Song added to library successfully\n");
                break;
            case 2:
                displaySongs(myLibrary);
                break;
            case 3:
                printf("\nEnter song title to search: ");
                scanf("%s", title);

                searchByTitle(title, myLibrary);
                break;
            case 4:
                printf("\nExiting...\n");
                exit(0);
                break;
            default:
                printf("\nInvalid choice, please try again\n");
        }
    } while (1);

    return 0;
}