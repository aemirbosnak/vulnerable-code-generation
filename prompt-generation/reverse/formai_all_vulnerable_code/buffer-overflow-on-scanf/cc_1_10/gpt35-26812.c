//FormAI DATASET v1.0 Category: Queue Implementation ; Style: synchronous
#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 5 //Defining maximum size of the queue

int queue[MAXSIZE]; //Array for implementing the queue
int front=-1,rear=-1; //Setting initial values of front and rear to -1.

//Function to insert an element into the queue
void enqueue(int value)
{
    if(rear==MAXSIZE-1) //Check if the queue is already full
    {
        printf("\nQueue is full!");
    }
    else
    {
        if(front==-1) //Initialize front
        {
            front=0;
        }
        rear++; //Move the rear pointer to next index
        queue[rear]=value; //Insert the value
        printf("\n%d has been added to the queue",value);
    }
}

//Function to delete an element from the queue
void dequeue()
{
    if(front==-1) //Check if the queue is empty
    {
        printf("\nQueue is empty!");
    }
    else
    {
        printf("\n%d has been removed from the queue",queue[front]); //Display the value being removed
        front++; //Move the front pointer to next index
        if(front>rear) //Resetting front and rear when the queue becomes empty
        {
            front=-1;
            rear=-1;
        }
    }
}

//Function to display the queue
void display()
{
    if(front==-1) //Check if the queue is empty
    {
        printf("\nQueue is empty!");
    }
    else
    {
        printf("\nElements of the queue are: ");
        for(int i=front;i<=rear;i++) //Print all elements in the queue
        {
            printf("%d ",queue[i]);
        }
    }
}

//Driver code
int main()
{
    int choice,value;
    printf("\n*********Queue Implementation using Array*********\n");
    printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit");
    do
    {
        printf("\nEnter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: 
                printf("\nEnter the value to be added:");
                scanf("%d",&value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("\nExiting...");
                exit(0);
                break;
            default:
                printf("\nEnter a valid choice!");
                break;
        }
    }while(choice!=4);
    return 0;
}