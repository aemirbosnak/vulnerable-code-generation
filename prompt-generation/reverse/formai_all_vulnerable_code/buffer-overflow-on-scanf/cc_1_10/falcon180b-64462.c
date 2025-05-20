//Falcon-180B DATASET v1.0 Category: Memory management ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define MAX_SIZE 1000

// Node structure definition
typedef struct node {
    int data;
    struct node* next;
} Node;

// Stack structure definition using linked list
typedef struct stack {
    Node* top;
} Stack;

// Function to create a new node with given data
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory error\n");
        exit(0);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to push an element onto the stack
void push(Stack* stack, int data) {
    Node* newNode = createNode(data);
    newNode->next = stack->top;
    stack->top = newNode;
}

// Function to pop an element from the stack
int pop(Stack* stack) {
    if (stack->top == NULL)
        return -1;
    Node* tempNode = stack->top;
    int poppedData = tempNode->data;
    stack->top = tempNode->next;
    free(tempNode);
    return poppedData;
}

// Function to check if the stack is empty
int isEmpty(Stack* stack) {
    return (stack->top == NULL);
}

// Main function demonstrating usage of stack operations
int main() {
    Stack myStack;
    myStack.top = NULL;

    int choice, data;

    do {
        printf("\n\nSTACK OPERATIONS\n");
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data to be pushed: ");
                scanf("%d", &data);
                push(&myStack, data);
                break;
            case 2:
                data = pop(&myStack);
                if (data!= -1)
                    printf("Popped element is %d\n", data);
                else
                    printf("Stack is empty\n");
                break;
            case 3:
                if (isEmpty(&myStack))
                    printf("Stack is empty\n");
                else {
                    printf("Stack elements are:\n");
                    Node* temp = myStack.top;
                    while (temp!= NULL) {
                        printf("%d ", temp->data);
                        temp = temp->next;
                    }
                    printf("\n");
                }
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice!= 4);

    return 0;
}