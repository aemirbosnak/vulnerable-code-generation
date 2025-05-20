//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of a diary entry
#define MAX_ENTRY_LENGTH 1024

// Define the filename where the diary will be stored
#define DIARY_FILENAME "diary.txt"

// Declare the diary structure
struct Diary {
  char entries[MAX_ENTRY_LENGTH];
  int num_entries;
};

// Declare the diary object
struct Diary diary;

// Function to add an entry to the diary
void add_entry(char *entry) {
  // Check if the diary is full
  if (diary.num_entries >= MAX_ENTRY_LENGTH) {
    printf("The diary is full. Please delete some entries before adding a new one.\n");
    return;
  }

  // Copy the entry into the diary
  strcpy(diary.entries + diary.num_entries, entry);

  // Increment the number of entries
  diary.num_entries++;
}

// Function to delete an entry from the diary
void delete_entry(int index) {
  // Check if the index is valid
  if (index < 0 || index >= diary.num_entries) {
    printf("Invalid index. Please enter a valid index.\n");
    return;
  }

  // Shift the entries after the deleted entry to the left
  for (int i = index + 1; i < diary.num_entries; i++) {
    strcpy(diary.entries + i - 1, diary.entries + i);
  }

  // Decrement the number of entries
  diary.num_entries--;
}

// Function to print the diary
void print_diary() {
  // Print the diary entries
  for (int i = 0; i < diary.num_entries; i++) {
    printf("%d. %s\n", i + 1, diary.entries + i);
  }
}

// Function to save the diary to a file
void save_diary() {
  // Open the diary file for writing
  FILE *fp = fopen(DIARY_FILENAME, "w");

  // Check if the file was opened successfully
  if (fp == NULL) {
    printf("Error opening the diary file for writing.\n");
    return;
  }

  // Write the diary entries to the file
  for (int i = 0; i < diary.num_entries; i++) {
    fprintf(fp, "%s\n", diary.entries + i);
  }

  // Close the diary file
  fclose(fp);
}

// Function to load the diary from a file
void load_diary() {
  // Open the diary file for reading
  FILE *fp = fopen(DIARY_FILENAME, "r");

  // Check if the file was opened successfully
  if (fp == NULL) {
    printf("Error opening the diary file for reading.\n");
    return;
  }

  // Read the diary entries from the file
  char line[MAX_ENTRY_LENGTH];
  while (fgets(line, MAX_ENTRY_LENGTH, fp)) {
    add_entry(line);
  }

  // Close the diary file
  fclose(fp);
}

// Main function
int main() {
  // Load the diary from a file
  load_diary();

  // Get the user's input
  char input[100];
  while (1) {
    printf("Enter a command (add, delete, print, save, quit): ");
    scanf("%s", input);

    // Check the user's input
    if (strcmp(input, "add") == 0) {
      // Add an entry to the diary
      char entry[MAX_ENTRY_LENGTH];
      printf("Enter an entry: ");
      scanf(" %[^\n]s", entry);  // Read the entry with spaces
      add_entry(entry);
    } else if (strcmp(input, "delete") == 0) {
      // Delete an entry from the diary
      int index;
      printf("Enter the index of the entry to delete: ");
      scanf("%d", &index);
      delete_entry(index);
    } else if (strcmp(input, "print") == 0) {
      // Print the diary
      print_diary();
    } else if (strcmp(input, "save") == 0) {
      // Save the diary to a file
      save_diary();
    } else if (strcmp(input, "quit") == 0) {
      // Quit the program
      break;
    } else {
      // Invalid input
      printf("Invalid command. Please enter a valid command.\n");
    }
  }

  return 0;
}