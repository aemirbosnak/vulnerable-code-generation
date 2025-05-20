//Code Llama-13B DATASET v1.0 Category: Music Library Management System ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structures

typedef struct {
  char name[50];
  char artist[50];
  char genre[50];
  int year;
} Song;

typedef struct {
  Song *songs;
  int num_songs;
} Playlist;

// Functions

void print_song(Song song) {
  printf("Song: %s by %s (%s, %d)\n", song.name, song.artist, song.genre, song.year);
}

void print_playlist(Playlist playlist) {
  for (int i = 0; i < playlist.num_songs; i++) {
    print_song(playlist.songs[i]);
  }
}

// Main function

int main() {
  // Initialize playlist
  Playlist playlist;
  playlist.num_songs = 3;
  playlist.songs = malloc(playlist.num_songs * sizeof(Song));

  // Add songs to playlist
  Song song1 = {"The Sound of Silence", "Simon & Garfunkel", "Classic Rock", 1965};
  Song song2 = {"Imagine", "John Lennon", "Classic Rock", 1971};
  Song song3 = {"Bohemian Rhapsody", "Queen", "Classic Rock", 1975};
  playlist.songs[0] = song1;
  playlist.songs[1] = song2;
  playlist.songs[2] = song3;

  // Print playlist
  print_playlist(playlist);

  // Free memory
  free(playlist.songs);

  return 0;
}