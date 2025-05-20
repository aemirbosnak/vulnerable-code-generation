//FormAI DATASET v1.0 Category: Queue Implementation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 10

typedef struct queue
{
    int data[MAX_QUEUE_SIZE];
    int front, rear;
} Queue;

void enqueue(Queue *q, int element)
{
    if ((q->rear + 1) % MAX_QUEUE_SIZE == q->front)
    {
        printf("Queue is full, cannot enqueue %d!\n", element);
        return;
    }
    q->data[q->rear] = element;
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    printf("%d enqueued successfully!\n", element);
}

int dequeue(Queue *q)
{
    if (q->front == q->rear)
    {
        printf("Queue is empty, cannot dequeue!\n");
        return -1;
    }
    int element = q->data[q->front];
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    printf("%d dequeued successfully!\n", element);
    return element;
}

int main()
{
    Queue q;
    q.front = 0;
    q.rear = 0;

    printf("Welcome to the unique C Queue Implementation program!\n");
    printf("You can enqueue up to %d integers in this queue.\n", MAX_QUEUE_SIZE);

    int choice, element;
    while (1)
    {
        printf("\nEnter 1 to enqueue, 2 to dequeue, 3 to exit: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the integer to enqueue: ");
            scanf("%d", &element);
            enqueue(&q, element);
            break;
        case 2:
            element = dequeue(&q);
            if (element != -1)
                printf("Dequeued element: %d\n", element);
            break;
        case 3:
            printf("\nExiting the program...\n");
            exit(0);
        default:
            printf("\nInvalid choice! Please try again.\n");
            break;
        }
    }

    return 0;
}