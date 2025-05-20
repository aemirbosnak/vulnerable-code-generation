//FormAI DATASET v1.0 Category: Queue Implementation ; Style: puzzling
#include <stdio.h>
#define MAX 5 // Maximum size of queue

int queue[MAX];
int front = -1;
int rear = -1;

int isFull() // Returns 1 if queue is full, 0 otherwise
{
    if ((front == rear + 1) || (front == 0 && rear == MAX - 1))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isEmpty() // Returns 1 if queue is empty, 0 otherwise
{
    if (front == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void enQueue(int element) // Adds element to the queue
{
    if (isFull())
    {
        printf("\nQueue is full\n");
    }
    else
    {
        if (front == -1)
        {
            front = 0;
        }
        rear = (rear + 1) % MAX;
        queue[rear] = element;
        printf("\nInserted %d into queue\n", element);
    }
}

int deQueue() // Removes element from the queue
{
    int element;
    if (isEmpty())
    {
        printf("\nQueue is empty\n");
        return (-1);
    }
    else
    {
        element = queue[front];
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front + 1) % MAX;
        }
        printf("\nRemoved %d from queue\n", element);
        return (element);
    }
}

int main()
{
    int choice, element;
    do
    {
        printf("\n1. Add element to queue");
        printf("\n2. Remove element from queue");
        printf("\n3. Quit");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter element : ");
            scanf("%d", &element);
            enQueue(element);
            break;
        case 2:
            deQueue();
            break;
        case 3:
            printf("\nExiting Program");
            break;
        default:
            printf("\nInvalid choice");
        }
    } while (choice != 3);
    return 0;
}