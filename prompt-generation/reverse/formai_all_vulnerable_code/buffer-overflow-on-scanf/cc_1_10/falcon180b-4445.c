//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

// Define the maximum size of the array
#define MAX_SIZE 100

// Define the structure for a node in the linked list
typedef struct node {
    int data;
    struct node* next;
} Node;

// Define the structure for a stack
typedef struct stack {
    Node* top;
    int size;
} Stack;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to push an element onto the stack
void push(Stack* stack, int data) {
    Node* newNode = createNode(data);
    if (stack->top == NULL) {
        stack->top = newNode;
    }
    else {
        newNode->next = stack->top;
        stack->top = newNode;
    }
    stack->size++;
}

// Function to pop an element from the stack
int pop(Stack* stack) {
    if (stack->top == NULL) {
        printf("Stack is empty\n");
        exit(1);
    }
    int data = stack->top->data;
    Node* temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
    stack->size--;
    return data;
}

// Function to print the stack
void printStack(Stack* stack) {
    if (stack->top == NULL) {
        printf("Stack is empty\n");
    }
    else {
        printf("Stack elements are:\n");
        Node* temp = stack->top;
        while (temp!= NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    Stack stack;
    stack.top = NULL;
    stack.size = 0;

    int choice, data;

    do {
        printf("Enter your choice:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Print Stack\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the element to be pushed: ");
                scanf("%d", &data);
                push(&stack, data);
                break;
            case 2:
                data = pop(&stack);
                printf("Popped element is %d\n", data);
                break;
            case 3:
                printStack(&stack);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while(choice!= 4);

    return 0;
}