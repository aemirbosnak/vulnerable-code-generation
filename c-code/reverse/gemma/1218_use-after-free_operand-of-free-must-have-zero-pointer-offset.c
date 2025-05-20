#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdlib.h>

typedef struct Node {
  struct Node* next;
  void* data;
} Node;

void* my_malloc(int size) {
  Node* newNode = malloc(sizeof(Node) + size);
  newNode->data = (void*) ((char*) newNode + sizeof(Node));
  newNode->next = NULL;
  return newNode->data;
}

void my_free(void* ptr) {
  Node* node = ptr - sizeof(Node);
  free(node);
}

int main() {
  void* a = my_malloc(10);
  my_free(a);
  void* b = my_malloc(20);
  // Use-after-free vulnerability: Overwrite the previously freed memory region
  *(int*)b = 42;
  my_free(b);
  return 0;
}
