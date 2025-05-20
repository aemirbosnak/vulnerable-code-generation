//FormAI DATASET v1.0 Category: Queue ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

#define SIZE 5 // define the size of the queue

int queue[SIZE]; // declare the queue
int front = 0, rear = -1, count = 0; // initialize the queue indices and the count of elements

void enqueue(int value) // function to enqueue an element
{
    if(count == SIZE) // if the queue is full
    {
        printf("\nQueue is full. Cannot enqueue %d.", value);
        return;
    }
    rear = (rear + 1) % SIZE;
    queue[rear] = value;
    printf("\nEnqueued %d.", value);
    count++;
}

void dequeue() // function to dequeue an element
{
    if(count == 0) // if the queue is empty
    {
        printf("\nQueue is empty. Cannot dequeue.");
        return;
    }
    printf("\nDequeued %d.", queue[front]);
    front = (front + 1) % SIZE;
    count--;
}

void display() // function to display the queue
{
    if(count == 0) // if the queue is empty
    {
        printf("\nQueue is empty. Nothing to display.");
        return;
    }
    printf("\nQueue elements are:");
    for(int i = 0; i < count; i++)
    {
        printf("\n%d", queue[(front + i) % SIZE]);
    }
}

int main()
{
    int choice, value;
    do
    {
        printf("\n\n***** MENU *****");
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nEnter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("\nEnter the value to enqueue: ");
                scanf("%d", &value);
                enqueue(value); // call the enqueue function
                break;

            case 2:
                dequeue(); // call the dequeue function
                break;

            case 3:
                display(); // call the display function
                break;

            case 4:
                printf("\nExiting...");
                exit(0); // exit the program

            default:
                printf("\nInvalid choice. Please enter a valid choice (1-4).");
        }
    } while(choice != 4);

    return 0;
}