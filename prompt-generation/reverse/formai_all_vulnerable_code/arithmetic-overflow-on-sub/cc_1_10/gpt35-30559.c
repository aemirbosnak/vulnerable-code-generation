//FormAI DATASET v1.0 Category: Educational ; Style: thoughtful
/* This C program is a simple implementation of a stack data structure. The program prompts the user to enter the stack size and push/pop values onto/from the stack.*/

#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100

void push(int stack[], int *top, int value);
int pop(int stack[], int *top);
void display(int stack[], int *top);

int main(){

    int stack[MAXSIZE], choice, value, top = -1, size, i;

    printf("Enter the stack size: ");
    scanf("%d", &size);

    while(1){

        printf("\n\nStack Operations Menu\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice){

            case 1:
                if(top == size-1){
                    printf("\nStack Overflow\n");
                    break;
                }
                printf("\nEnter a value to push: ");
                scanf("%d", &value);
                push(stack, &top, value);
                break;

            case 2:
                if(top == -1){
                    printf("\nStack Underflow\n");
                    break;
                }
                printf("\nThe popped value is %d\n", pop(stack, &top));
                break;

            case 3:
                display(stack, &top);
                break;

            case 4:
                exit(0);

            default:
                printf("\nPlease enter a valid choice!\n");
                break;
        }

    }

    return 0;

}

void push(int stack[], int *top, int value){

    *top = *top + 1;
    stack[*top] = value;
    printf("\n%d has been pushed onto the stack\n", value);

}

int pop(int stack[], int *top){

    int value = stack[*top];
    *top = *top - 1;
    return value;

}

void display(int stack[], int *top){

    int i;

    if(*top == -1){
        printf("\nStack is empty\n");
        return;
    }

    printf("\nThe current stack is: ");
    for(i=*top; i>=0; i--){
        printf("\n%d", stack[i]);
    }

}