//Falcon-180B DATASET v1.0 Category: Medical Store Management System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

struct node {
    int data;
    struct node* next;
};

struct node* create_node(int data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void push(struct node** top_ref, int new_data) {
    struct node* new_node = create_node(new_data);
    new_node->next = *top_ref;
    *top_ref = new_node;
}

int pop(struct node** top_ref) {
    char res;
    struct node* top = *top_ref;
    if (top == NULL) {
        printf("Stack is empty\n");
        exit(0);
    }
    res = top->data;
    struct node* temp = top;
    *top_ref = top->next;
    free(temp);
    return res;
}

int peek(struct node* top) {
    if (top == NULL) {
        printf("Stack is empty\n");
        exit(0);
    }
    return top->data;
}

int is_empty(struct node* top) {
    return top == NULL;
}

void display(struct node* top) {
    while (top!= NULL) {
        printf("%d ", top->data);
        top = top->next;
    }
}

int main() {
    struct node* stack = NULL;
    int choice, value;

    do {
        printf("\n\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to be pushed: ");
                scanf("%d", &value);
                push(&stack, value);
                break;
            case 2:
                value = pop(&stack);
                printf("The popped value is %d\n", value);
                break;
            case 3:
                value = peek(stack);
                printf("The top value is %d\n", value);
                break;
            case 4:
                display(stack);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice!= 5);

    return 0;
}