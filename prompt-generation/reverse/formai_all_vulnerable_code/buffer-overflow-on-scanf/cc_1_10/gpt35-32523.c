//FormAI DATASET v1.0 Category: Queue Implementation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100 // Maximum size of the queue

int queue[MAX_SIZE]; // Declare the queue
int front = -1; // Declare front and rear variables
int rear = -1;

// Function to check if the queue is empty
bool is_empty() {
   return front == -1;
}

// Function to check if the queue is full
bool is_full() {
   return rear == MAX_SIZE - 1;
}

// Function to add an element to the queue
void enqueue(int element) {
   if(is_full()) {
      printf("Queue is full\n");
   } else {
      if(front == -1) {
         front = 0;
      }
      rear++;
      queue[rear] = element;
      printf("%d added to the queue\n", element);
   }
}

// Function to remove an element from the queue
void dequeue() {
   if(is_empty()) {
      printf("Queue is empty\n");
   } else {
      printf("%d removed from the queue\n", queue[front]);
      front++;
      if(front > rear) {
         front = rear = -1;
      }
   }
}

// Function to display the elements in the queue
void display() {
   if(is_empty()) {
      printf("Queue is empty\n");
   } else {
      printf("Elements in the queue: ");
      for(int i = front; i <= rear; i++) {
         printf("%d ", queue[i]);
      }
      printf("\n");
   }
}

int main() {
   int choice, element;
   do {
      printf("Choose an operation:\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
      scanf("%d", &choice);
      switch(choice) {
         case 1:
            printf("Enter element to add: ");
            scanf("%d", &element);
            enqueue(element);
            break;
         case 2:
            dequeue();
            break;
         case 3:
            display();
            break;
         case 4:
            printf("Exiting program\n");
            break;
         default:
            printf("Invalid choice\n");
      }
   } while(choice != 4);
   return 0;
}