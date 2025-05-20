#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 10

typedef struct Node {
  int data;
  struct Node* next;
} Node;

void hanoi(int n, Node** stack) {
  if (n == 0) {
    return;
  }

  hanoi(n - 1, stack);

  Node* newNode = malloc(sizeof(Node));
  newNode->data = n;
  newNode->next = NULL;

  if (*stack == NULL) {
    *stack = newNode;
  } else {
    (*stack)->next = newNode;
    *stack = newNode;
  }

  hanoi(n - 1, stack);
}

int main() {
  Node* stack = NULL;
  hanoi(3, &stack);

  return 0;
}
