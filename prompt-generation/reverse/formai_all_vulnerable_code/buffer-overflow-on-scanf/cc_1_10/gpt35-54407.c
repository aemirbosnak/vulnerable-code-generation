//FormAI DATASET v1.0 Category: Queue Implementation ; Style: ephemeral
#include<stdio.h>
#include<stdlib.h>

#define SIZE 10         //defining size of queue

int queue[SIZE], front = -1, rear = -1;    //initializing queue and front and rear indices

//function declarations
void enqueue(int item);
int dequeue();
void display();

int main()    //main function
{
    int choice, item;

    do
    {
        //displaying the options
        printf("\n\n\t\tC QUEUE IMPLEMENTATION\n\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        //switch case for performing appropriate operation based on user's choice
        switch(choice)
        {
            case 1:
                printf("\nEnter the item to be inserted: ");
                scanf("%d", &item);
                enqueue(item);
                break;

            case 2:
                item = dequeue();
                if(item != -1)
                    printf("\nDeleted item is: %d", item);
                break;

            case 3:
                display();
                break;

            case 4:
                exit(0);
                break;

            default:
                printf("\nInvalid Choice. Please try again.");
                break;
        }
    }while(choice != 4);

    return 0;
}

void enqueue(int item)    //function to add element to queue
{
    if((front == 0 && rear == SIZE-1) || (front == rear+1))    //checking if queue is full
    {
        printf("\nQueue Overflow. Cannot insert the item.");
        return;
    }

    if(front == -1)    //if queue is empty
    {
        front = rear = 0;
        queue[rear] = item;
    }
    else if(rear == SIZE-1)    //if rear manually moves to starting of queue
    {
        rear = 0;
        queue[rear] = item;
    }
    else    //normal case
    {
        rear++;
        queue[rear] = item;
    }
}

int dequeue()    //function to remove element from queue
{
    if(front == -1)    //checking if queue is empty
    {
        printf("\nQueue Underflow. Cannot delete the item.");
        return -1;
    }

    int item = queue[front];

    if(front == rear)    //if only one element was present in queue
        front = rear = -1;
    else if(front == SIZE-1)    //if front manually moves to starting of queue
        front = 0;
    else    //normal case
        front++;

    return item;
}

void display()    //function to display queue elements
{
    if(front == -1)    //checking if queue is empty
    {
        printf("\nQueue is empty.");
        return;
    }

    printf("\nQueue Elements: ");

    if(rear >= front)    //normal case
    {
        for(int i=front; i<=rear; i++)
            printf("%d ", queue[i]);
    }
    else    //if elements of queue wrap around
    {
        for(int i=front; i<=SIZE-1; i++)
            printf("%d ", queue[i]);

        for(int i=0; i<=rear; i++)
            printf("%d ", queue[i]);
    }
}