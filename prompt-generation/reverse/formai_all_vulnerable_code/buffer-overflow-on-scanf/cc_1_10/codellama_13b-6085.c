//Code Llama-13B DATASET v1.0 Category: Digital Diary ; Style: Sherlock Holmes
// Digital Diary in a Sherlock Holmes style
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define constants
#define MAX_ENTRIES 100
#define ENTRY_LENGTH 256

// Define data structures
typedef struct {
  char entry[ENTRY_LENGTH];
  time_t timestamp;
} Entry;

// Define functions
void print_menu();
void add_entry();
void view_entry();
void remove_entry();

// Main function
int main() {
  Entry entries[MAX_ENTRIES];
  int entry_count = 0;

  // Print menu
  print_menu();

  // Get user input
  char input;
  while (1) {
    scanf("%c", &input);

    // Add entry
    if (input == 'a') {
      add_entry(entries, &entry_count);
    }

    // View entry
    else if (input == 'v') {
      view_entry(entries, entry_count);
    }

    // Remove entry
    else if (input == 'r') {
      remove_entry(entries, &entry_count);
    }

    // Exit program
    else if (input == 'e') {
      break;
    }
  }

  return 0;
}

// Print menu
void print_menu() {
  printf("----------------------------------\n");
  printf("1. Add entry\n");
  printf("2. View entry\n");
  printf("3. Remove entry\n");
  printf("4. Exit program\n");
  printf("----------------------------------\n");
}

// Add entry
void add_entry(Entry entries[], int* entry_count) {
  // Get user input
  char entry[ENTRY_LENGTH];
  printf("Enter entry: ");
  fgets(entry, ENTRY_LENGTH, stdin);

  // Add entry to array
  entries[*entry_count].timestamp = time(NULL);
  strcpy(entries[*entry_count].entry, entry);
  *entry_count += 1;

  // Print success message
  printf("Entry added successfully.\n");
}

// View entry
void view_entry(Entry entries[], int entry_count) {
  // Get user input
  int index;
  printf("Enter index: ");
  scanf("%d", &index);

  // Check if index is valid
  if (index < 0 || index >= entry_count) {
    printf("Invalid index.\n");
    return;
  }

  // Print entry
  printf("Entry: %s\n", entries[index].entry);
  printf("Timestamp: %s", ctime(&entries[index].timestamp));
}

// Remove entry
void remove_entry(Entry entries[], int* entry_count) {
  // Get user input
  int index;
  printf("Enter index: ");
  scanf("%d", &index);

  // Check if index is valid
  if (index < 0 || index >= *entry_count) {
    printf("Invalid index.\n");
    return;
  }

  // Remove entry from array
  for (int i = index; i < *entry_count - 1; i++) {
    entries[i] = entries[i + 1];
  }
  *entry_count -= 1;

  // Print success message
  printf("Entry removed successfully.\n");
}