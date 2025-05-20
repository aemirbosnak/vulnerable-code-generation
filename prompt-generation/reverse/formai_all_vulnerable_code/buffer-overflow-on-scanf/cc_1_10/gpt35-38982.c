//FormAI DATASET v1.0 Category: Music Library Management System ; Style: thoughtful
// This program is a music library management system that allows the user to add, remove, and display songs in a playlist. 
// It is a console-based application that uses dynamic memory allocation and linked lists to organize the playlist.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define the Song struct
typedef struct Song {
  char title[100];
  char artist[100];
  int length;
  struct Song *next;
} Song;

// Declare the functions used in the program
void addSong(Song **head);
void removeSong(Song **head);
void displayPlaylist(Song *head);
void displaySong(Song *song);

int main() {
  Song *playlist = NULL; // Initialize the playlist to be empty
  int choice;

  do {
    // Display the menu and get the user's choice
    printf("====== C Music Library Management System ======\n");
    printf("1. Add a song\n");
    printf("2. Remove a song\n");
    printf("3. Display playlist\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
      case 1:
        addSong(&playlist);
        break;
      case 2:
        removeSong(&playlist);
        break;
      case 3:
        displayPlaylist(playlist);
        break;
      case 4:
        printf("Exiting program...\n");
        break;
      default:
        printf("Invalid choice, please try again.\n");
        break;
    }
  } while(choice != 4);

  return 0;
}

// Function to add a song to the playlist
void addSong(Song **head) {
  char title[100];
  char artist[100];
  int length;

  // Get the song information from the user
  printf("Enter the song title: ");
  scanf("%s", title);
  printf("Enter the artist name: ");
  scanf("%s", artist);
  printf("Enter the song length in seconds: ");
  scanf("%d", &length);

  // Create a new Song struct
  Song *newSong = (Song*)malloc(sizeof(Song));
  strcpy(newSong->title, title);
  strcpy(newSong->artist, artist);
  newSong->length = length;
  newSong->next = NULL;

  // Add the new song to the end of the playlist
  if(*head == NULL) {
    *head = newSong;
  } else {
    Song *cur = *head;
    while(cur->next != NULL) {
      cur = cur->next;
    }
    cur->next = newSong;
  }

  printf("Song added to playlist!\n");
}

// Function to remove a song from the playlist
void removeSong(Song **head) {
  char title[100];
  printf("Enter the title of the song you want to remove: ");
  scanf("%s", title);

  Song *cur = *head;
  Song *prev = NULL;

  // Traverse the playlist to find the song to remove
  while(cur != NULL && strcmp(cur->title, title) != 0) {
    prev = cur;
    cur = cur->next;
  }

  // Remove the song if it was found
  if(cur != NULL) {
    if(prev != NULL) {
      prev->next = cur->next;
    } else {
      *head = cur->next;
    }
    free(cur);
    printf("Song removed from playlist!\n");
  } else {
    printf("Song not found in playlist.\n");
  } 
}

// Function to display the entire playlist
void displayPlaylist(Song *head) {
  if(head == NULL) {
    printf("The playlist is empty!\n");
    return;
  }

  Song *cur = head;
  int i = 1;

  // Traverse the playlist and display each song
  while(cur != NULL) {
    printf("Song %d:\n", i);
    displaySong(cur);
    cur = cur->next;
    i++;
  }
}

// Function to display a single song
void displaySong(Song *song) {
  printf("Title: %s\n", song->title);
  printf("Artist: %s\n", song->artist);
  printf("Length: %d seconds\n", song->length);
}