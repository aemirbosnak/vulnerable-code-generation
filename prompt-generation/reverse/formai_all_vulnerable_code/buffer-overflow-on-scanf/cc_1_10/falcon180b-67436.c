//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 1000

typedef struct {
    int data;
    struct node* next;
} node;

node* createNode(int data) {
    node* newNode = (node*)malloc(sizeof(node));
    if (newNode == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void push(node** top_ref, int new_data) {
    node* new_node = createNode(new_data);
    new_node->next = *top_ref;
    *top_ref = new_node;
}

int pop(node** top_ref) {
    node* top = *top_ref;
    if (top == NULL)
        return -1;
    int data = top->data;
    node* temp = top;
    *top_ref = top->next;
    free(temp);
    return data;
}

int peek(node* stack) {
    if (stack == NULL)
        return -1;
    return stack->data;
}

int isEmpty(node* stack) {
    return stack == NULL;
}

int main() {
    node* stack = NULL;
    int choice, data;
    while (true) {
        printf("Enter your choice:\n");
        printf("1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the element to be pushed: ");
                scanf("%d", &data);
                push(&stack, data);
                break;
            case 2:
                data = pop(&stack);
                if (data!= -1)
                    printf("Popped element is: %d\n", data);
                break;
            case 3:
                data = peek(stack);
                if (data!= -1)
                    printf("Top element is: %d\n", data);
                break;
            case 4:
                if (isEmpty(stack))
                    printf("Stack is empty\n");
                else {
                    printf("Stack elements are: ");
                    node* temp = stack;
                    while (temp!= NULL) {
                        printf("%d ", temp->data);
                        temp = temp->next;
                    }
                    printf("\n");
                }
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}