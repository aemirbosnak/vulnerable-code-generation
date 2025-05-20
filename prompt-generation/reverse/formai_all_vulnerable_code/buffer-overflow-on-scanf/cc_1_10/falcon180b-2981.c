//Falcon-180B DATASET v1.0 Category: Error handling ; Style: Dennis Ritchie
#include<stdio.h>
#include<stdlib.h>

#define MAX 100

//Function to check if stack is empty
int is_empty(int top)
{
    if(top == -1)
        return 1;
    else
        return 0;
}

//Function to check if stack is full
int is_full(int top, int capacity)
{
    if(top == capacity-1)
        return 1;
    else
        return 0;
}

//Function to push an element onto the stack
void push(int *stack, int capacity, int *top, int value)
{
    if(is_full(*top, capacity))
    {
        printf("\nStack Overflow Error!");
        exit(0);
    }
    else
    {
        (*top)++;
        stack[*top] = value;
    }
}

//Function to pop an element from the stack
int pop(int *stack, int capacity, int *top)
{
    int value;
    if(is_empty(*top))
    {
        printf("\nStack Underflow Error!");
        exit(0);
    }
    else
    {
        value = stack[*top];
        (*top)--;
        return value;
    }
}

//Function to display the elements in the stack
void display(int *stack, int capacity, int top)
{
    int i;
    if(is_empty(top))
        printf("\nStack is empty!");
    else
    {
        for(i=top; i>=0; i--)
            printf("%d ", stack[i]);
        printf("\n");
    }
}

int main()
{
    int stack[MAX], capacity=MAX, choice, value, top=-1;

    printf("\nEnter the choice of operation on the stack: ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1: //Push operation
            printf("\nEnter the value to be pushed onto the stack: ");
            scanf("%d", &value);
            push(stack, capacity, &top, value);
            break;

        case 2: //Pop operation
            value = pop(stack, capacity, &top);
            printf("\nThe popped element is: %d\n", value);
            break;

        case 3: //Display operation
            display(stack, capacity, top);
            break;

        default:
            printf("\nInvalid choice of operation!");
            break;
    }

    return 0;
}