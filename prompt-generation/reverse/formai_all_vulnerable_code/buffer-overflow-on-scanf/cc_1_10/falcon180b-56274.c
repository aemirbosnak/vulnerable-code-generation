//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct node {
    int data;
    struct node* next;
};

void push(struct node** top_ref, int new_data);
int pop(struct node** top_ref);
int peek(struct node* top);
void print_stack(struct node* top);

int main() {
    struct node* stack = (struct node*) malloc(sizeof(struct node));
    stack->data = -1;
    stack->next = NULL;

    int choice, data;

    do {
        printf("\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Print Stack\n");
        printf("5. Exit\n");
        printf("\n");

        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter element to push: ");
                scanf("%d", &data);
                push(&stack, data);
                break;

            case 2:
                data = pop(&stack);
                if(data!= -1)
                    printf("Popped element is: %d\n", data);
                break;

            case 3:
                data = peek(stack);
                if(data!= -1)
                    printf("Top element is: %d\n", data);
                break;

            case 4:
                print_stack(stack);
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice\n");
        }

    } while(1);

    return 0;
}

void push(struct node** top_ref, int new_data) {
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->next = (*top_ref);
    (*top_ref) = new_node;
}

int pop(struct node** top_ref) {
    char res;
    struct node* top = *top_ref;

    if(top == NULL) {
        printf("Stack is Empty\n");
        return -1;
    }

    res = top->data;
    struct node* temp = top;
    top = top->next;
    free(temp);
    (*top_ref) = top;

    return res;
}

int peek(struct node* top) {
    if(top == NULL)
        return -1;

    return top->data;
}

void print_stack(struct node* top) {
    if(top == NULL)
        printf("Stack is Empty\n");
    else {
        printf("Stack elements are: ");
        while(top!= NULL) {
            printf("%d ", top->data);
            top = top->next;
        }
        printf("\n");
    }
}