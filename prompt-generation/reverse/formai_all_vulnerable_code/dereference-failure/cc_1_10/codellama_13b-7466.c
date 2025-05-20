//Code Llama-13B DATASET v1.0 Category: Data structures visualization ; Style: cheerful
/*
 * Unique C Data structures visualization example program
 *
 * Author: [Your Name]
 * Date: [Date]
 */

#include <stdio.h>
#include <stdlib.h>

// Linked list structure
struct node {
  int data;
  struct node *next;
};

// Stack structure
struct stack {
  struct node *top;
};

// Queue structure
struct queue {
  struct node *front;
  struct node *rear;
};

// Function to create a new node
struct node* createNode(int data) {
  struct node *newNode = (struct node*)malloc(sizeof(struct node));
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

// Function to push an element to the stack
void push(struct stack *stack, int data) {
  struct node *newNode = createNode(data);
  newNode->next = stack->top;
  stack->top = newNode;
}

// Function to pop an element from the stack
int pop(struct stack *stack) {
  if (stack->top == NULL) {
    printf("Stack underflow!\n");
    return -1;
  }
  int data = stack->top->data;
  struct node *temp = stack->top;
  stack->top = stack->top->next;
  free(temp);
  return data;
}

// Function to enqueue an element to the queue
void enqueue(struct queue *queue, int data) {
  struct node *newNode = createNode(data);
  if (queue->rear == NULL) {
    queue->front = newNode;
    queue->rear = newNode;
  } else {
    queue->rear->next = newNode;
    queue->rear = newNode;
  }
}

// Function to dequeue an element from the queue
int dequeue(struct queue *queue) {
  if (queue->front == NULL) {
    printf("Queue underflow!\n");
    return -1;
  }
  int data = queue->front->data;
  struct node *temp = queue->front;
  queue->front = queue->front->next;
  free(temp);
  return data;
}

int main() {
  // Linked list example
  struct node *head = NULL;
  int data = 1;
  for (int i = 0; i < 5; i++) {
    struct node *newNode = createNode(data);
    if (head == NULL) {
      head = newNode;
    } else {
      struct node *temp = head;
      while (temp->next != NULL) {
        temp = temp->next;
      }
      temp->next = newNode;
    }
    data++;
  }
  printf("Linked list: ");
  struct node *temp = head;
  while (temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");

  // Stack example
  struct stack stack;
  stack.top = NULL;
  int data1 = 10;
  for (int i = 0; i < 5; i++) {
    push(&stack, data1);
    data1++;
  }
  printf("Stack: ");
  while (stack.top != NULL) {
    printf("%d ", pop(&stack));
  }
  printf("\n");

  // Queue example
  struct queue queue;
  queue.front = NULL;
  queue.rear = NULL;
  int data2 = 20;
  for (int i = 0; i < 5; i++) {
    enqueue(&queue, data2);
    data2++;
  }
  printf("Queue: ");
  while (queue.front != NULL) {
    printf("%d ", dequeue(&queue));
  }
  printf("\n");

  return 0;
}