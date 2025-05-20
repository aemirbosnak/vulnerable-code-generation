//Code Llama-13B DATASET v1.0 Category: Data structures visualization ; Style: curious
/*
 * Curious C Data Structures Visualization Example Program
 *
 * This program generates a visual representation of a set of data structures,
 * including arrays, linked lists, stacks, and queues.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Array structure
typedef struct {
  int size;
  int *data;
} Array;

// Linked list structure
typedef struct Node {
  int data;
  struct Node *next;
} Node;

// Stack structure
typedef struct {
  int size;
  Node *top;
} Stack;

// Queue structure
typedef struct {
  int size;
  Node *front;
  Node *rear;
} Queue;

// Function prototypes
void print_array(Array *arr);
void print_list(Node *head);
void print_stack(Stack *stack);
void print_queue(Queue *queue);

// Main function
int main() {
  // Array example
  Array arr;
  arr.size = 5;
  arr.data = (int *)malloc(arr.size * sizeof(int));
  for (int i = 0; i < arr.size; i++) {
    arr.data[i] = i;
  }
  print_array(&arr);

  // Linked list example
  Node *head = NULL;
  for (int i = 0; i < 5; i++) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = i;
    node->next = head;
    head = node;
  }
  print_list(head);

  // Stack example
  Stack stack;
  stack.size = 5;
  for (int i = 0; i < stack.size; i++) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = i;
    node->next = stack.top;
    stack.top = node;
  }
  print_stack(&stack);

  // Queue example
  Queue queue;
  queue.size = 5;
  for (int i = 0; i < queue.size; i++) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = i;
    if (queue.front == NULL) {
      queue.front = node;
    } else {
      queue.rear->next = node;
    }
    queue.rear = node;
  }
  print_queue(&queue);

  return 0;
}

// Function definitions
void print_array(Array *arr) {
  printf("Array: ");
  for (int i = 0; i < arr->size; i++) {
    printf("%d ", arr->data[i]);
  }
  printf("\n");
}

void print_list(Node *head) {
  printf("Linked List: ");
  while (head != NULL) {
    printf("%d ", head->data);
    head = head->next;
  }
  printf("\n");
}

void print_stack(Stack *stack) {
  printf("Stack: ");
  Node *node = stack->top;
  while (node != NULL) {
    printf("%d ", node->data);
    node = node->next;
  }
  printf("\n");
}

void print_queue(Queue *queue) {
  printf("Queue: ");
  Node *node = queue->front;
  while (node != NULL) {
    printf("%d ", node->data);
    node = node->next;
  }
  printf("\n");
}