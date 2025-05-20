#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1024

typedef struct Node {
  struct Node* next;
  char data[MAX_SIZE];
} Node;

Node* alloc(int size) {
  Node* newNode = malloc(sizeof(Node) + size);
  newNode->next = NULL;
  return newNode;
}

int main() {
  char* buffer = alloc(MAX_SIZE);
  gets(buffer);
  free(buffer);
  return 0;
}
