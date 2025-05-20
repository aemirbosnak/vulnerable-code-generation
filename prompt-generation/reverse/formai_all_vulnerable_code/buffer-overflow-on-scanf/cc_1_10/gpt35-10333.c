//FormAI DATASET v1.0 Category: Queue ; Style: active
#include <stdio.h>
#include <stdlib.h>

#define QUEUE_SIZE 10 //define the size of the queue

int rear = -1, front = -1; //initialize the queue
int queue[QUEUE_SIZE];

void enqueue(int x) //function to add an element to the queue
{ 
    if (rear == QUEUE_SIZE - 1) //check if the queue is full
    {
        printf("\nError: Queue Overflow\n\n");
        return;
    }
    else if (front == -1 && rear == -1) //check if the queue is empty
    {
        front = rear = 0;
        queue[rear] = x;
        printf("\nEnqueued Element: %d\n\n", x);
    }
    else //otherwise, add the element to the rear end of the queue
    {
        rear++;
        queue[rear] = x;
        printf("\nEnqueued Element: %d\n\n", x);
    }
}

void dequeue() //function to remove an element from the queue
{ 
    if (front == -1 && rear == -1) //check if the queue is empty
    {
        printf("\nError: Queue Underflow\n\n");
        return;
    }
    else if (front == rear) //check if there is only one element in the queue
    {
        printf("\nDequeued Element: %d\n\n", queue[front]);
        front = rear = -1;
    }
    else //otherwise, remove the front element from the queue
    {
        printf("\nDequeued Element: %d\n\n", queue[front]);
        front++;
    }
}

void display() //function to display the elements of the queue
{ 
    if (front == -1) //check if the queue is empty
    {
        printf("\nError: Queue Empty\n\n");
        return;
    }
    printf("\nElements in the Queue: ");
    for (int i = front; i <= rear; i++) //loop through the queue and display its elements
        printf("%d ", queue[i]);
    printf("\n\n");
}

int main() //driver function
{
    int choice = 0, x;
    
    printf("-----Queue Operations-----\n\n");
    
    while (choice != 4) //display the menu until the user chooses to exit
    {
        printf("1. Enqueue an Element\n2. Dequeue an Element\n3. Display Elements in the Queue\n4. Exit\n\n");
        printf("Enter Your Choice: ");
        scanf("%d", &choice);
        
        switch (choice) //execute the selected operation
        {
            case 1:
                printf("\nEnter Element to Enqueue: ");
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
                printf("\nExiting Program...\n");
                exit(0);
                break;
            default:
                printf("\nInvalid Choice. Try Again.\n\n");
        }
    }
    
    return 0;
}