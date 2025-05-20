//Code Llama-13B DATASET v1.0 Category: Music Library Management System ; Style: peaceful
// music_library.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structures for storing music information
typedef struct {
  char* title;
  char* artist;
  char* album;
  int year;
  int rating;
} Music;

typedef struct {
  char* name;
  Music** musics;
  int num_musics;
} MusicLibrary;

// Function to add a music to the library
void add_music(MusicLibrary* library, char* title, char* artist, char* album, int year, int rating) {
  // Create a new music struct
  Music* music = malloc(sizeof(Music));
  music->title = strdup(title);
  music->artist = strdup(artist);
  music->album = strdup(album);
  music->year = year;
  music->rating = rating;

  // Add the music to the library
  library->musics[library->num_musics++] = music;
}

// Function to search for a music in the library
int search_music(MusicLibrary* library, char* title, char* artist, char* album, int year, int rating) {
  // Loop through the library and search for the music
  for (int i = 0; i < library->num_musics; i++) {
    Music* music = library->musics[i];
    if (strcmp(music->title, title) == 0 &&
        strcmp(music->artist, artist) == 0 &&
        strcmp(music->album, album) == 0 &&
        music->year == year &&
        music->rating == rating) {
      return i;
    }
  }
  return -1;
}

// Function to delete a music from the library
void delete_music(MusicLibrary* library, int index) {
  // Free the memory of the music
  Music* music = library->musics[index];
  free(music->title);
  free(music->artist);
  free(music->album);
  free(music);

  // Remove the music from the library
  for (int i = index; i < library->num_musics - 1; i++) {
    library->musics[i] = library->musics[i + 1];
  }
  library->num_musics--;
}

int main() {
  // Create a music library
  MusicLibrary* library = malloc(sizeof(MusicLibrary));
  library->name = strdup("My Music Library");
  library->musics = malloc(sizeof(Music*) * 100);
  library->num_musics = 0;

  // Add some musics to the library
  add_music(library, "My Heart Will Go On", "Celine Dion", "Titanic", 1997, 5);
  add_music(library, "Bohemian Rhapsody", "Queen", "A Night at the Opera", 1975, 5);
  add_music(library, "Stairway to Heaven", "Led Zeppelin", "Led Zeppelin IV", 1971, 5);

  // Search for a music in the library
  int index = search_music(library, "Bohemian Rhapsody", "Queen", "A Night at the Opera", 1975, 5);
  if (index != -1) {
    printf("Found music at index %d\n", index);
  }

  // Delete a music from the library
  delete_music(library, 0);

  // Print the library
  printf("My Music Library:\n");
  for (int i = 0; i < library->num_musics; i++) {
    Music* music = library->musics[i];
    printf("%d. %s - %s (%s, %d, %d)\n", i + 1, music->title, music->artist, music->album, music->year, music->rating);
  }

  // Free the memory of the library
  free(library->name);
  for (int i = 0; i < library->num_musics; i++) {
    Music* music = library->musics[i];
    free(music->title);
    free(music->artist);
    free(music->album);
    free(music);
  }
  free(library->musics);
  free(library);

  return 0;
}