//FormAI DATASET v1.0 Category: Queue ; Style: excited
#include<stdio.h>
#define MAX 5
int queue[MAX];
int front=-1;
int rear=-1;
void enqueue(int val)          //function to insert elements into the queue 
{
    if(rear==MAX-1 && front==0 || rear==front-1)
    {
        printf("Queue is Full\n");
    }
    else if(rear==-1 && front==-1)
    {
        rear=front=0;
        queue[rear]=val;
    }
    else if(rear==MAX-1 && front!=0)
    {
        rear=0;
        queue[rear]=val;
    }
    else
    {
        rear++;
        queue[rear]=val;
    }
}
void dequeue()                //function to delete elements from the queue 
{
    if(front==-1)
    {
        printf("Queue is Empty\n");
    }
    else if(front==rear)
    {
        printf("Deleted Element: %d\n",queue[front]);
        front=rear=-1;
    }
    else if(front==MAX-1)
    {
        printf("Deleted Element: %d\n",queue[front]);
        front=0;
    }
    else
    {
        printf("Deleted Element: %d\n",queue[front]);
        front++;
    }
}
void display()                 //function to display elements in the queue 
{
    int i;
    if(front==-1)
    {
        printf("Queue is Empty\n");
    }
    else if(rear>=front)
    {
        printf("Elements in the Queue: ");
        for(i=front;i<=rear;i++)            
            printf("%d ",queue[i]);
    }
    else
    {
        printf("Elements in the Queue: ");
        for(i=front;i<MAX;i++)       
            printf("%d ",queue[i]);
        for(i=0;i<=rear;i++)
            printf("%d ",queue[i]);
    }
}
int main()
{
    printf("-----Welcome to the Queue Program-----\n");
    int ch,val;
    do
    {
        printf("\nIf you want to insert, enter 1\n");
        printf("If you want to delete, enter 2\n");
        printf("If you want to display, enter 3\n");
        printf("If you want to quit, enter 4\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("Enter the Element to be Enqueued: ");
                scanf("%d",&val); 
                enqueue(val);
                break;
            case 2:
                printf("Element is being Dequeued\n");
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting the Program\n");
                break;
            default:
                printf("Enter a Valid Choice\n");
        }
    }while(ch!=4);
    return 0;
}