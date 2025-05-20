//FormAI DATASET v1.0 Category: Music Library Management System ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define struct to store album information
typedef struct Album {
  char artist[50];
  char title[50];
  int year;
} Album;

// Function to display array of albums
void displayAlbums(Album arr[], int size) {
  printf("\nList of Albums:\n");
  for (int i = 0; i < size; i++) {
    printf("Album %d\n", i+1);
    printf("Artist: %s\n", arr[i].artist);
    printf("Title: %s\n", arr[i].title);
    printf("Year: %d\n", arr[i].year);
    printf("\n");
  }
}

// Function to add new album to array
void addAlbum(Album arr[], int size) {
  Album newAlbum;
  printf("Enter album artist: ");
  scanf("%s", newAlbum.artist);
  printf("Enter album title: ");
  scanf("%s", newAlbum.title);
  printf("Enter album year: ");
  scanf("%d", &newAlbum.year);
  arr[size] = newAlbum;
  printf("\nAlbum added successfully!\n");
}

// Function to delete album from array
void deleteAlbum(Album arr[], int size) {
  int index;
  printf("Enter index of album to delete: ");
  scanf("%d", &index);
  // Shift all elements after index to fill the gap
  for (int i = index; i < size; i++) {
    arr[i] = arr[i+1];
  }
  printf("\nAlbum deleted successfully!\n");
}

int main() {
  int choice, size = 0;
  // Initialize array of albums
  Album albums[100];

  while (1) {
    // Display menu options
    printf("\nOptions:\n");
    printf("1. Display list of albums\n");
    printf("2. Add new album\n");
    printf("3. Delete album\n");
    printf("4. Quit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        displayAlbums(albums, size);
        break;
      case 2:
        addAlbum(albums, size);
        size++;
        break;
      case 3:
        deleteAlbum(albums, size);
        size--;
        break;
      case 4:
        printf("\nThanks for using the Music Library Management System!\n\n");
        exit(0);
        break;
      default:
        printf("\nInvalid input, please try again.\n");
    }
  }

  return 0;
}