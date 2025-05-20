//FormAI DATASET v1.0 Category: Music Library Management System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Music library structure
struct musicLibrary {
  char title[50];
  char artist[50];
  int year;
  char genre[20];
};

// Function declarations
void addSong(struct musicLibrary** libptr, int* sizeptr);
void displayLibrary(struct musicLibrary** libptr, int* sizeptr);
void searchByTitle(struct musicLibrary** libptr, int* sizeptr);
void searchByArtist(struct musicLibrary** libptr, int* sizeptr);
void searchByYear(struct musicLibrary** libptr, int* sizeptr);
void searchByGenre(struct musicLibrary** libptr, int* sizeptr);
void deleteSong(struct musicLibrary** libptr, int* sizeptr);

int main() {
  struct musicLibrary* library = NULL; // Declare pointer to array of struct musicLibrary
  int size = 0; // Store current size of the library
  int choice; // Store user's menu choice

  while(1) {
    // Display menu to user
    printf("\n---- Music Library Menu ----\n");
    printf("1. Add Song\n");
    printf("2. Display Library\n");
    printf("3. Search by Title\n");
    printf("4. Search by Artist\n");
    printf("5. Search by Year\n");
    printf("6. Search by Genre\n");
    printf("7. Delete Song\n");
    printf("8. Quit\n");
    printf("---------------------------\n");

    printf("Enter your choice (1-8): ");
    scanf("%d", &choice);

    switch(choice) {
      case 1:
        addSong(&library, &size); // Pass address of pointer and size variable to function
        break;
      case 2:
        displayLibrary(&library, &size); // Pass address of pointer and size variable to function
        break;
      case 3:
        searchByTitle(&library, &size); // Pass address of pointer and size variable to function
        break;
      case 4:
        searchByArtist(&library, &size); // Pass address of pointer and size variable to function
        break;
      case 5:
        searchByYear(&library, &size); // Pass address of pointer and size variable to function
        break;
      case 6:
        searchByGenre(&library, &size); // Pass address of pointer and size variable to function
        break;
      case 7:
        deleteSong(&library, &size); // Pass address of pointer and size variable to function
        break;
      case 8:
        printf("\nThank you for using the Music Library Management System!\n");
        exit(0); // Exit program
      default:
        printf("\nInvalid choice. Please enter a number from 1 to 8.\n");
        break;
    }
  }

  return 0;
}

// Function to add a song to the library
void addSong(struct musicLibrary** libptr, int* sizeptr) {
  struct musicLibrary song; // Declare struct variable to hold new song details

  printf("\nEnter the following details for the new song:");
  printf("\nTitle: ");
  scanf("%s", song.title);
  printf("Artist: ");
  scanf("%s", song.artist);
  printf("Year: ");
  scanf("%d", &song.year);
  printf("Genre: ");
  scanf("%s", song.genre);

  // Allocate memory for new song in library
  *libptr = (struct musicLibrary*) realloc(*libptr, (*sizeptr + 1) * sizeof(struct musicLibrary));

  // Copy new song details to the last element of the library
  strcpy((*libptr)[*sizeptr].title, song.title);
  strcpy((*libptr)[*sizeptr].artist, song.artist); 
  (*libptr)[*sizeptr].year = song.year;
  strcpy((*libptr)[*sizeptr].genre, song.genre);

  (*sizeptr)++; // Increment size of the library
  printf("\nSong added successfully!\n");
}

// Function to display the library
void displayLibrary(struct musicLibrary** libptr, int* sizeptr) {
  if(*sizeptr == 0) { // Check if library is empty
    printf("\nLibrary is empty. Please add a song.\n");
    return;
  }

  printf("\n---- Music Library ----\n");
  printf("%-25s %-25s %-10s %-15s\n", "Title", "Artist", "Year", "Genre");
  for(int i = 0; i < *sizeptr; i++) {
    printf("%-25s %-25s %-10d %-15s\n", (*libptr)[i].title, (*libptr)[i].artist, (*libptr)[i].year, (*libptr)[i].genre);
  }
}

