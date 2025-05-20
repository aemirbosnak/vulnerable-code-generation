//Code Llama-13B DATASET v1.0 Category: Music Library Management System ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Struct for a music library
typedef struct {
  char* title;
  char* artist;
  char* album;
  int year;
} Song;

// Struct for a music library
typedef struct {
  Song* songs;
  int size;
  int capacity;
} Library;

// Function to create a new song
Song* create_song(char* title, char* artist, char* album, int year) {
  Song* song = malloc(sizeof(Song));
  song->title = strdup(title);
  song->artist = strdup(artist);
  song->album = strdup(album);
  song->year = year;
  return song;
}

// Function to create a new library
Library* create_library() {
  Library* library = malloc(sizeof(Library));
  library->songs = NULL;
  library->size = 0;
  library->capacity = 0;
  return library;
}

// Function to add a song to a library
void add_song_to_library(Library* library, Song* song) {
  if (library->size == library->capacity) {
    library->capacity *= 2;
    library->songs = realloc(library->songs, library->capacity * sizeof(Song));
  }
  library->songs[library->size] = *song;
  library->size++;
}

// Function to search for a song in a library
Song* search_library(Library* library, char* title) {
  for (int i = 0; i < library->size; i++) {
    if (strcmp(library->songs[i].title, title) == 0) {
      return &library->songs[i];
    }
  }
  return NULL;
}

// Function to delete a song from a library
void delete_song_from_library(Library* library, Song* song) {
  for (int i = 0; i < library->size; i++) {
    if (&library->songs[i] == song) {
      memmove(&library->songs[i], &library->songs[i+1], (library->size - i - 1) * sizeof(Song));
      library->size--;
      return;
    }
  }
}

// Function to delete a library
void delete_library(Library* library) {
  for (int i = 0; i < library->size; i++) {
    free(library->songs[i].title);
    free(library->songs[i].artist);
    free(library->songs[i].album);
  }
  free(library->songs);
  free(library);
}

int main() {
  Library* library = create_library();

  Song* song1 = create_song("Song 1", "Artist 1", "Album 1", 2000);
  Song* song2 = create_song("Song 2", "Artist 2", "Album 2", 2001);
  Song* song3 = create_song("Song 3", "Artist 3", "Album 3", 2002);

  add_song_to_library(library, song1);
  add_song_to_library(library, song2);
  add_song_to_library(library, song3);

  Song* search_result = search_library(library, "Song 2");
  if (search_result != NULL) {
    printf("Found song: %s by %s from %s (%d)\n", search_result->title, search_result->artist, search_result->album, search_result->year);
  } else {
    printf("Song not found\n");
  }

  delete_song_from_library(library, song2);

  delete_library(library);

  return 0;
}