//Falcon-180B DATASET v1.0 Category: Recursive ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100

typedef struct {
    int data;
    struct node* next;
} node;

node* stack[MAX_STACK_SIZE];
int top = -1;

void push(int data) {
    if (top == MAX_STACK_SIZE-1) {
        printf("Stack Overflow\n");
        return;
    }
    top++;
    stack[top] = (node*)malloc(sizeof(node));
    stack[top]->data = data;
    stack[top]->next = NULL;
}

int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    int data = stack[top]->data;
    node* temp = stack[top];
    top--;
    free(temp);
    return data;
}

void printStack() {
    if (top == -1) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements are:\n");
    node* temp = stack[top];
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int isEmpty() {
    if (top == -1)
        return 1;
    else
        return 0;
}

int isFull() {
    if (top == MAX_STACK_SIZE-1)
        return 1;
    else
        return 0;
}

int main() {
    int choice, data;
    while(1) {
        printf("\n1. Push\n2. Pop\n3. Print Stack\n4. Check if Stack is Empty\n5. Check if Stack is Full\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter the data to be pushed: ");
                scanf("%d", &data);
                push(data);
                break;
            case 2:
                data = pop();
                if (data!= -1)
                    printf("Popped element is %d\n", data);
                break;
            case 3:
                printStack();
                break;
            case 4:
                if (isEmpty())
                    printf("Stack is empty\n");
                else
                    printf("Stack is not empty\n");
                break;
            case 5:
                if (isFull())
                    printf("Stack is full\n");
                else
                    printf("Stack is not full\n");
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}