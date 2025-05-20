//Code Llama-13B DATASET v1.0 Category: Music Library Management System ; Style: brave
// Brave Music Library Management System
// Developed by @BraveCoders

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for storing songs
typedef struct {
  char title[100];
  char artist[100];
  char genre[100];
  int year;
  float length;
} Song;

// Function to display the menu
void displayMenu() {
  printf("Welcome to the Brave Music Library Management System!\n");
  printf("Please select an option:\n");
  printf("1. Add song\n");
  printf("2. Display songs\n");
  printf("3. Search song\n");
  printf("4. Remove song\n");
  printf("5. Exit\n");
}

// Function to add a song
void addSong(Song *songs, int *numSongs) {
  // Ask for song details
  printf("Enter the song title: ");
  scanf("%s", &songs[*numSongs].title);
  printf("Enter the artist name: ");
  scanf("%s", &songs[*numSongs].artist);
  printf("Enter the genre: ");
  scanf("%s", &songs[*numSongs].genre);
  printf("Enter the year: ");
  scanf("%d", &songs[*numSongs].year);
  printf("Enter the length (in minutes): ");
  scanf("%f", &songs[*numSongs].length);
  // Increment the number of songs
  (*numSongs)++;
}

// Function to display songs
void displaySongs(Song *songs, int numSongs) {
  // Display the header
  printf("Song Title\tArtist\tGenre\tYear\tLength\n");
  for (int i = 0; i < numSongs; i++) {
    printf("%s\t%s\t%s\t%d\t%.2f\n", songs[i].title, songs[i].artist, songs[i].genre, songs[i].year, songs[i].length);
  }
}

// Function to search for a song
void searchSong(Song *songs, int numSongs) {
  // Ask for the song title
  printf("Enter the song title: ");
  char title[100];
  scanf("%s", title);
  // Check if the song is present in the library
  for (int i = 0; i < numSongs; i++) {
    if (strcmp(songs[i].title, title) == 0) {
      printf("Song found: %s - %s\n", songs[i].title, songs[i].artist);
      return;
    }
  }
  printf("Song not found.\n");
}

// Function to remove a song
void removeSong(Song *songs, int *numSongs) {
  // Ask for the song title
  printf("Enter the song title: ");
  char title[100];
  scanf("%s", title);
  // Check if the song is present in the library
  for (int i = 0; i < *numSongs; i++) {
    if (strcmp(songs[i].title, title) == 0) {
      // Remove the song
      for (int j = i; j < *numSongs - 1; j++) {
        songs[j] = songs[j + 1];
      }
      (*numSongs)--;
      printf("Song removed: %s - %s\n", songs[i].title, songs[i].artist);
      return;
    }
  }
  printf("Song not found.\n");
}

int main() {
  // Initialize the number of songs
  int numSongs = 0;
  // Declare an array to store songs
  Song songs[100];

  // Display the menu
  displayMenu();

  // Loop until the user selects option 5
  int option;
  do {
    // Ask for the user's option
    printf("Enter your option: ");
    scanf("%d", &option);
    // Perform the selected action
    switch (option) {
      case 1:
        addSong(songs, &numSongs);
        break;
      case 2:
        displaySongs(songs, numSongs);
        break;
      case 3:
        searchSong(songs, numSongs);
        break;
      case 4:
        removeSong(songs, &numSongs);
        break;
      case 5:
        break;
      default:
        printf("Invalid option. Please try again.\n");
        break;
    }
  } while (option != 5);

  return 0;
}