//Code Llama-13B DATASET v1.0 Category: Music Library Management System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Music {
  char title[50];
  char artist[50];
  char genre[50];
  int year;
  char album[50];
};

struct Library {
  struct Music* songs;
  int num_songs;
};

void add_song(struct Library* library, struct Music* song) {
  library->songs = realloc(library->songs, (library->num_songs + 1) * sizeof(struct Music));
  library->songs[library->num_songs] = *song;
  library->num_songs++;
}

void remove_song(struct Library* library, int index) {
  if (index < 0 || index >= library->num_songs) {
    return;
  }
  for (int i = index; i < library->num_songs - 1; i++) {
    library->songs[i] = library->songs[i + 1];
  }
  library->num_songs--;
}

void search_song(struct Library* library, char* title, char* artist) {
  for (int i = 0; i < library->num_songs; i++) {
    if (strcmp(library->songs[i].title, title) == 0 && strcmp(library->songs[i].artist, artist) == 0) {
      printf("Song found: %s - %s\n", library->songs[i].title, library->songs[i].artist);
      return;
    }
  }
  printf("Song not found\n");
}

int main() {
  struct Library library = {NULL, 0};
  struct Music song1 = {"Song 1", "Artist 1", "Genre 1", 2020, "Album 1"};
  struct Music song2 = {"Song 2", "Artist 2", "Genre 2", 2010, "Album 2"};
  struct Music song3 = {"Song 3", "Artist 3", "Genre 3", 2000, "Album 3"};
  add_song(&library, &song1);
  add_song(&library, &song2);
  add_song(&library, &song3);
  search_song(&library, "Song 1", "Artist 1");
  remove_song(&library, 0);
  search_song(&library, "Song 1", "Artist 1");
  return 0;
}