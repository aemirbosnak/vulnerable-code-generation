//FormAI DATASET v1.0 Category: Queue Implementation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 10

typedef struct Queue
{
    int front, rear;
    int items[MAX_QUEUE_SIZE];
} Queue;

void initialize(Queue *queue)
{
    queue->front = -1;
    queue->rear = -1;
}

int isEmpty(Queue *queue)
{
    if (queue->rear == -1)
    {
        return 1;
    }

    return 0;
}

int isFull(Queue *queue)
{
    if (queue->rear == MAX_QUEUE_SIZE - 1)
    {
        return 1;
    }

    return 0;
}

void enqueue(Queue *queue, int value)
{
    if (isFull(queue))
    {
        printf("Queue is full.\n");
    }
    else
    {
        if (queue->front == -1)
        {
            queue->front = 0;
        }

        queue->rear++;
        queue->items[queue->rear] = value;

        printf("Inserted %d.\n", value);
    }
}

int dequeue(Queue *queue)
{
    int value;

    if (isEmpty(queue))
    {
        printf("Queue is empty.\n");
        return -1;
    }
    else
    {
        value = queue->items[queue->front];

        if (queue->front >= queue->rear)
        {
            queue->front = -1;
            queue->rear = -1;
        }
        else
        {
            queue->front++;
        }

        printf("Removed %d.\n", value);
        return value;
    }
}

int front(Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty.\n");
        return -1;
    }

    return queue->items[queue->front];
}

void display(Queue *queue)
{
    int i;

    if (isEmpty(queue))
    {
        printf("Queue is empty.\n");
    }
    else
    {
        printf("\nQueue elements are:\n");
        for (i = queue->front; i <= queue->rear; i++)
        {
            printf("%d\n", queue->items[i]);
        }
    }
}

int main()
{
    int choice, value;

    Queue *queue = (Queue *)malloc(sizeof(Queue));

    initialize(queue);

    while (1)
    {
        printf("\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Front\n");
        printf("4. Display\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the value to be inserted: ");
            scanf("%d", &value);
            enqueue(queue, value);
            break;

        case 2:
            dequeue(queue);
            break;

        case 3:
            printf("Front element is: %d\n", front(queue));
            break;

        case 4:
            display(queue);
            break;

        case 5:
            exit(0);
            break;

        default:
            printf("Invalid option selected.\n");
        }
    }

    return 0;
}