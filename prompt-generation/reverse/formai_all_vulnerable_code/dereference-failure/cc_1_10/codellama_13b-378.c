//Code Llama-13B DATASET v1.0 Category: Music Library Management System ; Style: visionary
// C Music Library Management System

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structures
typedef struct {
  char* artist;
  char* album;
  char* genre;
  int track_count;
  int play_count;
} Song;

typedef struct {
  Song* songs;
  int song_count;
} Library;

// Functions
void add_song(Library* library, char* artist, char* album, char* genre, int track_count, int play_count) {
  library->songs = realloc(library->songs, (library->song_count + 1) * sizeof(Song));
  library->songs[library->song_count].artist = strdup(artist);
  library->songs[library->song_count].album = strdup(album);
  library->songs[library->song_count].genre = strdup(genre);
  library->songs[library->song_count].track_count = track_count;
  library->songs[library->song_count].play_count = play_count;
  library->song_count++;
}

void remove_song(Library* library, int index) {
  for (int i = index; i < library->song_count - 1; i++) {
    library->songs[i] = library->songs[i + 1];
  }
  library->song_count--;
}

void update_song(Library* library, int index, char* artist, char* album, char* genre, int track_count, int play_count) {
  library->songs[index].artist = strdup(artist);
  library->songs[index].album = strdup(album);
  library->songs[index].genre = strdup(genre);
  library->songs[index].track_count = track_count;
  library->songs[index].play_count = play_count;
}

void print_song(Song* song) {
  printf("Artist: %s\n", song->artist);
  printf("Album: %s\n", song->album);
  printf("Genre: %s\n", song->genre);
  printf("Track Count: %d\n", song->track_count);
  printf("Play Count: %d\n", song->play_count);
}

void print_library(Library* library) {
  for (int i = 0; i < library->song_count; i++) {
    print_song(&library->songs[i]);
  }
}

// Main
int main() {
  Library library;
  library.songs = NULL;
  library.song_count = 0;

  // Add songs
  add_song(&library, "Artist 1", "Album 1", "Genre 1", 10, 100);
  add_song(&library, "Artist 2", "Album 2", "Genre 2", 15, 200);
  add_song(&library, "Artist 3", "Album 3", "Genre 3", 12, 150);

  // Remove song
  remove_song(&library, 1);

  // Update song
  update_song(&library, 2, "Artist 2", "Album 2", "Genre 2", 20, 300);

  // Print library
  print_library(&library);

  // Free memory
  for (int i = 0; i < library.song_count; i++) {
    free(library.songs[i].artist);
    free(library.songs[i].album);
    free(library.songs[i].genre);
  }
  free(library.songs);

  return 0;
}