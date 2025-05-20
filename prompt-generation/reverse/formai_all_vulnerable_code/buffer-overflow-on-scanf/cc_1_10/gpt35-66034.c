//FormAI DATASET v1.0 Category: Queue Implementation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 50

typedef struct{
  int front, rear;
  int data[MAX_QUEUE_SIZE];
}Queue;

void initQueue(Queue *q){
  q->front = q->rear = 0;
}

int isQueueEmpty(Queue *q){
  return q->front == q->rear;
}

int isQueueFull(Queue *q){
  return (q->rear + 1) % MAX_QUEUE_SIZE == q->front;
}

void enqueue(Queue *q, int item){
  if(isQueueFull(q)){
    printf("Queue is full!\n");
    return;
  }
  q->data[q->rear] = item;
  q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
}

int dequeue(Queue *q){
  if(isQueueEmpty(q)){
    printf("Queue is empty!\n");
    return -1;
  }
  int item = q->data[q->front];
  q->front = (q->front + 1) % MAX_QUEUE_SIZE;
  return item;
}

void printQueue(Queue *q){
  if(isQueueEmpty(q)){
    printf("Queue is empty!\n");
    return;
  }
  printf("Queue elements are: ");
  int i = q->front;
  while(i != q->rear){
    printf("%d ",q->data[i]);
    i = (i + 1) % MAX_QUEUE_SIZE;
  }
  printf("\n");
}

int main(){
  Queue q;
  initQueue(&q);

  printf("Welcome to Neo's Queue, Operator.\n");

  while(1){
    int choice, item;
    printf("Enter your choice:\n");
    printf("1. Enqueue an item\n");
    printf("2. Dequeue an item\n");
    printf("3. Print the queue\n");
    printf("4. Exit the program\n");
    scanf("%d",&choice);

    switch(choice){
      case 1:
        printf("Enter the item to enqueue: ");
        scanf("%d",&item);
        enqueue(&q, item);
        printf("Item %d has been successfully enqueued into Neo's Queue.\n", item);
        break;
      case 2:
        item = dequeue(&q);
        if(item != -1)
          printf("Item %d has been successfully dequeued from Neo's Queue.\n", item);
        break;
      case 3:
        printQueue(&q);
        break;
      case 4:
        printf("Exiting Neo's Queue. Goodbye, Operator.\n");
        exit(0);
      default:
        printf("Invalid choice!\n");
    }
  }
  return 0;
}