//FormAI DATASET v1.0 Category: Queue Implementation ; Style: ephemeral
#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 5

int queue[MAX_SIZE], front = -1, rear = -1;

int isFull()
{
    if(rear == MAX_SIZE-1 && front == 0 || rear == front-1)
        return 1;
    else
        return 0;
}

int isEmpty()
{
    if(front == -1)
        return 1;
    else
        return 0;
}

void enqueue(int data)
{
    if(isFull())
    {
        printf("\nSorry, The Queue is Full!\n");
        return;
    }

    if(front == -1)
    {
        front = 0;
    }

    rear = (rear+1)%MAX_SIZE;
    queue[rear] = data;
    printf("\nAdded %d to the Queue!\n", data);
}

void dequeue()
{
    if(isEmpty())
    {
        printf("\nSorry, The Queue is Empty!\n");
        return;
    }

    int data = queue[front];
    if(front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front = (front+1)%MAX_SIZE;
    }
    printf("\nRemoved %d from the Queue!\n", data);
}

void display()
{
    if(isEmpty())
    {
        printf("\nSorry, The Queue is Empty!\n");
        return;
    }

    int i;

    printf("\nQueue: ");
    for(i=front;i!=rear;i=(i+1)%MAX_SIZE)
    {
        printf("%d ", queue[i]);
    }
    printf("%d ", queue[i]);
    printf("\n");
}

int main()
{
    int choice, data;

    while(1)
    {
        printf("\nMENU:\n");
        printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("\nEnter the data to add to the Queue: ");
                scanf("%d", &data);
                enqueue(data);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("\nExiting Program!");
                exit(0);

            default:
                printf("\nInvalid Choice, Please Try again!!\n");
        }
    }
    return 0;
}