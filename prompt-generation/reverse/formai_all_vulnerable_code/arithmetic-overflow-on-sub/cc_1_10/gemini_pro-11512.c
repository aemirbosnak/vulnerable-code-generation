//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: calm
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

typedef struct stack {
    node *top;
} stack;

void push(stack *s, int data) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = s->top;
    s->top = new_node;
}

int pop(stack *s) {
    if (s->top == NULL) {
        return -1;
    }
    int data = s->top->data;
    node *temp = s->top;
    s->top = s->top->next;
    free(temp);
    return data;
}

int peek(stack *s) {
    if (s->top == NULL) {
        return -1;
    }
    return s->top->data;
}

int is_empty(stack *s) {
    return s->top == NULL;
}

void print_stack(stack *s) {
    node *temp = s->top;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void tower_of_hanoi(int n, stack *source, stack *destination, stack *auxiliary) {
    if (n == 1) {
        push(destination, pop(source));
        return;
    }
    tower_of_hanoi(n - 1, source, auxiliary, destination);
    push(destination, pop(source));
    tower_of_hanoi(n - 1, auxiliary, destination, source);
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    stack source, destination, auxiliary;
    source.top = NULL;
    destination.top = NULL;
    auxiliary.top = NULL;
    for (int i = n; i >= 1; i--) {
        push(&source, i);
    }
    tower_of_hanoi(n, &source, &destination, &auxiliary);
    printf("The disks have been moved from the source stack to the destination stack.\n");
    return 0;
}