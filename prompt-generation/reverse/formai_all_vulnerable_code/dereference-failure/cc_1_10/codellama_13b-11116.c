//Code Llama-13B DATASET v1.0 Category: Queue Implementation ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Queue structure
struct Queue {
  int *items;
  int capacity;
  int front;
  int rear;
  int count;
};

// Create a new queue
struct Queue *createQueue(int capacity) {
  struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
  queue->items = (int *)malloc(capacity * sizeof(int));
  queue->capacity = capacity;
  queue->front = 0;
  queue->rear = 0;
  queue->count = 0;
  return queue;
}

// Enqueue an item
void enqueue(struct Queue *queue, int item) {
  if (queue->count >= queue->capacity) {
    printf("Queue is full\n");
    return;
  }
  queue->items[queue->rear] = item;
  queue->rear = (queue->rear + 1) % queue->capacity;
  queue->count++;
}

// Dequeue an item
int dequeue(struct Queue *queue) {
  if (queue->count <= 0) {
    printf("Queue is empty\n");
    return -1;
  }
  int item = queue->items[queue->front];
  queue->front = (queue->front + 1) % queue->capacity;
  queue->count--;
  return item;
}

// Peek the front item
int peek(struct Queue *queue) {
  if (queue->count <= 0) {
    printf("Queue is empty\n");
    return -1;
  }
  return queue->items[queue->front];
}

// Check if queue is empty
int isEmpty(struct Queue *queue) {
  return queue->count == 0;
}

// Check if queue is full
int isFull(struct Queue *queue) {
  return queue->count >= queue->capacity;
}

// Print the queue
void printQueue(struct Queue *queue) {
  printf("Queue: ");
  for (int i = queue->front; i < queue->rear; i++) {
    printf("%d ", queue->items[i]);
  }
  printf("\n");
}

int main() {
  struct Queue *queue = createQueue(10);
  enqueue(queue, 1);
  enqueue(queue, 2);
  enqueue(queue, 3);
  printQueue(queue);
  printf("Dequeued item: %d\n", dequeue(queue));
  printQueue(queue);
  printf("Peeked item: %d\n", peek(queue));
  printf("Is queue empty: %d\n", isEmpty(queue));
  printf("Is queue full: %d\n", isFull(queue));
  return 0;
}