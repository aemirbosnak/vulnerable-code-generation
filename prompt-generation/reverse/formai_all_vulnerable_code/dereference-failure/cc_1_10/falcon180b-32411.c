//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: Dennis Ritchie
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<math.h>

#define MAX 100

struct {
    int top;
    int capacity;
    int *stack;
}stack;

void push(int x)
{
    if(stack.top==stack.capacity-1)
        printf("\nStack Overflow");
    else
    {
        stack.top++;
        stack.stack[stack.top]=x;
    }
}

int pop()
{
    int x;
    if(stack.top==-1)
        printf("\nStack Underflow");
    else
    {
        x=stack.stack[stack.top];
        stack.top--;
        return x;
    }
}

void display()
{
    int i;
    if(stack.top==-1)
        printf("\nStack is Empty");
    else
    {
        printf("\nElements in the Stack are:");
        for(i=stack.top;i>=0;i--)
            printf("%d ",stack.stack[i]);
    }
}

int main()
{
    int n,i,j,temp;
    printf("\nEnter the number of disks:");
    scanf("%d",&n);
    printf("\nMove %d disks from rod 1 to rod 3\n",n);
    for(i=n;i>=1;i--)
    {
        for(j=1;j<i;j++)
        {
            push(i);
        }
        temp=pop();
        printf("\nMove disk %d from rod 1 to rod 3",temp);
        push(temp);
    }
    printf("\n\nAll disks moved to rod 3");
    return 0;
}