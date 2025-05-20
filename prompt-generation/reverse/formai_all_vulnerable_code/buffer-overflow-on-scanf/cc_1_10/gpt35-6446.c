//FormAI DATASET v1.0 Category: Memory management ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

#define MAX_STRING_LENGTH 50
#define MAX_ALLOCATION_SIZE 1024

typedef struct Node {
  int value;
  struct Node* next;
} Node;

void allocate_memory(int** ptr, int size) {
  *ptr = (int*) malloc(sizeof(int) * size);
  if (*ptr == NULL) {
    printf("Error allocating memory.\n");
    exit(1);
  }
}

void free_memory(int** ptr) {
  free(*ptr);
  *ptr = NULL;
}

Node* create_node(int value) {
  Node* node = (Node*) malloc(sizeof(Node*));
  if (node == NULL) {
    printf("Error creating node.\n");
    exit(1);
  }
  node->value = value;
  node->next = NULL;
  return node;
}

void delete_node(Node** node) {
  free(*node);
  *node = NULL;
}

int main() {
  char* string = (char*) malloc(sizeof(char) * MAX_STRING_LENGTH);
  if (string == NULL) {
    printf("Error allocating memory.\n");
    exit(1);
  }
  printf("Enter a string: ");
  scanf("%s", string);
  printf("You entered: %s\n", string);
  free(string);

  int* array;
  allocate_memory(&array, MAX_ALLOCATION_SIZE);
  for (int i = 0; i < MAX_ALLOCATION_SIZE; i++) {
    array[i] = i;
  }
  printf("First element of array: %d\n", array[0]);
  free_memory(&array);

  Node* node = create_node(10);
  printf("Value of node: %d\n", node->value);
  delete_node(&node);

  return 0;
}