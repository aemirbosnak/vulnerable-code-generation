//Code Llama-13B DATASET v1.0 Category: Music Library Management System ; Style: creative
// Music Library Management System

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct song {
  char* title;
  char* artist;
  char* album;
  int year;
  char* genre;
};

struct library {
  int num_songs;
  struct song* songs;
};

void add_song(struct library* lib, char* title, char* artist, char* album, int year, char* genre) {
  lib->num_songs++;
  lib->songs = realloc(lib->songs, lib->num_songs * sizeof(struct song));
  lib->songs[lib->num_songs - 1].title = title;
  lib->songs[lib->num_songs - 1].artist = artist;
  lib->songs[lib->num_songs - 1].album = album;
  lib->songs[lib->num_songs - 1].year = year;
  lib->songs[lib->num_songs - 1].genre = genre;
}

void print_song(struct song* song) {
  printf("Title: %s\nArtist: %s\nAlbum: %s\nYear: %d\nGenre: %s\n\n", song->title, song->artist, song->album, song->year, song->genre);
}

void print_library(struct library* lib) {
  for (int i = 0; i < lib->num_songs; i++) {
    print_song(&lib->songs[i]);
  }
}

int main() {
  struct library* lib = malloc(sizeof(struct library));
  lib->num_songs = 0;
  lib->songs = NULL;

  add_song(lib, "Song 1", "Artist 1", "Album 1", 2022, "Genre 1");
  add_song(lib, "Song 2", "Artist 2", "Album 2", 2021, "Genre 2");
  add_song(lib, "Song 3", "Artist 3", "Album 3", 2020, "Genre 3");

  print_library(lib);

  free(lib);
  return 0;
}