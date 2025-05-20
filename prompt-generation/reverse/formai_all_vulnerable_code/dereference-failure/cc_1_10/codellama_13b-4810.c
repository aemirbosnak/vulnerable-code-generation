//Code Llama-13B DATASET v1.0 Category: Music Library Management System ; Style: surprised
// C Music Library Management System Example Program
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store information about a song
typedef struct {
    char title[50];
    char artist[50];
    int playcount;
} Song;

// Structure to store information about a playlist
typedef struct {
    char name[50];
    Song* songs;
    int num_songs;
} Playlist;

// Function to add a song to a playlist
void addSongToPlaylist(Playlist* playlist, Song song) {
    // Allocate memory for the new song
    playlist->songs = (Song*)realloc(playlist->songs, (playlist->num_songs + 1) * sizeof(Song));

    // Add the new song to the playlist
    playlist->songs[playlist->num_songs] = song;
    playlist->num_songs++;
}

// Function to remove a song from a playlist
void removeSongFromPlaylist(Playlist* playlist, int index) {
    // Check if the index is valid
    if (index < 0 || index >= playlist->num_songs) {
        printf("Invalid index\n");
        return;
    }

    // Move all songs after the index to the left
    for (int i = index; i < playlist->num_songs - 1; i++) {
        playlist->songs[i] = playlist->songs[i + 1];
    }

    // Decrement the number of songs
    playlist->num_songs--;
}

// Function to play a song from a playlist
void playSong(Playlist* playlist, int index) {
    // Check if the index is valid
    if (index < 0 || index >= playlist->num_songs) {
        printf("Invalid index\n");
        return;
    }

    // Print the title and artist of the song
    Song song = playlist->songs[index];
    printf("Now playing: %s - %s\n", song.title, song.artist);
}

// Function to print a playlist
void printPlaylist(Playlist* playlist) {
    // Print the name of the playlist
    printf("Playlist: %s\n", playlist->name);

    // Print the songs in the playlist
    for (int i = 0; i < playlist->num_songs; i++) {
        Song song = playlist->songs[i];
        printf("%d. %s - %s\n", i + 1, song.title, song.artist);
    }
}

int main() {
    // Create a playlist
    Playlist* playlist = (Playlist*)malloc(sizeof(Playlist));
    strcpy(playlist->name, "My Playlist");
    playlist->num_songs = 0;

    // Add some songs to the playlist
    Song song1;
    strcpy(song1.title, "Song 1");
    strcpy(song1.artist, "Artist 1");
    song1.playcount = 0;
    addSongToPlaylist(playlist, song1);

    Song song2;
    strcpy(song2.title, "Song 2");
    strcpy(song2.artist, "Artist 2");
    song2.playcount = 0;
    addSongToPlaylist(playlist, song2);

    Song song3;
    strcpy(song3.title, "Song 3");
    strcpy(song3.artist, "Artist 3");
    song3.playcount = 0;
    addSongToPlaylist(playlist, song3);

    // Play a song from the playlist
    playSong(playlist, 0);

    // Remove a song from the playlist
    removeSongFromPlaylist(playlist, 0);

    // Print the playlist
    printPlaylist(playlist);

    // Free the memory allocated for the playlist
    free(playlist);

    return 0;
}