//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct node {
    int data;
    struct node* next;
} Node;

typedef struct stack {
    Node* top;
} Stack;

void push(Stack* stack, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if (stack->top == NULL) {
        stack->top = newNode;
    } else {
        newNode->next = stack->top;
        stack->top = newNode;
    }
}

int pop(Stack* stack) {
    int data = -1;
    if (stack->top!= NULL) {
        Node* temp = stack->top;
        data = temp->data;
        stack->top = temp->next;
        free(temp);
    }
    return data;
}

void printStack(Stack* stack) {
    Node* temp = stack->top;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Stack stack;
    stack.top = NULL;
    int choice, data;

    do {
        printf("Enter your choice:\n");
        printf("1. Push\n2. Pop\n3. Print\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter the element to push: ");
            scanf("%d", &data);
            push(&stack, data);
            break;
        case 2:
            data = pop(&stack);
            if (data!= -1)
                printf("Popped element is %d\n", data);
            break;
        case 3:
            printStack(&stack);
            break;
        case 4:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice!\n");
        }
    } while (choice!= 4);

    return 0;
}