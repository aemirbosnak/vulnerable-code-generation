//FormAI DATASET v1.0 Category: Queue ; Style: surprised
#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int queue[MAX];
int front=-1,rear=-1;
void insert(int element) 
{
    if(front==-1 && rear==-1)
        front=rear=0;
    else if(rear==MAX-1)
        rear=0;
    else
        rear++;
    if(rear==front)
    {
        printf("Queue is Full\n");
        if(rear==0)
            rear=MAX-1;
        else
            rear--;
    }
    else
        queue[rear]=element;
    printf("\n%d has been inserted in the queue successfully!\n",element);
}
void delete() 
{
    int d_element;
    if(front==-1 && rear==-1)
        printf("\nQueue is Empty\n");
    else
    {
        d_element=queue[front];
        queue[front]=-1;
        if(front==rear)
            front=rear=-1;
        else if(front==MAX-1)
            front=0;
        else
            front++;
        printf("\n%d has been deleted from the queue successfully!\n",d_element);    
    }
}
void display() 
{
    int i;
    if(front==-1 && rear==-1)
        printf("\nQueue is Empty\n");
    else
    {
        printf("\nElements of Queue are:\n");
        if(rear>=front) 
            for(i=front;i<=rear;i++)
                printf("%d  ",queue[i]);
        else
        {
            for(i=front;i<MAX;i++)
                printf("%d  ",queue[i]);
            for(i=0;i<=rear;i++)
                printf("%d  ",queue[i]);
        }
    }
}
int main() 
{
    int choice,element;
    char ch;
    do{
        printf("\n---------------------------------------------------------------------------------\n");
        printf("\nEnter 1 to insert element into queue.\nEnter 2 to delete element from queue.\nEnter 3 to display all elements of queue.\n");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice) 
        {
            case 1:
                printf("\nEnter the element that you want to insert in the queue: ");
                scanf("%d",&element);
                insert(element);
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            default:
                printf("\nInvalid choice.\n");
        }
        printf("\nDo you want to continue(press y to continue, any other key to exit): ");
        scanf(" %c",&ch);
    }while(ch=='y' || ch=='Y');
    printf("\nThank you for using the program!");
    return 0;
}