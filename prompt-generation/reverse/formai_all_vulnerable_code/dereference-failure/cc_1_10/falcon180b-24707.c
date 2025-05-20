//Falcon-180B DATASET v1.0 Category: Recursive ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

typedef struct {
    char data[MAX_LENGTH];
    struct node* next;
} node;

void push(node** top_ref, char new_data[MAX_LENGTH]) {
    node* new_node = (node*)malloc(sizeof(node));
    strcpy(new_node->data, new_data);
    new_node->next = (*top_ref);
    (*top_ref) = new_node;
}

void pop(node** top_ref) {
    node* top = (*top_ref);
    (*top_ref) = top->next;
    free(top);
}

void print_stack(node* stack_pointer) {
    while (stack_pointer!= NULL) {
        printf("%s ", stack_pointer->data);
        stack_pointer = stack_pointer->next;
    }
    printf("\n");
}

int main() {
    node* stack[MAX_LENGTH];
    int top = -1;
    char input[MAX_LENGTH];

    while (1) {
        printf("Enter your choice:\n");
        printf("1. Push\n2. Pop\n3. Print Stack\n4. Exit\n");
        scanf("%d", &top);

        switch (top) {
            case 1:
                printf("Enter the data to be pushed: ");
                scanf("%s", input);
                push(&stack[++top], input);
                break;
            case 2:
                if (top == -1)
                    printf("Stack is empty.\n");
                else
                    pop(&stack[top]);
                break;
            case 3:
                print_stack(stack[top]);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}