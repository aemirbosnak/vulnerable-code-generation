//FormAI DATASET v1.0 Category: Queue Implementation ; Style: romantic
#include<stdio.h>
#include<stdlib.h>

#define MAX 5

void enqueue(int);
void dequeue(void);
void display(void);

int queue[MAX];
int front = -1;
int rear = -1;

int main()
{
    int choice, item;
    while(1)
    {
        printf("\n1. Insert element");
        printf("\n2. Delete element");
        printf("\n3. Display elements");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("\nEnter element to insert: ");
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
            default:
                printf("\nInvalid choice! Try again.");
        }
    }
}

void enqueue(int item)
{
    if(rear == MAX-1)
        printf("\nQueue Overflow!");
    else
    {
        if(front == -1)
            front = 0;
        rear++;
        queue[rear] = item;
        printf("\nElement inserted to queue.");
    }
}

void dequeue()
{
    if(front == -1)
        printf("\nQueue Underflow!");
    else 
    {
        printf("\nDeleted element from queue: %d", queue[front]);
        front++;
        if(front > rear)
            front = rear = -1;
    }
}

void display()
{
    int i;
    if(front == -1)
        printf("\nQueue is empty!");
    else 
    {
        printf("\nElements in queue are: ");
        for(i = front; i <= rear; i++)
            printf("%d ", queue[i]);
    }
}