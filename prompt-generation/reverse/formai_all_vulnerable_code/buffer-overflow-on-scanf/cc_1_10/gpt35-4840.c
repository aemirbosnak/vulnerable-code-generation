//FormAI DATASET v1.0 Category: Queue Implementation ; Style: synchronous
#include<stdio.h>
#define MAX 5

int queue[MAX];
int front=-1, rear=-1;

void insert(int item)
{
    if(front==0 && rear==MAX-1)
    {
        printf("\n Queue is full");
        return;
    }

    if(front==-1)
    {
        front=0;
        rear=0;
    }

    else if(front!=0 && rear==MAX-1)
    {
        rear=0;
    }

    else
    {
        rear=rear+1;
    }

    queue[rear]=item;
}

int deletion()
{
    if(front==-1)
    {
        printf("\nQueue is empty\n");
        return 0;
    }

    int item = queue[front];

    if(front==rear)
    {
        front=-1;
        rear=-1;
    }

    else if(front==MAX-1)
    {
        front=0;
    }

    else
    {
        front=front+1;
    }

    return item;
}

void display()
{
    int i;

    if(front==-1)
    {
        printf("\nQueue is empty\n");
        return;
    }

    printf("\nElements in the Queue:\n");

    if(front<=rear)
    {
        for(i=front; i<=rear; i++)
            printf("%d ",queue[i]);
    }

    else
    {
        for(i=front; i<=MAX-1; i++)
            printf("%d ",queue[i]);

        for(i=0; i<=rear; i++)
            printf("%d ", queue[i]);
    }

    printf("\n");
}

int main()
{
    int choice, item;

    while(1)
    {
        printf("\nChoose the operation:\n1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                printf("\nEnter the element:");
                scanf("%d", &item);
                insert(item);
                break;
            case 2:
                printf("\nDeleted element is %d", deletion());
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("\nInvalid input!");
        }
    }
}