//FormAI DATASET v1.0 Category: Queue Implementation ; Style: safe
#include<stdio.h>
#include<stdlib.h>

#define MAX_QUEUE_SIZE 100

int queue[MAX_QUEUE_SIZE];
int front = -1;
int rear = -1;

// function to check if the queue is empty
int isQueueEmpty() {
   if(front == -1 || front > rear)
      return 1;
   else
      return 0;
}
 
// function to check if the queue is full
int isQueueFull() {
   if(rear == MAX_QUEUE_SIZE-1)
      return 1;
   else
      return 0;
}

// function to add elements to the queue
void enqueue(int element) {
   if(isQueueFull())
      printf("Queue is full");
   else {
      if(front == -1)
         front = 0;
      rear++;
      queue[rear] = element;
   }
}

// function to remove elements from the queue
void dequeue() {
   if(isQueueEmpty())
      printf("Queue is empty");
   else {
      printf("Element dequeued: %d\n", queue[front]);
      front++;
   }
}

// function to display the elements of the queue
void displayQueue() {
   if(isQueueEmpty())
      printf("Queue is empty");
   else {
      printf("Elements in the queue are: ");
      for(int i=front; i<=rear; i++)
         printf("%d ", queue[i]);
      printf("\n");
   }
}

int main() {
   int choice, element;
   
   do {
      printf("\n\n--------MENU--------");
      printf("\n1. Insert element into queue");
      printf("\n2. Remove element from queue");
      printf("\n3. Display elements in the queue");
      printf("\n4. Exit");
      printf("\n\nEnter your choice (1-4): ");
      scanf("%d", &choice);
      
      switch(choice) {
         case 1:
            printf("\nEnter the element to be inserted: ");
            scanf("%d", &element);
            enqueue(element);
            break;
         case 2:
            dequeue();
            break;
         case 3:
            displayQueue();
            break;
         case 4:
            exit(0);
            break;
         default:
            printf("\nInvalid input");
            break;
      }
   } while(choice != 4);

   return 0;
}