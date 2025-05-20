//FormAI DATASET v1.0 Category: Queue ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5 // Maximum size of the queue

typedef struct {
  int data[MAX_SIZE];
  int front;
  int rear;
} Queue;

void enqueue(Queue *q, int item) {
  if ((q->rear + 1) % MAX_SIZE == q->front) {
    printf("Queue is full\n");
    return;
  }
  q->data[q->rear] = item;
  q->rear = (q->rear + 1) % MAX_SIZE;
}

int dequeue(Queue *q) {
  if (q->front == q->rear) {
    printf("Queue is empty\n");
    return -1;
  }
  int item = q->data[q->front];
  q->front = (q->front + 1) % MAX_SIZE;
  return item;
}

void display(Queue *q) {
  int i;
  if (q->front == q->rear) {
    printf("Queue is empty\n");
    return;
  }
  printf("Elements in queue: ");
  for (i = q->front; i != q->rear; i = (i + 1) % MAX_SIZE) {
    printf("%d ", q->data[i]);
  }
  printf("\n");
}

int main() {
  Queue q;
  q.front = 0;
  q.rear = 0;

  printf("Queue operations: \n");
  printf("1 - Enqueue item\n");
  printf("2 - Dequeue item\n");
  printf("3 - Display queue\n");
  printf("4 - Quit program\n");

  int choice, item;
  do {
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
      case 1:
        printf("Enter item to enqueue: ");
        scanf("%d", &item);
        enqueue(&q, item);
        break;
      case 2:
        item = dequeue(&q);
        if (item != -1) {
          printf("Item dequeued: %d\n", item);
        }
        break;
      case 3:
        display(&q);
        break;
      case 4:
        printf("Quitting program...\n");
        break;
      default:
        printf("Invalid choice\n");
    }
  } while(choice != 4);

  return 0;
}