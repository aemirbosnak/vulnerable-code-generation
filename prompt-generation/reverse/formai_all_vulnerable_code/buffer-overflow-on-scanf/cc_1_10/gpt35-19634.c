//FormAI DATASET v1.0 Category: Music Library Management System ; Style: Ken Thompson
/*
C Music Library Management System
By Ken Thompson

This program allows users to manage their music library by adding and deleting songs, and searching for songs

*/

#include <stdio.h>
#include <string.h>

#define MAX_SONGS 100 // Maximum number of songs
#define MAX_LENGTH 50 // Maximum length of song title and artist name

int num_songs = 0; // Current number of songs

// Song structure
struct Song {
  char title[MAX_LENGTH];
  char artist[MAX_LENGTH];
  int year;
};

// Array of songs
struct Song songs[MAX_SONGS];

// Function prototypes
void add_song(); // Add a song to the library
void delete_song(); // Delete a song from the library
void search_songs(); // Search for songs in the library
void print_songs(); // Print all songs in the library

int main() {
  int choice;
  
  do {
    // Print menu
    printf("\n------- Music Library Management System -------");
    printf("\n[1] Add a song");
    printf("\n[2] Delete a song");
    printf("\n[3] Search for songs");
    printf("\n[4] Print all songs");
    printf("\n[5] Exit");
    printf("\nEnter your choice (1-5): ");
    scanf("%d", &choice);
    
    // Call appropriate function
    switch(choice) {
      case 1:
        add_song();
        break;
      case 2:
        delete_song();
        break;
      case 3:
        search_songs();
        break;
      case 4:
        print_songs();
        break;
      case 5:
        printf("\nExiting...\n");
        break;
      default:
        printf("\nInvalid choice. Try again.\n");
    }
  } while (choice != 5);
  
  return 0;
}

// Add a song to the library
void add_song() {
  // Check if maximum number of songs has been reached
  if (num_songs == MAX_SONGS) {
    printf("\nSorry, maximum number of songs reached.\n");
    return;
  }
  
  // Get song details from user
  printf("\nEnter song title: ");
  scanf("%s", songs[num_songs].title);
  printf("Enter artist name: ");
  scanf("%s", songs[num_songs].artist);
  printf("Enter year: ");
  scanf("%d", &songs[num_songs].year);
  
  // Increment number of songs
  num_songs++;
  
  printf("\nSong added successfully.\n");
}

// Delete a song from the library
void delete_song() {
  // Check if library is empty
  if (num_songs == 0) {
    printf("\nLibrary is empty.\n");
    return;
  }
  
  char title[MAX_LENGTH];
  printf("\nEnter song title: ");
  scanf("%s", title);
  
  // Find song in library
  int index = -1;
  for (int i = 0; i < num_songs; i++) {
    if (strcmp(songs[i].title, title) == 0) {
      index = i;
      break;
    }
  }
  
  // Delete song from library
  if (index != -1) {
    for (int i = index; i < num_songs - 1; i++) {
      strcpy(songs[i].title, songs[i+1].title);
      strcpy(songs[i].artist, songs[i+1].artist);
      songs[i].year = songs[i+1].year;
    }
    num_songs--;
    printf("\nSong deleted successfully.\n");
  } else {
    printf("\nSong not found.\n");
  }
}

// Search for songs in the library
void search_songs() {
  // Check if library is empty
  if (num_songs == 0) {
    printf("\nLibrary is empty.\n");
    return;
  }
  
  char keyword[MAX_LENGTH];
  printf("\nEnter keyword: ");
  scanf("%s", keyword);
  
  // Print matching songs
  printf("\nMatching songs:\n");
  for (int i = 0; i < num_songs; i++) {
    if (strstr(songs[i].title, keyword) != NULL || strstr(songs[i].artist, keyword) != NULL) {
      printf("%s (%s, %d)\n", songs[i].title, songs[i].artist, songs[i].year);
    }
  }
}

// Print all songs in the library
void print_songs() {
  // Check if library is empty
  if (num_songs == 0) {
    printf("\nLibrary is empty.\n");
    return;
  }
  
  // Print all songs
  printf("\nAll songs:\n");
  for (int i = 0; i < num_songs; i++) {
    printf("%s (%s, %d)\n", songs[i].title, songs[i].artist, songs[i].year);
  }
}