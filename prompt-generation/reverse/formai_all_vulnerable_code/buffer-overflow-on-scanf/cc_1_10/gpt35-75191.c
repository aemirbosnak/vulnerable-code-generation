//FormAI DATASET v1.0 Category: Data structures visualization ; Style: protected
#include <stdio.h>
#define SIZE 5

struct stack
{
    int data[SIZE];
    int top;    
};

int isFull(struct stack *s)
{
    if(s->top == SIZE-1)
        return 1;
    else
        return 0;
}

int isEmpty(struct stack *s)
{
    if(s->top == -1)
        return 1;
    else
        return 0;
}

void push(struct stack *s, int x)
{
    if(isFull(s))
        printf("Stack is Full\n");
    else
    {
        s->top++;
        s->data[s->top] = x;
    }
}

void pop(struct stack *s)
{
    if(isEmpty(s))
        printf("Stack is Empty\n");
    else
    {
        printf("Popped Element: %d\n", s->data[s->top]);
        s->top--;
    }
}

void display(struct stack *s)
{
    if(isEmpty(s))
        printf("Stack is Empty\n");
    else
    {
        int i;
        for(i=s->top; i>=0; i--)
            printf("%d\n", s->data[i]);
    }
}

int main()
{
    struct stack s;
    s.top = -1;
    int choice, x;

    do
    {
        printf("\nMENU\n");
        printf("1.Push\n2.Pop\n3.Display\n4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: printf("Enter the element to be pushed: ");
                    scanf("%d", &x);
                    push(&s, x);
                    break;
            case 2: pop(&s);
                    break;
            case 3: display(&s);
                    break;
            case 4: printf("Exit\n");
                    break;
            default: printf("Invalid choice!\n");
                     break;
        }
    }while(choice!=4);

    return 0;
}