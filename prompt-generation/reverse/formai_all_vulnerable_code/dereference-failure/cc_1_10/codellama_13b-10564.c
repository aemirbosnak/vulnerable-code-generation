//Code Llama-13B DATASET v1.0 Category: Queue Implementation ; Style: grateful
// C Queue Implementation Example Program
#include <stdio.h>
#include <stdlib.h>

// Queue structure
typedef struct {
  int* arr;
  int front;
  int rear;
  int capacity;
} Queue;

// Function to create a new queue
Queue* createQueue(int capacity) {
  Queue* queue = (Queue*)malloc(sizeof(Queue));
  queue->arr = (int*)malloc(capacity * sizeof(int));
  queue->front = -1;
  queue->rear = -1;
  queue->capacity = capacity;
  return queue;
}

// Function to enqueue an element
void enqueue(Queue* queue, int element) {
  if (queue->rear == queue->capacity - 1) {
    printf("Queue is full\n");
    return;
  }
  queue->rear++;
  queue->arr[queue->rear] = element;
}

// Function to dequeue an element
int dequeue(Queue* queue) {
  if (queue->front == queue->rear) {
    printf("Queue is empty\n");
    return -1;
  }
  int element = queue->arr[queue->front + 1];
  queue->front++;
  return element;
}

// Function to display the queue
void displayQueue(Queue* queue) {
  int i;
  printf("Queue: ");
  for (i = queue->front + 1; i <= queue->rear; i++) {
    printf("%d ", queue->arr[i]);
  }
  printf("\n");
}

// Driver code
int main() {
  Queue* queue = createQueue(5);
  enqueue(queue, 10);
  enqueue(queue, 20);
  enqueue(queue, 30);
  displayQueue(queue);
  int element = dequeue(queue);
  printf("Dequeued element: %d\n", element);
  displayQueue(queue);
  return 0;
}