//FormAI DATASET v1.0 Category: Queue Implementation ; Style: detailed
#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 10

int queue[MAX_SIZE];
int front = -1;
int rear = -1;

bool isFull() {
  if (rear == MAX_SIZE - 1) {
    return true;
  } else {
    return false;
  }
}

bool isEmpty() {
  if (front == -1 || front == rear + 1) {
    return true;
  } else {
    return false;
  }
}

void enqueue(int num) {
  if (isFull()) {
    printf("Queue is full, cannot enqueue element.\n");
  } else {
    if (front == -1) {
      front = 0;
    }
    rear++;
    queue[rear] = num;
    printf("%d was enqueued into the queue.\n", num);
  }
}

void dequeue() {
  if (isEmpty()) {
    printf("Queue is empty, cannot dequeue element.\n");
  } else {
    int num = queue[front];
    printf("%d was dequeued from the queue.\n", num);
    front++;
  }
}

void displayQueue() {
  if (isEmpty()) {
    printf("Queue is empty, nothing to display.\n");
  } else {
    printf("Elements in the queue: ");
    for (int i = front; i <= rear; i++) {
      printf("%d ", queue[i]);
    }
    printf("\n");
  }
}

int main() {
  int choice, num;

  printf("C Queue Implementation Example Program\n");

  do {
    printf("\nMenu: \n");
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Display Queue\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        printf("Enter the number to enqueue: ");
        scanf("%d", &num);
        enqueue(num);
        break;
      case 2:
        dequeue();
        break;
      case 3:
        displayQueue();
        break;
      case 4:
        printf("Exiting program...\n");
        break;
      default:
        printf("Invalid choice, try again.\n");
    }
  } while (choice != 4);

  return 0;
}