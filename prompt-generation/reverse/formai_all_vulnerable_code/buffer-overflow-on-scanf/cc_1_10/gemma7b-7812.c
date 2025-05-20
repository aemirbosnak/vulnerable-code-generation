//Gemma-7B DATASET v1.0 Category: Digital Diary ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENTRIES 100

typedef struct Entry {
  char title[50];
  char content[200];
  struct Entry* next;
} Entry;

Entry* head = NULL;

void addEntry() {
  Entry* newEntry = (Entry*)malloc(sizeof(Entry));
  newEntry->next = NULL;

  printf("Enter the title of your entry:");
  scanf("%s", newEntry->title);

  printf("Enter the content of your entry:");
  scanf("%s", newEntry->content);

  if (head == NULL) {
    head = newEntry;
  } else {
    Entry* currentEntry = head;
    while (currentEntry->next != NULL) {
      currentEntry = currentEntry->next;
    }
    currentEntry->next = newEntry;
  }
}

void displayEntries() {
  Entry* currentEntry = head;
  while (currentEntry) {
    printf("Title: %s\n", currentEntry->title);
    printf("Content: %s\n", currentEntry->content);
    printf("\n");
    currentEntry = currentEntry->next;
  }
}

int main() {
  time_t t = time(NULL);
  srand(t);

  switch (rand() % 3) {
    case 0:
      addEntry();
      break;
    case 1:
      displayEntries();
      break;
    case 2:
      addEntry();
      displayEntries();
      break;
  }

  return 0;
}