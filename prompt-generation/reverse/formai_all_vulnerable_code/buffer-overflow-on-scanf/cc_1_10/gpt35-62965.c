//FormAI DATASET v1.0 Category: Digital Diary ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#define MAX_DIARY_ENTRIES 100 // Maximum number of diary entries
#define MAX_ENTRY_LENGTH 1000 // Maximum length of each diary entry
#define DATE_FORMAT "%d/%m/%Y" // Date format used in the diary

// Structure to store each entry in the diary
typedef struct {
  char date[11]; // DD/MM/YYYY format
  char text[MAX_ENTRY_LENGTH];
} DiaryEntry;

// Function to add a new entry to the diary
void addEntry(DiaryEntry* diary, int* numEntries) {
  // Check if the maximum number of entries has been reached
  if (*numEntries == MAX_DIARY_ENTRIES) {
    printf("The maximum number of entries has been reached.\n");
    return;
  }

  // Get the current date and time
  time_t now = time(NULL);
  struct tm* tm = localtime(&now);
  strftime(diary[*numEntries].date, sizeof(diary[*numEntries].date), DATE_FORMAT, tm);

  // Prompt the user to enter the text of the entry
  printf("Enter the text of the entry (max %d characters):\n", MAX_ENTRY_LENGTH - 1);
  fgets(diary[*numEntries].text, sizeof(diary[*numEntries].text), stdin);

  // Remove the newline character from the end of the input
  diary[*numEntries].text[strcspn(diary[*numEntries].text, "\n")] = '\0';

  // Increment the number of entries
  (*numEntries)++;
}

// Function to display the diary entries
void displayEntries(DiaryEntry* diary, int numEntries) {
  if (numEntries == 0) {
    printf("There are no diary entries.\n");
    return;
  }

  // Loop through all entries in reverse order (most recent first)
  for (int i = numEntries - 1; i >= 0; i--) {
    printf("%s:\n%s\n\n", diary[i].date, diary[i].text);
  }
}

int main() {
  // Create an array to store the diary entries
  DiaryEntry diary[MAX_DIARY_ENTRIES];
  int numEntries = 0;

  // Loop until the user chooses to quit
  while (true) {
    // Prompt the user to choose an action
    printf("Choose an action:\n1. Add entry\n2. View entries\n3. Quit\n");

    // Get the user's choice
    int choice;
    scanf("%d", &choice);
    getchar(); // Consume the newline character left by scanf

    // Perform the chosen action
    switch (choice) {
      case 1:
        addEntry(diary, &numEntries);
        break;
      case 2:
        displayEntries(diary, numEntries);
        break;
      case 3:
        printf("Goodbye!\n");
        exit(0);
      default:
        printf("Invalid choice.\n");
        break;
    }
  }

  return 0;
}