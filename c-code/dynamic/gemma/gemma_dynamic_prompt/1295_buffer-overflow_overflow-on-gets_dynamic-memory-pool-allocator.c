#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_POOL_SIZE 1024

typedef struct Node {
  struct Node* next;
  char* data;
} Node;

Node* newNode(int size) {
  Node* newNode = malloc(sizeof(Node));
  newNode->data = malloc(size);
  newNode->next = NULL;
  return newNode;
}

int main() {
  Node* head = NULL;

  char* buffer = NULL;
  int i = 0;

  // Allocate a large buffer
  buffer = malloc(MAX_POOL_SIZE);

  // Overflow the buffer
  for (i = 0; i < MAX_POOL_SIZE + 1; i++) {
    gets(buffer);
  }

  // Free the buffer
  free(buffer);

  return 0;
}
