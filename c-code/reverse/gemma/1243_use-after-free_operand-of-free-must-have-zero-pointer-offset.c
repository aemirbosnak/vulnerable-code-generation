#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_ENTRIES 10

typedef struct Entry {
  char *title;
  char *content;
} Entry;

Entry **entries = NULL;

void addEntry() {
  Entry *newEntry = malloc(sizeof(Entry));
  newEntry->title = malloc(20);
  newEntry->content = malloc(100);

  printf("Enter title: ");
  scanf("%s", newEntry->title);

  printf("Enter content: ");
  scanf("%s", newEntry->content);

  entries = realloc(entries, (MAX_ENTRIES + 1) * sizeof(Entry));
  entries[MAX_ENTRIES] = newEntry;
}

void displayEntries() {
  for (int i = 0; i < MAX_ENTRIES; i++) {
    if (entries[i] != NULL) {
      printf("Title: %s\n", entries[i]->title);
      printf("Content: %s\n", entries[i]->content);
      printf("\n");
    }
  }
}

int main() {
  int i = 0;

  while (i < MAX_ENTRIES) {
    addEntry();
    i++;
  }

  displayEntries();

  for (i = 0; i < MAX_ENTRIES; i++) {
    free(entries[i]->title);
    free(entries[i]->content);
    free(entries[i]);
  }

  free(entries);

  return 0;
}
