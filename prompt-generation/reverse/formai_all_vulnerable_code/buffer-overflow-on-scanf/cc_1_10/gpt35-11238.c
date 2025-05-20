//FormAI DATASET v1.0 Category: Queue Implementation ; Style: satisfied
#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1;
int rear = -1;

void enqueue(int value)
{
    if (rear == SIZE - 1)
    {
        printf("\nQueue is full!!\n");
    }
    else
    {
        if (front == -1)
            front = 0;
        rear++;
        queue[rear] = value;
        printf("\nInsertion successful!!\n");
    }
}

void dequeue()
{
    if (front == -1)
    {
        printf("\nQueue is empty!!\n");
    }
    else
    {
        printf("\nDeleted element is %d\n", queue[front]);
        front++;
        if (front > rear)
            front = rear = -1;
    }
}

void display()
{
    if (front == -1)
    {
        printf("\nQueue is empty!!\n");
    }
    else
    {
        int i;
        printf("\nQueue elements are:\n");
        for (i = front; i <= rear; i++)
            printf("%d\t", queue[i]);
        printf("\n");
    }
}

int main()
{
    int choice, value;
    printf("*********C Queue Implementation*********\n");
    while (1)
    {
        printf("\nChoose an operation on the Queue:\n");
        printf("1.EnQueue\n2.DeQueue\n3.Display\n4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter the value to be inserted: ");
            scanf("%d", &value);
            enqueue(value);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("\nExiting...\n");
            return 0;
        default:
            printf("\nInvalid choice!!\n");
        }
    }
    return 0;
}