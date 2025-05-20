//Code Llama-13B DATASET v1.0 Category: Queue Implementation ; Style: systematic
// Queue Implementation Example Program
#include <stdio.h>
#include <stdlib.h>

// Queue structure
typedef struct {
  int front;
  int rear;
  int size;
  int* data;
} Queue;

// Function to create a new queue
Queue* createQueue(int size) {
  Queue* queue = malloc(sizeof(Queue));
  queue->front = 0;
  queue->rear = 0;
  queue->size = size;
  queue->data = malloc(size * sizeof(int));
  return queue;
}

// Function to check if the queue is empty
int isEmpty(Queue* queue) {
  return queue->front == queue->rear;
}

// Function to check if the queue is full
int isFull(Queue* queue) {
  return queue->front == queue->rear + 1;
}

// Function to add an element to the queue
void enqueue(Queue* queue, int element) {
  if (isFull(queue)) {
    printf("Queue is full");
    return;
  }
  queue->data[queue->rear] = element;
  queue->rear = (queue->rear + 1) % queue->size;
}

// Function to remove an element from the queue
int dequeue(Queue* queue) {
  if (isEmpty(queue)) {
    printf("Queue is empty");
    return -1;
  }
  int element = queue->data[queue->front];
  queue->front = (queue->front + 1) % queue->size;
  return element;
}

// Function to print the elements of the queue
void printQueue(Queue* queue) {
  int i = queue->front;
  while (i != queue->rear) {
    printf("%d ", queue->data[i]);
    i = (i + 1) % queue->size;
  }
  printf("\n");
}

// Main function
int main() {
  Queue* queue = createQueue(5);
  enqueue(queue, 10);
  enqueue(queue, 20);
  enqueue(queue, 30);
  enqueue(queue, 40);
  enqueue(queue, 50);
  printQueue(queue);
  dequeue(queue);
  dequeue(queue);
  printQueue(queue);
  return 0;
}