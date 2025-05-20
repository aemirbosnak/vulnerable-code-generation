//FormAI DATASET v1.0 Category: Digital Diary ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Maximum number of diary entries
#define MAX_ENTRIES 100

// Structure to hold a single diary entry
struct DiaryEntry {
  char title[50];
  char text[1000];
  time_t timestamp;
};

// Function to add a new diary entry
void addEntry(struct DiaryEntry diary[], int* numEntries) {
  char title[50];
  char text[1000];
  struct DiaryEntry newEntry;

  printf("\nEnter a title for your diary entry: ");
  scanf("%s", title);
  printf("\nEnter the text for your diary entry: ");
  scanf(" %[^\n]s", text);

  // Copy the title and text into the new entry
  strcpy(newEntry.title, title);
  strcpy(newEntry.text, text);

  // Get the current time and add it to the new entry
  newEntry.timestamp = time(NULL);

  // Add the new entry to the diary
  diary[*numEntries] = newEntry;
  (*numEntries)++;

  printf("\nEntry added!\n");
}

// Function to view all diary entries
void viewEntries(struct DiaryEntry diary[], int numEntries) {
  if (numEntries == 0) {
    printf("\nNo entries to view.\n");
    return;
  }

  printf("\nAll diary entries:\n");

  for (int i = 0; i < numEntries; i++) {
    printf("\nEntry %d\n", i+1);
    printf("Title: %s\n", diary[i].title);
    printf("Text: %s\n", diary[i].text);
    printf("Date and time: %s\n", ctime(&diary[i].timestamp));
  }
}

// Main function
int main() {
  struct DiaryEntry diary[MAX_ENTRIES];
  int numEntries = 0;
  int choice;

  printf("Welcome to your digital diary!\n");

  // Loop until the user chooses to exit
  do {
    printf("\nChoose an option:\n");
    printf("1. Add a new diary entry\n");
    printf("2. View all diary entries\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        addEntry(diary, &numEntries);
        break;
      case 2:
        viewEntries(diary, numEntries);
        break;
      case 3:
        printf("\nGoodbye!\n");
        break;
      default:
        printf("\nInvalid choice. Try again.\n");
    }
  } while (choice != 3);

  return 0;
}