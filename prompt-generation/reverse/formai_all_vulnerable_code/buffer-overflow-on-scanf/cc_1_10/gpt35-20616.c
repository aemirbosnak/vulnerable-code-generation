//FormAI DATASET v1.0 Category: Music Library Management System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LIBRARY_SIZE 100

typedef struct musicAlbum {
  char artist[50];
  char album[50];
  char genre[20];
  int year;
} MusicAlbum;

void addAlbum(MusicAlbum library[], int *size) {
  if (*size >= LIBRARY_SIZE) {
    printf("Sorry, the library is full.\n");
  } else {
    printf("Enter the artist's name: ");
    scanf("%s", library[*size].artist);
    printf("Enter the album's name: ");
    scanf("%s", library[*size].album);
    printf("Enter the album's genre: ");
    scanf("%s", library[*size].genre);
    printf("Enter the year of release: ");
    scanf("%d", &library[*size].year);
    (*size)++;
    printf("The album has been added to the library.\n");
  }
}

void searchAlbum(MusicAlbum library[], int size) {
  char searchAlbum[50];
  printf("Enter the album's name: ");
  scanf("%s", searchAlbum);
  printf("Search results:\n");
  for (int i = 0; i < size; i++) {
    if (strcmp(library[i].album, searchAlbum) == 0) {
      printf("Artist: %s\n", library[i].artist);
      printf("Album: %s\n", library[i].album);
      printf("Genre: %s\n", library[i].genre);
      printf("Year of release: %d\n", library[i].year);
      return;
    }
  }
  printf("Sorry, the album was not found in the library.\n");
}

void displayLibrary(MusicAlbum library[], int size) {
  printf("Music Library:\n");
  for (int i = 0; i < size; i++) {
    printf("Artist: %s\n", library[i].artist);
    printf("Album: %s\n", library[i].album);
    printf("Genre: %s\n", library[i].genre);
    printf("Year of release: %d\n", library[i].year);
    printf("\n");
  }
}

int main() {
  MusicAlbum library[LIBRARY_SIZE];
  int size = 0;
  int choice;

  printf("Welcome to the Music Library Management System!\n");

  while(1) {
    printf("\nMenu:\n1. Add an album\n2. Search for an album\n3. Display the library\n4. Quit\nEnter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
      case 1:
        addAlbum(library, &size);
        break;

      case 2:
        searchAlbum(library, size);
        break;

      case 3:
        displayLibrary(library, size);
        break;

      case 4:
        printf("Thank you for using the Music Library Management System!\n");
        exit(0);

      default:
        printf("Sorry, that is not a valid choice.\n");
    }
  }

  return 0;
}