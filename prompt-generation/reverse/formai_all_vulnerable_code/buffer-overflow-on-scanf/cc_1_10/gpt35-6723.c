//FormAI DATASET v1.0 Category: Queue ; Style: creative
#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 5 // Maximum size of the queue
int q[MAX_SIZE]; // declaring an array to store the elements
int rear = -1; // rear for insertion
int front = -1; // front for deletion
int i, option, item; // auxiliary variables for input and output

// Function to insert an element in the queue
void enqueue(int item)
{
    if(rear == MAX_SIZE-1) // Checking if the queue is full
    {
        printf("\nError! Queue is full\n");
    }
    else
    {
        if(front == -1) front = 0; // If the queue is empty, set the front to 0
        rear++; // Increase rear by 1
        q[rear] = item; // Inserting the item in the queue
    }
}

// Function to delete an element from the queue
void dequeue()
{
    if(front == -1 || front > rear) // Checking if the queue is empty
    {
        printf("\nError! Queue is empty\n");
    }
    else
    {
        printf("\nElement dequeued: %d\n", q[front]); // Displaying the dequeued element
        front++; // Increasing front by 1
    }
}

// Function to display the elements of the queue
void display()
{
    if(front == -1 || front > rear) // Checking if the queue is empty
    {
        printf("\nQueue is empty\n");
    }
    else
    {
        printf("\nElements of the queue:\n");
        for(i=front;i<=rear;i++) // Loop to display the elements
        {
            printf("%d\t",q[i]);
        }
        printf("\n");
    }
}

int main()
{
    do // Loop to display the menu until the user exits
    {
        printf("Select an option:\n");
        printf("1. Enqueue an element\n");
        printf("2. Dequeue an element\n");
        printf("3. Display the queue\n");
        printf("4. Exit\n");
        scanf("%d",&option); // Taking input from the user
        switch(option)
        {
            case 1: printf("Enter the element to be enqueued:\n");
                    scanf("%d",&item); // Taking input from the user
                    enqueue(item); // Calling the enqueue() function
                    break;
            case 2: dequeue(); // Calling the dequeue() function
                    break;
            case 3: display(); // Calling the display() function
                    break;
            case 4: printf("Exiting...\n");
                    exit(0); // Exiting the program
            default: printf("\nInvalid option! Try again\n"); // Displaying error message for invalid options
        }
    }while(option != 4);
    return 0;
}