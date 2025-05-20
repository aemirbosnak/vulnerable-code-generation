//Falcon-180B DATASET v1.0 Category: Warehouse Management System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Node structure definition
struct Node {
    int data;
    struct Node* next;
};

void push(struct Node** top_ref, int new_data);
int pop(struct Node** top_ref);
int peek(struct Node* top);
int isEmpty(struct Node* top);
void display(struct Node* top);

int main() {
    struct Node* top = NULL;

    push(&top, 10);
    push(&top, 20);
    push(&top, 30);
    push(&top, 40);

    printf("Stack elements are: ");
    display(top);

    printf("\nAfter popping an element from stack: ");
    pop(&top);
    display(top);

    printf("\nTop element is: %d", peek(top));

    if(isEmpty(top))
        printf("\nStack is empty");
    else
        printf("\nStack is not empty");

    return 0;
}

void push(struct Node** top_ref, int new_data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

    if(new_node == NULL) {
        printf("\nStack overflow");
        exit(0);
    }

    new_node->data = new_data;
    new_node->next = (*top_ref);
    (*top_ref) = new_node;
}

int pop(struct Node** top_ref) {
    char res;
    struct Node* top = *top_ref;

    if(top == NULL) {
        printf("\nStack underflow");
        exit(0);
    }

    res = top->data;
    free(top);
    top = top->next;
    (*top_ref) = top;

    return res;
}

int peek(struct Node* top) {
    if(top == NULL)
        return -1;
    else
        return top->data;
}

int isEmpty(struct Node* top) {
    if(top == NULL)
        return 1;
    else
        return 0;
}

void display(struct Node* top) {
    while(top!= NULL) {
        printf("%d ", top->data);
        top = top->next;
    }
}