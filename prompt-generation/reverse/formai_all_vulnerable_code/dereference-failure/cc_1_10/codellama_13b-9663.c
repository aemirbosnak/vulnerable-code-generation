//Code Llama-13B DATASET v1.0 Category: Music Library Management System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Structure to represent a song
struct song {
  char title[100];
  char artist[100];
  char genre[100];
  int duration;
};

// Structure to represent a playlist
struct playlist {
  char name[100];
  struct song *songs;
  int num_songs;
};

// Function to add a song to a playlist
void add_song_to_playlist(struct playlist *playlist, struct song *song) {
  playlist->songs = realloc(playlist->songs, (playlist->num_songs + 1) * sizeof(struct song));
  playlist->songs[playlist->num_songs] = *song;
  playlist->num_songs++;
}

// Function to remove a song from a playlist
void remove_song_from_playlist(struct playlist *playlist, int index) {
  for (int i = index; i < playlist->num_songs - 1; i++) {
    playlist->songs[i] = playlist->songs[i + 1];
  }
  playlist->num_songs--;
}

// Function to print a playlist
void print_playlist(struct playlist *playlist) {
  printf("Playlist: %s\n", playlist->name);
  for (int i = 0; i < playlist->num_songs; i++) {
    printf("  %d: %s - %s (%s)\n", i + 1, playlist->songs[i].title, playlist->songs[i].artist, playlist->songs[i].genre);
  }
}

int main() {
  // Create a new playlist
  struct playlist *playlist = malloc(sizeof(struct playlist));
  strcpy(playlist->name, "My Playlist");
  playlist->num_songs = 0;

  // Add some songs to the playlist
  struct song song1 = {"Song 1", "Artist 1", "Genre 1", 300};
  add_song_to_playlist(playlist, &song1);
  struct song song2 = {"Song 2", "Artist 2", "Genre 2", 200};
  add_song_to_playlist(playlist, &song2);
  struct song song3 = {"Song 3", "Artist 3", "Genre 3", 100};
  add_song_to_playlist(playlist, &song3);

  // Remove a song from the playlist
  remove_song_from_playlist(playlist, 1);

  // Print the playlist
  print_playlist(playlist);

  // Clean up memory
  free(playlist);

  return 0;
}