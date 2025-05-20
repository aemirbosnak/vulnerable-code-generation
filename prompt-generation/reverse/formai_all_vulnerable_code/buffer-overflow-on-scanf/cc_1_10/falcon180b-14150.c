//Falcon-180B DATASET v1.0 Category: Music Library Management System ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONGS 100
#define MAX_PLAYLISTS 10
#define MAX_PLAYLIST_SIZE 100

struct Song {
    char title[100];
    char artist[100];
    char album[100];
    int duration;
};

struct Playlist {
    char name[100];
    int size;
    int capacity;
    struct Song songs[MAX_PLAYLIST_SIZE];
};

void addSong(struct Song* song) {
    printf("Enter song title: ");
    scanf("%s", song->title);
    printf("Enter song artist: ");
    scanf("%s", song->artist);
    printf("Enter song album: ");
    scanf("%s", song->album);
    printf("Enter song duration (in seconds): ");
    scanf("%d", &song->duration);
}

void printSong(struct Song song) {
    printf("Title: %s\n", song.title);
    printf("Artist: %s\n", song.artist);
    printf("Album: %s\n", song.album);
    printf("Duration: %d seconds\n\n", song.duration);
}

void addPlaylist(struct Playlist* playlist) {
    printf("Enter playlist name: ");
    scanf("%s", playlist->name);
    playlist->size = 0;
    playlist->capacity = MAX_PLAYLIST_SIZE;
}

void printPlaylist(struct Playlist playlist) {
    printf("Playlist name: %s\n", playlist.name);
    printf("Number of songs: %d\n", playlist.size);
    printf("Maximum playlist size: %d\n\n", playlist.capacity);
}

void addSongToPlaylist(struct Song song, struct Playlist* playlist) {
    if (playlist->size >= playlist->capacity) {
        printf("Playlist is full.\n");
        return;
    }
    playlist->songs[playlist->size] = song;
    playlist->size++;
}

void printPlaylistSongs(struct Playlist playlist) {
    int i;
    for (i = 0; i < playlist.size; i++) {
        printSong(playlist.songs[i]);
    }
}

int main() {
    struct Song song;
    struct Playlist playlist;

    addSong(&song);
    printSong(song);

    addPlaylist(&playlist);
    printPlaylist(playlist);

    addSongToPlaylist(song, &playlist);
    printPlaylistSongs(playlist);

    return 0;
}