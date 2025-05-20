//FormAI DATASET v1.0 Category: Music Library Management System ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ALBUMS 100
#define MAX_SONGS 500

typedef struct {
    char title[50];
    char artist[30];
    int releaseYear;
    int numOfSongs;
    char genre[20];
} Album;

typedef struct {
    char title[50];
    char artist[30];
    int trackNum;
    int duration;
} Song;

Album albums[MAX_ALBUMS];
Song songs[MAX_SONGS];

int numOfAlbums;
int numOfSongs;

void addAlbum() {
    Album album;
    printf("Enter album title: ");
    scanf("%s", album.title);
    printf("Enter album artist: ");
    scanf("%s", album.artist);
    printf("Enter release year: ");
    scanf("%d", &album.releaseYear);
    printf("Enter number of songs: ");
    scanf("%d", &album.numOfSongs);
    printf("Enter genre: ");
    scanf("%s", album.genre);
    albums[numOfAlbums++] = album;
}

void addSong() {
    Song song;
    printf("Enter song title: ");
    scanf("%s", song.title);
    printf("Enter artist: ");
    scanf("%s", song.artist);
    printf("Enter track number: ");
    scanf("%d", &song.trackNum);
    printf("Enter duration: ");
    scanf("%d", &song.duration);
    songs[numOfSongs++] = song;
}

void displayAlbums() {
    printf("Albums:\n");
    for (int i = 0; i < numOfAlbums; i++) {
        printf("%d. %s - %s (%d) - %s\n", i + 1, albums[i].artist, albums[i].title, albums[i].releaseYear, albums[i].genre);
    }
}

void displaySongs() {
    printf("Songs:\n");
    for (int i = 0; i < numOfSongs; i++) {
        printf("%d. %s - %s (%d:%d)\n", i + 1, songs[i].artist, songs[i].title, songs[i].duration / 60, songs[i].duration % 60);
    }
}

void searchSong() {
    char searchQuery[50];
    printf("Enter the song to search: ");
    scanf("%s", searchQuery);

    int found = 0;
    for (int i = 0; i < numOfSongs; i++) {
        if (strstr(songs[i].title, searchQuery)) {
            found = 1;
            printf("%d. %s - %s (%d:%d)\n", i + 1, songs[i].artist, songs[i].title, songs[i].duration / 60, songs[i].duration % 60);
        }
    }

    if (!found)
        printf("No song found with the name '%s'\n", searchQuery);
}

int main() {
    int choice;

    while (1) {
        printf("\n*************\n");
        printf("1. Add album\n");
        printf("2. Add song\n");
        printf("3. Display albums\n");
        printf("4. Display songs\n");
        printf("5. Search song\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addAlbum();
                break;
            case 2:
                addSong();
                break;
            case 3:
                displayAlbums();
                break;
            case 4:
                displaySongs();
                break;
            case 5:
                searchSong();
                break;
            case 6:
                exit(0);
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    }

    return 0;
}