//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DISKS 100
#define STACK_SIZE 1000

// Function prototypes
void push(int *stack, int *top, int value);
int pop(int *stack, int *top);
void display(int *stack, int size);
void move_disk(int n, char from, char to, char aux);
void tower_of_hanoi(int n, char from, char to, char aux);

int main() {
    int n, choice;
    char ch;

    printf("Enter the number of disks: ");
    scanf("%d", &n);

    int stack[STACK_SIZE];
    int top = -1;

    tower_of_hanoi(n, 'A', 'C', 'B');

    return 0;
}

void push(int *stack, int *top, int value) {
    if (*top >= (*top - 1)) {
        printf("\nStack Overflow");
        exit(0);
    } else {
        (*top)++;
        stack[*top] = value;
    }
}

int pop(int *stack, int *top) {
    int item;
    if (*top < 0) {
        printf("\nStack Underflow");
        exit(0);
    } else {
        item = stack[*top];
        (*top)--;
        return item;
    }
}

void display(int *stack, int size) {
    int i;
    for (i = 0; i <= size; i++) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

void move_disk(int n, char from, char to, char aux) {
    if (n == 1) {
        printf("\nMove disk 1 from rod %c to rod %c", from, to);
        return;
    }

    move_disk(n - 1, from, aux, to);

    printf("\nMove disk %d from rod %c to rod %c", n, from, to);

    move_disk(n - 1, aux, to, from);
}

void tower_of_hanoi(int n, char from, char to, char aux) {
    int stack[STACK_SIZE];
    int top = -1;

    push(stack, &top, n);

    while (top >= 0) {
        int size = pop(stack, &top);

        if (size == 1) {
            move_disk(1, from, to, aux);
        } else {
            push(stack, &top, size);
            move_disk(size, from, aux, to);
            move_disk(size - 1, aux, to, from);
        }
    }
}