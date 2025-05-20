//FormAI DATASET v1.0 Category: Queue Implementation ; Style: mind-bending
#include<stdio.h>
#define queue_size 5 // Define the maximum size of the queue as 5

int queue[queue_size];
int front = -1; // Initially front and rear indices are -1
int rear = -1;

void enqueue(int value) // Function to insert elements into the queue
{
    if (rear == queue_size - 1) // Check if the queue is full
    {
        printf("\nQueue is full. Dequeue some elements to insert new ones."); // Print error message
        return;
    }
    else
    {
        if (front == -1) // If the queue is empty
            front = 0; // Move front to the first element
        rear++; // Increment the rear index
        queue[rear] = value; // Insert the new element
        printf("\n%d has been enqueued successfully!",value); // Print success message
    }
}

void dequeue() // Function to remove elements from the queue
{
    if (front == -1) // Check if the queue is empty
    {
        printf("\nQueue is empty. Enqueue some elements to dequeue."); // Print error message
        return;
    }
    else
    {
        printf("\n%d has been dequeued successfully!",queue[front]); // Print the element being dequeued
        if (front == rear) // If there is only one element in the queue
            front = rear = -1; // Reset front and rear indices to -1
        else
            front++; // Move front to the next element
    }
}

void display() // Function to display the elements in the queue
{
    if (front == -1) // Check if the queue is empty
    {
        printf("\nQueue is empty!"); // Print error message
        return;
    }
        
    printf("\nThe elements in the queue are:\n");
    for (int i=front;i<=rear;i++)
        printf("%d ",queue[i]); // Print each element in the queue
}

int main()
{
    int choice, value;
    printf("\n---- Welcome to the Queue Implementation Program ----\n");

    while(1)
    {
        printf("\nMenu:\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&choice); // Get user input
    
        switch(choice)
        {
            case 1:
                printf("\nEnter the element to be enqueued: ");
                scanf("%d",&value); // Get user input
                enqueue(value); // Call enqueue function
                break;
                
            case 2:
                dequeue(); // Call dequeue function
                break;
            
            case 3:
                display(); // Call display function
                break;
                
            case 4:
                printf("\n---- Thank you for using the program! ----");
                return 0;
            
            default:
                printf("\nInvalid choice. Please try again."); // Print error message
        }
    }
}