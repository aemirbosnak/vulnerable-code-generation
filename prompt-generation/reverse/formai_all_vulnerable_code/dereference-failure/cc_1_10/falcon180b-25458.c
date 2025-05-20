//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 1000

struct node {
    int data;
    struct node* next;
};

struct node* head = NULL;
struct node* tail = NULL;

void push(int data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
        tail = new_node;
        return;
    }

    tail->next = new_node;
    tail = new_node;
}

int pop() {
    if (head == NULL) {
        printf("Stack is empty\n");
        return -1;
    }

    int data = head->data;
    struct node* temp = head;
    head = head->next;
    free(temp);

    if (head == NULL) {
        tail = NULL;
    }

    return data;
}

int peek() {
    if (head == NULL) {
        printf("Stack is empty\n");
        return -1;
    }

    return head->data;
}

int is_empty() {
    return head == NULL;
}

void print_stack() {
    if (head == NULL) {
        printf("Stack is empty\n");
        return;
    }

    struct node* temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    push(10);
    push(20);
    push(30);
    push(40);

    print_stack();

    int popped_data = pop();
    printf("Popped data: %d\n", popped_data);

    print_stack();

    printf("Top element: %d\n", peek());

    if (is_empty()) {
        printf("Stack is empty\n");
    } else {
        printf("Stack is not empty\n");
    }

    return 0;
}