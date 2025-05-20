//Code Llama-13B DATASET v1.0 Category: Music Library Management System ; Style: careful
// Music Library Management System

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structures
typedef struct {
    char title[50];
    char artist[50];
    char genre[50];
    int release_year;
} Song;

typedef struct {
    char name[50];
    Song *songs;
    int num_songs;
} Playlist;

// Functions
void add_song(Playlist *playlist, Song song) {
    playlist->songs = realloc(playlist->songs, (playlist->num_songs + 1) * sizeof(Song));
    playlist->songs[playlist->num_songs] = song;
    playlist->num_songs++;
}

void remove_song(Playlist *playlist, int index) {
    if (index >= playlist->num_songs) {
        printf("Invalid index\n");
        return;
    }
    for (int i = index; i < playlist->num_songs - 1; i++) {
        playlist->songs[i] = playlist->songs[i + 1];
    }
    playlist->num_songs--;
}

void display_song(Song song) {
    printf("%s - %s (%d)\n", song.artist, song.title, song.release_year);
}

void display_playlist(Playlist playlist) {
    printf("Playlist: %s\n", playlist.name);
    for (int i = 0; i < playlist.num_songs; i++) {
        display_song(playlist.songs[i]);
    }
}

int main() {
    Playlist playlist1 = {"My Favorite Songs", NULL, 0};
    Song song1 = {"Song 1", "Artist 1", "Genre 1", 2022};
    Song song2 = {"Song 2", "Artist 2", "Genre 2", 2023};
    add_song(&playlist1, song1);
    add_song(&playlist1, song2);
    display_playlist(playlist1);

    Playlist playlist2 = {"My New Playlist", NULL, 0};
    Song song3 = {"Song 3", "Artist 3", "Genre 3", 2024};
    add_song(&playlist2, song3);
    display_playlist(playlist2);

    remove_song(&playlist1, 0);
    display_playlist(playlist1);

    return 0;
}