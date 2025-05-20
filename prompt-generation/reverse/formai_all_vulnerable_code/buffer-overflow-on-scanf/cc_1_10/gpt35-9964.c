//FormAI DATASET v1.0 Category: Queue ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#define MAX 5

struct Queue
{
     int front, rear;
     int items[MAX];
};

typedef struct Queue queue;

int isFull(queue *q)
{
     if ((q->rear + 1) % MAX == q->front)
     {
          return 1;
     }
     return 0;
}

int isEmpty(queue *q)
{
     if (q->front == q->rear)
     {
          return 1;
     }
     return 0;
}

void enqueue(queue *q, int element)
{
     if (isFull(q))
     {
          printf("Queue is Full\n");
     }
     else
     {
          q->rear = (q->rear + 1) % MAX;
          q->items[q->rear] = element;
          printf("Inserted -> %d\n", element);
     }
}

int dequeue(queue *q)
{
     int element;
     if (isEmpty(q))
     {
          printf("Queue is Empty\n");
          return (-1);
     }
     else
     {
          element = q->items[q->front];
          printf("Deleted element -> %d\n", element);
          q->front = (q->front + 1) % MAX;
          return (element);
     }
}

void display(queue *q)
{
     int i;
     if (isEmpty(q))
     {
          printf("Queue is Empty\n");
     }
     else
     {
          printf("Queue Elements are:\n");
          for (i = q->front; i != q->rear; i = (i + 1) % MAX)
          {
               printf("%d ", q->items[i]);
          }
          printf("%d ", q->items[i]);
     }
}

int main()
{
     queue *q = (queue *)malloc(sizeof(queue));
     q->front = 0;
     q->rear = 0;
     int choice, element;

     while (1)
     {
          printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
          printf("Enter your Choice:");
          scanf("%d", &choice);
          switch (choice)
          {
          case 1:
               printf("Enter the element: ");
               scanf("%d", &element);
               enqueue(q, element);
               break;
          case 2:
               dequeue(q);
               break;
          case 3:
               display(q);
               break;
          case 4:
               exit(1);
          default:
               printf("Invalid Choice\n");
               break;
          }
     }
     return 0;
}