//Falcon-180B DATASET v1.0 Category: Music Library Management System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_MUSIC 1000
#define MAX_TITLE 100
#define MAX_ARTIST 50
#define MAX_ALBUM 100
#define MAX_GENRE 30

typedef struct {
    char title[MAX_TITLE];
    char artist[MAX_ARTIST];
    char album[MAX_ALBUM];
    char genre[MAX_GENRE];
    char path[100];
} Music;

Music musicLibrary[MAX_MUSIC];
int numOfSongs = 0;

void addSong() {
    char title[MAX_TITLE], artist[MAX_ARTIST], album[MAX_ALBUM], genre[MAX_GENRE];
    char path[100];
    printf("Enter the song title: ");
    scanf("%s", title);
    strcpy(musicLibrary[numOfSongs].title, title);
    printf("Enter the song artist: ");
    scanf("%s", artist);
    strcpy(musicLibrary[numOfSongs].artist, artist);
    printf("Enter the song album: ");
    scanf("%s", album);
    strcpy(musicLibrary[numOfSongs].album, album);
    printf("Enter the song genre: ");
    scanf("%s", genre);
    strcpy(musicLibrary[numOfSongs].genre, genre);
    printf("Enter the song path: ");
    scanf("%s", path);
    strcpy(musicLibrary[numOfSongs].path, path);
    numOfSongs++;
}

void displaySongs() {
    printf("Songs in the library:\n");
    for (int i = 0; i < numOfSongs; i++) {
        printf("%d. %s - %s\n", i+1, musicLibrary[i].title, musicLibrary[i].artist);
    }
}

void searchSong() {
    char search[MAX_TITLE];
    printf("Enter the song title to search: ");
    scanf("%s", search);
    for (int i = 0; i < numOfSongs; i++) {
        if (strcmp(musicLibrary[i].title, search) == 0) {
            printf("Song found:\n");
            printf("Title: %s\n", musicLibrary[i].title);
            printf("Artist: %s\n", musicLibrary[i].artist);
            printf("Album: %s\n", musicLibrary[i].album);
            printf("Genre: %s\n", musicLibrary[i].genre);
            printf("Path: %s\n", musicLibrary[i].path);
        }
    }
}

int main() {
    addSong();
    addSong();
    addSong();
    displaySongs();
    searchSong();
    return 0;
}