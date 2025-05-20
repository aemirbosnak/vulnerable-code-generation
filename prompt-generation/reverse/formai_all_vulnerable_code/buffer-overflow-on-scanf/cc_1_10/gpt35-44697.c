//FormAI DATASET v1.0 Category: Queue Implementation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

int front = -1, rear = -1;
int queue[MAX_SIZE];

void enqueue(int element) {
  if(rear == MAX_SIZE-1) {
    printf("Queue is full\n");
    return;
  }
  else if(front == -1 && rear == -1) {
    front = rear = 0;
    queue[rear] = element;
  }
  else {
    rear++;
    queue[rear] = element;
  }
  printf("Element %d has been inserted into the queue\n", element);
}

int dequeue() {
  int removed_element;
  if(front == -1 && rear == -1) {
    printf("Queue is empty\n");
    return -1;
  }
  else if(front == rear) {
    removed_element = queue[front];
    front = rear = -1;
  }
  else {
    removed_element = queue[front];
    front++;
  }
  printf("Element %d has been removed from the queue\n", removed_element);
  return removed_element;
}

void display() {
  if(front == -1 && rear == -1) {
    printf("Queue is empty\n");
    return;
  }
  printf("The elements of the queue are: ");
  for(int i=front; i<=rear; i++) {
    printf("%d ", queue[i]);
  }
  printf("\n");
}

int main() {
  int choice, element;
  do {
    printf("-----------MENU-----------\n");
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Display\n");
    printf("4. Exit\n");
    printf("Please enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
      case 1: {
        printf("Please enter the element you want to insert: ");
        scanf("%d", &element);
        enqueue(element);
        break;
      }
      case 2: {
        dequeue();
        break;
      }
      case 3: {
        display();
        break;
      }
      case 4: {
        printf("Thank you for using the program!\n");
        exit(0);
      }
      default: printf("Invalid choice, please try again!\n");
    }
  } while(choice != 4);

  return 0;
}