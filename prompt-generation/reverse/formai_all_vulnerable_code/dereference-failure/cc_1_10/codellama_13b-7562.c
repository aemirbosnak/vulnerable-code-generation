//Code Llama-13B DATASET v1.0 Category: Music Library Management System ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structure to store song information
struct Song {
  char title[256];
  char artist[256];
  int duration;
};

// Define structure to store song list
struct SongList {
  struct Song* songs;
  int size;
};

// Function to create a new song
struct Song* newSong(char* title, char* artist, int duration) {
  struct Song* song = (struct Song*)malloc(sizeof(struct Song));
  strcpy(song->title, title);
  strcpy(song->artist, artist);
  song->duration = duration;
  return song;
}

// Function to add a song to the list
void addSong(struct SongList* list, struct Song* song) {
  list->songs = (struct Song*)realloc(list->songs, sizeof(struct Song) * (list->size + 1));
  list->songs[list->size] = *song;
  list->size++;
}

// Function to print the list of songs
void printSongList(struct SongList* list) {
  for (int i = 0; i < list->size; i++) {
    printf("%d. %s - %s (%d minutes)\n", i + 1, list->songs[i].title, list->songs[i].artist, list->songs[i].duration);
  }
}

// Function to remove a song from the list
void removeSong(struct SongList* list, int index) {
  if (index < 0 || index >= list->size) {
    return;
  }
  for (int i = index; i < list->size - 1; i++) {
    list->songs[i] = list->songs[i + 1];
  }
  list->size--;
}

// Function to search for a song in the list
struct Song* searchSong(struct SongList* list, char* title) {
  for (int i = 0; i < list->size; i++) {
    if (strcmp(list->songs[i].title, title) == 0) {
      return &list->songs[i];
    }
  }
  return NULL;
}

int main() {
  // Create a new song list
  struct SongList* list = (struct SongList*)malloc(sizeof(struct SongList));
  list->songs = NULL;
  list->size = 0;

  // Add some songs to the list
  addSong(list, newSong("Bohemian Rhapsody", "Queen", 5));
  addSong(list, newSong("Stairway to Heaven", "Led Zeppelin", 9));
  addSong(list, newSong("Hotel California", "Eagles", 9));

  // Print the list of songs
  printSongList(list);

  // Remove a song from the list
  removeSong(list, 1);

  // Search for a song in the list
  struct Song* song = searchSong(list, "Bohemian Rhapsody");
  if (song != NULL) {
    printf("Found song: %s - %s (%d minutes)\n", song->title, song->artist, song->duration);
  } else {
    printf("Song not found\n");
  }

  // Free the list of songs
  free(list);

  return 0;
}