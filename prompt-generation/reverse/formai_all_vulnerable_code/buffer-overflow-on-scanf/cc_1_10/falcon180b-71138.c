//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: automated
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int data;
    struct node* next;
} node;

void push(node** top_ref, int new_data) {
    node* new_node = (node*) malloc(sizeof(node));
    new_node->data = new_data;
    new_node->next = (*top_ref);
    (*top_ref) = new_node;
}

int pop(node** top_ref) {
    node* top_node = *top_ref;
    int popped_data = top_node->data;
    *top_ref = top_node->next;
    free(top_node);
    return popped_data;
}

void print_stack(node* stack) {
    while (stack!= NULL) {
        printf("%d ", stack->data);
        stack = stack->next;
    }
}

void move_tower(int n, char source, char dest, char aux) {
    node* stack[n];
    for (int i = 0; i < n; i++) {
        push(&stack[i], i+1);
    }
    printf("Initial tower:\n");
    print_stack(stack[0]);
    printf("\n");

    while (n > 1) {
        while (stack[n-1]->data > 1) {
            pop(&stack[n-1]);
            push(&stack[n-2], pop(&stack[n-1]));
        }
        push(&stack[n-1], pop(&stack[n-2]));
        printf("Move disk %d from %c to %c:\n", stack[n-1]->data, source, dest);
        print_stack(stack[n-1]);
        printf("\n");
        n--;
    }
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    move_tower(n, 'A', 'C', 'B');
    return 0;
}