//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store music library details
typedef struct music_library {
  char title[50];
  char artist[50];
  char album[50];
  int year;
  char genre[50];
} music_library;

// Function to add a new song to the music library
void add_song(music_library *library) {
  printf("Enter the title of the song: ");
  scanf("%s", library->title);

  printf("Enter the artist of the song: ");
  scanf("%s", library->artist);

  printf("Enter the album of the song: ");
  scanf("%s", library->album);

  printf("Enter the year the song was released: ");
  scanf("%d", &library->year);

  printf("Enter the genre of the song: ");
  scanf("%s", library->genre);
}

// Function to print the details of a song
void print_song(music_library *library) {
  printf("Title: %s\n", library->title);
  printf("Artist: %s\n", library->artist);
  printf("Album: %s\n", library->album);
  printf("Year: %d\n", library->year);
  printf("Genre: %s\n", library->genre);
}

// Main function
int main() {
  // Create a music library
  music_library library[100];

  // Add songs to the library
  for (int i = 0; i < 10; i++) {
    add_song(&library[i]);
  }

  // Print the details of the songs
  for (int i = 0; i < 10; i++) {
    print_song(&library[i]);
    printf("\n");
  }

  return 0;
}