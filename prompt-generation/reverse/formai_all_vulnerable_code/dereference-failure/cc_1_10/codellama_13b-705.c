//Code Llama-13B DATASET v1.0 Category: Queue Implementation ; Style: surrealist
// A unique C Queue Implementation in a surrealist style
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Queue {
  int *data;
  int size;
  int front;
  int rear;
};

void init(struct Queue *q, int size) {
  q->data = malloc(size * sizeof(int));
  q->size = size;
  q->front = -1;
  q->rear = -1;
}

int is_empty(struct Queue *q) {
  return q->front == -1 && q->rear == -1;
}

int is_full(struct Queue *q) {
  return q->rear == q->size - 1;
}

void enqueue(struct Queue *q, int value) {
  if (is_full(q)) {
    printf("Queue is full\n");
    return;
  }
  q->rear = (q->rear + 1) % q->size;
  q->data[q->rear] = value;
}

int dequeue(struct Queue *q) {
  if (is_empty(q)) {
    printf("Queue is empty\n");
    return -1;
  }
  q->front = (q->front + 1) % q->size;
  return q->data[q->front];
}

int main() {
  struct Queue q;
  init(&q, 5);
  enqueue(&q, 1);
  enqueue(&q, 2);
  enqueue(&q, 3);
  enqueue(&q, 4);
  enqueue(&q, 5);
  printf("Queue size: %d\n", q.size);
  printf("Queue front: %d\n", q.front);
  printf("Queue rear: %d\n", q.rear);
  printf("Dequeued element: %d\n", dequeue(&q));
  printf("Dequeued element: %d\n", dequeue(&q));
  printf("Dequeued element: %d\n", dequeue(&q));
  printf("Dequeued element: %d\n", dequeue(&q));
  printf("Dequeued element: %d\n", dequeue(&q));
  return 0;
}