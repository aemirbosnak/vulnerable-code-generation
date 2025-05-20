//Gemma-7B DATASET v1.0 Category: Digital Diary ; Style: all-encompassing
#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 10

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
  scanf("%s", newEntry.content);

  newEntry.timestamp = time(NULL);

  for (int i = 0; i < MAX_ENTRIES; i++) {
    if (entries[i].timestamp == 0) {
      entries[i] = newEntry;
      break;
    }
  }
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

  printf("Enter 1 to add an entry, 2 to display entries: ");
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

  return 0;
}