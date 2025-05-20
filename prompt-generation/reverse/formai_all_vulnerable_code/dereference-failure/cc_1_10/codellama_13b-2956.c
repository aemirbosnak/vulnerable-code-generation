//Code Llama-13B DATASET v1.0 Category: Queue Implementation ; Style: surprised
// A unique C Queue Implementation example program in a surprised style
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Queue structure
typedef struct {
  int size;
  int front;
  int rear;
  int* arr;
} Queue;

// Function to create a new queue
Queue* createQueue(int size) {
  Queue* queue = (Queue*)malloc(sizeof(Queue));
  queue->size = size;
  queue->front = 0;
  queue->rear = -1;
  queue->arr = (int*)malloc(size * sizeof(int));
  return queue;
}

// Function to enqueue an element
void enqueue(Queue* queue, int element) {
  if (queue->rear == queue->size - 1) {
    printf("Queue is full!\n");
    return;
  }
  queue->rear++;
  queue->arr[queue->rear] = element;
}

// Function to dequeue an element
int dequeue(Queue* queue) {
  if (queue->front == queue->rear) {
    printf("Queue is empty!\n");
    return -1;
  }
  int element = queue->arr[queue->front];
  queue->front++;
  return element;
}

// Function to print the queue
void printQueue(Queue* queue) {
  printf("Queue: ");
  for (int i = queue->front; i <= queue->rear; i++) {
    printf("%d ", queue->arr[i]);
  }
  printf("\n");
}

int main() {
  Queue* queue = createQueue(5);
  enqueue(queue, 1);
  enqueue(queue, 2);
  enqueue(queue, 3);
  enqueue(queue, 4);
  enqueue(queue, 5);
  printQueue(queue);
  printf("Dequeued element: %d\n", dequeue(queue));
  printf("Dequeued element: %d\n", dequeue(queue));
  enqueue(queue, 6);
  printQueue(queue);
  return 0;
}