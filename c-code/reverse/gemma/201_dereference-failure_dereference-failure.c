#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

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
    *head = newNode;
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

int hano(int n, Node** src, Node** dest, Node** aux) {
  if (n == 0) {
    return 0;
  }

  hano(n - 1, src, aux, dest);
  push(dest, pop(src));
  hano(n - 1, aux, dest, src);

  return 1;
}

int main() {
  Node* src = NULL;
  Node* dest = NULL;
  Node* aux = NULL;

  hano(3, &src, &dest, &aux);

  if (dest->data != 3) {
    printf("Error: stack overflow\n");
  } else {
    printf("The puzzle is solved.\n");
  }

  return 0;
}
