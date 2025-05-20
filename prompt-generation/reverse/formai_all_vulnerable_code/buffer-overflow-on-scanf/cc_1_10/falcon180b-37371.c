//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

#define MAX_DISKS 10
#define STACK_SIZE 50

typedef struct {
    int top;
    int *stack;
} Stack;

void push(Stack *s, int value) {
    if (s->top >= STACK_SIZE - 1) {
        printf("Error: Stack is full!\n");
        exit(1);
    }
    s->stack[++s->top] = value;
}

int pop(Stack *s) {
    if (s->top <= 0) {
        printf("Error: Stack is empty!\n");
        exit(1);
    }
    return s->stack[s->top--];
}

void move_disk(int n, char from_rod, char to_rod, char aux_rod) {
    printf("Move disk %d from rod %c to rod %c using rod %c\n", n, from_rod, to_rod, aux_rod);
}

void hanoi(int n, char from_rod, char to_rod, char aux_rod) {
    if (n == 1) {
        printf("Move disk 1 from rod %c to rod %c\n", from_rod, to_rod);
        return;
    }
    hanoi(n - 1, from_rod, aux_rod, to_rod);
    move_disk(n, from_rod, to_rod, aux_rod);
    hanoi(n - 1, aux_rod, to_rod, from_rod);
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    if (n <= 0 || n > MAX_DISKS) {
        printf("Error: Invalid number of disks!\n");
        exit(1);
    }
    printf("Tower of Hanoi with %d disks:\n", n);
    hanoi(n, 'A', 'C', 'B');
    return 0;
}