//Falcon-180B DATASET v1.0 Category: Music Library Management System ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONGS 100
#define MAX_TITLE_LEN 100
#define MAX_ARTIST_LEN 100
#define MAX_ALBUM_LEN 100
#define MAX_GENRE_LEN 50
#define MAX_YEAR_LEN 10

typedef struct {
    char title[MAX_TITLE_LEN];
    char artist[MAX_ARTIST_LEN];
    char album[MAX_ALBUM_LEN];
    char genre[MAX_GENRE_LEN];
    char year[MAX_YEAR_LEN];
} Song;

void addSong(Song* songs, int numSongs) {
    printf("Enter song title: ");
    scanf("%s", songs[numSongs].title);
    printf("Enter artist name: ");
    scanf("%s", songs[numSongs].artist);
    printf("Enter album name: ");
    scanf("%s", songs[numSongs].album);
    printf("Enter genre: ");
    scanf("%s", songs[numSongs].genre);
    printf("Enter year: ");
    scanf("%s", songs[numSongs].year);
}

void displaySong(Song song) {
    printf("Title: %s\n", song.title);
    printf("Artist: %s\n", song.artist);
    printf("Album: %s\n", song.album);
    printf("Genre: %s\n", song.genre);
    printf("Year: %s\n", song.year);
}

int main() {
    Song songs[MAX_SONGS];
    int numSongs = 0;

    while (numSongs < MAX_SONGS) {
        printf("Enter song information:\n");
        addSong(songs, numSongs);
        numSongs++;
    }

    printf("Songs:\n");
    for (int i = 0; i < numSongs; i++) {
        displaySong(songs[i]);
    }

    return 0;
}