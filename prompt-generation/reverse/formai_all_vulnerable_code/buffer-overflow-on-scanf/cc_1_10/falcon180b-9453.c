//Falcon-180B DATASET v1.0 Category: Error handling ; Style: recursive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

int top=-1;
char stack[MAX];

void push(char element)
{
    if(top==MAX-1)
    {
        printf("Stack Overflow\n");
        exit(0);
    }
    else
    {
        top++;
        stack[top]=element;
    }
}

char pop()
{
    char element;
    if(top==-1)
    {
        printf("Stack Underflow\n");
        exit(0);
    }
    else
    {
        element=stack[top];
        top--;
        return element;
    }
}

int isEmpty()
{
    if(top==-1)
        return 1;
    else
        return 0;
}

int isFull()
{
    if(top==MAX-1)
        return 1;
    else
        return 0;
}

void display()
{
    if(top==-1)
        printf("Stack is empty\n");
    else
    {
        printf("Stack elements are:\n");
        for(int i=top;i>=0;i--)
            printf("%c\n",stack[i]);
    }
}

int main()
{
    int choice,element;
    char ch;
    do
    {
        printf("Enter your choice:\n");
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter the element to be pushed:");
                scanf(" %c",&ch);
                push(ch);
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
                printf("Invalid choice\n");
        }
    }while(1);
    return 0;
}