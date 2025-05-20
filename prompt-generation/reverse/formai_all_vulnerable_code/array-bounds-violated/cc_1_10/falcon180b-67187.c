//Falcon-180B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: peaceful
#include<stdio.h>
#include<stdlib.h>

#define MAX 100
#define INF 999

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int val)
{
    if(rear == MAX-1)
        printf("\nQueue is full!!");
    else if(front == -1)
        front = 0;
    rear++;
    queue[rear] = val;
}

int dequeue()
{
    int val;
    if(front == -1)
        printf("\nQueue is empty!!");
    else if(front == rear)
        front = rear = -1;
    else
        front++;
    val = queue[front];
    return val;
}

void display()
{
    int i;
    if(front == -1)
        printf("\nQueue is empty!!");
    else
    {
        printf("\nQueue elements are: ");
        for(i=front;i<=rear;i++)
        {
            printf("%d ",queue[i]);
        }
    }
}

int main()
{
    int choice, val;
    while(1)
    {
        printf("\nEnter your choice:\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("\nEnter the value to be enqueued: ");
                scanf("%d",&val);
                enqueue(val);
                break;
            case 2:
                val = dequeue();
                if(val!= INF)
                    printf("\nThe dequeued value is: %d",val);
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("\nInvalid choice!!");
        }
    }
    return 0;
}