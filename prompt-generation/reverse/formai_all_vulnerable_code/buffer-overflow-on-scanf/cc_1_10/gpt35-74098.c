//FormAI DATASET v1.0 Category: Queue ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#define MAX 5
 
int front = -1, rear = -1; 
int cqueue[MAX];
 
void enqueue()
{
    int element;
 
    if ((front == 0 && rear == MAX-1) || (front == rear+1))
    {
        printf("\nCircular Queue is full\n");
        return;
    }
    else
    {
        if (front == -1) 
        {
            front = 0;
            rear = 0;
        }
        else
        {
            if (rear == MAX-1) 
                rear = 0;
            else
                rear = rear+1;
        }
        printf("\nEnter the element : ");
        scanf("%d", &element);
        cqueue[rear] = element ;
    }
}
 
void dequeue()
{
    if (front == -1)
    {
        printf("\nCircular Queue is empty! \n");
        return ;
    }
 
    printf("\nElement deleted from circular queue : %d\n",cqueue[front]);
    if (front == rear) 
    {
        front = -1;
        rear = -1;
    }
    else
    {
        if (front == MAX-1)
            front = 0;
        else
            front = front+1;
    }
}
 
void display()
{
    int i;
    if((front == -1) && (rear==-1))
    {
        printf("\nCircular Queue is empty!\n");
        return;
    }
 
    printf("\nCircular Queue Elements are : \n");
    if(rear >= front)
    {
        for(i=front;i<=rear;i++)
            printf("%d ",cqueue[i]);
    }
    else
    {
        for(i=front;i<MAX;i++)
            printf("%d ",cqueue[i]);
 
        for(i=0;i<=rear;i++)
            printf("%d ",cqueue[i]);
    }
    printf("\n");
}
 
int main()
{
    int choice;
 
    while(1)
    {
        printf("\n---------------------------------------------------\n");
        printf("\n                CIRCULAR QUEUE MENU                \n");
        printf("\n---------------------------------------------------\n");
        printf("\n 1. Enqueue \n 2. Dequeue \n 3. Display\n 4. Exit \n");
        printf("\n---------------------------------------------------\n");
        printf("\nEnter your choice : ");
        scanf("%d",&choice);
 
        switch(choice)
        {
            case 1:
	            enqueue();
	            break;
            case 2:
	            dequeue();
	            break;
            case 3:
	            display();
	            break;
            case 4:
	            printf("\nExiting the program.......\n");
	            exit(0);
	            break;
            default:
	            printf("\nWrong choice...Try again!!\n");
        } 
    }
    return 0;
}