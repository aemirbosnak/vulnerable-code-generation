//Gemma-7B DATASET v1.0 Category: Digital Diary ; Style: excited
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct Entry {
  char name[50];
  int age;
  char entry[MAX_SIZE];
  struct Entry* next;
} Entry;

Entry* head = NULL;

void addEntry() {
  Entry* newEntry = (Entry*)malloc(sizeof(Entry));

  printf("Enter your name: ");
  scanf("%s", newEntry->name);

  printf("Enter your age: ");
  scanf("%d", &newEntry->age);

  printf("Enter your entry: ");
  scanf("%[^\n]%*c", newEntry->entry);

  newEntry->next = head;
  head = newEntry;
}

void displayEntries() {
  Entry* currentEntry = head;

  while (currentEntry) {
    printf("Name: %s\n", currentEntry->name);
    printf("Age: %d\n", currentEntry->age);
    printf("Entry: %s\n", currentEntry->entry);
    printf("\n");
    currentEntry = currentEntry->next;
  }
}

int main() {
  int choice;

  printf("Welcome to your digital diary!\n");

  while (1) {
    printf("1. Add entry\n");
    printf("2. Display entries\n");
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