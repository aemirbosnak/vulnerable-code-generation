//FormAI DATASET v1.0 Category: Queue Implementation ; Style: statistical
#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 10

int queue[MAX_SIZE], front=-1, rear=-1;

void enqueue(int data)
{
    if(rear==MAX_SIZE-1)
    {
        printf("\nQueue overflow!");
    }
    else
    {
        if(front==-1 && rear==-1)
        {
            front=rear=0;
        }
        else
        {
            rear++;
        }
        queue[rear] = data;
        printf("\n%d enqueued successfully!", data);
    }
}

void dequeue()
{
    int data;
    if(front==-1 && rear==-1)
    {
        printf("\nQueue underflow!");
    }
    else
    {
        data = queue[front];
        if(front==rear)
        {
            front=rear=-1;
        }
        else
        {
            front++;
        }
        printf("\n%d dequeued successfully!", data);
    }
}

void display()
{
    int i;
    if(front==-1 && rear==-1)
    {
        printf("\nQueue is empty!");
    }
    else
    {
        printf("\nThe queue is: ");
        for(i=front; i<=rear; i++)
        {
            printf("%d ", queue[i]);
        }
    }
}

int main()
{
    int choice, data;
    while(1)
    {
        printf("\n\nQueue Menu");
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("\nEnter data to enqueue: ");
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
                exit(0);
            default:
                printf("\nInvalid choice!");
        }
    }
    return 0;
}