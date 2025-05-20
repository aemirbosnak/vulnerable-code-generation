//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void push(struct Node** top_ref, int new_data);
int pop(struct Node** top_ref);
int peek(struct Node* top);
void print_stack(struct Node* top);

int main() {
    struct Node* stack = NULL;
    int choice, data;

    do {
        printf("\nEnter your choice:\n");
        printf("1. Push\n2. Pop\n3. Peek\n4. Print stack\n5. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to be pushed: ");
                scanf("%d", &data);
                push(&stack, data);
                break;
            case 2:
                pop(&stack);
                break;
            case 3:
                data = peek(stack);
                if (data == -1)
                    printf("Stack is empty\n");
                else
                    printf("Top element is %d\n", data);
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

void push(struct Node** top_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*top_ref);
    (*top_ref) = new_node;
}

int pop(struct Node** top_ref) {
    char res;
    struct Node* top = *top_ref;

    if (top == NULL) {
        printf("Stack is empty\n");
        return -1;
    }
    res = top->data;
    struct Node* temp = top;
    top = top->next;
    free(temp);
    (*top_ref) = top;

    return res;
}

int peek(struct Node* top) {
    if (top == NULL)
        return -1;
    else
        return top->data;
}

void print_stack(struct Node* top) {
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