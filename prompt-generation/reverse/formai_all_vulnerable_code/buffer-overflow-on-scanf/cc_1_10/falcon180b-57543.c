//Falcon-180B DATASET v1.0 Category: Recursive ; Style: peaceful
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define MAX 100

int arr[MAX];
int top = -1;

void push(int value)
{
    if(top >= MAX-1)
        printf("\nStack Overflow");
    else
    {
        top++;
        arr[++top] = value;
    }
}

int pop()
{
    if(top < 0)
        printf("\nStack Underflow");
    else
        return arr[top--];
}

void display()
{
    if(top < 0)
        printf("\nStack is Empty");
    else
    {
        printf("\nElements in the Stack are: ");
        for(int i=top;i>=0;i--)
            printf("%d ",arr[i]);
    }
}

int main()
{
    int choice,value;

    while(1)
    {
        printf("\n\nSTACK OPERATIONS");
        printf("\n1.Push");
        printf("\n2.Pop");
        printf("\n3.Display");
        printf("\n4.Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                printf("\nEnter the value to be pushed: ");
                scanf("%d",&value);
                push(value);
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
                printf("\nInvalid Choice");
        }
    }

    return 0;
}