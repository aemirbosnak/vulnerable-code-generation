//FormAI DATASET v1.0 Category: Queue Implementation ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>

#define SIZE 5                // Maximum size of the queue

int queue[SIZE];              // Declaring an array of SIZE to hold the queue elements
int front = -1, rear = -1;    // Initializing the front and rear variables to -1
 
void enqueue(int val) {
   if (rear == SIZE-1) {           // Checking if the queue is full
      printf("\nQueue is overflow!");
      return;
   }
   queue[++rear] = val;           // If the queue is not full, insert the element at the rear position
   if (front == -1)               // If queue is empty, initialize the front variable
      front = 0;
}
 
void dequeue() {
   if (front == -1) {           // Checking if the queue is empty
      printf("\nQueue is underflow!");
      return;
   }
   printf("Deleted : %d\n", queue[front]);
   if (front == rear)           // If there is only one element in the queue, reset the front and rear variables
      front = rear = -1;
   else
      front++;                 // If there are more elements in the queue, move the front pointer to the next position
}
 
void display() {
   if (rear == -1) {            // Checking if the queue is empty
      printf("\nQueue is empty!");
      return;
   }
   int i;
   printf("\nQueue elements are:\n");
   for (i = front; i <= rear; i++)    // Traversing the queue from front to rear
      printf("%d\t", queue[i]);
}
 
int main() {
   int ch, val;
   while(1) {
      printf("\nQueue Operations:\n");
      printf("1.EnQueue\n2.DeQueue\n3.Display\n4.Exit\n");
      printf("Enter your choice : ");
      scanf("%d", &ch);
      switch(ch) {
         case 1: printf("\nEnter value to insert : ");
                 scanf("%d", &val);
                 enqueue(val);
                 break;
         case 2: dequeue();
                 break;
         case 3: display();
                 break;
         case 4: exit(0);
         default: printf("\nInvalid choice!");
      }
   }
   return 0;
}