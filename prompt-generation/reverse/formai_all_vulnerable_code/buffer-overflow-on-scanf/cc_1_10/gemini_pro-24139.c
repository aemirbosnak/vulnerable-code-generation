//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Queue {
  int front, rear;
  int size;
  int *array;
};

struct Queue* createQueue(int size) {
  struct Queue *queue = (struct Queue*) malloc(sizeof(struct Queue));
  queue->front = queue->rear = -1;
  queue->size = size;
  queue->array = (int*) malloc(queue->size * sizeof(int));
  return queue;
}

int isEmpty(struct Queue *queue) {
  return queue->front == -1;
}

int isFull(struct Queue *queue) {
  return (queue->rear + 1) % queue->size == queue->front;
}

void enqueue(struct Queue *queue, int data) {
  if (isFull(queue)) {
    printf("Queue is full!\n");
    return;
  }
  else {
    if (isEmpty(queue)) {
      queue->front = queue->rear = 0;
    }
    else {
      queue->rear = (queue->rear + 1) % queue->size;
    }
    queue->array[queue->rear] = data;
  }
}

int dequeue(struct Queue *queue) {
  if (isEmpty(queue)) {
    printf("Queue is empty!\n");
    return -1;
  }
  else {
    int data = queue->array[queue->front];
    if (queue->front == queue->rear) {
      queue->front = queue->rear = -1;
    }
    else {
      queue->front = (queue->front + 1) % queue->size;
    }
    return data;
  }
}

void display(struct Queue *queue) {
  if (isEmpty(queue)) {
    printf("Queue is empty!\n");
  }
  else {
    int i = queue->front;
    while (i != queue->rear) {
      printf("%d  ", queue->array[i]);
      i = (i + 1) % queue->size;
    }
    printf("%d\n", queue->array[queue->rear]);
  }
}

int main() {
  int choice, data;
  struct Queue *queue = createQueue(MAX_SIZE);

  while (1) {
    printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        printf("Enter data to enqueue: ");
        scanf("%d", &data);
        enqueue(queue, data);
        break;
      case 2:
        data = dequeue(queue);
        if (data != -1)
          printf("Dequeued data: %d\n", data);
        break;
      case 3:
        display(queue);
        break;
      case 4:
        exit(0);
      default:
        printf("Invalid choice!\n");
    }
  }

  return 0;
}