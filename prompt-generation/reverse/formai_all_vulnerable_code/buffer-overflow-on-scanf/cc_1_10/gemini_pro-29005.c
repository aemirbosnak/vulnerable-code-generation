//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store the details of a music track
typedef struct {
  char title[50];
  char artist[50];
  char album[50];
  int year;
  int track_number;
} Track;

// Function to add a new track to the library
void add_track(Track** library, int* num_tracks) {
  // Allocate memory for the new track
  Track* new_track = malloc(sizeof(Track));

  // Get the details of the new track from the user
  printf("Enter the title of the track: ");
  scanf("%s", new_track->title);
  printf("Enter the artist of the track: ");
  scanf("%s", new_track->artist);
  printf("Enter the album of the track: ");
  scanf("%s", new_track->album);
  printf("Enter the year the track was released: ");
  scanf("%d", &new_track->year);
  printf("Enter the track number: ");
  scanf("%d", &new_track->track_number);

  // Add the new track to the library
  library[*num_tracks] = new_track;
  *num_tracks = *num_tracks + 1;
}

// Function to search for a track in the library
void search_track(Track** library, int num_tracks) {
  // Get the search term from the user
  char search_term[50];
  printf("Enter the search term: ");
  scanf("%s", search_term);

  // Search for the track
  int found = 0;
  for (int i = 0; i < num_tracks; i++) {
    if (strcmp(search_term, library[i]->title) == 0 || strcmp(search_term, library[i]->artist) == 0 || strcmp(search_term, library[i]->album) == 0) {
      // Track found
      printf("Title: %s\n", library[i]->title);
      printf("Artist: %s\n", library[i]->artist);
      printf("Album: %s\n", library[i]->album);
      printf("Year: %d\n", library[i]->year);
      printf("Track number: %d\n", library[i]->track_number);
      found = 1;
      break;
    }
  }

  // If the track was not found, print an error message
  if (!found) {
    printf("Track not found.\n");
  }
}

// Function to print the entire library
void print_library(Track** library, int num_tracks) {
  // Print the details of each track in the library
  for (int i = 0; i < num_tracks; i++) {
    printf("Title: %s\n", library[i]->title);
    printf("Artist: %s\n", library[i]->artist);
    printf("Album: %s\n", library[i]->album);
    printf("Year: %d\n", library[i]->year);
    printf("Track number: %d\n\n", library[i]->track_number);
  }
}

// Main function
int main() {
  // Initialize the library
  Track* library[100];
  int num_tracks = 0;

  // Add some tracks to the library
  add_track(library, &num_tracks);
  add_track(library, &num_tracks);
  add_track(library, &num_tracks);

  // Search for a track in the library
  search_track(library, num_tracks);

  // Print the entire library
  print_library(library, num_tracks);

  return 0;
}