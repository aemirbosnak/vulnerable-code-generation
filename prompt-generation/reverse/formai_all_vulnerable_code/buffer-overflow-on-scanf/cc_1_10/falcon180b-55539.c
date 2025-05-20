//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct node {
    int data;
    struct node* next;
} Node;

typedef struct stack {
    Node* top;
    int size;
} Stack;

// Function to create a new node with the given data
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to push a node onto the stack
void push(Stack* stack, int data) {
    Node* newNode = createNode(data);
    newNode->next = stack->top;
    stack->top = newNode;
    stack->size++;
}

// Function to pop a node from the stack
int pop(Stack* stack) {
    if (stack->top == NULL) {
        printf("Stack is empty\n");
        exit(0);
    }
    Node* tempNode = stack->top;
    int poppedData = tempNode->data;
    stack->top = tempNode->next;
    stack->size--;
    free(tempNode);
    return poppedData;
}

// Function to display the current state of the stack
void display(Stack stack) {
    Node* tempNode = stack.top;
    printf("Stack: ");
    while (tempNode!= NULL) {
        printf("%d ", tempNode->data);
        tempNode = tempNode->next;
    }
    printf("\n");
}

int main() {
    Stack myStack;
    myStack.top = NULL;
    myStack.size = 0;

    int choice, data;

    do {
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                push(&myStack, data);
                break;
            case 2:
                data = pop(&myStack);
                printf("Popped data: %d\n", data);
                break;
            case 3:
                display(myStack);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice!= 4);

    return 0;
}