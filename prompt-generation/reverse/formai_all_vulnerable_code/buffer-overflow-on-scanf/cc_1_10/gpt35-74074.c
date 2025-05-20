//FormAI DATASET v1.0 Category: Queue Implementation ; Style: retro
#include<stdio.h>
#include<stdlib.h>
#define MAX 5

int queue[MAX], front=-1, rear=-1;

void insert()
{
    int data;
    printf("Enter the element to insert into the queue: ");
    scanf("%d",&data);
    if(rear==MAX-1)
    {
        printf("Queue is full\n");
    }
    else if(front==-1 && rear==-1)
    {
        front=rear=0;
        queue[rear]=data;
        printf("%d is inserted into the queue\n", data);
    }
    else
    {
        rear++;
        queue[rear]=data;
        printf("%d is inserted into the queue\n", data);
    }
}

void delete()
{
    if(front==-1 && rear==-1)
    {
        printf("Queue is empty\n");
    }
    else if(front==rear)
    {
        printf("%d is deleted from the queue\n", queue[front]);
        front=rear=-1;
    }
    else
    {
        printf("%d is deleted from the queue\n", queue[front]);
        front++;
    }
}

void display()
{
    int i;
    if(front==-1 && rear==-1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Elements in the queue are: \n");
        for(i=front;i<=rear;i++)
        {
            printf("%d\n",queue[i]);
        }
    }
}

int main()
{
    int choice;
    do
    {
        printf("\n\t\t Queue Operations Menu\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: insert(); break;
            case 2: delete(); break;
            case 3: display(); break;
            case 4: exit(0);
            default: printf("Invalid choice\n");
        }
    }while(choice!=4);
    return 0;
}