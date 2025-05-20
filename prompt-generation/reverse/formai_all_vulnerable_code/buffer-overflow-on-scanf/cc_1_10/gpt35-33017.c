//FormAI DATASET v1.0 Category: Queue Implementation ; Style: artistic
#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 5 //Max size of the queue

int front = -1; //initialize front 
int rear = -1; //initialize front

int queue[MAXSIZE]; //Declaring the queue of MAXSIZE

//function to insert element
void enqueue(int num)
{
    if(rear==MAXSIZE-1) //check if queue is full or not
    {
        printf("Queue is full");
        return;
    }
    else
    {
        if(front==-1) //if queue is empty, initialize front
            front=0;
        
        rear++;
        queue[rear]=num;
        printf("%d has been enqueued to the queue\n", num);
    }
}

//function to delete element
int dequeue()
{
    int dequeued;
    if(front==-1 || front>rear) //check if queue is empty or not
    {
        printf("Queue is empty\n");
        return(-1);
    }
    else
    {
        dequeued = queue[front];
        front++;
        printf("%d has been dequeued from the queue\n", dequeued);
        return(dequeued);
    }
}

//function to display elements in queue
void display()
{
    if(front==-1 || front>rear) //check if queue is empty or not
    {
        printf("Queue is empty\n");
        return;
    }
    else
    {
        int i;
        printf("Elements in the queue are:\n");
        for(i=front; i<=rear; i++)
            printf("%d ", queue[i]);
        printf("\n");
    }
}

int main()
{
    //Menu
    while(1)
    {
        int choice, num;

        printf("\n**********QUEUE**********\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                printf("Enter the number to be enqueued: ");
                scanf("%d",&num);
                enqueue(num);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting program...Thank you for using our queue.\n");
                exit(0);
                break;

            default:
                printf("Invalid choice. Try again!\n");
                break;
        }
    }

    return 0;
}