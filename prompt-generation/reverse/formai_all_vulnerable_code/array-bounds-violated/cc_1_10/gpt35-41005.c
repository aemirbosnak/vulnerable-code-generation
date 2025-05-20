//FormAI DATASET v1.0 Category: Queue Implementation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

int queue[MAX_SIZE];
int front = -1, rear = -1;

void enqueue(int num) {
  if (rear == MAX_SIZE - 1 && front == 0 || rear == front - 1) {
    printf("Sorry, the queue is full!\n");
  } else if (front == -1 && rear == -1) {
    front = rear = 0;
    queue[rear] = num;
  } else if (rear == MAX_SIZE - 1) {
    rear = 0;
    queue[rear] = num;
  } else {
    rear++;
    queue[rear] = num;
  }
}

int dequeue() {
  if (front == -1) {
    printf("Sorry, the queue is empty!\n");
    return -1;
  } else {
    int dequeued = queue[front];
    if (front == rear) {
      front = rear = -1;
    } else if (front == MAX_SIZE - 1) {
      front = 0;
    } else {
      front++;
    }
    return dequeued;
  }
}

void display() {
  int i;
  printf("\n");
  printf("------------------------------\n");
  printf("FRONT: %d \t REAR: %d\n", front, rear);
  printf("------------------------------\n");
  printf("QUEUE: ");
  if (front <= rear) {
    for (i = front; i <= rear; i++) {
      printf("%d ", queue[i]);
    }
  } else {
    for (i = front; i <= MAX_SIZE - 1; i++) {
      printf("%d ", queue[i]);
    }
    for (i = 0; i <= rear; i++) {
      printf("%d ", queue[i]);
    }
  }
  printf("\n");
}

int main() {

  int choice, num;

  do {
    printf("\n---------- MENU ----------\n");
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Display\n");
    printf("4. Exit\n");
    printf("---------------------------\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        printf("\nEnter a number to enqueue: ");
        scanf("%d", &num);
        enqueue(num);
        break;
      case 2:
        printf("\nDequeuing item %d\n", dequeue());
        break;
      case 3:
        display();
        break;
      case 4:
        printf("\nExiting program...\n\n");
        exit(0);
      default:
        printf("\nInvalid choice!\n");
        break;
    }

  } while (1);

  return 0;
}