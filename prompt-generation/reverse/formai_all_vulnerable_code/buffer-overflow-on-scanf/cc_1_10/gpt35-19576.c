//FormAI DATASET v1.0 Category: Queue ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

int queue[MAX_SIZE];
int front = -1;
int rear = -1;

void enQueue(int value)
{
    if (rear == MAX_SIZE - 1)
    {
        printf("\nQueue is full!!!");
    }
    else
    {
        if (front == -1)
            front = 0;
        rear++;
        queue[rear] = value;
        printf("\n%d is enqueued to the queue.", value);
    }
}

void deQueue()
{
    if (front == -1)
    {
        printf("\nQueue is empty!!!");
    }
    else
    {
        printf("\n%d is dequeued from the queue.", queue[front]);
        front++;
        if (front > rear)
            front = rear = -1;
    }
}

void display()
{
    if (rear == -1)
    {
        printf("\nQueue is empty!!!");
    }
    else
    {
        printf("\nElements in the queue are: ");
        for (int i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }
    }
}

int main()
{
    int choice, value;

    do
    {
        printf("\n*************************");
        printf("\n*    QUEUE OPERATIONS   *");
        printf("\n*************************");
        printf("\n[1] Enqueue\n[2] Dequeue\n[3] Display\n[4] Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter the value to enqueue: ");
            scanf("%d", &value);
            enQueue(value);
            break;

        case 2:
            deQueue();
            break;

        case 3:
            display();
            break;

        case 4:
            printf("\nExiting...Thanks for using the program!");
            exit(0);

        default:
            printf("\nInvalid choice!");
        }
    } while (1);

    return 0;
}