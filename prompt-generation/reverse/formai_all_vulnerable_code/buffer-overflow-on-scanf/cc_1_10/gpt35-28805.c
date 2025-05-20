//FormAI DATASET v1.0 Category: Queue Implementation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10

int queue[MAX_SIZE], front = -1, rear = -1;

void enqueue(int item)
{
    if (rear == MAX_SIZE - 1)
    {
        printf("Queue Overflow");
    }
    else
    {
        if (front == -1)
        {
            front = 0;
        }
        rear++;
        queue[rear] = item;
        printf("%d enqueued to queue\n", item);
    }
}

int dequeue()
{
    int item;
    if (front == -1 || front > rear)
    {
        printf("Queue Underflow\n");
        return -1;
    }
    else
    {
        item = queue[front];
        front++;
        printf("%d dequeued from queue\n", item);
        return item;
    }
}

void display()
{
    int i;
    if (front == -1)
    {
        printf("Queue is empty\n");
        return;
    }
    else
    {
        printf("Queue is:\n");
        for (i = front; i <= rear; i++)
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
        printf("Enter your choice:\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the element to be enqueued: ");
            scanf("%d", &item);
            enqueue(item);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Invalid input\n");
        }
    }
    return 0;
}