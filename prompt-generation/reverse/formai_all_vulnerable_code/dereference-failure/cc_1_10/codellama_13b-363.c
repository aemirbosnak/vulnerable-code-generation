//Code Llama-13B DATASET v1.0 Category: Queue Implementation ; Style: automated
// Queue implementation example program

#include <stdio.h>
#include <stdlib.h>

// Define the queue structure
typedef struct {
  int *arr;
  int front;
  int rear;
  int size;
} Queue;

// Initialize the queue
Queue *init_queue(int size) {
  Queue *q = malloc(sizeof(Queue));
  q->arr = malloc(sizeof(int) * size);
  q->front = 0;
  q->rear = 0;
  q->size = size;
  return q;
}

// Enqueue an element
void enqueue(Queue *q, int data) {
  if (q->rear == q->size - 1) {
    printf("Queue is full\n");
    return;
  }
  q->arr[q->rear++] = data;
}

// Dequeue an element
int dequeue(Queue *q) {
  if (q->front == q->rear) {
    printf("Queue is empty\n");
    return -1;
  }
  return q->arr[q->front++];
}

// Display the queue
void display_queue(Queue *q) {
  printf("Queue: ");
  for (int i = q->front; i < q->rear; i++) {
    printf("%d ", q->arr[i]);
  }
  printf("\n");
}

// Driver code
int main() {
  Queue *q = init_queue(5);
  enqueue(q, 10);
  enqueue(q, 20);
  enqueue(q, 30);
  display_queue(q);
  printf("Dequeued element: %d\n", dequeue(q));
  display_queue(q);
  return 0;
}