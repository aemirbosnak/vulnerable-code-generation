//FormAI DATASET v1.0 Category: Database Indexing System ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct Node {
  int key;
  struct Node *next;
} Node;

void insertAtIndex(Node *table[], int key) {
  int index = key % MAX;
  Node *newNode = (Node *) malloc(sizeof(Node));
  newNode->key = key;
  newNode->next = table[index];
  table[index] = newNode;
}

void searchIndex(Node *table[], int key) {
  int index = key % MAX;
  Node *temp = table[index];
  while(temp != NULL) {
    if(temp->key == key) {
      printf("Element found at index %d\n", index);
      return;
    }
    temp = temp->next;
  }
  printf("Element not found.\n");
}

void deleteAtIndex(Node *table[], int key) {
  int index = key % MAX;
  Node *temp = table[index];
  Node *prev = NULL;

  while(temp != NULL) {
    if(temp->key == key) {
      if(prev == NULL) {
        table[index] = temp->next;
      } else {
        prev->next = temp->next;
      }
      free(temp);
      printf("Element deleted from index %d\n", index);
      return;
    }
    prev = temp;
    temp = temp->next;
  }
  printf("Element not found.\n");
}

int main() {
  Node *table[MAX] = {NULL};
  int choice, key;

  while(1) {
    printf("\nC Database Indexing System\n");
    printf("1. Insert Element\n");
    printf("2. Search Element\n");
    printf("3. Delete Element\n");
    printf("4. Exit");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
      case 1:
        printf("Enter key value: ");
        scanf("%d", &key);
        insertAtIndex(table, key);
        break;
      case 2:
        printf("Enter key value: ");
        scanf("%d", &key);
        searchIndex(table, key);
        break;
      case 3:
        printf("Enter key value: ");
        scanf("%d", &key);
        deleteAtIndex(table, key);
        break;
      case 4:
        exit(0);
      default:
        printf("Invalid choice.\n");
    }
  }

  return 0;
}