//FormAI DATASET v1.0 Category: Data structures visualization ; Style: immersive
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

// Structure for a Stack element
struct Stack
{
    int top;
    int arr[MAX];
};

// Function to push an element onto the Stack
void push(struct Stack *s, int data)
{
    if(s->top == MAX - 1)
        printf("Stack Overflow!\n");
    else
    {
        s->top++;
        s->arr[s->top] = data;
    }
}

// Function to pop an element from the Stack
int pop(struct Stack *s)
{
    if(s->top == -1)
        printf("Stack Underflow!\n");
    else
    {
        int data = s->arr[s->top];
        s->top--;
        return data;
    }
}

// Function to display the Stack in a visual manner
void display(struct Stack *s)
{
    printf("---------------------\n");
    printf("\tSTACK\n");
    printf("---------------------\n");
    for(int i = s->top; i >= 0; i--)
    {
        printf("|  %-2d  |\n", s->arr[i]);
        printf("-------\n");
    }
    printf("\n");
}

int main()
{
    struct Stack s;
    s.top = -1;
    int choice, data, del;

    do{
        printf("OPTIONS MENU\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display Stack\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1: printf("Enter data to be pushed: ");
                    scanf("%d", &data);
                    push(&s, data);
                    break;
            case 2: del = pop(&s);
                    printf("The deleted element is: %d\n", del);
                    break;
            case 3: display(&s);
                    break;
            case 4: printf("Exiting...\n");
                    exit(0);
            default: printf("Invalid choice!\n");
                     break;
        }

        printf("\n");
        
    }while(choice != 4);

    return 0;
}