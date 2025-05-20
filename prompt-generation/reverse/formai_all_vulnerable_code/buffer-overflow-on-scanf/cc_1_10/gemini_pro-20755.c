//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char *name;
  char *entry;
  struct Node *next;
} Node;

Node *head = NULL;
Node *tail = NULL;

void addEntry(char *name, char *entry) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->name = (char *)malloc(strlen(name) + 1);
  strcpy(newNode->name, name);
  newNode->entry = (char *)malloc(strlen(entry) + 1);
  strcpy(newNode->entry, entry);  
  
  if (head == NULL) {
    head = newNode;
    tail = newNode;
  } else {
    tail->next = newNode;
    tail = newNode;
  }
}

void printEntries() {
  Node *current = head;
  while (current != NULL) {
    printf("%s: %s\n", current->name, current->entry);
    current = current->next;
  }
}

int main() {
  char name[20];
  char entry[100];
  int choice;

  do {
    printf("1. Add an entry\n");
    printf("2. Print all entries\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        printf("Enter your name: ");
        scanf("%s", name);
        printf("Enter your entry: ");
        scanf(" %[^\n]s", entry);  
        addEntry(name, entry);
        break;
      case 2:
        printEntries();
        break;
      case 3:
        break;
      default:
        printf("Invalid choice\n");
    }
  } while (choice != 3);

  return 0;
}