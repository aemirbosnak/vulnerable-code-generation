//Code Llama-13B DATASET v1.0 Category: Music Library Management System ; Style: statistical
#include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include <time.h>

  struct song {
    char title[50];
    char artist[50];
    int year;
    char genre[50];
  };

  struct library {
    struct song *songs;
    int num_songs;
  };

  void init_library(struct library *lib, int num_songs) {
    lib->songs = malloc(num_songs * sizeof(struct song));
    lib->num_songs = num_songs;
  }

  void add_song(struct library *lib, char *title, char *artist, int year, char *genre) {
    struct song *song = &lib->songs[lib->num_songs];
    strcpy(song->title, title);
    strcpy(song->artist, artist);
    song->year = year;
    strcpy(song->genre, genre);
    lib->num_songs++;
  }

  void print_song(struct song *song) {
    printf("%s - %s (%d) [%s]\n", song->title, song->artist, song->year, song->genre);
  }

  void print_library(struct library *lib) {
    for (int i = 0; i < lib->num_songs; i++) {
      print_song(&lib->songs[i]);
    }
  }

  int main() {
    struct library *lib = malloc(sizeof(struct library));
    init_library(lib, 10);

    add_song(lib, "Happy", "John Lennon", 1970, "Rock");
    add_song(lib, "Imagine", "John Lennon", 1971, "Rock");
    add_song(lib, "Yesterday", "The Beatles", 1965, "Rock");
    add_song(lib, "Stairway to Heaven", "Led Zeppelin", 1971, "Rock");
    add_song(lib, "Bohemian Rhapsody", "Queen", 1975, "Rock");
    add_song(lib, "Hotel California", "Eagles", 1976, "Rock");
    add_song(lib, "Sweet Child O' Mine", "Guns N' Roses", 1987, "Rock");
    add_song(lib, "Smells Like Teen Spirit", "Nirvana", 1991, "Grunge");
    add_song(lib, "Blackbird", "The Beatles", 1968, "Rock");
    add_song(lib, "Stairway to Heaven", "Led Zeppelin", 1971, "Rock");

    print_library(lib);

    return 0;
  }