//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: Cryptic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_SIZE 100

int front = -1,rear = -1;
int queue[MAX_SIZE];

void enqueue(int element)
{
    if(rear == MAX_SIZE-1)
        printf("\nQueue Overflow");
    else if(front == -1)
        front = 0;
    rear++;
    queue[rear] = element;
}

void dequeue()
{
    if(front == -1 || front > rear)
        printf("\nQueue Underflow");
    else
        front++;
}

void display()
{
    int i;
    if(front == -1)
        printf("\nQueue is Empty");
    else
    {
        printf("\nElements in Queue are : ");
        for(i=front;i<=rear;i++)
            printf("%d ",queue[i]);
    }
}

int main()
{
    int choice,element;
    while(1)
    {
        printf("\nEnter 1 to Enqueue");
        printf("\nEnter 2 to Dequeue");
        printf("\nEnter 3 to Display");
        printf("\nEnter 4 to Exit");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("\nEnter the Element to be Inserted : ");
                scanf("%d",&element);
                enqueue(element);
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
                printf("\nInvalid Choice");
        }
    }
    return 0;
}