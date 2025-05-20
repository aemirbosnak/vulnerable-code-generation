//Falcon-180B DATASET v1.0 Category: Music Library Management System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char title[100];
    char artist[100];
    char genre[50];
    int duration;
} Song;

typedef struct {
    Song *songs;
    int size;
    int capacity;
} Playlist;

Playlist *createPlaylist() {
    Playlist *playlist = (Playlist*)malloc(sizeof(Playlist));
    playlist->songs = (Song*)malloc(10 * sizeof(Song));
    playlist->size = 0;
    playlist->capacity = 10;
    return playlist;
}

void addSong(Playlist *playlist, Song song) {
    if (playlist->size >= playlist->capacity) {
        playlist->capacity += 10;
        playlist->songs = (Song*)realloc(playlist->songs, playlist->capacity * sizeof(Song));
    }
    playlist->songs[playlist->size++] = song;
}

void printPlaylist(Playlist *playlist) {
    for (int i = 0; i < playlist->size; i++) {
        printf("Title: %s\nArtist: %s\nGenre: %s\nDuration: %d\n\n", playlist->songs[i].title, playlist->songs[i].artist, playlist->songs[i].genre, playlist->songs[i].duration);
    }
}

int main() {
    Song song1 = {"Bohemian Rhapsody", "Queen", "Rock", 6};
    Song song2 = {"Billie Jean", "Michael Jackson", "Pop", 5};
    Song song3 = {"Stairway to Heaven", "Led Zeppelin", "Rock", 8};
    Song song4 = {"Thriller", "Michael Jackson", "Pop", 5};
    Song song5 = {"November Rain", "Guns N' Roses", "Rock", 9};

    Playlist *playlist = createPlaylist();
    addSong(playlist, song1);
    addSong(playlist, song2);
    addSong(playlist, song3);
    addSong(playlist, song4);
    addSong(playlist, song5);

    printPlaylist(playlist);

    return 0;
}