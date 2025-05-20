#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_POOL_SIZE 10

typedef struct Node {
  struct Node* next;
  char data[MAX_POOL_SIZE];
} Node;

Node* alloc(int size) {
  Node* newNode = malloc(sizeof(Node));
  if (newNode == NULL) {
    return NULL;
  }
  newNode->next = NULL;
  newNode->data[0] = '\0';
  return newNode;
}

int main() {
  Node* head = NULL;

  char buffer[MAX_POOL_SIZE];

  printf("Enter a command: ");
  scanf("%s", buffer);

  // Overflow on fscanf
  fscanf(stdin, "%s", buffer);

  printf("Allocated memory: %s\n", buffer);

  return 0;
}
