//Code Llama-13B DATASET v1.0 Category: Data structures visualization ; Style: relaxed
// A unique C data structures visualization example program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

// Structure definitions
struct Node {
  int value;
  struct Node *left;
  struct Node *right;
};

struct LinkedList {
  struct Node *head;
  struct Node *tail;
};

struct Stack {
  struct Node *head;
};

struct Queue {
  struct Node *head;
  struct Node *tail;
};

// Function definitions
void init_stack(struct Stack *stack) {
  stack->head = NULL;
}

void push(struct Stack *stack, int value) {
  struct Node *node = malloc(sizeof(struct Node));
  node->value = value;
  node->left = NULL;
  node->right = stack->head;
  stack->head = node;
}

int pop(struct Stack *stack) {
  if (stack->head == NULL) {
    return -1;
  }
  struct Node *node = stack->head;
  int value = node->value;
  stack->head = node->right;
  free(node);
  return value;
}

void init_queue(struct Queue *queue) {
  queue->head = NULL;
  queue->tail = NULL;
}

void enqueue(struct Queue *queue, int value) {
  struct Node *node = malloc(sizeof(struct Node));
  node->value = value;
  node->left = NULL;
  node->right = NULL;
  if (queue->tail == NULL) {
    queue->head = node;
    queue->tail = node;
  } else {
    queue->tail->right = node;
    queue->tail = node;
  }
}

int dequeue(struct Queue *queue) {
  if (queue->head == NULL) {
    return -1;
  }
  struct Node *node = queue->head;
  int value = node->value;
  queue->head = node->right;
  free(node);
  return value;
}

void print_list(struct LinkedList *list) {
  struct Node *node = list->head;
  while (node != NULL) {
    printf("%d ", node->value);
    node = node->right;
  }
  printf("\n");
}

int main() {
  struct LinkedList list;
  list.head = NULL;
  list.tail = NULL;
  int i;
  for (i = 0; i < 10; i++) {
    struct Node *node = malloc(sizeof(struct Node));
    node->value = i;
    node->left = NULL;
    node->right = NULL;
    if (list.tail == NULL) {
      list.head = node;
      list.tail = node;
    } else {
      list.tail->right = node;
      list.tail = node;
    }
  }
  print_list(&list);
  struct Stack stack;
  init_stack(&stack);
  for (i = 0; i < 5; i++) {
    push(&stack, i);
  }
  for (i = 0; i < 5; i++) {
    printf("%d ", pop(&stack));
  }
  printf("\n");
  struct Queue queue;
  init_queue(&queue);
  for (i = 0; i < 10; i++) {
    enqueue(&queue, i);
  }
  for (i = 0; i < 10; i++) {
    printf("%d ", dequeue(&queue));
  }
  printf("\n");
  return 0;
}