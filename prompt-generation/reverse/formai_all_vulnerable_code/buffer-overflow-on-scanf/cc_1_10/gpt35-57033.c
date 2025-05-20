//FormAI DATASET v1.0 Category: Queue Implementation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10 // Maximum size of queue

// Initialize front and rear to -1
int front = -1, rear = -1;

// Create an empty queue
int queue[MAX_SIZE];

// Function to check if queue is empty
int is_empty()
{
    if (front == -1 && rear == -1)
        return 1;
    else
        return 0;
}

// Function to check if queue is full
int is_full()
{
    if (rear == MAX_SIZE-1)
        return 1;
    else
        return 0;
}

// Function to insert an element in queue
void enqueue(int element)
{
    if (is_full())
    {
        printf("Queue is full\n");
        return;
    }
    else if (is_empty())
    {
        front = rear = 0;
        queue[rear] = element;
    }
    else
    {
        rear++;
        queue[rear] = element;
    }
}

// Function to delete an element from queue
int dequeue()
{
    int element;
    if (is_empty())
    {
        printf("Queue is empty\n");
        return -1;
    }
    else if (front == rear)
    {
        element = queue[front];
        front = rear = -1;
    }
    else
    {
        element = queue[front];
        front++;
    }
    return element;
}

// Function to display the queue
void display()
{
    int i;
    if (is_empty())
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue is: \n");
    for (i = front; i <= rear; i++)
        printf("%d ", queue[i]);
    printf("\n");
}

// Main function
int main()
{
    int choice, element;

    do
    {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter element to enqueue: ");
                scanf("%d", &element);
                enqueue(element);
                break;
            case 2:
                printf("Deleted element is: %d\n", dequeue());
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Invalid choice\n");
        }
    }while(choice != 4);

    return 0;
}