//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

// Define a structure for a music track
typedef struct MusicTrack {
  char title[50];
  char artist[50];
  char genre[50];
  int year;
  struct MusicTrack* next;
} MusicTrack;

// Function to insert a track at the end
void insertTrack(MusicTrack** head) {
  MusicTrack* newTrack = (MusicTrack*)malloc(sizeof(MusicTrack));
  printf("Enter track title: ");
  scanf("%s", newTrack->title);
  printf("Enter artist: ");
  scanf("%s", newTrack->artist);
  printf("Enter genre: ");
  scanf("%s", newTrack->genre);
  printf("Enter year: ");
  scanf("%d", &newTrack->year);

  if (*head == NULL) {
    *head = newTrack;
  } else {
    (*head)->next = newTrack;
  }
}

// Function to display all tracks
void displayTracks(MusicTrack* head) {
  while (head) {
    printf("%s - %s (%d) - %s\n", head->title, head->artist, head->year, head->genre);
    head = head->next;
  }
}

// Function to search for a track
void searchTrack(MusicTrack* head) {
  char searchTerm[50];
  printf("Enter search term: ");
  scanf("%s", searchTerm);

  while (head) {
    if (strstr(head->title, searchTerm) || strstr(head->artist, searchTerm) || strstr(head->genre, searchTerm)) {
      printf("%s - %s (%d) - %s\n", head->title, head->artist, head->year, head->genre);
    }
    head = head->next;
  }
}

int main() {
  MusicTrack* head = NULL;

  // Insert some tracks
  insertTrack(&head);
  insertTrack(&head);
  insertTrack(&head);

  // Display all tracks
  displayTracks(head);

  // Search for a track
  searchTrack(head);

  return 0;
}