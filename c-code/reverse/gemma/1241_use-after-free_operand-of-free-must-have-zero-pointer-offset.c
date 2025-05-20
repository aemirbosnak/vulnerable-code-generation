#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_ENTRIES 10

typedef struct Entry {
  char title[50];
  char content[200];
} Entry;

Entry entries[MAX_ENTRIES];

int numEntries = 0;

void addEntry() {
  if (numEntries >= MAX_ENTRIES) {
    printf("Error: Array full.\n");
    return;
  }

  printf("Enter title: ");
  scanf("%s", entries[numEntries].title);

  printf("Enter content: ");
  scanf("%s", entries[numEntries].content);

  numEntries++;
}

void displayEntries() {
  for (int i = 0; i < numEntries; i++) {
    printf("Title: %s\n", entries[i].title);
    printf("Content: %s\n", entries[i].content);
    printf("\n");
  }
}

int main() {
  addEntry();
  addEntry();
  addEntry();
  addEntry();
  addEntry();
  addEntry();
  addEntry();
  addEntry();
  addEntry();
  addEntry();

  displayEntries();

  return 0;
}
