//Code Llama-13B DATASET v1.0 Category: Music Library Management System ; Style: unmistakable
// Music Library Management System
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Structures
typedef struct {
    int id;
    char title[256];
    char artist[256];
    char album[256];
    int year;
    int duration;
} Song;

typedef struct {
    int id;
    char name[256];
    char genre[256];
    Song songs[100];
} Playlist;

// Functions
void addSong(Song *song) {
    song->id = 1;
    printf("Enter the song title: ");
    fgets(song->title, 256, stdin);
    printf("Enter the artist name: ");
    fgets(song->artist, 256, stdin);
    printf("Enter the album name: ");
    fgets(song->album, 256, stdin);
    printf("Enter the song year: ");
    scanf("%d", &song->year);
    printf("Enter the song duration: ");
    scanf("%d", &song->duration);
}

void addPlaylist(Playlist *playlist) {
    playlist->id = 1;
    printf("Enter the playlist name: ");
    fgets(playlist->name, 256, stdin);
    printf("Enter the genre: ");
    fgets(playlist->genre, 256, stdin);
    for (int i = 0; i < 100; i++) {
        addSong(&playlist->songs[i]);
    }
}

void printSong(Song *song) {
    printf("Song: %s - %s (%s) (%d)\n", song->title, song->artist, song->album, song->year);
}

void printPlaylist(Playlist *playlist) {
    printf("Playlist: %s (%s)\n", playlist->name, playlist->genre);
    for (int i = 0; i < 100; i++) {
        printSong(&playlist->songs[i]);
    }
}

int main() {
    Song song;
    Playlist playlist;
    addSong(&song);
    addPlaylist(&playlist);
    printSong(&song);
    printPlaylist(&playlist);
    return 0;
}