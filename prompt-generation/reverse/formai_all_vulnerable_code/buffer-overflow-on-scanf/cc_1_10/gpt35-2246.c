//FormAI DATASET v1.0 Category: Queue ; Style: cheerful
#include<stdio.h>
#include<stdlib.h>
#define MAX 5  //max size of queue

/* This is a queue program in C. Queues are usually
   used to store data in First In First Out (FIFO) order.
   In this program, we will be implementing the queue using an array.*/

int queue[MAX], front=-1, rear=-1; //initializing front and rear to -1 since queue is empty

/*Here is the function to check if the queue is full.*/
int isFull()
{
    if(rear == MAX-1)
        return 1; //returns 1 if queue is full
    else
        return 0; //returns 0 if queue is not full
}

/*Here is the function to check if the queue is empty.*/
int isEmpty()
{
    if (front == -1 && rear == -1)
        return 1; // returns 1 if queue is empty
    else
        return 0; // returns 0 if queue is not empty
}

/*Enqueue function adds an element to the back of the queue.*/
void enqueue(int x)
{
    if (isFull())
        printf("\nUh-oh! The queue is full. No space left for %d.\n",x);
    else
    {
        if (front == -1)
            front = 0;
        rear++;
        queue[rear] = x;
        printf("\nYay! %d added to the queue.\n",x);
    }
}

/*The dequeue function removes an element from the front of the queue.*/
void dequeue()
{
    if (isEmpty())
        printf("\nUh-oh! The queue is empty. Nothing to dequeue.\n");
    else
    {
        printf("\nYay! %d removed from the queue.\n",queue[front]);
        front++;
        if (front > rear)
            front = rear = -1;
    }
}

/*The display function prints out the contents of the queue.*/
void display()
{
    if (isEmpty())
        printf("\nUh-oh! The queue is empty. Nothing to display.\n");
    else
    {
        int i;
        printf("\nThe current queue contents are: ");
        for (i=front;i<=rear;i++)
            printf("%d ",queue[i]);
        printf("\n");
    }
}

/*The main function executes the program and includes the user interface.*/
int main()
{
    int choice, num;

    do
    {
        printf("\n\nHello! I am the Cheerful Queue. What would you like to do?");
        printf("\n1. Enqueue an element\n2. Dequeue an element\n3. Display queue contents\n4. Exit\n");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1:
                printf("Enter the element you want to enqueue: ");
                scanf("%d",&num);
                enqueue(num);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("\nThank you for using Cheerful Queue. Have a great day! :)\n");
                exit(0);
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }while(1);

    return 0;
}