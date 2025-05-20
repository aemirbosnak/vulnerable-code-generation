//FormAI DATASET v1.0 Category: Music Library Management System ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define struct for storing details of a music library entry
struct MusicLibraryEntry {
  int id;
  char title[100];
  char artist[100];
  char album[100];
  int year;
};

// Declare functions to handle library entries
void addEntry(struct MusicLibraryEntry library[], int *entryCount);
void editEntry(struct MusicLibraryEntry library[], int entryCount);
void deleteEntry(struct MusicLibraryEntry library[], int *entryCount);
void displayLibrary(struct MusicLibraryEntry library[], int entryCount);

// Main function
int main() {
  int entryCount = 0; // Variable to store the number of entries in the library
  struct MusicLibraryEntry library[100]; // Array of struct to store the library entries
  int userChoice; // Variable to store user's choice in the menu
  
  // Display menu and prompt user for choice
  while(1) {
    printf("\nWelcome to the Music Library Management System!\n");
    printf("1. Add new entry\n");
    printf("2. Edit existing entry\n");
    printf("3. Delete entry\n");
    printf("4. Display library\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &userChoice);
    
    switch(userChoice) {
      case 1:
        addEntry(library, &entryCount);
        break;
      case 2:
        editEntry(library, entryCount);
        break;
      case 3:
        deleteEntry(library, &entryCount);
        break;
      case 4:
        displayLibrary(library, entryCount);
        break;
      case 5:
        printf("Thank you for using the Music Library Management System!\n\n");
        exit(0);
      default:
        printf("Invalid choice. Please enter a valid choice.\n");
    }
  }
  
  return 0;
}

// Function to add a new entry to the library
void addEntry(struct MusicLibraryEntry library[], int *entryCount) {
  struct MusicLibraryEntry newEntry; // Declare struct to store new entry details
  char buffer[100]; // Declare char array for input buffer
  
  // Prompt user for new entry details
  printf("\nEnter details for new entry:\n");
  printf("Title: ");
  fgets(buffer, 100, stdin); // Consume newline character from previous scanf call
  fgets(newEntry.title, 100, stdin);
  printf("Artist: ");
  fgets(newEntry.artist, 100, stdin);
  printf("Album: ");
  fgets(newEntry.album, 100, stdin);
  printf("Year: ");
  scanf("%d", &newEntry.year);
  
  // Add new entry to library and update entry count
  newEntry.id = (*entryCount) + 1;
  library[*entryCount] = newEntry;
  (*entryCount)++;
  
  printf("New entry added successfully!\n");
}

// Function to edit an existing entry in the library
void editEntry(struct MusicLibraryEntry library[], int entryCount) {
  int idToEdit; // Variable to store ID of entry to edit
  int i; // Loop variable
  char buffer[100]; // Declare char array for input buffer
  
  // Prompt user for ID of entry to edit
  printf("\nEnter ID of entry to edit: ");
  scanf("%d", &idToEdit);
  
  // Find entry with specified ID and prompt user for new details
  for(i=0; i<entryCount; i++) {
    if(library[i].id == idToEdit) {
      printf("\nEnter new details for entry with ID %d:\n", idToEdit);
      printf("Title: ");
      fgets(buffer, 100, stdin); // Consume newline character from previous scanf call
      fgets(library[i].title, 100, stdin);
      printf("Artist: ");
      fgets(library[i].artist, 100, stdin);
      printf("Album: ");
      fgets(library[i].album, 100, stdin);
      printf("Year: ");
      scanf("%d", &library[i].year);
      printf("Entry with ID %d updated successfully!\n", idToEdit);
      return;
    }
  }
  
  printf("Entry with ID %d not found.\n", idToEdit);
}

// Function to delete an entry from the library
void deleteEntry(struct MusicLibraryEntry library[], int *entryCount) {
  int idToDelete; // Variable to store ID of entry to delete
  int i, j; // Loop variables
  
  // Prompt user for ID of entry to delete
  printf("\nEnter ID of entry to delete: ");
  scanf("%d", &idToDelete);
  
  // Find entry with specified ID, shift remaining entries and update entry count
  for(i=0; i<(*entryCount); i++) {
    if(library[i].id == idToDelete) {
      for(j=i; j<((*entryCount)-1); j++) {
        library[j] = library[j+1];
        library[j].id--;
      }
      (*entryCount)--;
      printf("Entry with ID %d deleted successfully!\n", idToDelete);
      return;
    }
  }
  
  printf("Entry with ID %d not found.\n", idToDelete);
}

// Function to display the entire music library
void displayLibrary(struct MusicLibraryEntry library[], int entryCount) {
  int i; // Loop variable
  
  // Print table headers
  printf("\nID  TITLE                                        ARTIST                                       ALBUM                                        YEAR\n");
  printf("-----------------------------------------------------------------------------------------------------------\n");
  
  // Print details of each entry in the library
  for(i=0; i<entryCount; i++) {
    printf("%-4d", library[i].id);
    printf("%-44s", library[i].title);
    printf("%-44s", library[i].artist);
    printf("%-44s", library[i].album);
    printf("%-4d", library[i].year);
    printf("\n");
  }
}