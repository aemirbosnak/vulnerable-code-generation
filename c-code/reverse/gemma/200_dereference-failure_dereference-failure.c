#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct Node {
  int data;
  struct Node* next;
} Node;

void push(Node** head, int data) {
  Node* newNode = malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;

  if (*head == NULL) {
    *head = newNode;
  } else {
    (*head)->next = newNode;
  }
}

int pop(Node** head) {
  if (*head == NULL) {
    return -1;
  }

  int data = (*head)->data;
  *head = (*head)->next;

  return data;
}

int hano(int n) {
  Node* stack1 = NULL;
  Node* stack2 = NULL;
  Node* stack3 = NULL;

  push(stack1, n);

  while (!stack2 && !stack3) {
    int moved = pop(stack1);

    if (moved != -1) {
      push(stack2, moved);
    }
  }

  return 0;
}

int main() {
  hano(3);

  return 0;
}
