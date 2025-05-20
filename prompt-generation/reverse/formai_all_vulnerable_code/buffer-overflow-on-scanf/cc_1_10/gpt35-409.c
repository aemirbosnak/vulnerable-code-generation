//FormAI DATASET v1.0 Category: Queue ; Style: synchronous
#include<stdio.h>
#define MAX 5

void enqueue();
void dequeue();
void display();

int queue[MAX],front=-1,rear=-1;

int main()
{ 
    int choice;
    while(1) {
        printf("\n---------------------");
        printf("\nQueue Operations");
        printf("\n---------------------");
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit");
        printf("\nEnter your choice(1-4) : ");
        scanf("%d",&choice);

        switch(choice) {
            case 1 :
                enqueue();
                break;
            case 2:
                dequeue();
                break; 
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("\nInvalid input\n");
        }
    }
}

void enqueue()
{
    int x;
    if(rear==MAX-1) {
        printf("\nQueue is full\n");
    }
    else {
        if(front==-1 && rear==-1) {
            front=rear=0;
        }
        else {
            rear++;
        }
        printf("\nEnter element to insert : ");
        scanf("%d",&x);
        queue[rear]=x;
        printf("\nElement %d is inserted",x);
    }
}

void dequeue()
{
    if(front==-1 && rear==-1) {
        printf("\nQueue is empty\n");
    }
    else {
        printf("\nDeleted element is %d",queue[front]);
        if(front==rear) {
            front=rear=-1;
        }
        else {
            front++;
        }
    }
}

void display()
{
    int i;
    if(rear==-1 && front==-1) {
        printf("\nQueue is empty\n");
    }
    else {
        printf("\nElements in queue : ");
        for(i=front;i<=rear;i++) {
            printf("%d ",queue[i]);
        }
    }
}