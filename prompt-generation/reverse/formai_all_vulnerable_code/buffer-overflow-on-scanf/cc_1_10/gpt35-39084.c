//FormAI DATASET v1.0 Category: Digital Diary ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENTRIES 100 // Maximum number of entries in diary
#define MAX_CHARS 1000 // Maximum number of characters in an entry

void displayMenu();
void addEntry(char entries[][MAX_CHARS], int* numEntries);
void viewEntries(char entries[][MAX_CHARS], int numEntries);

int main() {
  char diaryEntries[MAX_ENTRIES][MAX_CHARS];
  int numEntries = 0;
  int choice;

  srand(time(0)); // seed the random number generator

  while (1) { // loop until user exits program
    displayMenu();
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        addEntry(diaryEntries, &numEntries);
        break;
      case 2:
        viewEntries(diaryEntries, numEntries);
        break;
      case 3:
        printf("Exiting program.\n");
        exit(0);
      default:
        printf("Invalid choice. Please try again.\n");
    }
  }

  return 0;
}

void displayMenu() {
  printf("\n");
  printf("Digital Diary:\n");
  printf("1. Add entry\n");
  printf("2. View entries\n");
  printf("3. Exit\n");
  printf("Enter your choice: ");
}

void addEntry(char entries[][MAX_CHARS], int* numEntries) {
  if (*numEntries >= MAX_ENTRIES) {
    printf("Maximum number of entries reached.\n");
    return;
  }

  time_t now = time(0); // get current time
  struct tm* timeinfo = localtime(&now);
  char timestamp[20];
  strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", timeinfo); // format time as string

  printf("Enter your diary entry:\n");
  getchar(); // consume newline character left in input buffer
  fgets(entries[*numEntries], MAX_CHARS, stdin); // read input from user
  entries[*numEntries][strlen(entries[*numEntries]) - 1] = '\0'; // replace newline character with null character
  strcat(entries[*numEntries], "\n"); // add newline character back to end of input

  printf("Entry added at %s\n", timestamp);
  (*numEntries)++;
}

void viewEntries(char entries[][MAX_CHARS], int numEntries) {
  if (numEntries == 0) {
    printf("No entries to display.\n");
    return;
  }

  int randomIndex = rand() % numEntries;

  printf("Random entry:\n");
  printf("%s", entries[randomIndex]);
  printf("\n");
}