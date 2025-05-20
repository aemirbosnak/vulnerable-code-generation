//FormAI DATASET v1.0 Category: Music Library Management System ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of char arrays
#define MAX_NAME_LENGTH 50
#define MAX_ARTIST_LENGTH 50
#define MAX_ALBUM_LENGTH 50

// Define the maximum number of songs in the library
#define MAX_SONGS 100

// Struct for a single song
typedef struct {
  char name[MAX_NAME_LENGTH];
  char artist[MAX_ARTIST_LENGTH];
  char album[MAX_ALBUM_LENGTH];
  int duration;
} Song;

// Struct for the music library
typedef struct {
  Song songs[MAX_SONGS];
  int num_songs;
} Library;

// Function prototypes
void add_song(Library* library);
void remove_song(Library* library);
void search_song(Library* library);
void print_library(Library* library);

int main() {
  Library library = {{}, 0}; // Initialize empty library

  // Display main menu
  int selection = 0;
  while (selection != 5) {
    printf("\nMusic Library Management System\n");
    printf("1. Add song\n");
    printf("2. Remove song\n");
    printf("3. Search song\n");
    printf("4. Print library\n");
    printf("5. Quit\n");

    // Get user selection
    printf("\nEnter selection: ");
    scanf("%d", &selection);

    // Call appropriate function based on selection
    switch(selection) {
      case 1: add_song(&library);
              break;
      case 2: remove_song(&library);
              break;
      case 3: search_song(&library);
              break;
      case 4: print_library(&library);
              break;
      case 5: printf("\nGoodbye!\n");
              break;
      default: printf("\nInvalid selection. Please try again.\n");
               break;
    }
  }
  return 0;
}

/* Adds a song to the library */
void add_song(Library* library) {
  Song song;

  // Get song information from user
  printf("\nEnter song name: ");
  fflush(stdin);
  fgets(song.name, MAX_NAME_LENGTH, stdin);
  song.name[strcspn(song.name, "\n")] = 0; // Remove newline character

  printf("Enter artist name: ");
  fflush(stdin);
  fgets(song.artist, MAX_ARTIST_LENGTH, stdin);
  song.artist[strcspn(song.artist, "\n")] = 0; // Remove newline character

  printf("Enter album name: ");
  fflush(stdin);
  fgets(song.album, MAX_ALBUM_LENGTH, stdin);
  song.album[strcspn(song.album, "\n")] = 0; // Remove newline character

  printf("Enter duration (in seconds): ");
  scanf("%d", &song.duration);

  // Add song to library
  if (library->num_songs < MAX_SONGS) {
    library->songs[library->num_songs] = song;
    library->num_songs++;
    printf("\nSong added successfully!\n");
  } else {
    printf("\nMaximum number of songs reached. Unable to add song.\n");
  }
}

/* Removes a song from the library */
void remove_song(Library* library) {
  char target_name[MAX_NAME_LENGTH];
  int found_song = 0;

  // Get song to be removed from user
  printf("\nEnter the name of the song to be removed: ");
  fflush(stdin);
  fgets(target_name, MAX_NAME_LENGTH, stdin);
  target_name[strcspn(target_name, "\n")] = 0; // Remove newline character

  // Iterate over all songs in the library
  for (int i = 0; i < library->num_songs; i++) {
    if (strcmp(library->songs[i].name, target_name) == 0) { // Song found
      // Shift remaining songs down to fill gap
      for (int j = i; j < library->num_songs-1; j++) {
        library->songs[j] = library->songs[j+1];
      }
      library->num_songs--;
      found_song = 1;
      printf("\nSong removed successfully!\n");
      break;
    }
  }

  if (!found_song) {
    printf("\nSong not found. Unable to remove.\n");
  }
}

/* Searches for a song in the library */
void search_song(Library* library) {
  char target_name[MAX_NAME_LENGTH];
  int found_song = 0;

  // Get song to be searched for from user
  printf("\nEnter the name of the song to search for: ");
  fflush(stdin);
  fgets(target_name, MAX_NAME_LENGTH, stdin);
  target_name[strcspn(target_name, "\n")] = 0; // Remove newline character

  // Iterate over all songs in the library
  for (int i = 0; i < library->num_songs; i++) {
    if (strcmp(library->songs[i].name, target_name) == 0) { // Song found
      // Print song information
      printf("\n%s by %s on %s (%d seconds)\n", library->songs[i].name, 
                                                 library->songs[i].artist,
                                                 library->songs[i].album,
                                                 library->songs[i].duration);
      found_song = 1;
      break;
    }
  }

  if (!found_song) {
    printf("\nSong not found.\n");
  }
}

/* Prints all songs in the library */
void print_library(Library* library) {
  // Check if library is empty
  if (library->num_songs == 0) {
    printf("\nNo songs in library.\n");
    return;
  }

  // Print song information for each song in the library
  printf("\nSong Information:\n");
  for (int i = 0; i < library->num_songs; i++) {
    printf("%s by %s on %s (%d seconds)\n", library->songs[i].name, 
                                            library->songs[i].artist,
                                            library->songs[i].album,
                                            library->songs[i].duration);
  }
}