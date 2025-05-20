//FormAI DATASET v1.0 Category: Queue Implementation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 10

typedef struct {
   int arr[MAX_SIZE];
   int front;
   int rear;
} queue;

void init(queue *q) {
   q->front = -1;
   q->rear = -1;
}

bool isEmpty(queue *q) {
   return q->front == -1;
}

bool isFull(queue *q) {
   return (q->rear + 1) % MAX_SIZE == q->front;
}

void enqueue(queue *q, int n) {
   if (isFull(q)) {
      printf("Queue is full!\n");
      return;
   }
   
   if (isEmpty(q)) {
      q->front = 0;
   }
   
   q->rear = (q->rear + 1) % MAX_SIZE;
   q->arr[q->rear] = n;
}

int dequeue(queue *q) {
   if (isEmpty(q)) {
      printf("Queue is empty!\n");
      return -1;
   }
   
   int data = q->arr[q->front];
   
   if (q->front == q->rear) {
      init(q);
   }
   else {
      q->front = (q->front + 1) % MAX_SIZE;
   }
   
   return data;
}

void display(queue *q) {
   if (isEmpty(q)) {
      printf("Queue is empty!\n");
      return; 
   }
   
   printf("Queue: ");
   
   int i;
   for (i = q->front; i != q->rear; i = (i + 1) % MAX_SIZE) {
      printf("%d ", q->arr[i]);
   }
   printf("%d\n", q->arr[i]);
}

int main() {
   queue q;
   init(&q);
   
   printf("Welcome to the post-apocalyptic world!\n");
   printf("You have found a queue system!\n");
   
   while (true) {
      printf("\n1. Enqueue\n");
      printf("2. Dequeue\n");
      printf("3. Display\n");
      printf("4. Quit\n");
      
      int choice;
      printf("Enter your choice: ");
      scanf("%d", &choice);
      
      switch(choice) {
         case 1: {
            int n;
            printf("Enter element to enqueue: ");
            scanf("%d", &n);
            enqueue(&q, n);
            break;
         }
         
         case 2: {
            int data = dequeue(&q);
            if (data != -1) {
               printf("Dequeued element: %d\n", data);
            }
            break;
         }
         
         case 3: {
            display(&q);
            break;
         }
         
         case 4: {
            printf("Goodbye!\n");
            exit(0);
         }
         
         default: {
            printf("Invalid choice!\n");
         }
      }
   }
   
   return 0;
}