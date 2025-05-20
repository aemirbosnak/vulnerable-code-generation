//Falcon-180B DATASET v1.0 Category: Music Library Management System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE_LENGTH 100
#define MAX_ARTIST_LENGTH 100
#define MAX_ALBUM_LENGTH 200
#define MAX_GENRE_LENGTH 50
#define MAX_YEAR_LENGTH 10

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char artist[MAX_ARTIST_LENGTH];
    char album[MAX_ALBUM_LENGTH];
    char genre[MAX_GENRE_LENGTH];
    char year[MAX_YEAR_LENGTH];
} Song;

typedef struct {
    Song songs[1000];
    int numSongs;
} MusicLibrary;

void addSong(MusicLibrary* library) {
    printf("Enter song title: ");
    scanf("%s", library->songs[library->numSongs].title);
    printf("Enter artist name: ");
    scanf("%s", library->songs[library->numSongs].artist);
    printf("Enter album name: ");
    scanf("%s", library->songs[library->numSongs].album);
    printf("Enter genre: ");
    scanf("%s", library->songs[library->numSongs].genre);
    printf("Enter year: ");
    scanf("%s", library->songs[library->numSongs].year);
    library->numSongs++;
}

void displaySong(Song song) {
    printf("Title: %s\n", song.title);
    printf("Artist: %s\n", song.artist);
    printf("Album: %s\n", song.album);
    printf("Genre: %s\n", song.genre);
    printf("Year: %s\n", song.year);
}

void displayLibrary(MusicLibrary* library) {
    printf("Music Library:\n");
    for (int i = 0; i < library->numSongs; i++) {
        displaySong(library->songs[i]);
    }
}

void searchLibrary(MusicLibrary* library, char* query) {
    printf("Search results:\n");
    for (int i = 0; i < library->numSongs; i++) {
        if (strstr(library->songs[i].title, query)!= NULL ||
            strstr(library->songs[i].artist, query)!= NULL ||
            strstr(library->songs[i].album, query)!= NULL ||
            strstr(library->songs[i].genre, query)!= NULL ||
            strstr(library->songs[i].year, query)!= NULL) {
            displaySong(library->songs[i]);
        }
    }
}

int main() {
    MusicLibrary library;
    library.numSongs = 0;
    addSong(&library);
    addSong(&library);
    addSong(&library);
    displayLibrary(&library);
    searchLibrary(&library, "love");
    return 0;
}