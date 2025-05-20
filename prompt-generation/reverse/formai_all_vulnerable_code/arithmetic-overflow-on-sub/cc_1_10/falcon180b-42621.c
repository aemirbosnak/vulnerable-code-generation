//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

#define STACK_MAX 1000

typedef struct {
    int data;
    struct node *next;
} node;

node *stack[STACK_MAX];
int top = -1;

void push(int data) {
    node *temp = (node *) malloc(sizeof(node));
    temp->data = data;
    temp->next = NULL;
    if (top >= STACK_MAX - 1) {
        printf("Stack Overflow\n");
        exit(0);
    }
    top++;
    stack[top] = temp;
}

int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        exit(0);
    }
    int data = stack[top]->data;
    node *temp = stack[top];
    top--;
    free(temp);
    return data;
}

void display() {
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

void tower_of_hanoi(int n, char from_rod, char to_rod, char aux_rod) {
    if (n == 1) {
        printf("Move disk 1 from rod %c to rod %c\n", from_rod, to_rod);
        return;
    }
    tower_of_hanoi(n - 1, from_rod, aux_rod, to_rod);
    printf("Move disk %d from rod %c to rod %c\n", n, from_rod, to_rod);
    tower_of_hanoi(n - 1, aux_rod, to_rod, from_rod);
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    tower_of_hanoi(n, 'A', 'C', 'B');
    return 0;
}