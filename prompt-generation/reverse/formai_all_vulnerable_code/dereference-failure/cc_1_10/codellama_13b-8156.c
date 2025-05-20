//Code Llama-13B DATASET v1.0 Category: Music Library Management System ; Style: ephemeral
// music_lib.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structures

typedef struct {
  char* title;
  char* artist;
  int release_year;
  float length;
} Song;

typedef struct {
  char* name;
  int num_songs;
  Song* songs;
} Album;

typedef struct {
  char* name;
  int num_albums;
  Album* albums;
} Artist;

// Functions

void print_song(Song* song) {
  printf("Title: %s\n", song->title);
  printf("Artist: %s\n", song->artist);
  printf("Release Year: %d\n", song->release_year);
  printf("Length: %f\n", song->length);
}

void print_album(Album* album) {
  printf("Name: %s\n", album->name);
  printf("Number of Songs: %d\n", album->num_songs);
  printf("Songs:\n");
  for (int i = 0; i < album->num_songs; i++) {
    print_song(&album->songs[i]);
  }
}

void print_artist(Artist* artist) {
  printf("Name: %s\n", artist->name);
  printf("Number of Albums: %d\n", artist->num_albums);
  printf("Albums:\n");
  for (int i = 0; i < artist->num_albums; i++) {
    print_album(&artist->albums[i]);
  }
}

// Main

int main() {
  Artist* artist = malloc(sizeof(Artist));
  artist->name = "John Mayer";
  artist->num_albums = 2;
  artist->albums = malloc(sizeof(Album) * 2);

  // Initialize albums
  artist->albums[0].name = "Born and Raised";
  artist->albums[0].num_songs = 10;
  artist->albums[0].songs = malloc(sizeof(Song) * 10);
  artist->albums[1].name = "Continuum";
  artist->albums[1].num_songs = 12;
  artist->albums[1].songs = malloc(sizeof(Song) * 12);

  // Initialize songs
  for (int i = 0; i < 10; i++) {
    artist->albums[0].songs[i].title = "Slow Dancing in a Burning Room";
    artist->albums[0].songs[i].artist = "John Mayer";
    artist->albums[0].songs[i].release_year = 2003;
    artist->albums[0].songs[i].length = 4.25;
  }

  for (int i = 0; i < 12; i++) {
    artist->albums[1].songs[i].title = "No Such Thing";
    artist->albums[1].songs[i].artist = "John Mayer";
    artist->albums[1].songs[i].release_year = 2006;
    artist->albums[1].songs[i].length = 4.50;
  }

  print_artist(artist);

  free(artist);
  return 0;
}