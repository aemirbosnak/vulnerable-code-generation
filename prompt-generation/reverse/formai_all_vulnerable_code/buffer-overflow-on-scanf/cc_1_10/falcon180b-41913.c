//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int data;
    struct node* next;
} Node;

void push(Node** top_ref, int new_data);
void pop(Node** top_ref);
void printList(Node* node);

int main() {
    Node* top = NULL;
    int choice, value;

    do {
        printf("Enter your choice:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Print\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the value to be pushed: ");
                scanf("%d", &value);
                push(&top, value);
                break;
            case 2:
                pop(&top);
                break;
            case 3:
                printList(top);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    } while(1);

    return 0;
}

void push(Node** top_ref, int new_data) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->data = new_data;
    new_node->next = (*top_ref);
    (*top_ref) = new_node;
}

void pop(Node** top_ref) {
    Node* top = *top_ref;
    if(top == NULL) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Popped element is %d\n", top->data);
    Node* temp = top;
    top = top->next;
    free(temp);
    (*top_ref) = top;
}

void printList(Node* node) {
    while(node!= NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}