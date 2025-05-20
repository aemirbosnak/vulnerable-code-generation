//Falcon-180B DATASET v1.0 Category: Pattern printing ; Style: ultraprecise
#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int *arr;
    int capacity;
    int top;
} Stack;

//Function to create a new stack
Stack* createStack(int capacity) {
    Stack* newStack = (Stack*)malloc(sizeof(Stack));
    newStack->arr = (int*)malloc(capacity*sizeof(int));
    newStack->capacity = capacity;
    newStack->top = -1;
    return newStack;
}

//Function to push an element onto the stack
void push(Stack* stack, int element) {
    if(stack->top == stack->capacity-1) {
        printf("Stack is full! Cannot push %d\n", element);
        return;
    }
    stack->top++;
    stack->arr[stack->top] = element;
}

//Function to pop an element from the stack
int pop(Stack* stack) {
    if(stack->top == -1) {
        printf("Stack is empty! Cannot pop\n");
        return -1;
    }
    int poppedElement = stack->arr[stack->top];
    stack->top--;
    return poppedElement;
}

//Function to check if the stack is empty
int isEmpty(Stack* stack) {
    if(stack->top == -1)
        return 1;
    else
        return 0;
}

//Function to check if the stack is full
int isFull(Stack* stack) {
    if(stack->top == stack->capacity-1)
        return 1;
    else
        return 0;
}

//Function to print the elements of the stack
void printStack(Stack* stack) {
    if(isEmpty(stack)) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Elements in the stack are: ");
    for(int i=stack->top; i>=0; i--)
        printf("%d ", stack->arr[i]);
    printf("\n");
}

//Main function to test the stack implementation
int main() {
    Stack* myStack = createStack(5);
    push(myStack, 10);
    push(myStack, 20);
    push(myStack, 30);
    push(myStack, 40);
    push(myStack, 50);
    printStack(myStack);
    printf("Popped element is: %d\n", pop(myStack));
    printf("Popped element is: %d\n", pop(myStack));
    printStack(myStack);
    push(myStack, 60);
    push(myStack, 70);
    printf("Popped element is: %d\n", pop(myStack));
    printStack(myStack);
    return 0;
}