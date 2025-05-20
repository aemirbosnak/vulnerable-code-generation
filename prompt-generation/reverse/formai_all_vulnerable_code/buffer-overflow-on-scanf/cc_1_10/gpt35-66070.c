//FormAI DATASET v1.0 Category: Music Library Management System ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum size of the music library
#define MAX_SIZE 50

// Define the struct representing a Music object
struct Music {
  int id;
  char title[50];
  char artist[20];
  int releaseYear;
};

// Declare the music library array
struct Music musicLibrary[MAX_SIZE];

// Declare the current size of the music library
int currentSize = 0;

// Implement the function to add new music to the library
void addMusic() {
  // Check if the library is full
  if (currentSize >= MAX_SIZE) {
    printf("The music library is full!\n");
    return;
  }

  // Prompt the user for the details of the new music
  int id;
  char title[50];
  char artist[20];
  int releaseYear;

  printf("Enter the id of the music: ");
  scanf("%d", &id);

  printf("Enter the title of the music: ");
  scanf("%s", title);

  printf("Enter the artist of the music: ");
  scanf("%s", artist);

  printf("Enter the release year of the music: ");
  scanf("%d", &releaseYear);

  // Create a new Music object
  struct Music newMusic;
  newMusic.id = id;
  strcpy(newMusic.title, title);
  strcpy(newMusic.artist, artist);
  newMusic.releaseYear = releaseYear;

  // Add the new Music object to the library
  musicLibrary[currentSize] = newMusic;
  currentSize++;

  printf("The music has been added to the library!\n");
}

// Implement the function to remove music from the library
void removeMusic() {
  // Check if the library is empty
  if (currentSize == 0) {
    printf("The music library is empty!\n");
    return;
  }

  // Prompt the user for the id of the music to be removed
  int id;

  printf("Enter the id of the music to be removed: ");
  scanf("%d", &id);

  // Find the index of the Music object with the specified id
  int index = -1;

  for (int i = 0; i < currentSize; i++) {
    if (musicLibrary[i].id == id) {
      index = i;
      break;
    }
  }

  // If the Music object is not found, print an error message
  if (index == -1) {
    printf("The music with the specified id could not be found!\n");
    return;
  }

  // Remove the Music object from the library
  for (int i = index; i < currentSize - 1; i++) {
    musicLibrary[i] = musicLibrary[i + 1];
  }
  currentSize--;

  printf("The music has been removed from the library!\n");
}

// Implement the function to display all the music in the library
void displayMusic() {
  // Check if the library is empty
  if (currentSize == 0) {
    printf("The music library is empty!\n");
    return;
  }

  // Print a header for the music table
  printf("%-5s %-20s %-20s %-10s\n", "ID", "Title", "Artist", "Year");
  printf("------------------------------------------------------\n");

  for (int i = 0; i < currentSize; i++) {
    struct Music music = musicLibrary[i];

    // Print each music details in a formatted way
    printf("%-5d %-20s %-20s %-10d\n", music.id, music.title, music.artist, music.releaseYear);
  }
}

int main() {
  // Declare the variables
  char command[20];

  // Print the welcome message
  printf("Welcome to the C Music Library Management System!\n");

  // Keep the program running until the user quits
  while (1) {
    // Print the command prompt
    printf("\nEnter a command (ADD, REMOVE, DISPLAY, QUIT): ");
    scanf("%s", command);

    // Determine which command to execute
    if (strcmp(command, "ADD") == 0) {
      addMusic();
    } else if (strcmp(command, "REMOVE") == 0) {
      removeMusic();
    } else if (strcmp(command, "DISPLAY") == 0) {
      displayMusic();
    } else if (strcmp(command, "QUIT") == 0) {
      printf("\nThank you for using the C Music Library Management System!\n");
      break;
    } else {
      printf("Invalid command!\n");
    }
  }

  return 0;
}