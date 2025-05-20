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

void moveDisk(Node** top, int n) {
  if (*top == NULL) {
    *top = malloc(sizeof(Node));
    (*top)->data = n;
    (*top)->next = NULL;
  } else {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = n;
    newNode->next = *top;
    *top = newNode;
  }
  // Off-by-one error: Should be (*top)->data - 1 instead of (*top)->data
  (*top)->data--;
}

int main() {
  Node* top = NULL;
  moveDisk(&top, 3);
  return 0;
}
