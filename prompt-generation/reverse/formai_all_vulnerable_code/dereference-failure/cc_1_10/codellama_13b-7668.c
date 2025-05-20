//Code Llama-13B DATASET v1.0 Category: Queue Implementation ; Style: interoperable
// unique_queue.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUEUE_SIZE 100

typedef struct {
  int size;
  int front;
  int rear;
  int *arr;
} Queue;

void init_queue(Queue *q) {
  q->size = MAX_QUEUE_SIZE;
  q->front = 0;
  q->rear = 0;
  q->arr = (int *)malloc(q->size * sizeof(int));
}

void enqueue(Queue *q, int data) {
  if (q->rear == q->size) {
    printf("Queue is full.\n");
    return;
  }
  q->arr[q->rear] = data;
  q->rear++;
}

int dequeue(Queue *q) {
  if (q->front == q->rear) {
    printf("Queue is empty.\n");
    return -1;
  }
  int data = q->arr[q->front];
  q->front++;
  return data;
}

int main() {
  Queue q;
  init_queue(&q);
  enqueue(&q, 1);
  enqueue(&q, 2);
  enqueue(&q, 3);
  printf("Dequeued value: %d\n", dequeue(&q));
  printf("Dequeued value: %d\n", dequeue(&q));
  enqueue(&q, 4);
  printf("Dequeued value: %d\n", dequeue(&q));
  printf("Dequeued value: %d\n", dequeue(&q));
  return 0;
}