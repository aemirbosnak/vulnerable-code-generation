//FormAI DATASET v1.0 Category: Queue Implementation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 5 //maximum size of the queue

int queue[MAX_SIZE]; //queue initialized globally
int front = -1, rear = -1; //initialize front and rear as -1

int isFull() //a function to check if the queue is full
{
    if ((front == 0 && rear == MAX_SIZE - 1) || (front == rear + 1))
        return 1; //return 1 if queue is full
    else
        return 0; //return 0 if queue is not full
}

int isEmpty() //a function to check if the queue is empty
{
    if (front == -1)
        return 1; //return 1 if queue is empty
    else
        return 0; //return 0 if queue is not empty
}

void enqueue(int data) //a function to add an element to the queue
{
    if (isFull()) //check if queue is full
    {
        printf("Queue Overflow\n");
        return; //exit function if queue is full
    }

    if (front == -1) //if queue is empty
        front = 0;

    rear = (rear + 1) % MAX_SIZE; //increment rear index
    queue[rear] = data; //add data to queue
}

int dequeue() //a function to remove an element from the queue
{
    int data;

    if (isEmpty()) //check if queue is empty
    {
        printf("Queue Underflow\n");
        exit(1); //exit program with error code 1 if queue is empty
    }

    data = queue[front]; //retrieve data from front of queue
    if (front == rear) //if there is only one element in the queue
        front = rear = -1;
    else
        front = (front + 1) % MAX_SIZE; //increment front index

    return data; //return dequeued data
}

void display() //a function to display the contents of the queue
{
    int i;

    if (isEmpty()) //check if queue is empty
    {
        printf("Queue is Empty\n");
        return;
    }

    printf("Queue contains: ");
    for (i = front; i != rear; i = (i + 1) % MAX_SIZE) //loop through queue from front to rear
        printf("%d ", queue[i]); //print data at each index

    printf("%d\n", queue[i]); //print data at rear index
}

int main()
{
    int choice, data;

    while (1) //infinite loop
    {
        printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter data to enqueue: ");
                scanf("%d", &data);
                enqueue(data); //add data to queue
                break;
            case 2:
                printf("Dequeued element: %d\n", dequeue()); //remove data from queue and print it
                break;
            case 3:
                display(); //display contents of queue
                break;
            case 4:
                exit(0); //exit program with success code 0
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}