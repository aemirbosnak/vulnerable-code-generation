#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_POOL_SIZE 1024

typedef struct Node {
  struct Node* next;
  void* data;
} Node;

Node* newNode(void* data) {
  Node* newNode = malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

int main() {
  char input[MAX_POOL_SIZE];
  Node* head = NULL;

  printf("Enter data (up to %d characters): ", MAX_POOL_SIZE - 1);
  scanf("%s", input);

  // Overflow on sscanf
  scanf("%s", input);

  // Allocate memory for the data
  void* data = malloc(strlen(input) + 1);
  strcpy(data, input);

  // Insert the data into the pool
  newNode(data);

  // Print the data
  printf("Data: %s\n", data);

  return 0;
}
