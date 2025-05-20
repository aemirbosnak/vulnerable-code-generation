//FormAI DATASET v1.0 Category: Queue ; Style: brave
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

int queue[MAX_SIZE];
int front = -1;
int rear = -1;

void insert(int value) {
  if ((front == 0 && rear == MAX_SIZE - 1) || (front == rear + 1)) {
    printf("Queue Overflow\n");
    return;
  }

  if (front == -1) {
    front = 0;
    rear = 0;
  } else {
    if (rear == MAX_SIZE - 1) {
      rear = 0;
    } else {
      rear++;
    }
  }

  queue[rear] = value;
}

void delete() {
  if (front == -1) {
    printf("Queue Underflow\n");
    return;
  }

  printf("Deleted item is: %d\n", queue[front]);

  if (front == rear) {
    front = -1;
    rear = -1;
  } else {
    if (front == MAX_SIZE - 1) {
      front = 0;
    } else {
      front++;
    }
  }
}

void display() {
  int i;

  if (front == -1) {
    printf("Queue is empty\n");
    return;
  }

  printf("Queue elements are:\n");

  if (rear >= front) {
    for (i = front; i <= rear; i++) {
      printf("%d ", queue[i]);
    }
  } else {
    for (i = front; i < MAX_SIZE; i++) {
      printf("%d ", queue[i]);
    }

    for (i = 0; i <= rear; i++) {
      printf("%d ", queue[i]);
    }
  }

  printf("\n");
}

int main() {
  int choice, value;

  while (1) {
    printf("1. Insert\n");
    printf("2. Delete\n");
    printf("3. Display\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        printf("Enter the value to be inserted: ");
        scanf("%d", &value);
        insert(value);
        break;
      case 2:
        delete();
        break;
      case 3:
        display();
        break;
      case 4:
        printf("Exiting the program\n");
        exit(0);
        break;
      default:
        printf("Invalid choice\n");
    }
  }

  return 0;
}