// Function to search for a song by Title
void searchByTitle(struct musicLibrary** libptr, int* sizeptr) {
  char searchTitle[50]; // Declare variable to store search term
  int foundFlag = 0; // Flag to store if any song was found

  printf("\nEnter the title of the song to search: ");
  scanf("%s", searchTitle);

  for(int i = 0; i < *sizeptr; i++) {
    if(strcmp((*libptr)[i].title, searchTitle) == 0) {
      printf("\nSong found:\n");
      printf("Title: %s\nArtist: %s\nYear: %d\nGenre: %s\n", (*libptr)[i].title, (*libptr)[i].artist, (*libptr)[i].year, (*libptr)[i].genre);
      
      foundFlag = 1;
    }
  }

  if(foundFlag == 0) {
    printf("\nSorry, song not found.\n");
  }
}

// Function to search for a song by Artist
void searchByArtist(struct musicLibrary** libptr, int* sizeptr) {
  char searchArtist[50]; // Declare variable to store search term
  int foundFlag = 0; // Flag to store if any song was found

  printf("\nEnter the artist of the song to search: ");
  scanf("%s", searchArtist);

  for(int i = 0; i < *sizeptr; i++) {
    if(strcmp((*libptr)[i].artist, searchArtist) == 0) {
      printf("\nSong found:\n");
      printf("Title: %s\nArtist: %s\nYear: %d\nGenre: %s\n", (*libptr)[i].title, (*libptr)[i].artist, (*libptr)[i].year, (*libptr)[i].genre);
      
      foundFlag = 1;
    }
  }

  if(foundFlag == 0) {
    printf("\nSorry, song not found.\n");
  }
}

// Function to search for a song by Year
void searchByYear(struct musicLibrary** libptr, int* sizeptr) {
  int searchYear; // Declare variable to store search term
  int foundFlag = 0; // Flag to store if any song was found

  printf("\nEnter the year of the song to search: ");
  scanf("%d", &searchYear);

  for(int i = 0; i < *sizeptr; i++) {
    if((*libptr)[i].year == searchYear) {
      printf("\nSong found:\n");
      printf("Title: %s\nArtist: %s\nYear: %d\nGenre: %s\n", (*libptr)[i].title, (*libptr)[i].artist, (*libptr)[i].year, (*libptr)[i].genre);
      
      foundFlag = 1;
    }
  }

  if(foundFlag == 0) {
    printf("\nSorry, song not found.\n");
  }
}

// Function to search for a song by Genre
void searchByGenre(struct musicLibrary** libptr, int* sizeptr) {
  char searchGenre[20]; // Declare variable to store search term
  int foundFlag = 0; // Flag to store if any song was found

  printf("\nEnter the genre of the song to search: ");
  scanf("%s", searchGenre);

  for(int i = 0; i < *sizeptr; i++) {
    if(strcmp((*libptr)[i].genre, searchGenre) == 0) {
      printf("\nSong found:\n");
      printf("Title: %s\nArtist: %s\nYear: %d\nGenre: %s\n", (*libptr)[i].title, (*libptr)[i].artist, (*libptr)[i].year, (*libptr)[i].genre);
      
      foundFlag = 1;
    }
  }

  if(foundFlag == 0) {
    printf("\nSorry, song not found.\n");
  }
}

// Function to delete a song from the library
void deleteSong(struct musicLibrary** libptr, int* sizeptr) {
  char deleteTitle[50]; // Declare variable to store title of song to delete
  int deleteIndex = -1; // Store index of song to delete
  struct musicLibrary temp; // Declare temporary struct to hold values during deletion

  printf("\nEnter the title of the song to delete: ");
  scanf("%s", deleteTitle);

  for(int i = 0; i < *sizeptr; i++) {
    if(strcmp((*libptr)[i].title, deleteTitle) == 0) {
      deleteIndex = i;
      break;
    }
  }

  if(deleteIndex == -1) { // Check if song to delete was found
    printf("\nSorry, song not found.\n");
    return;
  }

  // Shift elements of library to overwrite deleted song
  for(int i = deleteIndex; i < *sizeptr - 1; i++) {
    temp = (*libptr)[i];
    (*libptr)[i] = (*libptr)[i + 1];
    (*libptr)[i + 1] = temp;
  }

  // Reduce size of library by 1
  *libptr = (struct musicLibrary*) realloc(*libptr, (*sizeptr - 1) * sizeof(struct musicLibrary));
  (*sizeptr)--;
  
  printf("\nSong deleted successfully!\n");
}