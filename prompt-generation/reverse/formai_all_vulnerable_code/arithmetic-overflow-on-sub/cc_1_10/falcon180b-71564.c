//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

#define MAX_DISKS 10
#define STACK_SIZE (MAX_DISKS * 4)

// Function to print the disks on the stack
void print_stack(int stack[], int top) {
    printf("Stack: ");
    for (int i = top - 1; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

// Function to check if a move is valid
int is_valid_move(int from, int to, int n, int stack[], int top) {
    if (from < 0 || from >= n || to < 0 || to >= n || from == to) {
        return 0;
    }
    if (top >= STACK_SIZE) {
        return 0;
    }
    return 1;
}

// Function to move a disk from one peg to another
void move_disk(int from, int to, int n, int stack[], int *top) {
    if (is_valid_move(from, to, n, stack, *top)) {
        printf("Move disk %d from peg %d to peg %d\n", n, from, to);
        if (from == to) {
            return;
        }
        if (from < to) {
            stack[*top] = n;
            (*top)++;
            move_disk(from + 1, to, n, stack, top);
        } else {
            stack[*top] = n;
            (*top)++;
            move_disk(from - 1, to, n, stack, top);
        }
    }
}

// Function to solve the tower of hanoi problem
void tower_of_hanoi(int n, int from, int to, int aux, int stack[], int top) {
    if (n == 1) {
        move_disk(from, to, n, stack, top);
        return;
    }
    tower_of_hanoi(n - 1, from, aux, to, stack, top);
    move_disk(from, to, n, stack, top);
    tower_of_hanoi(n - 1, aux, to, from, stack, top);
}

int main() {
    int n, from, to;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    int stack[STACK_SIZE];
    int top = -1;
    printf("Solving the Tower of Hanoi problem with %d disks...\n", n);
    tower_of_hanoi(n, 0, 2, 1, stack, &top);
    print_stack(stack, top);
    return 0;
}