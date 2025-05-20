//FormAI DATASET v1.0 Category: Queue ; Style: beginner-friendly
/*
This program demonstrates the implementation of a beginner-friendly C Queue using arrays.
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10 // Maximum size of the Queue

// Function prototypes
void enqueue(int);
int dequeue();
void display();

// Queue definition
int queue[MAX_SIZE], front = -1, rear = -1;

// Main function
int main()
{
    printf("Welcome to C Queue!\n\n");

    while (1)
    {
        int choice, value;

        // Menu
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                // Enqueue an element
                printf("\nEnter the value to be enqueued: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            
            case 2:
                // Dequeue an element
                value = dequeue();
                if (value != -1) printf("\nDequeued element: %d\n", value);
                break;
            
            case 3:
                // Display the Queue
                display();
                break;
            
            case 4:
                // Exit the program
                printf("\nThank you for using C Queue!\n");
                exit(0);

            default:
                printf("\nInvalid choice. Please try again.\n");
        }

        printf("\n");
    }

    return 0;
}

// Function to enqueue an element
void enqueue(int value)
{
    if (rear == MAX_SIZE - 1) // Overflow condition
    {
        printf("\nQueue Overflow. Cannot enqueue element.\n");
        return;
    }

    if (front == -1) front = 0;
    
    rear++;
    queue[rear] = value;

    printf("\nEnqueued element: %d\n", value);
}

// Function to dequeue an element
int dequeue()
{
    if (front == -1) // Underflow condition
    {
        printf("\nQueue Underflow. Cannot dequeue element.\n");
        return -1;
    }

    int value = queue[front];
    
    if (front == rear) front = rear = -1;
    else front++;

    return value;
}

// Function to display the Queue
void display()
{
    if (front == -1) printf("\nQueue is empty.\n");
    else
    {
        printf("\nQueue elements: ");
        for (int i = front; i <= rear; i++)
            printf("%d ", queue[i]);
        printf("\n");
    }
}