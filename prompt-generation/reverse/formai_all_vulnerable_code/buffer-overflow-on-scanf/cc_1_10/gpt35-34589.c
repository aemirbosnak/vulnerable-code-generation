//FormAI DATASET v1.0 Category: Queue ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_SIZE 5

int front = -1, rear = -1, queue[MAX_SIZE];

bool isFull() {
  return ((rear == MAX_SIZE-1 && front == 0) || (front == rear+1));
}

bool isEmpty() {
  return (front == -1 && rear == -1);
}

void enqueue(int item) {
  if (isFull()) {
    printf("Queue is full\n");
    return;
  } else if (isEmpty()) {
    front = rear = 0;
  } else {
    if (rear == MAX_SIZE-1)
      rear = 0;
    else
      rear++;
  }
  queue[rear] = item;
  printf("%d added\n", item);
}

int dequeue() {
  int value;
  if (isEmpty()) {
    printf("Queue is empty\n");
    return -1;
  } else if (front == rear) {
    value = queue[front];
    front = rear = -1;
  } else {
    if (front == MAX_SIZE-1)
      front = 0;
    else
      front++;
    value = queue[front];
  }
  return value;
}

void display() {
  int i;
  if (isEmpty()) {
    printf("Queue is empty\n");
  } else {
    printf("Queue elements are: ");
    if (front <= rear) {
      for (i=front; i<=rear; i++)
        printf("%d ", queue[i]);
    } else {
      for (i=front; i<=MAX_SIZE-1; i++)
        printf("%d ", queue[i]);
      for (i=0; i<=rear; i++)
        printf("%d ", queue[i]);
    }
    printf("\n");
  }
}

int main() {
  int choice, item;

  printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");

  do {
    printf("Enter choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        printf("Enter element: ");
        scanf("%d", &item);
        enqueue(item);
        break;
      case 2:
        printf("%d removed\n", dequeue());
        break;
      case 3:
        display();
        break;
      case 4:
        exit(0);
        break;
      default:
        printf("Invalid choice\n");
        break;
    }
  } while (choice != 4);

  return 0;
}