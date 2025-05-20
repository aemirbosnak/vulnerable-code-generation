//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: irregular
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_SIZE 1024

typedef struct {
  time_t timestamp;
  char entry[MAX_ENTRY_SIZE];
} DiaryEntry;

DiaryEntry diary[MAX_ENTRIES];
int numEntries = 0;

void addEntry(char *entry) {
  if (numEntries < MAX_ENTRIES) {
    time(&diary[numEntries].timestamp);
    strcpy(diary[numEntries].entry, entry);
    numEntries++;
  }
}

void printEntry(int index) {
  if (index >= 0 && index < numEntries) {
    printf("Entry %d:\n", index + 1);
    printf("Timestamp: %s", ctime(&diary[index].timestamp));
    printf("Entry: %s\n\n", diary[index].entry);
  }
}

void printAllEntries() {
  for (int i = 0; i < numEntries; i++) {
    printEntry(i);
  }
}

void searchEntries(char *keyword) {
  for (int i = 0; i < numEntries; i++) {
    if (strstr(diary[i].entry, keyword) != NULL) {
      printEntry(i);
    }
  }
}

int main() {
  char input[MAX_ENTRY_SIZE];
  int choice;

  do {
    printf("Digital Diary Menu\n\n");
    printf("1. Add a new entry\n");
    printf("2. Print a specific entry\n");
    printf("3. Print all entries\n");
    printf("4. Search for a keyword\n");
    printf("5. Exit\n\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        printf("Enter your entry: ");
        scanf(" %[^\n]", input);
        addEntry(input);
        break;
      case 2:
        printf("Enter the entry number: ");
        scanf("%d", &choice);
        choice--;
        printEntry(choice);
        break;
      case 3:
        printAllEntries();
        break;
      case 4:
        printf("Enter the keyword to search for: ");
        scanf(" %[^\n]", input);
        searchEntries(input);
        break;
      case 5:
        printf("Exiting the program.\n");
        break;
      default:
        printf("Invalid choice. Please enter a number between 1 and 5.\n");
    }
  } while (choice != 5);

  return 0;
}