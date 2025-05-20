//FormAI DATASET v1.0 Category: Music Library Management System ; Style: authentic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Constants
#define MAX_SONGS 100
#define MAX_TITLE_LENGTH 100
#define MAX_ARTIST_LENGTH 50

// Song Struct
typedef struct {
    char title[MAX_TITLE_LENGTH];
    char artist[MAX_ARTIST_LENGTH];
    int length;
} Song;

// Music Library Struct
typedef struct {
    Song songs[MAX_SONGS];
    int num_songs;
} MusicLibrary;

// Function Prototypes
void addSong(MusicLibrary *library);
void removeSong(MusicLibrary *library);
void searchSongs(MusicLibrary *library);
void displayAllSongs(MusicLibrary *library);
void displaySong(Song song);

// Main Function
int main() {
    // Initializations
    MusicLibrary library;
    library.num_songs = 0;

    // Menu Loop
    int choice;
    do {
        printf("\n\nMusic Library Management System\n");
        printf("1. Add Song\n");
        printf("2. Remove Song\n");
        printf("3. Search Songs\n");
        printf("4. Display All Songs\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addSong(&library);
                break;

            case 2:
                removeSong(&library);
                break;

            case 3:
                searchSongs(&library);
                break;

            case 4:
                displayAllSongs(&library);
                break;

            case 5:
                printf("\nGoodbye!\n");
                break;

            default:
                printf("\nInvalid Choice! Try Again.\n");
        }
    } while(choice != 5);

    return 0;
}

// Function Definitions

// Add Song Function
void addSong(MusicLibrary *library) {
    if(library->num_songs == MAX_SONGS) {
        printf("\nMusic Library Full! Cannot Add More Songs.\n");
        return;
    }

    Song song;
    printf("\nEnter Song Title: ");
    scanf(" %[^\n]s", song.title);
    printf("Enter Artist Name: ");
    scanf(" %[^\n]s", song.artist);
    printf("Enter Song Length (in seconds): ");
    scanf("%d", &song.length);

    library->songs[library->num_songs] = song;
    library->num_songs++;

    printf("\nSong Added to Music Library Successfully!\n");
}

// Remove Song Function
void removeSong(MusicLibrary *library) {
    char title[MAX_TITLE_LENGTH];
    printf("\nEnter Title of Song to Remove: ");
    scanf(" %[^\n]s", title);

    int i, found = 0;
    for(i = 0; i < library->num_songs; i++) {
        if(strcmp(title, library->songs[i].title) == 0) {
            found = 1;
            break;
        }
    }

    if(!found) {
        printf("\nSong Not Found in Music Library!\n");
        return;
    }

    // Shift all songs to left from i + 1 to num_songs - 1
    for(; i < library->num_songs - 1; i++) {
        library->songs[i] = library->songs[i + 1];
    }

    library->num_songs--;

    printf("\nSong Removed from Music Library Successfully!\n");
}

// Search Songs Function
void searchSongs(MusicLibrary *library) {
    char query[MAX_TITLE_LENGTH];
    int i, found = 0;

    printf("\nEnter Search Query: ");
    scanf(" %[^\n]s", query);

    printf("\nSearch Results:\n\n");

    for(i = 0; i < library->num_songs; i++) {
        if(strstr(library->songs[i].title, query) != NULL || strstr(library->songs[i].artist, query) != NULL) {
            displaySong(library->songs[i]);
            found = 1;
        }
    }

    if(!found) {
        printf("\nNo Match Found for Query '%s'!\n", query);
    }
}

// Display All Songs Function
void displayAllSongs(MusicLibrary *library) {
    printf("\nAll Songs in Music Library:\n\n");
    int i;
    for(i = 0; i < library->num_songs; i++) {
        displaySong(library->songs[i]);
    }
}

// Display Song Function
void displaySong(Song song) {
    printf("Title: %s\n", song.title);
    printf("Artist: %s\n", song.artist);
    printf("Length: %d seconds\n\n", song.length);
}