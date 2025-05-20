//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define STACK_SIZE 1000

typedef struct {
    int data;
    struct node *next;
} node;

node *stack[STACK_SIZE];
int top = -1;

// function to push an element onto the stack
void push(int value) {
    if (top == STACK_SIZE - 1) {
        printf("Stack overflow\n");
        exit(0);
    }
    top++;
    stack[top] = (node *) malloc(sizeof(node));
    stack[top]->data = value;
    stack[top]->next = NULL;
}

// function to pop an element from the stack
int pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        exit(0);
    }
    int value = stack[top]->data;
    node *temp = stack[top];
    top--;
    free(temp);
    return value;
}

// function to print the stack
void print_stack() {
    if (top == -1) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements are:\n");
    node *temp = stack[top];
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// function to check if the stack is empty
int is_empty() {
    return (top == -1);
}

// function to move n disks from source to destination using the stack
void tower_of_hanoi(int n, char source, char destination, char auxiliary) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", source, destination);
        return;
    }
    tower_of_hanoi(n - 1, source, auxiliary, destination);
    printf("Move disk %d from %c to %c\n", n, source, destination);
    tower_of_hanoi(n - 1, auxiliary, destination, source);
}

// main function to call the tower_of_hanoi function
int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    tower_of_hanoi(n, 'A', 'C', 'B');
    return 0;
}