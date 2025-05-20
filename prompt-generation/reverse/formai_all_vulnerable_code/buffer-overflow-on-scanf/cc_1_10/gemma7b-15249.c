//Gemma-7B DATASET v1.0 Category: Digital Diary ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct Entry {
  char title[MAX_SIZE];
  char content[MAX_SIZE];
  struct Entry* next;
} Entry;

Entry* head = NULL;

void addEntry() {
  Entry* newEntry = (Entry*)malloc(sizeof(Entry));
  printf("Enter title: ");
  scanf("%s", newEntry->title);
  printf("Enter content: ");
  scanf("%s", newEntry->content);
  newEntry->next = head;
  head = newEntry;
}

void listEntries() {
  Entry* currentEntry = head;
  while (currentEntry) {
    printf("Title: %s\n", currentEntry->title);
    printf("Content: %s\n", currentEntry->content);
    printf("\n");
    currentEntry = currentEntry->next;
  }
}

int main() {
  char choice;
  while (1) {
    printf("Enter 'a' to add an entry, 'l' to list entries, or 'q' to quit: ");
    scanf("%c", &choice);

    switch (choice) {
      case 'a':
        addEntry();
        break;
      case 'l':
        listEntries();
        break;
      case 'q':
        exit(0);
    }
  }
}