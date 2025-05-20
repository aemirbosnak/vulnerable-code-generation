//FormAI DATASET v1.0 Category: Queue Implementation ; Style: Romeo and Juliet
// Romeo and Juliet's C Queue Implementation

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 10

int queue[MAX_SIZE];
int front = -1, rear = -1;

bool isFull() {
  return (rear == MAX_SIZE - 1);
}

bool isEmpty() {
  return (front == -1 && rear == -1);
}

void enqueue(int num) {
  if (isFull()) {
    printf("Alas, my love, the queue is full!\n");
  } else if (isEmpty()) {
    front = rear = 0;
    queue[rear] = num;
  } else {
    rear++;
    queue[rear] = num;
  }
}

int dequeue() {
  int num;
  if (isEmpty()) {
    printf("My sweet love, the queue be empty!\n");
    return -1;
  } else if (front == rear) {
    num = queue[front];
    front = rear = -1;
  } else {
    num = queue[front];
    front++;
  }
  return num;
}

int peek() {
  if (isEmpty()) {
    printf("Oh my love, the queue is empty!\n");
    return -1;
  } else {
    return queue[front];
  }
}

int main() {

  int choice, num;

  printf("Enter 1 to Enqueue\n");
  printf("Enter 2 to Dequeue\n");
  printf("Enter 3 to Peek\n");
  printf("Enter 4 to Exit\n");

  do {

    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
      case 1:
        printf("Enter the number to Enqueue: ");
        scanf("%d", &num);
        enqueue(num);
        break;
      case 2:
        num = dequeue();
        if (num != -1) {
          printf("Dequeued element: %d\n", num);
        }
        break;
      case 3:
        num = peek();
        if (num != -1) {
          printf("Peek element: %d\n", num);
        }
        break;
      case 4:
        printf("Farewell, my love!\n");
        break;
      default:
        printf("Oh, sweet music that hath charm'd my ears,\n"
               "Forsooth, thou hast choosen poorly!\n");
    }

  } while (choice != 4);

  return 0;
}