//FormAI DATASET v1.0 Category: Queue Implementation ; Style: curious
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 10 // defining the maximum size of the queue

// Defining a structure to represent the queue
struct Queue
{
     int items[MAXSIZE];
     int front;
     int rear;
};

// Function prototype to enqueue an element in the queue
void enqueue(struct Queue *q, int value);

// Function prototype to dequeue an element from the queue
int dequeue(struct Queue *q);

int main()
{
    struct Queue q; // declaring/creating a queue
    q.front=-1;    // setting the front and rear pointers to -1
    q.rear=-1;
    int choice, value;

    do
    {
        // Prompting the user to choose an option from the menu
        printf("\nMENU\n");
        printf("1. Enqueue an element\n");
        printf("2. Dequeue an element\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Using switch case to implement the user choice
        switch (choice)
        {
            case 1:
                printf("Enter the element to be enqueued: ");
                scanf("%d", &value);
                enqueue(&q, value); // Calling the enqueue function
                break;

            case 2:
                value=dequeue(&q);  // Calling the dequeue function
                if (value!=-1)     // Checking if the dequeue operation was successful
                    printf("The dequeued element is %d.\n", value);
                break;

            case 3:
                printf("Thank you for using the program.\n");
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }while(choice!=3);

    return 0;
}

// Function to enqueue an element in the queue
void enqueue(struct Queue *q, int value)
{
    if (q->rear==MAXSIZE-1)  // Checking if the queue is full
        printf("Queue Overflow.\n");

    else
    {
        if (q->front==-1)   // Checking if the queue is empty
            q->front=0;

        q->rear++;          // Moving the rear pointer
        q->items[q->rear]=value; // Storing the new element at the rear position
        printf("Enqueued element: %d\n", q->items[q->rear]);
    }
}

// Function to dequeue an element from the queue
int dequeue(struct Queue *q)
{
    int element;

    if (q->front==-1)   // Checking if the queue is empty
    {
        printf("Queue Underflow.\n");
        return -1;
    }

    else
    {
        element=q->items[q->front]; // Storing the first element in a variable
        q->front++;  // Moving the front pointer

        if (q->front>q->rear) // Checking if the queue has become empty
        {
            q->front=-1;
            q->rear=-1;
        }

        return element; // Returning the dequeued element
    }
}