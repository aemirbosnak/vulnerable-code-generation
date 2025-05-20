//Code Llama-13B DATASET v1.0 Category: Queue Implementation ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int *arr;
  int size;
  int front;
  int rear;
} Queue;

void init(Queue *q, int size) {
  q->arr = malloc(size * sizeof(int));
  q->size = size;
  q->front = -1;
  q->rear = -1;
}

int isEmpty(Queue *q) {
  return (q->front == -1 && q->rear == -1);
}

int isFull(Queue *q) {
  return (q->rear == q->size - 1);
}

void enqueue(Queue *q, int item) {
  if (isFull(q)) {
    printf("Queue is full\n");
    return;
  }
  q->rear++;
  q->arr[q->rear] = item;
}

int dequeue(Queue *q) {
  if (isEmpty(q)) {
    printf("Queue is empty\n");
    return -1;
  }
  int item = q->arr[q->front];
  q->front++;
  return item;
}

void display(Queue *q) {
  printf("Queue: ");
  for (int i = q->front; i <= q->rear; i++) {
    printf("%d ", q->arr[i]);
  }
  printf("\n");
}

int main() {
  Queue q;
  init(&q, 5);

  enqueue(&q, 1);
  enqueue(&q, 2);
  enqueue(&q, 3);
  display(&q);

  dequeue(&q);
  display(&q);

  enqueue(&q, 4);
  enqueue(&q, 5);
  display(&q);

  dequeue(&q);
  display(&q);

  dequeue(&q);
  display(&q);

  dequeue(&q);
  display(&q);

  dequeue(&q);
  display(&q);

  return 0;
}