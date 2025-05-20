#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdlib.h>
#include <stdio.h>

void* my_cache_eviction(char* key) {
  // Simulate a linked list node
  struct node {
    char* data;
    struct node* next;
  } *node = NULL;

  // Allocate memory for the node
  node = malloc(sizeof(struct node));

  // Store the key in the node
  node->data = key;

  // Insert the node into the cache
  if (node->next == NULL) {
    node->next = node;
  } else {
    node->next = node->next->next;
  }

  // Return the pointer to the node
  return node->data;
}

int main() {
  // Evict key "a" from the cache
  my_cache_eviction("a");

  // Use the freed memory, causing a use after free vulnerability
  char* data = (char*)my_cache_eviction("a");

  // Print the data
  printf("%s\n", data);

  return 0;
}
