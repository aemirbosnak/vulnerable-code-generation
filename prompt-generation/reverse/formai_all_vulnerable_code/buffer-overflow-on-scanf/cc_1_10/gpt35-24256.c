//FormAI DATASET v1.0 Category: Queue Implementation ; Style: automated
#include<stdio.h>
#include<stdlib.h>
#define SIZE 5
int queue[SIZE],front=-1,rear=-1;
void enqueue(int data)
{
    if(rear==SIZE-1)
    {
        printf("Queue is Full!\n");
    }
    else
    {
        if(front==-1)
        {
            front++;
        }
        rear++;
        queue[rear]=data;
        printf("%d is inserted Successfully!\n",data);
    }
}
void dequeue()
{
    if(front==-1 || front>rear)
    {
        printf("Queue is Empty!\n");
    }
    else
    {
        printf("%d is deleted Successfully!\n",queue[front]);
        front++;
    }
}
void display()
{
    if(front==-1 || front>rear)
    {
        printf("Queue is Empty!\n");
    }
    else
    {
        printf("The Queue Elements are: ");
        for(int i=front;i<=rear;i++)
        {
            printf("%d ",queue[i]);
        }
        printf("\n");
    }
}
int main()
{
    int option,data;
    do
    {
        printf("\n***MAIN MENU***\n");
        printf("1- Enqueue\n");
        printf("2- Dequeue\n");
        printf("3- Display\n");
        printf("4- Exit\n");
        printf("Enter the option: ");
        scanf("%d",&option);
        switch(option)
        {
            case 1:printf("Enter the data to be inserted: ");
                   scanf("%d",&data);
                   enqueue(data);
                   break;
            case 2:dequeue();
                   break;
            case 3:display();
                   break;
            case 4:exit(0);
            default:printf("Invalid Option!\n");
        }
    }while(1);
    return 0;
}