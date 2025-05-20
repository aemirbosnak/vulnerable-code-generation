#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  struct Node* next;
  int data;
} Node;

int main() {
  Node* head = NULL;
  head = malloc(sizeof(Node));
  head->data = 10;
  head->next = NULL;

  free(head);
  head->data = 20; // Use after free vulnerability

  printf("Data: %d", head->data);

  return 0;
}
