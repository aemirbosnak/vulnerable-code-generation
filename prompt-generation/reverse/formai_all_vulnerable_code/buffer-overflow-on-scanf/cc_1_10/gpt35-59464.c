//FormAI DATASET v1.0 Category: Queue Implementation ; Style: genious
#include<stdio.h>
#include<stdlib.h>

#define MAX 5

void enqueue(int [], int *, int *);
void dequeue(int [], int *, int *);
void display(int [], int *, int *);

int main()
{
    int queue[MAX];
    int front=-1, rear=-1, choice, item;
    system("clear");
    printf("---------------------Queue Implementation using Array---------------------\n");
    printf("\n\n\n\n");
    do{
        printf("\n\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n\nEnter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: 
            {
                enqueue(queue,&front,&rear);
                break;
            }

            case 2:
            {
                dequeue(queue,&front,&rear);
                break;
            }

            case 3:
            {
                display(queue,&front,&rear);
                break;
            }

            case 4:
            {
                printf("\nExiting.......\n");
                exit(0);
            }

            default:
            {
                printf("\nInvalid Choice Entered, Please Enter a Valid Choice.......\n");
            }
        }
    }while(choice!=4);

    return 0;
}

void enqueue(int queue[], int *front, int *rear)
{
    int item;
    if(*rear==MAX-1)
    {
        printf("\n Queue Overflow! Cannot Enqueue More!!\n");
    }

    else
    {
        printf("\nEnter the Element you want to Enqueue:");
        scanf("%d",&item);
        if(*front==-1 && *rear==-1)
        {
            *front=*rear=0;
        }

        else
        {
            *rear=*rear+1;
        }

        queue[*rear]=item;
        printf("\n%d has been Enqueued Succesfully...",item);
    }
}

void dequeue(int queue[], int *front, int *rear)
{
    int item;
    if(*front==-1 && *rear==-1)
    {
        printf("\n Queue Underflow! Queue is Empty!!\n");
    }

    else if(*front==*rear)
    {
        item=queue[*front];
        *front=*rear=-1;
        printf("\n%d has been Dequeued Succesfully...",item);
    }

    else
    {
        item=queue[*front];
        *front=*front+1;
        printf("\n%d has been Dequeued Succesfully...",item);
    }
}

void display(int queue[], int *front, int *rear)
{
    int i;
    if(*front==-1 && *rear==-1)
    {
        printf("\n Queue is Empty!!\n");
    }

    else
    {
        printf("\nElements of the Queue are: \n");
        for(i=*front; i<=*rear; i++)
        {
            printf("%d ",queue[i]);
        }
    }
}