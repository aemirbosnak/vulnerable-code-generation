//Code Llama-13B DATASET v1.0 Category: Queue Implementation ; Style: single-threaded
// C Queue Implementation Example Program
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Queue structure
typedef struct queue {
  int front;
  int rear;
  int size;
  int* arr;
} Queue;

// Function to create a queue
Queue* createQueue(int size) {
  Queue* queue = (Queue*)malloc(sizeof(Queue));
  queue->front = 0;
  queue->rear = 0;
  queue->size = size;
  queue->arr = (int*)malloc(size * sizeof(int));
  return queue;
}

// Function to enqueue an element
void enqueue(Queue* queue, int element) {
  if (queue->rear == queue->size) {
    printf("Queue is full\n");
    return;
  }
  queue->arr[queue->rear++] = element;
}

// Function to dequeue an element
int dequeue(Queue* queue) {
  if (queue->front == queue->rear) {
    printf("Queue is empty\n");
    return -1;
  }
  int element = queue->arr[queue->front++];
  return element;
}

// Function to display the queue
void display(Queue* queue) {
  int i;
  printf("Queue: ");
  for (i = queue->front; i < queue->rear; i++) {
    printf("%d ", queue->arr[i]);
  }
  printf("\n");
}

// Driver code
int main() {
  Queue* queue = createQueue(10);
  enqueue(queue, 10);
  enqueue(queue, 20);
  enqueue(queue, 30);
  display(queue);
  printf("Dequeued element: %d\n", dequeue(queue));
  display(queue);
  return 0;
}