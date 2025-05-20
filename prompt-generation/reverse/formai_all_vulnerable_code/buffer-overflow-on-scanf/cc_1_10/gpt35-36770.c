//FormAI DATASET v1.0 Category: Queue Implementation ; Style: light-weight
#include<stdio.h>
#include<stdlib.h>

#define MAX 5

int front=-1, rear=-1, cqueue[MAX];

void enqueue(int ele)
{
    if(front == (rear+1)%MAX)
    {
        printf("Queue is full\n");
        return;
    }
    else if(front == -1 && rear == -1)
    {
        front = 0;
        rear = 0;
    }
    else
    {
        rear = (rear+1)%MAX;
    }
    
    cqueue[rear] = ele;
    printf("Element %d is inserted\n", ele);
}

void dequeue()
{
    int ele;
    if(front == -1 && rear == -1)
    {
        printf("Queue is empty\n");
        return;
    }
    else if(front==rear)
    {
        ele = cqueue[front];
        front = -1;
        rear = -1;
    }
    else
    {
        ele = cqueue[front];
        front = (front+1)%MAX;
    }
    printf("Element %d is deleted\n", ele);
}

void display()
{
    int i;
    if(front == -1 && rear == -1)
    {
        printf("Queue is empty\n");
        return;
    }
    
    printf("Elements in the queue are: ");
    for(i=front;i!=rear;i=(i+1)%MAX)
    {
        printf("%d ", cqueue[i]);
    }
    printf("%d\n",cqueue[i]);
}

int main()
{
    int choice, ele;
    while(1)
    {
        printf("\n1. Insert element\n");
        printf("2. Delete element\n");
        printf("3. Display elements\n");
        printf("4. Exit\n");
        
        printf("Enter your choice: ");
        scanf("%d",&choice);
        
        switch(choice)
        {
            case 1: 
                printf("Enter the element to be inserted: ");
                scanf("%d",&ele);
                enqueue(ele);
                break;
            
            case 2:
                dequeue();
                break;
            
            case 3:
                display();
                break;
            
            case 4:
                exit(0);
            
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}