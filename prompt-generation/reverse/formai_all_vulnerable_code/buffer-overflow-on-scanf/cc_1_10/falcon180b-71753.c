//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: secure
#include<stdio.h>
#include<stdlib.h>

#define MAX 100

typedef struct node
{
    int data;
    struct node* next;
}node;

node* front=NULL,*rear=NULL;

void enqueue(int val)
{
    node* new_node=(node*)malloc(sizeof(node));
    new_node->data=val;
    new_node->next=NULL;

    if(front==NULL && rear==NULL)
    {
        front=rear=new_node;
    }
    else if(rear==NULL)
    {
        rear=new_node;
        rear->next=front;
    }
    else if(front==NULL)
    {
        front=rear->next=new_node;
        rear->next=front;
    }
    else
    {
        rear->next=front;
        rear=new_node;
        new_node->next=front;
    }
}

void dequeue()
{
    node* temp=front;

    if(front==rear)
    {
        front=rear=NULL;
    }
    else if(front==NULL)
    {
        front=rear->next;
        rear->next=front;
    }
    else if(rear==NULL)
    {
        rear=front->next;
        front->next=rear;
    }
    else
    {
        rear=rear->next;
        rear->next=front;
    }

    free(temp);
}

void display()
{
    node* temp=front;

    if(front==NULL)
    {
        printf("\nQueue is empty");
        return;
    }

    printf("\nElements in the Queue are: ");

    do
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }while(temp!=front);
}

int main()
{
    int choice,val;

    do
    {
        printf("\n\nMENU");
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                printf("\nEnter the value to be enqueued: ");
                scanf("%d",&val);
                enqueue(val);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("\nExiting...");
                break;

            default:
                printf("\nInvalid choice!");
        }
    }while(choice!=4);

    return 0;
}