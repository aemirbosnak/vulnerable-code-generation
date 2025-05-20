//FormAI DATASET v1.0 Category: Queue Implementation ; Style: active
#include <stdio.h>
#define MAX_SIZE 10

int front = 0, rear = -1;
int queue[MAX_SIZE];

void enqueue(int item) {
   if(rear == MAX_SIZE-1) {
      printf("\nQueue is full!");
   } else {
      rear++;
      queue[rear] = item;
      printf("\nInserted -> %d", item);
   }
}

void dequeue() {
   if(rear < front)
      printf("\nQueue is empty!");
   else {
      printf("\nDeleted : %d", queue[front]);
      front++;
   }
}

void display() {
   if(rear < front)
      printf("\nQueue is empty!");
   else {
      int i;
      printf("\nQueue elements: ");
      for(i=front; i<=rear; i++)
         printf("%d  ",queue[i]);
   }
}

int main() {
   int choice, value;
   while(1){
      printf("\n\nQueue Menu\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit");
      printf("\nEnter your choice: ");
      scanf("%d",&choice);
      switch(choice) {
         case 1: 
            printf("\nEnter the value to be inserted: ");
            scanf("%d", &value);
            enqueue(value);
            break;
         case 2:
            dequeue();
            break;
         case 3:
            display();
            break;
         case 4:
            printf("\nExiting...");
            return 0;
         default:
            printf("\nInvalid choice!");
      }   
   }
   return 0;
}