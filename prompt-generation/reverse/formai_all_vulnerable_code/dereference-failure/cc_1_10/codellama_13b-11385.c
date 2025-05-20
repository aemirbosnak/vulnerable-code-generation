//Code Llama-13B DATASET v1.0 Category: Music Library Management System ; Style: funny
// A funny C Music Library Management System example program
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a song
typedef struct {
  char title[50];
  char artist[50];
  int duration;
} Song;

// Structure to represent a playlist
typedef struct {
  char name[50];
  int num_songs;
  Song *songs;
} Playlist;

// Function to add a song to a playlist
void add_song_to_playlist(Playlist *playlist, Song song) {
  playlist->num_songs++;
  playlist->songs = realloc(playlist->songs, playlist->num_songs * sizeof(Song));
  playlist->songs[playlist->num_songs - 1] = song;
}

// Function to remove a song from a playlist
void remove_song_from_playlist(Playlist *playlist, int index) {
  if (index < 0 || index >= playlist->num_songs) {
    printf("Invalid index\n");
    return;
  }

  for (int i = index; i < playlist->num_songs - 1; i++) {
    playlist->songs[i] = playlist->songs[i + 1];
  }

  playlist->num_songs--;
  playlist->songs = realloc(playlist->songs, playlist->num_songs * sizeof(Song));
}

// Function to play a playlist
void play_playlist(Playlist *playlist) {
  printf("Playlist: %s\n", playlist->name);
  for (int i = 0; i < playlist->num_songs; i++) {
    printf("Song %d: %s by %s (%d seconds)\n", i + 1, playlist->songs[i].title, playlist->songs[i].artist, playlist->songs[i].duration);
  }
}

// Main function
int main() {
  // Create a playlist
  Playlist playlist;
  strcpy(playlist.name, "My Favorite Songs");
  playlist.num_songs = 0;
  playlist.songs = NULL;

  // Add some songs to the playlist
  Song song1 = {"Bohemian Rhapsody", "Queen", 360};
  Song song2 = {"Hotel California", "The Eagles", 1080};
  Song song3 = {"Stairway to Heaven", "Led Zeppelin", 1080};
  add_song_to_playlist(&playlist, song1);
  add_song_to_playlist(&playlist, song2);
  add_song_to_playlist(&playlist, song3);

  // Remove a song from the playlist
  remove_song_from_playlist(&playlist, 1);

  // Play the playlist
  play_playlist(&playlist);

  return 0;
}