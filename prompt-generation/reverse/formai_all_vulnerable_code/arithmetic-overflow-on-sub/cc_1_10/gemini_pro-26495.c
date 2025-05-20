//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int value;
    struct node *next;
} node;

typedef struct stack {
    node *top;
    int size;
} stack;

bool push(stack *s, int value) {
    node *new_node = (node *)malloc(sizeof(node));
    if (new_node == NULL) {
        return false;
    }
    new_node->value = value;
    new_node->next = s->top;
    s->top = new_node;
    s->size++;
    return true;
}

bool pop(stack *s, int *value) {
    if (s->size == 0) {
        return false;
    }
    node *temp = s->top;
    *value = temp->value;
    s->top = temp->next;
    free(temp);
    s->size--;
    return true;
}

int peek(stack *s) {
    if (s->size == 0) {
        return -1;
    }
    return s->top->value;
}

void print_stack(stack *s) {
    node *temp = s->top;
    while (temp != NULL) {
        printf("%d ", temp->value);
        temp = temp->next;
    }
    printf("\n");
}

void tower_of_hanoi(int n, stack *source, stack *destination, stack *auxiliary) {
    if (n == 1) {
        int value;
        pop(source, &value);
        push(destination, value);
    } else {
        tower_of_hanoi(n - 1, source, auxiliary, destination);
        int value;
        pop(source, &value);
        push(destination, value);
        tower_of_hanoi(n - 1, auxiliary, destination, source);
    }
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    stack source, destination, auxiliary;
    source.top = NULL;
    source.size = 0;
    destination.top = NULL;
    destination.size = 0;
    auxiliary.top = NULL;
    auxiliary.size = 0;

    for (int i = n; i >= 1; i--) {
        push(&source, i);
    }

    printf("Source stack: ");
    print_stack(&source);

    printf("Destination stack: ");
    print_stack(&destination);

    printf("Auxiliary stack: ");
    print_stack(&auxiliary);

    tower_of_hanoi(n, &source, &destination, &auxiliary);

    printf("Source stack: ");
    print_stack(&source);

    printf("Destination stack: ");
    print_stack(&destination);

    printf("Auxiliary stack: ");
    print_stack(&auxiliary);

    return 0;
}