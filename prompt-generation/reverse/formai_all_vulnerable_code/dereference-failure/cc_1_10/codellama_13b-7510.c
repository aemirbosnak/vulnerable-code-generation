//Code Llama-13B DATASET v1.0 Category: Queue Implementation ; Style: high level of detail
// Queue implementation using a linked list

#include <stdio.h>
#include <stdlib.h>

// Structures
typedef struct node {
  int data;
  struct node* next;
} Node;

typedef struct queue {
  Node* front;
  Node* rear;
  int size;
} Queue;

// Function prototypes
void initQueue(Queue* q);
void enqueue(Queue* q, int data);
int dequeue(Queue* q);
int isEmpty(Queue* q);

// Function definitions
void initQueue(Queue* q) {
  q->front = NULL;
  q->rear = NULL;
  q->size = 0;
}

void enqueue(Queue* q, int data) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;

  if (q->front == NULL) {
    q->front = newNode;
    q->rear = newNode;
  } else {
    q->rear->next = newNode;
    q->rear = newNode;
  }

  q->size++;
}

int dequeue(Queue* q) {
  if (q->front == NULL) {
    return -1;
  }

  Node* temp = q->front;
  int data = temp->data;
  q->front = temp->next;
  free(temp);
  q->size--;

  return data;
}

int isEmpty(Queue* q) {
  return q->front == NULL;
}

// Main function
int main() {
  Queue q;
  initQueue(&q);

  enqueue(&q, 1);
  enqueue(&q, 2);
  enqueue(&q, 3);

  while (!isEmpty(&q)) {
    int data = dequeue(&q);
    printf("%d ", data);
  }

  return 0;
}