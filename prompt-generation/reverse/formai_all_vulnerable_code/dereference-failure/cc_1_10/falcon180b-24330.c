//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct 
{
    int data;
    int priority;
    struct node *next;
}node;

typedef struct 
{
    node *front;
    node *rear;
}queue;

void initialize(queue *q)
{
    q->front = NULL;
    q->rear = NULL;
}

void enqueue(queue *q, int data, int priority)
{
    node *newnode = (node*)malloc(sizeof(node));
    newnode->data = data;
    newnode->priority = priority;
    newnode->next = NULL;

    if(q->front == NULL)
    {
        q->front = newnode;
        q->rear = newnode;
    }
    else if(q->rear->priority < priority)
    {
        q->rear->next = newnode;
        q->rear = newnode;
    }
    else
    {
        q->front->next = newnode;
        q->front = newnode;
    }
}

void dequeue(queue *q)
{
    if(q->front == NULL)
    {
        printf("Queue is empty");
        return;
    }

    node *temp = q->front;
    q->front = q->front->next;

    if(q->front == NULL)
        q->rear = NULL;

    free(temp);
}

void display(queue *q)
{
    if(q->front == NULL)
    {
        printf("Queue is empty");
        return;
    }

    node *temp = q->front;

    printf("Queue elements are: ");

    while(temp!= NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

int main()
{
    queue q;
    initialize(&q);

    enqueue(&q, 10, 3);
    enqueue(&q, 20, 2);
    enqueue(&q, 30, 1);
    enqueue(&q, 40, 4);

    display(&q);

    dequeue(&q);
    dequeue(&q);

    display(&q);

    return 0;
}