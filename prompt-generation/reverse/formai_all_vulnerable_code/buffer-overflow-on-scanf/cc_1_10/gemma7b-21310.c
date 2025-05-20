//Gemma-7B DATASET v1.0 Category: Digital Diary ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of entries
#define MAX_ENTRIES 10

// Define the structure of an entry
typedef struct Entry {
  char title[50];
  char content[200];
  struct Entry* next;
} Entry;

// Create a linked list of entries
Entry* head = NULL;

// Function to add an entry to the list
void addEntry() {
  // Allocate memory for the new entry
  Entry* newEntry = (Entry*)malloc(sizeof(Entry));

  // Get the title and content of the entry
  printf("Enter the title of the entry:");
  scanf("%s", newEntry->title);

  printf("Enter the content of the entry:");
  scanf("%s", newEntry->content);

  // Add the new entry to the list
  if (head == NULL) {
    head = newEntry;
  } else {
    newEntry->next = head;
    head = newEntry;
  }
}

// Function to display all entries
void displayEntries() {
  // Traverse the list of entries
  Entry* currentEntry = head;
  while (currentEntry) {
    // Print the title and content of the entry
    printf("Title: %s\n", currentEntry->title);
    printf("Content: %s\n", currentEntry->content);
    printf("\n");
    currentEntry = currentEntry->next;
  }
}

// Function to delete an entry
void deleteEntry() {
  // Get the title of the entry to be deleted
  char title[50];
  printf("Enter the title of the entry to be deleted:");
  scanf("%s", title);

  // Search for the entry to be deleted
  Entry* previousEntry = NULL;
  Entry* currentEntry = head;
  while (currentEntry) {
    if (strcmp(currentEntry->title, title) == 0) {
      // Delete the entry
      if (previousEntry) {
        previousEntry->next = currentEntry->next;
      } else {
        head = currentEntry->next;
      }
      free(currentEntry);
      return;
    }
    previousEntry = currentEntry;
    currentEntry = currentEntry->next;
  }

  // Entry not found
  printf("Entry not found.\n");
}

// Main loop
int main() {
  // Menu options
  int choice;

  // Display the menu
  printf("Welcome to your digital diary.\n");
  printf("Please select an option:\n");
  printf("1. Add Entry\n");
  printf("2. Display Entries\n");
  printf("3. Delete Entry\n");
  printf("4. Exit\n");

  // Get the user's choice
  scanf("%d", &choice);

  // Switch case to handle the user's choice
  switch (choice) {
    case 1:
      addEntry();
      break;
    case 2:
      displayEntries();
      break;
    case 3:
      deleteEntry();
      break;
    case 4:
      exit(0);
      break;
    default:
      printf("Invalid choice.\n");
  }

  // Return to the main loop
  main();
}