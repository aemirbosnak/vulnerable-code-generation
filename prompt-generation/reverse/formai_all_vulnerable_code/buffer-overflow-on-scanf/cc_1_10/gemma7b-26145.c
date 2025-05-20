//Gemma-7B DATASET v1.0 Category: Digital Diary ; Style: futuristic
#include <stdio.h>
#include <time.h>

#define MAX_ENTRIES 10

typedef struct Entry {
  char title[20];
  char content[200];
  time_t timestamp;
} Entry;

Entry entries[MAX_ENTRIES];

void addEntry() {
  time_t now = time(NULL);
  entries[MAX_ENTRIES - 1].timestamp = now;
  printf("Enter title: ");
  scanf("%s", entries[MAX_ENTRIES - 1].title);
  printf("Enter content: ");
  scanf("%s", entries[MAX_ENTRIES - 1].content);
  printf("Entry added!\n");
}

void listEntries() {
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

  printf("Welcome to the Future Diary!\n");
  printf("1. Add Entry\n");
  printf("2. List Entries\n");
  printf("Enter your choice: ");
  scanf("%d", &choice);

  switch (choice) {
    case 1:
      addEntry();
      break;
    case 2:
      listEntries();
      break;
    default:
      printf("Invalid choice.\n");
  }

  return 0;
}