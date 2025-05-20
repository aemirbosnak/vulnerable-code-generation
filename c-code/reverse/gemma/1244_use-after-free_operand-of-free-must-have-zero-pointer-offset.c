#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_ENTRIES 10

typedef struct Entry {
  char title[50];
  char content[200];
  struct Entry* next;
} Entry;

Entry* createEntry() {
  Entry* newEntry = malloc(sizeof(Entry));
  newEntry->next = NULL;
  return newEntry;
}

int main() {
  Entry* head = NULL;
  int i = 0;

  // Allocate entries until the array is full
  for (i = 0; i < MAX_ENTRIES; i++) {
    Entry* newEntry = createEntry();
    printf("Enter title: ");
    scanf("%s", newEntry->title);
    printf("Enter content: ");
    scanf("%s", newEntry->content);
    newEntry->next = head;
    head = newEntry;
  }

  // Demonstrate use-after-free vulnerability
  for (i = 0; i < MAX_ENTRIES; i++) {
    Entry* currentEntry = head;
    for (int j = 0; j < MAX_ENTRIES; j++) {
      if (currentEntry) {
        free(currentEntry);
        currentEntry = currentEntry->next;
      }
    }
  }

  return 0;
}
