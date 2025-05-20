//FormAI DATASET v1.0 Category: Queue ; Style: energetic
#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int queue[MAX];
int front=0,rear=-1,items=0;

void enqueue(int value);
int dequeue();
int peek();
int isFull();
int isEmpty();

int main()
{
    int choice,value;
    while(1)
    {
        printf("\n\n*****Welcome to my Unique Queue Example Program!*****\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Check if Queue is Full\n");
        printf("5. Check if Queue is Empty\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                printf("\nEnter the value to be inserted: ");
                scanf("%d",&value);
                enqueue(value);
                break;
            case 2:
                value=dequeue();
                if(value!=-1)
                {
                    printf("\n%d was removed from the queue.",value);
                }
                break;
            case 3:
                value=peek();
                if(value!=-1)
                {
                    printf("\nPeek value is %d.",value);
                }
                break;
            case 4:
                if(isFull())
                {
                    printf("\nThe queue is full.");
                }
                else
                {
                    printf("\nThe queue is not full.");
                }
                break;
            case 5:
                if(isEmpty())
                {
                    printf("\nThe queue is empty.");
                }
                else
                {
                    printf("\nThe queue is not empty.");
                }
                break;
            case 6:
                printf("\nThank you for using my Queue Example Program!");
                exit(0);
            default:
                printf("\nInvalid input! Please enter a valid choice.");
        }
    }
}

void enqueue(int value)
{
    if(isFull())
    {
        printf("\nThe queue is already full.");
    }
    else
    {
        rear=(rear+1)%MAX;
        queue[rear]=value;
        printf("\n%d was added to the queue.",value);
        items++;
    }
}

int dequeue()
{
    int value;
    if(isEmpty())
    {
        printf("\nThe queue is already empty.");
        return -1;
    }
    else
    {
        value=queue[front];
        front=(front+1)%MAX;
        items--;
        return value;
    }
}

int peek()
{
    if(isEmpty())
    {
        printf("\nThe queue is already empty.");
        return -1;
    }
    else
    {
        return queue[front];
    }
}

int isFull()
{
    if(items==MAX)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isEmpty()
{
    if(items==0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}