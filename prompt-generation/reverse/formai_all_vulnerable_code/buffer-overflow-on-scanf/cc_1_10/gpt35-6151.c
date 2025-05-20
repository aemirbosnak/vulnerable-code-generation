//FormAI DATASET v1.0 Category: Queue ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

struct Queue
{
    int items[MAX_SIZE];
    int front, rear;
};

typedef struct Queue queue;

queue q;

void init(queue *q)
{
    q->front = -1;
    q->rear = -1;
}

int is_empty(queue *q)
{
    if (q->rear == -1)
    {
        return 1;
    }
    return 0;
}

int is_full(queue *q)
{
    if (q->rear == MAX_SIZE - 1)
    {
        return 1;
    }
    return 0;
}

void enqueue(queue *q, int value)
{
    if (is_full(q))
    {
        printf("Queue Overflow. \n");
    }
    else
    {
        if (q->front == -1)
            q->front = 0;
        q->rear++;
        q->items[q->rear] = value;
        printf("Inserted -> %d\n", value);
    }
}

int dequeue(queue *q)
{
    int item;
    if (is_empty(q))
    {
        printf("Queue Underflow. \n");
        item = -1;
    }
    else
    {
        item = q->items[q->front];
        q->front++;
        if (q->front > q->rear)
        {
            printf("Resetting queue. \n");
            q->front = q->rear = -1;
        }
    }
    return item;
}

void display(queue *q)
{
    int i;
    if (is_empty(q))
    {
        printf("Empty Queue. \n");
    }
    else
    {
        printf("Front index-> %d, Rear index-> %d\n", q->front, q->rear);
        for (i = q->front; i <= q->rear; i++)
        {
            printf("%d | ", q->items[i]);
        }
    }
}

int main()
{
    init(&q);

    int choice = 1;
    int data;

    printf("Mathematical Queue Program Example\n");
    printf("=================================\n");
    printf("\n");

    do
    {
        printf("1. Insert into queue.\n");
        printf("2. Delete from queue.\n");
        printf("3. Display the queue.\n");
        printf("4. Exit\n");

        printf("Enter your choice:\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter data to be inserted:\n");
            scanf("%d", &data);
            enqueue(&q, data);
            break;
        case 2:
            dequeue(&q);
            break;
        case 3:
            display(&q);
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Invalid choice.\n");
        }
    } while (choice != 4);

    return 0;
}