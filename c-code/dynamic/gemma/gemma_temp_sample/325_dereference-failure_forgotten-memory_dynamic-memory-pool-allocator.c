#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

int main() {
  // Allocate memory for the pool
  void* pool = malloc(1024);

  // Create a linked list node
  struct node {
    void* data;
    struct node* next;
  }* head = NULL;

  // Allocate memory for the node
  struct node* newNode = malloc(sizeof(struct node));
  newNode->data = pool;
  newNode->next = NULL;

  // Add the node to the head of the list
  head = newNode;

  // Free the memory allocated for the node
  free(newNode);

  // Free the memory allocated for the pool
  free(pool);

  return 0;
}
