//FormAI DATASET v1.0 Category: Queue Implementation ; Style: beginner-friendly
#include<stdio.h>
#include<stdlib.h>
#define MAX 5

int front=0,rear=0,cqueue[MAX];

void insert(int x)
{
    if(front==(rear+1)%MAX)
    {
        printf("\nQueue full\n");
        return;
    }
    rear=(rear+1)%MAX;
    cqueue[rear]=x;
    if(front==0)   front=1;
    printf("\nSuccessfully inserted %d into queue.\n",x);
}

int del()
{
    int x;
    if(front==0)
    {
        printf("\nQueue empty\n");
        return 0;
    }
    x=cqueue[front];
    if(front==rear)
    {
        front=0;
        rear=0;
    }
    else
        front=(front+1)%MAX;
    printf("\nSuccessfully deleted %d from queue.\n",x);
    return x;
}

void display()
{
    int i;
    if(front==0)
    {
        printf("\nQueue empty\n");
        return;
    }
    printf("\nQueue : ");
    for(i=front;i!=rear;i=(i+1)%MAX)
        printf("%d ",cqueue[i]);
    printf("%d",cqueue[i]);
    printf("\n");
}

int main()
{
    int choice,x,data;
    while(1)
    {
        printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit\nEnter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("\nEnter the element to be inserted into queue : ");
                    scanf("%d",&x);
                    insert(x);
                    break;
            case 2: data=del();
                    if(data!=0) printf("\nDeleted Element : %d\n",data);
                    break;
            case 3: display(); break;
            case 4: exit(0);
            default: printf("\nWrong choice\n");
        }
    }
    return 0;
}