//FormAI DATASET v1.0 Category: Queue Implementation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 5

int queue[MAX_SIZE];
int front = -1, rear = -1;

//function to insert element in the queue
void enqueue(int item){
  if(rear == MAX_SIZE-1){
    printf("Queue Overflow!");
    return;
  }
  else if(front == -1 && rear == -1){
    front = rear = 0;
    queue[rear] = item;
  }
  else{
    rear++;
    queue[rear] = item;
  }
}

//function to remove element from the queue
void dequeue(){
  if(front == -1 && rear == -1){
    printf("Queue Underflow!");
    return;
  }
  else if(front == rear){
    printf("%d is dequeued.\n", queue[front]);
    front = rear = -1;
  }
  else{
    printf("%d is dequeued.\n", queue[front]);
    front++;
  }
  if(front != -1 && rear != -1) dequeue();
}

int main(){
  int choice, item;
  printf("1. Enqueue \n2. Dequeue \n3. Exit\n");
  while(1){
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch(choice){
      case 1:
        printf("Enter the element to be enqueued: ");
        scanf("%d", &item);
        enqueue(item);
        break;

      case 2:
        dequeue();
        break;

      case 3:
        exit(0);
    }
  }
  return 0;
}