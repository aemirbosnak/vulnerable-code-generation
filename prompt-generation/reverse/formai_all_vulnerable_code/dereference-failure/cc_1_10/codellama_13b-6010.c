//Code Llama-13B DATASET v1.0 Category: Music Library Management System ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct to represent a song
struct Song {
  char title[256];
  char artist[256];
  int year;
};

// Struct to represent a playlist
struct Playlist {
  char name[256];
  struct Song* songs;
  int num_songs;
};

// Function to add a song to a playlist
void add_song_to_playlist(struct Playlist* playlist, struct Song* song) {
  playlist->songs[playlist->num_songs++] = *song;
}

// Function to remove a song from a playlist
void remove_song_from_playlist(struct Playlist* playlist, int index) {
  if (index < 0 || index >= playlist->num_songs) {
    printf("Invalid index\n");
    return;
  }
  playlist->num_songs--;
  for (int i = index; i < playlist->num_songs; i++) {
    playlist->songs[i] = playlist->songs[i + 1];
  }
}

// Function to print a playlist
void print_playlist(struct Playlist* playlist) {
  printf("Playlist: %s\n", playlist->name);
  for (int i = 0; i < playlist->num_songs; i++) {
    printf("  Song %d: %s by %s (%d)\n", i + 1, playlist->songs[i].title, playlist->songs[i].artist, playlist->songs[i].year);
  }
}

int main() {
  // Create a playlist
  struct Playlist playlist;
  strcpy(playlist.name, "My Favorite Songs");
  playlist.num_songs = 0;

  // Add some songs to the playlist
  struct Song song1;
  strcpy(song1.title, "Happy");
  strcpy(song1.artist, "Pharrell Williams");
  song1.year = 2013;
  add_song_to_playlist(&playlist, &song1);

  struct Song song2;
  strcpy(song2.title, "Uptown Funk");
  strcpy(song2.artist, "Mark Ronson ft. Bruno Mars");
  song2.year = 2014;
  add_song_to_playlist(&playlist, &song2);

  struct Song song3;
  strcpy(song3.title, "Can't Stop the Feeling!");
  strcpy(song3.artist, "Justin Timberlake");
  song3.year = 2016;
  add_song_to_playlist(&playlist, &song3);

  // Remove a song from the playlist
  remove_song_from_playlist(&playlist, 1);

  // Print the playlist
  print_playlist(&playlist);

  return 0;
}