//FormAI DATASET v1.0 Category: Queue ; Style: inquisitive
#include<stdio.h>
#include<stdlib.h>
#define MAX 5

int front= -1, rear= -1; //initially empty queue
int queue[MAX];

void enqueue(int x)
{
    if(rear == MAX - 1) //if queue is full
    {
        printf("Sorry! Can't enqueue %d, queue is full.\n", x);
    }
    else if(front == -1 && rear == -1) //if queue is empty
    {
        front = rear = 0;
        queue[rear] = x;
        printf("%d enqueued successfully!\n", x);
    }
    else //if queue has some elements
    {
        rear++;
        queue[rear] = x;
        printf("%d enqueued successfully!\n", x);
    }
}

void dequeue()
{
    if(front == -1 && rear == -1) //if queue is empty
    {
        printf("Sorry! Can't dequeue, queue is empty.\n");
    }
    else if(front == rear) //if queue has only one element
    {
        printf("%d dequeued successfully!\n", queue[front]);
        front = rear = -1;
    }
    else //if queue has some elements
    {
        printf("%d dequeued successfully!\n", queue[front]);
        front++;
    }
}

void display()
{
    int i;
    if(front == -1 && rear == -1) //if queue is empty
    {
        printf("Sorry! Can't display, queue is empty.\n");
    }
    else //if queue has some elements
    {
        printf("Elements in queue are: ");
        for(i=front;i<=rear;i++)
        {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main()
{
    int choice, x;
    while(1)
    {
        printf("\n1-Enqueue\n2-Dequeue\n3-Display\n4-Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("Enter the element to enqueue: ");
                scanf("%d", &x);
                enqueue(x);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Thank you for using the program!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}