//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct node {
    int data;
    struct node* next;
} Node;

void push(Node** top_ref, int new_data);
int pop(Node** top_ref);
int peek(Node* top);
void printStack(Node* top);

int main() {
    Node* stack = NULL;
    char choice;
    int choice_val;

    do {
        printf("Enter your choice:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Print Stack\n");
        printf("5. Exit\n");
        scanf("%c", &choice);

        switch (choice) {
            case '1':
                printf("Enter the element to be pushed: ");
                scanf("%d", &choice_val);
                push(&stack, choice_val);
                break;
            case '2':
                pop(&stack);
                break;
            case '3':
                printf("Top element is: %d\n", peek(stack));
                break;
            case '4':
                printStack(stack);
                break;
            case '5':
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    } while (1);

    return 0;
}

void push(Node** top_ref, int new_data) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->data = new_data;
    new_node->next = (*top_ref);
    (*top_ref) = new_node;
}

int pop(Node** top_ref) {
    Node* top = *top_ref;
    int data = top->data;
    Node* temp = top;
    *top_ref = top->next;
    free(temp);
    return data;
}

int peek(Node* top) {
    return top->data;
}

void printStack(Node* top) {
    if (top == NULL)
        printf("Stack is empty\n");
    else {
        printf("Stack elements are: ");
        while (top!= NULL) {
            printf("%d ", top->data);
            top = top->next;
        }
        printf("\n");
    }
}