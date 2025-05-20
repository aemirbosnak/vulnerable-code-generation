//Falcon-180B DATASET v1.0 Category: Error handling ; Style: decentralized
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define MAX_SIZE 100

//Defining a structure for stack
typedef struct stack{
    int top;
    int capacity;
    int *array;
}Stack;

//Function to create a stack
Stack* createStack(int size){
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = -1;
    stack->capacity = size;
    stack->array = (int*)malloc(sizeof(int)*size);
    return stack;
}

//Function to push an element onto the stack
void push(Stack* stack, int value){
    if(stack->top == stack->capacity-1){
        printf("Stack Overflow\n");
        exit(0);
    }
    stack->top++;
    stack->array[stack->top] = value;
}

//Function to pop an element from the stack
int pop(Stack* stack){
    if(stack->top == -1){
        printf("Stack Underflow\n");
        exit(0);
    }
    int value = stack->array[stack->top];
    stack->top--;
    return value;
}

//Function to check if the stack is empty
int isEmpty(Stack* stack){
    if(stack->top == -1){
        return 1;
    }
    return 0;
}

//Function to check if the stack is full
int isFull(Stack* stack){
    if(stack->top == stack->capacity-1){
        return 1;
    }
    return 0;
}

int main(){
    Stack* stack = createStack(MAX_SIZE);
    int choice, value;
    do{
        printf("Enter your choice:\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter the value to be pushed:\n");
                scanf("%d",&value);
                push(stack,value);
                break;
            case 2:
                value = pop(stack);
                printf("Popped value: %d\n",value);
                break;
            case 3:
                if(isEmpty(stack)){
                    printf("Stack is empty\n");
                }
                else{
                    printf("Stack elements:\n");
                    for(int i=stack->top;i>=0;i--){
                        printf("%d ",stack->array[i]);
                    }
                    printf("\n");
                }
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }while(1);
    return 0;
}