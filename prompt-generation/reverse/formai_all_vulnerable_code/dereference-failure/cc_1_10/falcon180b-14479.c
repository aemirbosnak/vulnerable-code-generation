//Falcon-180B DATASET v1.0 Category: Music Library Management System ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE_LENGTH 100
#define MAX_ARTIST_LENGTH 50
#define MAX_ALBUM_LENGTH 100
#define MAX_GENRE_LENGTH 50

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char artist[MAX_ARTIST_LENGTH];
    char album[MAX_ALBUM_LENGTH];
    char genre[MAX_GENRE_LENGTH];
    int length;
} Song;

typedef struct {
    Song *songs;
    int num_songs;
} Playlist;

void add_song(Playlist *playlist, Song *song) {
    playlist->songs = realloc(playlist->songs, sizeof(Song) * (playlist->num_songs + 1));
    playlist->songs[playlist->num_songs] = *song;
    playlist->num_songs++;
}

void print_song(Song *song) {
    printf("Title: %s\n", song->title);
    printf("Artist: %s\n", song->artist);
    printf("Album: %s\n", song->album);
    printf("Genre: %s\n", song->genre);
    printf("Length: %d seconds\n", song->length);
}

void print_playlist(Playlist *playlist) {
    int i;
    for (i = 0; i < playlist->num_songs; i++) {
        print_song(&playlist->songs[i]);
    }
}

int main() {
    Song song1 = {"Bohemian Rhapsody", "Queen", "A Night at the Opera", "Rock", 183};
    Song song2 = {"Stairway to Heaven", "Led Zeppelin", "Led Zeppelin IV", "Rock", 420};
    Song song3 = {"Billie Jean", "Michael Jackson", "Thriller", "Pop", 180};

    Playlist playlist = {NULL, 0};
    add_song(&playlist, &song1);
    add_song(&playlist, &song2);
    add_song(&playlist, &song3);

    print_playlist(&playlist);

    free(playlist.songs);
    return 0;
}