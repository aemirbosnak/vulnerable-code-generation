//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 1000

// Structure to represent a diary entry
typedef struct {
  time_t timestamp;
  char entry[MAX_ENTRY_LENGTH];
} DiaryEntry;

// Global array to store the diary entries
DiaryEntry diary[MAX_ENTRIES];

// Function to add a new entry to the diary
void add_entry(char *entry) {
  // Get the current time
  time_t timestamp = time(NULL);

  // Find the first empty slot in the diary array
  int i;
  for (i = 0; i < MAX_ENTRIES; i++) {
    if (diary[i].timestamp == 0) {
      break;
    }
  }

  // If there are no empty slots, print an error message and return
  if (i == MAX_ENTRIES) {
    printf("Error: Diary is full.\n");
    return;
  }

  // Copy the entry into the diary array
  strcpy(diary[i].entry, entry);

  // Set the timestamp for the entry
  diary[i].timestamp = timestamp;

  // Print a success message
  printf("Entry added successfully.\n");
}

// Function to print all the entries in the diary
void print_entries() {
  // Iterate over the diary array and print each entry
  int i;
  for (i = 0; i < MAX_ENTRIES; i++) {
    if (diary[i].timestamp != 0) {
      printf("Entry %d:\n", i + 1);
      printf("  Timestamp: %s\n", ctime(&diary[i].timestamp));
      printf("  Entry: %s\n", diary[i].entry);
    }
  }
}

// Main function
int main() {
  // Get the user's input
  char input[100];
  printf("What would you like to do?\n");
  printf("  1. Add a new entry\n");
  printf("  2. Print all entries\n");
  printf("  3. Quit\n");
  printf("> ");
  scanf("%s", input);

  // Call the appropriate function based on the user's input
  if (strcmp(input, "1") == 0) {
    printf("Enter your entry:\n");
    char entry[MAX_ENTRY_LENGTH];
    fgets(entry, MAX_ENTRY_LENGTH, stdin);
    add_entry(entry);
  } else if (strcmp(input, "2") == 0) {
    print_entries();
  } else if (strcmp(input, "3") == 0) {
    printf("Exiting.\n");
    return 0;
  } else {
    printf("Invalid input.\n");
  }

  // Return to the main menu
  main();

  return 0;
}