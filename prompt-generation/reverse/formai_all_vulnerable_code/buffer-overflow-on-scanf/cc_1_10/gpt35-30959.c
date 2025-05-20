//FormAI DATASET v1.0 Category: Queue Implementation ; Style: synchronous
#include<stdio.h>
#include<stdlib.h>

#define QUEUE_SIZE 10

int queue[QUEUE_SIZE];
int front = -1, rear = -1;

void enqueue(int value) {

  if ((rear + 1) % QUEUE_SIZE == front) {
    printf("\nQueue overflow!\n");
    return;
  }

  if (front == -1) {
    front = rear = 0;
  } else {
    rear = (rear + 1) % QUEUE_SIZE;
  }

  queue[rear] = value;
}

int dequeue() {
  if (front == -1) {
    printf("\nQueue underflow!\n");
    return -1; // Using -1 to denote an invalid value since 0 could be a valid value to enqueue
  }

  int value = queue[front];

  if (front == rear) {
    front = rear = -1;
  } else {
    front = (front + 1) % QUEUE_SIZE;
  }

  return value;
}

void display() {
  if (front == -1 && rear == -1) {
    printf("\nQueue is empty!\n");
    return;
  }

  printf("\nQueue: ");
  for (int i = front; i != rear; i = (i + 1) % QUEUE_SIZE) {
    printf("%d ", queue[i]);
  }
  printf("%d\n", queue[rear]);
}

int main() {
  int choice, value;

  do {
    printf("\n1. Enqueue \n2. Dequeue\n3. Display\n4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        printf("Enter the value to enqueue: ");
        scanf("%d", &value);
        enqueue(value);
        break;
      case 2:
        printf("Dequeueing element: %d\n", dequeue());
        break;
      case 3:
        display();
        break;
      case 4:
        printf("\nExiting program...\n");
        break;
      default:
        printf("\nInvalid choice!\n");
    }
  } while (choice != 4);

  return 0;
}