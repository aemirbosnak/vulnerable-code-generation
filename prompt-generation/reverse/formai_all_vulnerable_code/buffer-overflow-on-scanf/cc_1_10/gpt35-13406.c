//FormAI DATASET v1.0 Category: Queue Implementation ; Style: enthusiastic
#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 100

// This is a unique implementation of Circular Queue
// Lets code and have fun!

int queue[MAX_SIZE], front = -1, rear = -1;

void enqueue(int element) {
  if((rear+1)%MAX_SIZE==front) {
    printf("Queue Overflow!\n");
  }
  else {
      rear = (rear+1) % MAX_SIZE;
      queue[rear] = element;
      if(front==-1) {
          front = 0;
      }
      printf("Element %d has been enqueued.\n", element);
  }
}

int dequeue() {
    int dequeuedElement = 0;
    if(front==-1) {
        printf("Queue Underflow!\n");
        return 0;
    }
    else {
        dequeuedElement = queue[front];
        if(front==rear) {
            front = rear = -1;
        }
        else {
            front = (front+1) % MAX_SIZE;
        }
    }
    printf("Element %d has been dequeued.\n", dequeuedElement);
    return dequeuedElement;
}

int main() {
    int choice, element, dequeuedElement;
    do {
        printf("Enter 1 to Enqueue.\n");
        printf("Enter 2 to Dequeue.\n");
        printf("Enter 3 to Exit.\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1: printf("Enter element to Enqueue: ");
                    scanf("%d", &element);
                    enqueue(element);
                    break;

            case 2: dequeuedElement = dequeue();
                    break;

            case 3: printf("Exiting Program...");
                    exit(0);

            default:printf("Invalid Choice!\n");
        }
    } while(choice!=3);
    return 0;
}