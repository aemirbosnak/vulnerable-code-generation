//Code Llama-13B DATASET v1.0 Category: Queue Implementation ; Style: Alan Turing
#include <stdio.h>
  #include <stdlib.h>
  #include <string.h>

  struct Queue {
    int size;
    int front;
    int rear;
    int *data;
  };

  void init(struct Queue *q, int size) {
    q->size = size;
    q->front = 0;
    q->rear = 0;
    q->data = (int *)malloc(size * sizeof(int));
  }

  int isEmpty(struct Queue *q) {
    return q->front == q->rear;
  }

  int isFull(struct Queue *q) {
    return q->front == (q->rear + 1) % q->size;
  }

  void enqueue(struct Queue *q, int x) {
    if (isFull(q)) {
      printf("Queue is full\n");
      return;
    }
    q->data[q->rear] = x;
    q->rear = (q->rear + 1) % q->size;
  }

  int dequeue(struct Queue *q) {
    if (isEmpty(q)) {
      printf("Queue is empty\n");
      return -1;
    }
    int x = q->data[q->front];
    q->front = (q->front + 1) % q->size;
    return x;
  }

  int main() {
    struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
    init(q, 5);
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);
    enqueue(q, 5);
    printf("Queue: ");
    for (int i = q->front; i != q->rear; i = (i + 1) % q->size) {
      printf("%d ", q->data[i]);
    }
    printf("\n");
    printf("Dequeued element: %d\n", dequeue(q));
    printf("Dequeued element: %d\n", dequeue(q));
    printf("Dequeued element: %d\n", dequeue(q));
    printf("Dequeued element: %d\n", dequeue(q));
    printf("Dequeued element: %d\n", dequeue(q));
    return 0;
  }