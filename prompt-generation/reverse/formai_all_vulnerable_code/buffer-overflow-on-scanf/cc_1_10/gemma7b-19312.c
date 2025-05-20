//Gemma-7B DATASET v1.0 Category: Mailing list manager ; Style: complex
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct Node {
  char name[MAX_SIZE];
  struct Node* next;
} Node;

Node* InsertAtTail(Node* head) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  scanf("Enter the name of the new contact: ", newNode->name);

  if (head == NULL) {
    head = newNode;
  } else {
    head->next = newNode;
  }

  return head;
}

void PrintList(Node* head) {
  while (head) {
    printf("%s\n", head->name);
    head = head->next;
  }
}

int main() {
  Node* head = NULL;

  while (1) {
    int choice;

    printf("1. Insert at tail\n");
    printf("2. Print list\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        InsertAtTail(head);
        break;
      case 2:
        PrintList(head);
        break;
      default:
        exit(0);
    }
  }

  return 0;
}