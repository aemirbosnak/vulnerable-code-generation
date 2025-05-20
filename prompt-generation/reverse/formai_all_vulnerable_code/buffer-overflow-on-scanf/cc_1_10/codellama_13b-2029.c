//Code Llama-13B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: interoperable
/*
 * Tower of Hanoi Problem in C
 *
 * Description:
 * The Tower of Hanoi is a mathematical puzzle where you have three rods and n disks of different sizes.
 * The objective of the puzzle is to move the entire stack of disks from one rod to another rod, following these rules:
 * 1. Only one disk can be moved at a time.
 * 2. Each move consists of taking the upper disk from one of the stacks and placing it on top of another stack.
 * 3. No larger disk can be placed on top of a smaller disk.
 *
 * The program will take as input the number of disks and will solve the Tower of Hanoi problem using an interoperable style.
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_DISKS 100

// Structure to represent a disk
typedef struct {
    int value;
    struct disk* next;
} disk;

// Structure to represent a stack
typedef struct {
    disk* top;
    int size;
} stack;

// Function to initialize a stack
void init_stack(stack* s) {
    s->top = NULL;
    s->size = 0;
}

// Function to push a disk onto a stack
void push(stack* s, disk* d) {
    d->next = s->top;
    s->top = d;
    s->size++;
}

// Function to pop a disk from a stack
disk* pop(stack* s) {
    if (s->size == 0) {
        return NULL;
    }
    disk* d = s->top;
    s->top = d->next;
    s->size--;
    return d;
}

// Function to move a disk from one stack to another
void move(stack* from, stack* to, int n) {
    if (n == 1) {
        disk* d = pop(from);
        push(to, d);
        return;
    }
    move(from, to, n - 1);
    move(from, to, 1);
    move(to, from, n - 1);
}

// Function to solve the Tower of Hanoi problem
void solve_tower_of_hanoi(int n) {
    stack s1, s2, s3;
    init_stack(&s1);
    init_stack(&s2);
    init_stack(&s3);
    for (int i = n; i > 0; i--) {
        push(&s1, malloc(sizeof(disk)));
        s1.top->value = i;
    }
    move(&s1, &s2, n);
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    solve_tower_of_hanoi(n);
    return 0;
}