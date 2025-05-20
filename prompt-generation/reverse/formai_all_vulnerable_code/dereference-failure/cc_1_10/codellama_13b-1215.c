//Code Llama-13B DATASET v1.0 Category: Queue Implementation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Queue structure
typedef struct Queue {
  int front, rear;
  int *arr;
  int capacity;
  int size;
} Queue;

// Function to create a new queue
Queue* createQueue(int capacity) {
  Queue *q = malloc(sizeof(Queue));
  q->front = q->rear = 0;
  q->capacity = capacity;
  q->size = 0;
  q->arr = malloc(sizeof(int) * capacity);
  return q;
}

// Function to check if the queue is empty
bool isEmpty(Queue *q) {
  return q->size == 0;
}

// Function to check if the queue is full
bool isFull(Queue *q) {
  return q->size == q->capacity;
}

// Function to add an element to the queue
void enqueue(Queue *q, int data) {
  if (isFull(q)) {
    printf("Queue is full\n");
    return;
  }
  q->arr[q->rear] = data;
  q->rear = (q->rear + 1) % q->capacity;
  q->size++;
}

// Function to remove an element from the queue
int dequeue(Queue *q) {
  if (isEmpty(q)) {
    printf("Queue is empty\n");
    return -1;
  }
  int data = q->arr[q->front];
  q->front = (q->front + 1) % q->capacity;
  q->size--;
  return data;
}

// Function to print the queue
void printQueue(Queue *q) {
  printf("Queue: ");
  for (int i = q->front; i < q->rear; i++) {
    printf("%d ", q->arr[i]);
  }
  printf("\n");
}

// Driver code
int main() {
  Queue *q = createQueue(10);
  enqueue(q, 10);
  enqueue(q, 20);
  enqueue(q, 30);
  printQueue(q);
  int data = dequeue(q);
  printf("Dequeued element: %d\n", data);
  printQueue(q);
  return 0;
}