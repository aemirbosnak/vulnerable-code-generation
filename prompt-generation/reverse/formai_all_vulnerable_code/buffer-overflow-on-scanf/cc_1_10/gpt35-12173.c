//FormAI DATASET v1.0 Category: Data structures visualization ; Style: decentralized
#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int top=-1;
int stack[MAX];
void push(void);
int pop(void);
void display(void);
void main()
{
    int choice;
    while(1)
    {
        printf("\n\nStack Menu:\n1.Push\n2.Pop\n3.Display\n4.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            push();
            break;
            case 2:
            pop();
            break;
            case 3:
            display();
            break;
            case 4:
            exit(0);
            default:
            printf("\n\n\t\t\tWrong Choice!!! Try Again.");
        }
    }
}
void push()
{
    int val;
    if(top==MAX-1)
    {
        printf("\n\n\t\t\tStack is Full!!! Cannot insert more elements.");
    }
    else
    {
        printf("\n\n\t\t\tEnter the element to push:");
        scanf("%d",&val);
        top=top+1;
        stack[top]=val;
    }
}
int pop()
{
    int val;
    if(top==-1)
    {
        printf("\n\n\t\t\tStack is Empty!!! Cannot delete any more elements.");
        return -1;
    }
    else
    {
        val=stack[top];
        top=top-1;
        printf("\n\n\t\t\tThe popped element is %d",val);
        return val;
    }
}
void display()
{
    int i;
    if(top==-1)
    printf("\n\n\t\t\tStack is Empty!!!");
    else
    {
        printf("\n\n\t\t\tStack elements are:\n\n");
        for(i=top;i>=0;--i)
        printf("\t\t\t%d\n",stack[i]);
    }
}