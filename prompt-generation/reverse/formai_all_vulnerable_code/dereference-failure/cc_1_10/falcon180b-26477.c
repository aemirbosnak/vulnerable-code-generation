//Falcon-180B DATASET v1.0 Category: Music Library Management System ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char title[100];
    char artist[100];
    char genre[50];
    int year;
    int duration;
} Song;

typedef struct {
    Song *songs;
    int num_songs;
    int capacity;
} Playlist;

void init_playlist(Playlist *playlist, int capacity) {
    playlist->songs = (Song *)malloc(capacity * sizeof(Song));
    playlist->num_songs = 0;
    playlist->capacity = capacity;
}

void add_song(Playlist *playlist, Song song) {
    if (playlist->num_songs >= playlist->capacity) {
        printf("Playlist is full.\n");
        return;
    }
    playlist->songs[playlist->num_songs++] = song;
}

void print_song(Song song) {
    printf("Title: %s\n", song.title);
    printf("Artist: %s\n", song.artist);
    printf("Genre: %s\n", song.genre);
    printf("Year: %d\n", song.year);
    printf("Duration: %d seconds\n", song.duration);
}

void print_playlist(Playlist playlist) {
    int i;
    for (i = 0; i < playlist.num_songs; i++) {
        print_song(playlist.songs[i]);
    }
}

int main() {
    Song song1 = {"Bohemian Rhapsody", "Queen", "Rock", 1975, 240};
    Song song2 = {"Stairway to Heaven", "Led Zeppelin", "Rock", 1971, 420};
    Song song3 = {"Thriller", "Michael Jackson", "Pop", 1982, 300};

    Playlist playlist;
    init_playlist(&playlist, 3);

    add_song(&playlist, song1);
    add_song(&playlist, song2);
    add_song(&playlist, song3);

    print_playlist(playlist);

    return 0;
}