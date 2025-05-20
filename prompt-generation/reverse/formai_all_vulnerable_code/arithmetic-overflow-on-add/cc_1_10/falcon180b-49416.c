//Falcon-180B DATASET v1.0 Category: Music Library Management System ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONGS 100
#define MAX_SONG_NAME_LENGTH 50
#define MAX_ALBUM_NAME_LENGTH 50
#define MAX_ARTIST_NAME_LENGTH 50

typedef struct {
    char songName[MAX_SONG_NAME_LENGTH];
    char albumName[MAX_ALBUM_NAME_LENGTH];
    char artistName[MAX_ARTIST_NAME_LENGTH];
    int duration;
} Song;

typedef struct {
    Song songs[MAX_SONGS];
    int numSongs;
} MusicLibrary;

void addSong(MusicLibrary* library) {
    if (library->numSongs >= MAX_SONGS) {
        printf("Error: library is full\n");
        return;
    }

    printf("Enter song name: ");
    scanf("%[^\n]", library->songs[library->numSongs].songName);

    printf("Enter album name: ");
    scanf("%[^\n]", library->songs[library->numSongs].albumName);

    printf("Enter artist name: ");
    scanf("%[^\n]", library->songs[library->numSongs].artistName);

    printf("Enter song duration (in seconds): ");
    scanf("%d", &library->songs[library->numSongs].duration);

    library->numSongs++;
}

void displaySongs(MusicLibrary* library) {
    printf("\n");
    printf("Song Name\tAlbum Name\tArtist Name\tDuration\n");
    printf("---------------------------------------------------------\n");
    for (int i = 0; i < library->numSongs; i++) {
        printf("%-50s\t%-50s\t%-50s\t%d\n", library->songs[i].songName, library->songs[i].albumName, library->songs[i].artistName, library->songs[i].duration);
    }
}

int main() {
    MusicLibrary library;
    library.numSongs = 0;

    int choice;
    do {
        printf("\nMusic Library Management System\n");
        printf("1. Add Song\n");
        printf("2. Display Songs\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            addSong(&library);
            break;
        case 2:
            displaySongs(&library);
            break;
        case 3:
            printf("Thank you for using the Music Library Management System!\n");
            break;
        default:
            printf("Invalid choice\n");
        }

    } while (choice!= 3);

    return 0;
}