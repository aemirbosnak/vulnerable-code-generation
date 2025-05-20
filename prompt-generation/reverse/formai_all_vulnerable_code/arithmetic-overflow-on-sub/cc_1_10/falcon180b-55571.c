//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int value;
    struct node* next;
} node;

void print_tower(node* top) {
    while (top!= NULL) {
        printf("%d ", top->value);
        top = top->next;
    }
    printf("\n");
}

void push(node** top_ref, int new_value) {
    node* new_node = (node*) malloc(sizeof(node));
    new_node->value = new_value;
    new_node->next = (*top_ref);
    (*top_ref) = new_node;
}

node* pop(node** top_ref) {
    node* top = *top_ref;
    if (top == NULL) {
        return NULL;
    }
    *top_ref = top->next;
    return top;
}

void move(node** source, node** destination, node** auxiliary) {
    node* top = pop(source);
    push(destination, top->value);
    push(auxiliary, top);
}

void hanoi(int n, char source, char destination, char auxiliary) {
    node* top_source = NULL;
    node* top_destination = NULL;
    node* top_auxiliary = NULL;
    if (n == 1) {
        move(&top_source, &top_destination, &top_auxiliary);
    }
    else {
        hanoi(n-1, source, auxiliary, destination);
        move(&top_source, &top_destination, &top_auxiliary);
        hanoi(n-1, auxiliary, destination, source);
    }
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    hanoi(n, 'A', 'C', 'B');
    printf("Tower of Hanoi problem solved!\n");
    return 0;
}