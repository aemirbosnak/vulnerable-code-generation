//Code Llama-13B DATASET v1.0 Category: Digital Diary ; Style: shocked
// Digital Diary Example Program in a Shocked Style

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENTRIES 100

// Struct to store diary entries
struct diary_entry {
  char date[11]; // 11 characters to store the date (YYYY-MM-DD)
  char title[50]; // 50 characters to store the title of the entry
  char body[100]; // 100 characters to store the body of the entry
};

// Function to add a new diary entry
void add_entry(struct diary_entry *entries, int *num_entries) {
  // Get the current date and time
  time_t t = time(NULL);
  struct tm *tm = localtime(&t);
  char date[11];
  strftime(date, 11, "%Y-%m-%d", tm);

  // Prompt the user to enter the title and body of the entry
  printf("Enter the title of the entry: ");
  fgets(entries[*num_entries].title, 50, stdin);
  printf("Enter the body of the entry: ");
  fgets(entries[*num_entries].body, 100, stdin);

  // Set the date of the entry
  strcpy(entries[*num_entries].date, date);

  // Increment the number of entries
  (*num_entries)++;
}

// Function to display all diary entries
void display_entries(struct diary_entry *entries, int num_entries) {
  // Iterate over all entries
  for (int i = 0; i < num_entries; i++) {
    // Display the date and title of the entry
    printf("%s: %s\n", entries[i].date, entries[i].title);

    // Display the body of the entry
    printf("%s\n\n", entries[i].body);
  }
}

int main() {
  // Initialize an array to store diary entries
  struct diary_entry entries[MAX_ENTRIES];
  int num_entries = 0;

  // Loop until the user quits
  while (1) {
    // Display the menu
    printf("1. Add a new entry\n");
    printf("2. Display all entries\n");
    printf("3. Quit\n");
    printf("Enter your choice: ");

    // Get the user's choice
    int choice;
    scanf("%d", &choice);

    // Add a new entry
    if (choice == 1) {
      add_entry(entries, &num_entries);
    }

    // Display all entries
    else if (choice == 2) {
      display_entries(entries, num_entries);
    }

    // Quit
    else if (choice == 3) {
      break;
    }

    // Invalid choice
    else {
      printf("Invalid choice. Try again.\n");
    }
  }

  return 0;
}