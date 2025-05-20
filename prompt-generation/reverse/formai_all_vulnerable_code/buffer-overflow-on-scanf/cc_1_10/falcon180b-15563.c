//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100 // maximum size of the stack

typedef struct {
    int data;
    struct node* next;
} node;

node* create_node(int data) {
    node* new_node = (node*)malloc(sizeof(node));
    if (new_node == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

node* push(node* top, int data) {
    node* new_node = create_node(data);
    new_node->next = top;
    return new_node;
}

int pop(node* top) {
    if (top == NULL) {
        printf("Stack underflow\n");
        exit(1);
    }
    int data = top->data;
    node* temp = top;
    top = top->next;
    free(temp);
    return data;
}

int peek(node* top) {
    if (top == NULL) {
        printf("Stack is empty\n");
        exit(1);
    }
    return top->data;
}

void display(node* top) {
    if (top == NULL) {
        printf("Stack is empty\n");
        exit(1);
    }
    printf("Stack elements are: ");
    while (top!= NULL) {
        printf("%d ", top->data);
        top = top->next;
    }
    printf("\n");
}

int main() {
    node* top = NULL;
    int choice, data;

    while (1) {
        printf("Enter your choice:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to be pushed: ");
                scanf("%d", &data);
                top = push(top, data);
                break;
            case 2:
                data = pop(top);
                printf("Popped value is: %d\n", data);
                break;
            case 3:
                data = peek(top);
                printf("Topmost value is: %d\n", data);
                break;
            case 4:
                display(top);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}