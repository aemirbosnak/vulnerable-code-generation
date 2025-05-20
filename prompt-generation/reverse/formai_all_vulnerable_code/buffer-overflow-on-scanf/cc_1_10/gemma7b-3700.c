//Gemma-7B DATASET v1.0 Category: Digital Diary ; Style: portable
#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100

typedef struct Entry {
  char title[50];
  char content[200];
  time_t timestamp;
} Entry;

Entry entries[MAX_ENTRIES];

void addEntry() {
  Entry newEntry;
  printf("Enter title: ");
  scanf("%s", newEntry.title);

  printf("Enter content: ");
  scanf("%[^\n]", newEntry.content);

  newEntry.timestamp = time(NULL);
  entries[entries[MAX_ENTRIES - 1].timestamp] = newEntry;
  entries[MAX_ENTRIES - 1].timestamp = newEntry.timestamp;
}

void displayEntries() {
  for (int i = 0; i < MAX_ENTRIES; i++) {
    if (entries[i].timestamp) {
      printf("Title: %s\n", entries[i].title);
      printf("Content: %s\n", entries[i].content);
      printf("Timestamp: %s\n", ctime(entries[i].timestamp));
      printf("\n");
    }
  }
}

int main() {
  int choice;

  printf("Welcome to your digital diary!\n");

  while (1) {
    printf("1. Add Entry\n");
    printf("2. Display Entries\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        addEntry();
        break;
      case 2:
        displayEntries();
        break;
      default:
        printf("Invalid choice.\n");
    }

    printf("Press any key to continue...");
    getchar();
  }

  return 0;
}