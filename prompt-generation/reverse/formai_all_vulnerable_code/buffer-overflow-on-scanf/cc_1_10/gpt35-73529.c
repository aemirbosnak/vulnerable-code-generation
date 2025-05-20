//FormAI DATASET v1.0 Category: Queue Implementation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5 // Maximum size for the queue

int queue[MAX_SIZE]; // Initializing the queue
int front = 0; // Initializing the front to zero
int rear = -1; // Initializing the rear to -1
int itemCount = 0; // Initializing the itemCount to zero

// Function prototype
void enqueue(int data);
int dequeue();
int peek();
int isEmpty();
int isFull();

// Function to add an element to the queue
void enqueue(int data)
{
    if(!isFull()) // If the queue is not full
    {
        if(rear == MAX_SIZE - 1) // If the rear is at the last index
        {
            rear = -1; // Setting rear to -1
        }
        queue[++rear] = data; // Adding the data to the rear of the queue
        itemCount++; // Incrementing the itemCount
        printf("%d added to queue.\n", data); // Printing the data added to the queue
    }
    else // If the queue is full
    {
        printf("Queue is full.\n"); // Printing queue full message
    }
}

// Function to remove an element from the queue
int dequeue()
{
    int data = queue[front++]; // Getting the data from the front of the queue and incrementing the front
    if(front == MAX_SIZE) // If the front is at the last index
    {
        front = 0; // Setting front to zero
    }
    itemCount--; // Decrementing the itemCount
    printf("%d removed from queue.\n", data); // Printing the data removed from the queue
    return data; // Returning the removed data
}

// Function to return the top element of the queue without removing it
int peek()
{
    return queue[front]; // Returning the element at the front of the queue
}

// Function to check if the queue is empty
int isEmpty()
{
    return itemCount == 0; // Returning true if the itemCount is zero
}

// Function to check if the queue is full
int isFull()
{
    return itemCount == MAX_SIZE; // Returning true if the itemCount is equal to MAX_SIZE
}

int main()
{
    // Initializing variables
    int choice;
    int data;

    do{
        // Printing out the menu
        printf("\nQUEUE IMPLEMENTATION: \n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Check if queue is empty\n");
        printf("5. Check if queue is full\n");
        printf("6. Quit\n");

        // Getting user's choice
        printf("Enter your choice (1-6): ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("\nEnter data to enqueue: ");
                scanf("%d", &data);
                enqueue(data); // Adding the data to the queue
                break;
            case 2:
                dequeue(); // Removing the element from the queue
                break;
            case 3:
                data = peek(); // Getting the top element from the queue
                printf("\nTop element is %d.\n", data);
                break;
            case 4:
                if(isEmpty()) // Checking if the queue is empty
                {
                    printf("\nQueue is empty.\n");
                }
                else
                {
                    printf("\nQueue is not empty.\n");
                }
                break;
            case 5:
                if(isFull()) // Checking if the queue is full
                {
                    printf("\nQueue is full.\n");
                }
                else
                {
                    printf("\nQueue is not full.\n");
                }
                break;
            case 6:
                printf("\nExiting program...\n");
                exit(0); // Exit the program with no errors
                break;
            default:
                printf("\nInvalid choice.\n"); // Printing if the user inputs invalid choice
        }
    }while(choice != 6); // Do the loop until user chooses to quit

    return 0;
}