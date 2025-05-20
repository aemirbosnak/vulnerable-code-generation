//Gemma-7B DATASET v1.0 Category: Error handling ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 20

typedef struct Node {
  char data;
  struct Node* next;
} Node;

int main() {

  Node* head = NULL;

  char command;
  int index;
  char data;

  printf("Enter command (add/remove/search): ");
  scanf("%c", &command);

  switch (command) {
    case 'a':
      printf("Enter index: ");
      scanf("%d", &index);
      printf("Enter data: ");
      scanf("%c", &data);

      if (head == NULL) {
        head = malloc(sizeof(Node));
        head->data = data;
        head->next = NULL;
      } else {
        Node* newNode = malloc(sizeof(Node));
        newNode->data = data;
        newNode->next = NULL;

        Node* traverse = head;
        while (traverse->next) {
          traverse = traverse->next;
        }

        traverse->next = newNode;
      }

      break;
    case 'r':
      printf("Enter index: ");
      scanf("%d", &index);

      if (head == NULL) {
        printf("List is empty\n");
      } else {
        Node* traverse = head;
        Node* previous = NULL;

        for (int i = 0; i < index && traverse; i++) {
          previous = traverse;
          traverse = traverse->next;
        }

        if (previous) {
          previous->next = traverse->next;
          free(traverse);
        } else {
          printf("Index out of bounds\n");
        }
      }

      break;
    case 's':
      printf("Enter index: ");
      scanf("%d", &index);

      if (head == NULL) {
        printf("List is empty\n");
      } else {
        Node* traverse = head;

        for (int i = 0; i < index && traverse; i++) {
          traverse = traverse->next;
        }

        if (traverse) {
          printf("Data: %c\n", traverse->data);
        } else {
          printf("Index out of bounds\n");
        }
      }

      break;
    default:
      printf("Invalid command\n");
  }

  return 0;
}