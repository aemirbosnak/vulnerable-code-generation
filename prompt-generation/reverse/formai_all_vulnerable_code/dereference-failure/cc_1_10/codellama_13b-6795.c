//Code Llama-13B DATASET v1.0 Category: Music Library Management System ; Style: energetic
// music_lib_management.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a song
typedef struct {
  char title[100];
  char artist[100];
  char genre[100];
  int duration;
} Song;

// Define the structure for a music library
typedef struct {
  Song *songs;
  int num_songs;
} MusicLibrary;

// Function to create a new music library
MusicLibrary *create_music_library() {
  MusicLibrary *lib = malloc(sizeof(MusicLibrary));
  lib->songs = NULL;
  lib->num_songs = 0;
  return lib;
}

// Function to add a song to the music library
void add_song_to_library(MusicLibrary *lib, Song song) {
  lib->songs = realloc(lib->songs, (lib->num_songs + 1) * sizeof(Song));
  lib->songs[lib->num_songs] = song;
  lib->num_songs++;
}

// Function to remove a song from the music library
void remove_song_from_library(MusicLibrary *lib, int index) {
  if (index < 0 || index >= lib->num_songs) {
    printf("Invalid index\n");
    return;
  }
  for (int i = index; i < lib->num_songs - 1; i++) {
    lib->songs[i] = lib->songs[i + 1];
  }
  lib->num_songs--;
  lib->songs = realloc(lib->songs, lib->num_songs * sizeof(Song));
}

// Function to print all the songs in the music library
void print_songs_in_library(MusicLibrary *lib) {
  printf("Songs in library:\n");
  for (int i = 0; i < lib->num_songs; i++) {
    Song song = lib->songs[i];
    printf("%d. %s - %s (%s)\n", i + 1, song.title, song.artist, song.genre);
  }
}

int main() {
  // Create a new music library
  MusicLibrary *lib = create_music_library();

  // Add some songs to the library
  Song song1 = {"Song 1", "Artist 1", "Genre 1", 100};
  Song song2 = {"Song 2", "Artist 2", "Genre 2", 200};
  add_song_to_library(lib, song1);
  add_song_to_library(lib, song2);

  // Print all the songs in the library
  print_songs_in_library(lib);

  // Remove a song from the library
  remove_song_from_library(lib, 1);

  // Print all the songs in the library again
  print_songs_in_library(lib);

  // Clean up
  free(lib->songs);
  free(lib);
  return 0;
}