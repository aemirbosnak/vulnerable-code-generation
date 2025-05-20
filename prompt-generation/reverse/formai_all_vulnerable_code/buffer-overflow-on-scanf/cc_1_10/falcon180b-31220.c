//Falcon-180B DATASET v1.0 Category: Game ; Style: Dennis Ritchie
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX 10

int arr[MAX];
int top=-1;

void push(int x)
{
    if(top==MAX-1)
        printf("\nStack Overflow");
    else
    {
        top++;
        arr[++top]=x;
        printf("\n%d pushed into stack",x);
    }
}

int pop()
{
    int x=-1;
    if(top==-1)
        printf("\nStack Underflow");
    else
    {
        x=arr[top--];
        printf("\n%d popped from stack",x);
    }
    return x;
}

int peek()
{
    int x=-1;
    if(top==-1)
        printf("\nStack is Empty");
    else
        x=arr[top];
    return x;
}

int main()
{
    int choice,x;

    printf("\n\n\t\tSTACK OPERATIONS");
    printf("\nEnter the number of elements you want to push (Max %d): ",MAX);
    scanf("%d",&choice);

    srand(time(0));
    for(int i=0; i<choice; i++)
    {
        x=rand()%100;
        push(x);
    }

    printf("\n\nAfter pushing elements, Stack is: ");
    for(int i=0; i<=top; i++)
        printf("%d ",arr[i]);

    printf("\n\nEnter 1 to Pop an element from Stack");
    printf("\nEnter 2 to Peek the topmost element of Stack");
    printf("\nEnter 3 to Exit");
    scanf("%d",&choice);

    switch(choice)
    {
        case 1: x=pop();
                 if(x!=-1)
                     printf("\n\nPopped element is: %d",x);
                 break;

        case 2: x=peek();
                 if(x!=-1)
                     printf("\n\nTopmost element is: %d",x);
                 break;

        case 3: exit(0);

        default: printf("\n\nInvalid Choice");
    }

    return 0;
}