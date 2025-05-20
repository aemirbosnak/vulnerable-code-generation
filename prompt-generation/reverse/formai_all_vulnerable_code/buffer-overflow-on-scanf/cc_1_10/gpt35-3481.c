//FormAI DATASET v1.0 Category: Music Library Management System ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONGS 100
#define MAX_TITLE_LENGTH 50
#define MAX_ARTIST_LENGTH 50

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char artist[MAX_ARTIST_LENGTH];
    int releaseYear;
} Song;

Song musicLibrary[MAX_SONGS];
int numSongs = 0;

void addSong() {
    Song newSong;
    printf("Enter song title: ");
    fgets(newSong.title, MAX_TITLE_LENGTH, stdin);
    printf("Enter artist name: ");
    fgets(newSong.artist, MAX_ARTIST_LENGTH, stdin);
    printf("Enter release year: ");
    scanf("%d", &newSong.releaseYear);
    getchar(); // consume the newline character left over from scanf
    
    musicLibrary[numSongs] = newSong;
    numSongs++;
    printf("Song added successfully!\n");
}

void searchByTitle() {
    char searchTitle[MAX_TITLE_LENGTH];
    printf("Enter the title to search for: ");
    fgets(searchTitle, MAX_TITLE_LENGTH, stdin);
    
    for (int i = 0; i < numSongs; i++) {
        if (strcmp(searchTitle, musicLibrary[i].title) == 0) {
            printf("Title: %s", musicLibrary[i].title);
            printf("Artist: %s", musicLibrary[i].artist);
            printf("Release year: %d\n", musicLibrary[i].releaseYear);
            return;
        }
    }
    printf("Song not found.\n");
}

void searchByArtist() {
    char searchArtist[MAX_ARTIST_LENGTH];
    printf("Enter the artist to search for: ");
    fgets(searchArtist, MAX_ARTIST_LENGTH, stdin);
    
    for (int i = 0; i < numSongs; i++) {
        if (strcmp(searchArtist, musicLibrary[i].artist) == 0) {
            printf("Title: %s", musicLibrary[i].title);
            printf("Artist: %s", musicLibrary[i].artist);
            printf("Release year: %d\n", musicLibrary[i].releaseYear);
            return;
        }
    }
    printf("Song not found.\n");
}

void deleteSong() {
    char deleteTitle[MAX_TITLE_LENGTH];
    printf("Enter the title of the song to delete: ");
    fgets(deleteTitle, MAX_TITLE_LENGTH, stdin);
    
    for (int i = 0; i < numSongs; i++) {
        if (strcmp(deleteTitle, musicLibrary[i].title) == 0) {
            for (int j = i; j < numSongs - 1; j++) {
                musicLibrary[j] = musicLibrary[j+1];
            }
            numSongs--;
            printf("Song deleted successfully!\n");
            return;
        }
    }
    printf("Song not found.\n");
}

void printLibrary() {
    printf("============= Music Library =============\n");
    for (int i = 0; i < numSongs; i++) {
        printf("Title: %s", musicLibrary[i].title);
        printf("Artist: %s", musicLibrary[i].artist);
        printf("Release year: %d\n", musicLibrary[i].releaseYear);
        printf("---------------------------------------\n");
    }
}

int main() {
    int choice;
    do {
        printf("============= Music Library Management System =============\n");
        printf("Please choose an option:\n");
        printf("1. Add a song\n");
        printf("2. Search for a song by title\n");
        printf("3. Search for songs by artist\n");
        printf("4. Delete a song\n");
        printf("5. View music library\n");
        printf("6. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);
        getchar(); // consume the newline character left over from scanf
        switch (choice) {
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
                deleteSong();
                break;
            case 5:
                printLibrary();
                break;
            case 6:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}