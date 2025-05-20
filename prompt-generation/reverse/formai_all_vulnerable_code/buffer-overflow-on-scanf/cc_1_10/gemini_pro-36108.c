//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Structure to represent a diary entry
typedef struct {
  char date[11];
  char time[9];
  char title[51];
  char entry[1001];
} DiaryEntry;

// Array to store diary entries
DiaryEntry entries[100];
int numEntries = 0;

// Function to add a new diary entry
void addEntry() {
  // Get the current date and time
  time_t rawtime;
  struct tm *timeinfo;
  time(&rawtime);
  timeinfo = localtime(&rawtime);
  strftime(entries[numEntries].date, sizeof(entries[numEntries].date), "%Y-%m-%d", timeinfo);
  strftime(entries[numEntries].time, sizeof(entries[numEntries].time), "%H:%M:%S", timeinfo);

  // Get the title and entry from the user
  printf("Enter title: ");
  gets(entries[numEntries].title);
  printf("Enter entry: ");
  gets(entries[numEntries].entry);

  // Increment the number of entries
  numEntries++;
}

// Function to view a diary entry
void viewEntry(int index) {
  // Check if the index is valid
  if (index < 0 || index >= numEntries) {
    printf("Invalid index\n");
    return;
  }

  // Print the diary entry
  printf("Date: %s\n", entries[index].date);
  printf("Time: %s\n", entries[index].time);
  printf("Title: %s\n", entries[index].title);
  printf("Entry: %s\n", entries[index].entry);
}

// Function to edit a diary entry
void editEntry(int index) {
  // Check if the index is valid
  if (index < 0 || index >= numEntries) {
    printf("Invalid index\n");
    return;
  }

  // Get the new title and entry from the user
  printf("Enter new title: ");
  gets(entries[index].title);
  printf("Enter new entry: ");
  gets(entries[index].entry);
}

// Function to delete a diary entry
void deleteEntry(int index) {
  // Check if the index is valid
  if (index < 0 || index >= numEntries) {
    printf("Invalid index\n");
    return;
  }

  // Shift the entries after the deleted entry to the left
  for (int i = index; i < numEntries - 1; i++) {
    entries[i] = entries[i + 1];
  }

  // Decrement the number of entries
  numEntries--;
}

// Function to print the menu
void printMenu() {
  printf("1. Add entry\n");
  printf("2. View entry\n");
  printf("3. Edit entry\n");
  printf("4. Delete entry\n");
  printf("5. Quit\n");
}

// Main function
int main() {
  // Initialize the diary
  numEntries = 0;

  // Main loop
  int choice;
  do {
    // Print the menu
    printMenu();

    // Get the user's choice
    printf("Enter your choice: ");
    scanf("%d", &choice);

    // Call the appropriate function based on the user's choice
    switch (choice) {
      case 1:
        addEntry();
        break;
      case 2:
        printf("Enter index: ");
        int index;
        scanf("%d", &index);
        viewEntry(index);
        break;
      case 3:
        printf("Enter index: ");
        scanf("%d", &index);
        editEntry(index);
        break;
      case 4:
        printf("Enter index: ");
        scanf("%d", &index);
        deleteEntry(index);
        break;
      case 5:
        printf("Quitting...\n");
        break;
      default:
        printf("Invalid choice\n");
    }
  } while (choice != 5);

  return 0;
}