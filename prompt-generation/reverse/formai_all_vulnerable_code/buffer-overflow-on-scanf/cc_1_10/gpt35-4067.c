//FormAI DATASET v1.0 Category: Queue Implementation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h> 

#define MAX_QUEUE_SIZE 10

int front = 0;
int rear = -1;
int queue[MAX_QUEUE_SIZE];

void enqueue(int item) 
{
    if (rear == MAX_QUEUE_SIZE-1)
    {
        printf("\nQueue Overflow\n");
    }
    else
    {
        queue[++rear] = item;
    }
}

int dequeue()  
{
    if (front > rear)
    {
        printf("\nQueue Underflow\n");
        exit(1);
    }
    else
    {
        return queue[front++];
    }
}

void display() 
{
    if (front > rear)
    {
        printf("\nQueue is empty\n");
    }
    else
    {
        printf("\nQueue: ");
        for (int i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main()
{
    int choice, item;

    while (1)
    {
        printf("\nChoose an operation:");
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("\nEnter an element to enqueue: ");
                scanf("%d", &item);
                enqueue(item);
                break;
            case 2:
                item = dequeue();
                printf("\nDequeued item: %d", item);
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("\nInvalid choice\n");
        }
    }
    return 0;
}