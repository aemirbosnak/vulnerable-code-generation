//Falcon-180B DATASET v1.0 Category: Music Library Management System ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_SONGS 100
#define MAX_PLAYLISTS 50
#define MAX_PLAYLIST_SIZE 100

typedef struct {
    char title[100];
    char artist[100];
    int duration;
} Song;

typedef struct {
    char name[100];
    int numSongs;
    Song songs[MAX_PLAYLIST_SIZE];
} Playlist;

typedef struct {
    int numSongs;
    Song songs[MAX_SONGS];
    int numPlaylists;
    Playlist playlists[MAX_PLAYLISTS];
} Library;

Library lib = {0};

void addSong(Song* song) {
    lib.songs[lib.numSongs++] = *song;
}

void addPlaylist(Playlist* playlist) {
    lib.playlists[lib.numPlaylists++] = *playlist;
}

void* addSongThread(void* arg) {
    Song song = {0};
    printf("Enter song title: ");
    scanf("%s", song.title);
    printf("Enter song artist: ");
    scanf("%s", song.artist);
    printf("Enter song duration (in seconds): ");
    scanf("%d", &song.duration);
    addSong(&song);
    pthread_exit(0);
}

void* addPlaylistThread(void* arg) {
    Playlist playlist = {0};
    printf("Enter playlist name: ");
    scanf("%s", playlist.name);
    printf("Enter number of songs in playlist: ");
    scanf("%d", &playlist.numSongs);
    for (int i = 0; i < playlist.numSongs; i++) {
        int index;
        printf("Enter song index: ");
        scanf("%d", &index);
        playlist.songs[i] = lib.songs[index];
    }
    addPlaylist(&playlist);
    pthread_exit(0);
}

void printSongs() {
    for (int i = 0; i < lib.numSongs; i++) {
        printf("%s - %s (%d seconds)\n", lib.songs[i].title, lib.songs[i].artist, lib.songs[i].duration);
    }
}

void printPlaylists() {
    for (int i = 0; i < lib.numPlaylists; i++) {
        printf("%s (%d songs)\n", lib.playlists[i].name, lib.playlists[i].numSongs);
    }
}

int main() {
    pthread_t threads[2];
    pthread_create(&threads[0], NULL, addSongThread, NULL);
    pthread_create(&threads[1], NULL, addPlaylistThread, NULL);
    pthread_join(threads[0], NULL);
    pthread_join(threads[1], NULL);

    printSongs();
    printPlaylists();

    return 0;
}