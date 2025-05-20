//Code Llama-13B DATASET v1.0 Category: Music Library Management System ; Style: safe
/*
 * Unique C Music Library Management System Example Program
 *
 * This program is an example of a simple music library management system
 * that allows users to add, delete, and modify music tracks.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store music track information
struct track {
  char title[50];
  char artist[50];
  int duration;
};

// Function to add a new track to the library
void add_track(struct track* library, int* size) {
  // Ask the user to enter the title and artist of the track
  printf("Enter the title and artist of the new track: ");
  scanf("%s %s", library[*size].title, library[*size].artist);

  // Ask the user to enter the duration of the track
  printf("Enter the duration of the track: ");
  scanf("%d", &library[*size].duration);

  // Increment the size of the library
  (*size)++;
}

// Function to delete a track from the library
void delete_track(struct track* library, int* size, int index) {
  // Check if the index is valid
  if (index < 0 || index >= *size) {
    printf("Invalid index.\n");
    return;
  }

  // Shift the elements after the deleted element to the left
  for (int i = index; i < *size - 1; i++) {
    library[i] = library[i + 1];
  }

  // Decrement the size of the library
  (*size)--;
}

// Function to modify a track in the library
void modify_track(struct track* library, int* size, int index) {
  // Check if the index is valid
  if (index < 0 || index >= *size) {
    printf("Invalid index.\n");
    return;
  }

  // Ask the user to enter the new title and artist of the track
  printf("Enter the new title and artist of the track: ");
  scanf("%s %s", library[index].title, library[index].artist);

  // Ask the user to enter the new duration of the track
  printf("Enter the new duration of the track: ");
  scanf("%d", &library[index].duration);
}

// Function to display the library
void display_library(struct track* library, int size) {
  // Print the title, artist, and duration of each track
  for (int i = 0; i < size; i++) {
    printf("%s by %s (%d minutes)\n", library[i].title, library[i].artist, library[i].duration);
  }
}

int main() {
  // Initialize the library with 100 tracks
  struct track library[100];
  int size = 0;

  // Add 5 tracks to the library
  for (int i = 0; i < 5; i++) {
    add_track(library, &size);
  }

  // Delete the track at index 2
  delete_track(library, &size, 2);

  // Modify the track at index 3
  modify_track(library, &size, 3);

  // Display the library
  display_library(library, size);

  return 0;
}