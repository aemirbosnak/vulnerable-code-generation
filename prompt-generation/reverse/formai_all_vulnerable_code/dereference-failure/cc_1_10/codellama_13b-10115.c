//Code Llama-13B DATASET v1.0 Category: Data structures visualization ; Style: cheerful
/*
 * Cheerful C Data Structures Visualization Example
 *
 * Author: [Your Name]
 * Date: [Current Date]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structures

// Array
struct Array {
  int* elements;
  int size;
};

// Linked List
struct Node {
  int data;
  struct Node* next;
};

// Stack
struct Stack {
  int* elements;
  int top;
};

// Queue
struct Queue {
  int* elements;
  int front;
  int rear;
};

// Functions

// Array Functions
void printArray(struct Array* arr) {
  for (int i = 0; i < arr->size; i++) {
    printf("%d ", arr->elements[i]);
  }
  printf("\n");
}

void pushArray(struct Array* arr, int data) {
  arr->elements[arr->size++] = data;
}

int popArray(struct Array* arr) {
  return arr->elements[--arr->size];
}

// Linked List Functions
void printLinkedList(struct Node* head) {
  struct Node* current = head;
  while (current != NULL) {
    printf("%d ", current->data);
    current = current->next;
  }
  printf("\n");
}

void pushLinkedList(struct Node** head, int data) {
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = *head;
  *head = newNode;
}

int popLinkedList(struct Node** head) {
  struct Node* current = *head;
  *head = current->next;
  int data = current->data;
  free(current);
  return data;
}

// Stack Functions
void printStack(struct Stack* stack) {
  printf("Stack: ");
  for (int i = 0; i <= stack->top; i++) {
    printf("%d ", stack->elements[i]);
  }
  printf("\n");
}

void pushStack(struct Stack* stack, int data) {
  stack->elements[++stack->top] = data;
}

int popStack(struct Stack* stack) {
  return stack->elements[stack->top--];
}

// Queue Functions
void printQueue(struct Queue* queue) {
  printf("Queue: ");
  for (int i = queue->front; i < queue->rear; i++) {
    printf("%d ", queue->elements[i]);
  }
  printf("\n");
}

void enqueue(struct Queue* queue, int data) {
  queue->elements[queue->rear++] = data;
}

int dequeue(struct Queue* queue) {
  return queue->elements[queue->front++];
}

// Main Function
int main() {
  // Array
  struct Array arr = {NULL, 0};
  pushArray(&arr, 1);
  pushArray(&arr, 2);
  pushArray(&arr, 3);
  printArray(&arr);
  printf("Popped: %d\n", popArray(&arr));
  printArray(&arr);

  // Linked List
  struct Node* head = NULL;
  pushLinkedList(&head, 1);
  pushLinkedList(&head, 2);
  pushLinkedList(&head, 3);
  printLinkedList(head);
  printf("Popped: %d\n", popLinkedList(&head));
  printLinkedList(head);

  // Stack
  struct Stack stack = {NULL, -1};
  pushStack(&stack, 1);
  pushStack(&stack, 2);
  pushStack(&stack, 3);
  printStack(&stack);
  printf("Popped: %d\n", popStack(&stack));
  printStack(&stack);

  // Queue
  struct Queue queue = {NULL, 0, 0};
  enqueue(&queue, 1);
  enqueue(&queue, 2);
  enqueue(&queue, 3);
  printQueue(&queue);
  printf("Dequeued: %d\n", dequeue(&queue));
  printQueue(&queue);

  return 0;
}