//Code Llama-13B DATASET v1.0 Category: Music Library Management System ; Style: happy
// Music Library Management System in C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Structure to store information about a song
struct Song {
  char title[50];
  char artist[50];
  char album[50];
  int year;
  float duration;
};

// Function to add a new song to the library
void addSong(struct Song library[], int *size) {
  printf("Enter the song title: ");
  scanf("%s", library[*size].title);
  printf("Enter the artist name: ");
  scanf("%s", library[*size].artist);
  printf("Enter the album name: ");
  scanf("%s", library[*size].album);
  printf("Enter the year released: ");
  scanf("%d", &library[*size].year);
  printf("Enter the duration (in minutes): ");
  scanf("%f", &library[*size].duration);
  *size += 1;
}

// Function to display all songs in the library
void displayAllSongs(struct Song library[], int size) {
  printf("Song Listing:\n");
  for (int i = 0; i < size; i++) {
    printf("%d. %s by %s (%s, %d, %.2f minutes)\n", i + 1, library[i].title, library[i].artist, library[i].album, library[i].year, library[i].duration);
  }
}

// Function to search for a song by title
void searchByTitle(struct Song library[], int size) {
  char title[50];
  printf("Enter the song title to search: ");
  scanf("%s", title);
  for (int i = 0; i < size; i++) {
    if (strcmp(library[i].title, title) == 0) {
      printf("%s by %s (%s, %d, %.2f minutes)\n", library[i].title, library[i].artist, library[i].album, library[i].year, library[i].duration);
      return;
    }
  }
  printf("Song not found.\n");
}

// Function to search for a song by artist
void searchByArtist(struct Song library[], int size) {
  char artist[50];
  printf("Enter the artist name to search: ");
  scanf("%s", artist);
  for (int i = 0; i < size; i++) {
    if (strcmp(library[i].artist, artist) == 0) {
      printf("%s by %s (%s, %d, %.2f minutes)\n", library[i].title, library[i].artist, library[i].album, library[i].year, library[i].duration);
    }
  }
  printf("Song not found.\n");
}

// Function to search for a song by album
void searchByAlbum(struct Song library[], int size) {
  char album[50];
  printf("Enter the album name to search: ");
  scanf("%s", album);
  for (int i = 0; i < size; i++) {
    if (strcmp(library[i].album, album) == 0) {
      printf("%s by %s (%s, %d, %.2f minutes)\n", library[i].title, library[i].artist, library[i].album, library[i].year, library[i].duration);
    }
  }
  printf("Song not found.\n");
}

int main() {
  struct Song library[100];
  int size = 0;
  char choice;
  while (1) {
    printf("Welcome to the Music Library Management System\n");
    printf("1. Add a new song\n");
    printf("2. Display all songs\n");
    printf("3. Search by title\n");
    printf("4. Search by artist\n");
    printf("5. Search by album\n");
    printf("6. Exit\n");
    scanf("%c", &choice);
    switch (choice) {
      case '1':
        addSong(library, &size);
        break;
      case '2':
        displayAllSongs(library, size);
        break;
      case '3':
        searchByTitle(library, size);
        break;
      case '4':
        searchByArtist(library, size);
        break;
      case '5':
        searchByAlbum(library, size);
        break;
      case '6':
        return 0;
    }
    printf("\n");
  }
  return 0;
}