//FormAI DATASET v1.0 Category: Queue Implementation ; Style: optimized
#include<stdio.h>
#define SIZE 5 //size of queue

int queue[SIZE]; //queue declaration
int front = -1;
int rear = -1;

void enqueue(int value) { //function for enqueue operation
  if(rear==SIZE-1) { //queue full condition
    printf("Queue is full, cannot enqueue.\n");
  } else {
    if(front == -1) front = 0; //if queue is initially empty
    rear++;
    queue[rear] = value; //insert the value in the queue
    printf("The element %d has been inserted successfully in the queue.\n", value);
  }

}

void dequeue() { //function for dequeue operation
  if(front==-1 || front>rear) { //queue empty condition
    printf("Queue is empty, cannot dequeue.\n");
  } else {
    printf("The element %d has been removed successfully from the queue.\n", queue[front]);
    front++; //move the front pointer
  }
}

void display() { //function for displaying queue elements
  if(front==-1 || front>rear) { //queue empty condition
    printf("Queue is empty, nothing to display.\n");
  } else {
    printf("The queue elements are: ");
    for(int i=front;i<=rear;i++) {
      printf("%d ", queue[i]);
    }
    printf("\n");
  }
}

int main() { //driver function
  int choice, value;

  printf("Welcome to the Queue implementation program!\n");

  while(1) {
    printf("\n");
    printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
      case 1:
        printf("Enter the element to be enqueued: ");
        scanf("%d", &value);
        enqueue(value); //call enqueue function
        break;
      case 2:
        dequeue(); //call dequeue function
        break;
      case 3:
        display(); //call display function
        break;
      case 4:
        printf("Thank you for using the Queue implementation program! Bye.\n");
        return 0;
      default:
        printf("Invalid choice, try again.\n");
    }
  }
  return 0;
}