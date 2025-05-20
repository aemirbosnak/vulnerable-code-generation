//Falcon-180B DATASET v1.0 Category: Recursive ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

typedef struct {
    int value;
    struct node *next;
} node;

void push(node **top_ref, int new_val);
int pop(node **top_ref);
int peek(node *top);
void print_stack(node *top);

int main() {
    node *stack = NULL;
    int choice, value;

    printf("Enter 1 to push an element onto the stack\n");
    printf("Enter 2 to pop an element off the stack\n");
    printf("Enter 3 to peek at the top element\n");
    printf("Enter 4 to print the stack\n");
    printf("Enter 5 to exit\n");

    do {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to be pushed: ");
                scanf("%d", &value);
                push(&stack, value);
                break;
            case 2:
                value = pop(&stack);
                if (value!= -1)
                    printf("The popped element is %d\n", value);
                break;
            case 3:
                value = peek(stack);
                if (value!= -1)
                    printf("The top element is %d\n", value);
                break;
            case 4:
                print_stack(stack);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    } while (1);

    return 0;
}

void push(node **top_ref, int new_val) {
    node *new_node = (node *) malloc(sizeof(node));

    if (new_node == NULL) {
        printf("Stack overflow\n");
        exit(0);
    }

    new_node->value = new_val;
    new_node->next = (*top_ref);
    (*top_ref) = new_node;
}

int pop(node **top_ref) {
    char res;
    node *top = *top_ref;

    if (top == NULL)
        return -1;

    res = top->value;
    node *temp = top;
    *top_ref = top->next;
    free(temp);

    return res;
}

int peek(node *top) {
    if (top == NULL)
        return -1;

    return top->value;
}

void print_stack(node *top) {
    if (top == NULL)
        printf("Stack is empty\n");
    else {
        printf("Stack elements are: ");
        while (top!= NULL) {
            printf("%d ", top->value);
            top = top->next;
        }
        printf("\n");
    }
}