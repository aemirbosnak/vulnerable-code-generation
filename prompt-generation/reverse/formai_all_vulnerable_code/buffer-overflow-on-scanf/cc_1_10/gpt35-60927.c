//FormAI DATASET v1.0 Category: Queue Implementation ; Style: Ken Thompson
#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 20

typedef struct queue
{
    int data[MAX_SIZE];
    int rear;
    int front;
} Queue;

void initialise(Queue *q)
{
    q->front = -1;
    q->rear = -1;
}

int isFull(Queue *q)
{
    if((q->rear+1) % MAX_SIZE == q->front)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isEmpty(Queue *q)
{
    if(q->rear == -1 && q->front == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void enqueue(Queue *q, int data)
{
    if(isFull(q))
    {
        printf("\nThe queue is already full.\n");
        return;
    }
    else if(isEmpty(q))
    {
        q->rear = q->front = 0;
    }
    else
    {
        q->rear = (q->rear+1) % MAX_SIZE;
    }
    q->data[q->rear] = data;
    printf("\n%d has been enqueued.\n", data);
}

int dequeue(Queue *q)
{
    int element;
    if(isEmpty(q))
    {
        printf("\nThe queue is already empty.\n");
        return -1;
    }
    else if(q->rear == q->front)
    {
        element = q->data[q->rear];
        q->rear = q->front = -1;
    }
    else
    {
        element = q->data[q->front];
        q->front = (q->front+1) % MAX_SIZE;
    }
    printf("\n%d has been dequeued.\n", element);
    return element;
}

void display(Queue *q)
{
    int i = q->front;
    if(isEmpty(q))
    {
        printf("\nThe queue is empty.\n");
        return;
    }
    printf("\nThe elements of the queue are:\n");
    while(i != q->rear)
    {
        printf("%d ", q->data[i]);
        i = (i+1) % MAX_SIZE;
    }
    printf("%d\n", q->data[i]);
}

int main()
{
    Queue q;
    int choice, data, element;
    initialise(&q);
    while(1)
    {
        printf("\nEnter 1 to enqueue.\nEnter 2 to dequeue.\nEnter 3 to display.\nEnter 4 to exit.\n");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
            {
                printf("\nEnter the data to be enqueued: ");
                scanf("%d", &data);
                enqueue(&q, data);
                break;
            }
            case 2:
            {
                element = dequeue(&q);
                printf("\n%d has been dequeued.\n", element);
                break;
            }
            case 3:
            {
                display(&q);
                break;
            }
            case 4:
            {
                exit(0);
            }
            default:
            {
                printf("\nInvalid choice.\n");
                break;
            }
        }
    }
    return 0;
}