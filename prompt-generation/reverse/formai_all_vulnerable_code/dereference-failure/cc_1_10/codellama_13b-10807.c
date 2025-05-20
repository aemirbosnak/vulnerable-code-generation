//Code Llama-13B DATASET v1.0 Category: Music Library Management System ; Style: thoughtful
// Music Library Management System
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Structures
typedef struct {
  char *artist;
  char *title;
  int release_year;
  char *genre;
} Music;

typedef struct {
  int size;
  Music *songs;
} MusicLibrary;

// Functions
void print_music_library(MusicLibrary *library) {
  for (int i = 0; i < library->size; i++) {
    Music *song = &library->songs[i];
    printf("%s - %s (%d)\n", song->artist, song->title, song->release_year);
  }
}

void add_song_to_library(MusicLibrary *library, Music *song) {
  library->songs[library->size++] = *song;
}

void remove_song_from_library(MusicLibrary *library, int index) {
  for (int i = index; i < library->size - 1; i++) {
    library->songs[i] = library->songs[i + 1];
  }
  library->size--;
}

void sort_library_by_artist(MusicLibrary *library) {
  for (int i = 0; i < library->size - 1; i++) {
    for (int j = 0; j < library->size - i - 1; j++) {
      if (strcmp(library->songs[j].artist, library->songs[j + 1].artist) > 0) {
        Music temp = library->songs[j];
        library->songs[j] = library->songs[j + 1];
        library->songs[j + 1] = temp;
      }
    }
  }
}

void sort_library_by_title(MusicLibrary *library) {
  for (int i = 0; i < library->size - 1; i++) {
    for (int j = 0; j < library->size - i - 1; j++) {
      if (strcmp(library->songs[j].title, library->songs[j + 1].title) > 0) {
        Music temp = library->songs[j];
        library->songs[j] = library->songs[j + 1];
        library->songs[j + 1] = temp;
      }
    }
  }
}

void sort_library_by_release_year(MusicLibrary *library) {
  for (int i = 0; i < library->size - 1; i++) {
    for (int j = 0; j < library->size - i - 1; j++) {
      if (library->songs[j].release_year > library->songs[j + 1].release_year) {
        Music temp = library->songs[j];
        library->songs[j] = library->songs[j + 1];
        library->songs[j + 1] = temp;
      }
    }
  }
}

int main() {
  MusicLibrary library = {0};
  Music song1 = {"Artist 1", "Title 1", 2010, "Genre 1"};
  Music song2 = {"Artist 2", "Title 2", 2015, "Genre 2"};
  Music song3 = {"Artist 3", "Title 3", 2017, "Genre 3"};
  Music song4 = {"Artist 4", "Title 4", 2020, "Genre 4"};

  add_song_to_library(&library, &song1);
  add_song_to_library(&library, &song2);
  add_song_to_library(&library, &song3);
  add_song_to_library(&library, &song4);

  printf("Before sorting:\n");
  print_music_library(&library);

  sort_library_by_artist(&library);
  printf("\nAfter sorting by artist:\n");
  print_music_library(&library);

  sort_library_by_title(&library);
  printf("\nAfter sorting by title:\n");
  print_music_library(&library);

  sort_library_by_release_year(&library);
  printf("\nAfter sorting by release year:\n");
  print_music_library(&library);

  remove_song_from_library(&library, 1);
  printf("\nAfter removing song 2:\n");
  print_music_library(&library);

  return 0;
}