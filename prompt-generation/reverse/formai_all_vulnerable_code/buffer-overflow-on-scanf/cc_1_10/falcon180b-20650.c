//Falcon-180B DATASET v1.0 Category: System boot optimizer ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct node {
    int data;
    struct node* next;
} Node;

Node* create_node(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void push(Node** top_ref, int new_data) {
    Node* new_node = create_node(new_data);
    new_node->next = *top_ref;
    *top_ref = new_node;
}

int is_empty(Node* stack) {
    return (stack == NULL);
}

int pop(Node** top_ref) {
    Node* top = *top_ref;
    int data = top->data;
    Node* temp = top;
    *top_ref = top->next;
    free(temp);
    return data;
}

void display(Node* stack) {
    while (stack!= NULL) {
        printf("%d ", stack->data);
        stack = stack->next;
    }
}

int main() {
    Node* stack = NULL;
    int choice, data;

    while (TRUE) {
        printf("\nMENU\n");
        printf("1. PUSH\n2. POP\n3. DISPLAY\n4. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter the element to be pushed: ");
            scanf("%d", &data);
            push(&stack, data);
            break;

        case 2:
            if (is_empty(stack)) {
                printf("Stack is empty\n");
            } else {
                data = pop(&stack);
                printf("Popped element is %d\n", data);
            }
            break;

        case 3:
            display(stack);
            break;

        case 4:
            exit(0);

        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}