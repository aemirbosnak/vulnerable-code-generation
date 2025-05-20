//GPT-4o-mini DATASET v1.0 Category: Tower of Hanoi Problem ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

#define MAX_DISCS 64 // Maximum number of discs

typedef struct {
    int discs[MAX_DISCS];
    int top;
} Stack;

void initialize(Stack* stack) {
    stack->top = -1;
}

int isFull(Stack* stack) {
    return stack->top == MAX_DISCS - 1;
}

int isEmpty(Stack* stack) {
    return stack->top == -1;
}

void push(Stack* stack, int item) {
    if (!isFull(stack)) {
        stack->discs[++stack->top] = item;
    }
}

int pop(Stack* stack) {
    if (!isEmpty(stack)) {
        return stack->discs[stack->top--];
    }
    return -1; // Return -1 if stack is empty
}

int peek(Stack* stack) {
    if (!isEmpty(stack)) {
        return stack->discs[stack->top];
    }
    return -1; // Return -1 if stack is empty
}

void moveDisc(int from, int to, int disc) {
    printf("Move disk %d from rod %d to rod %d\n", disc, from, to);
}

void hanoi(int n, Stack* source, Stack* target, Stack* auxiliary, int fromRod, int toRod, int auxRod) {
    if (n == 1) {
        int disk = pop(source);
        push(target, disk);
        moveDisc(fromRod, toRod, disk);
        return;
    }
    hanoi(n - 1, source, auxiliary, target, fromRod, auxRod, toRod);
    int disk = pop(source);
    push(target, disk);
    moveDisc(fromRod, toRod, disk);
    hanoi(n - 1, auxiliary, target, source, auxRod, toRod, fromRod);
}

void displayStacks(Stack* source, Stack* target, Stack* auxiliary, int n) {
    printf("\nCurrent State:\n");
    printf("Source rod: ");
    for (int i = source->top; i >= 0; i--) {
        printf("%d ", source->discs[i]);
    }
    printf("\nTarget rod: ");
    for (int i = target->top; i >= 0; i--) {
        printf("%d ", target->discs[i]);
    }
    printf("\nAuxiliary rod: ");
    for (int i = auxiliary->top; i >= 0; i--) {
        printf("%d ", auxiliary->discs[i]);
    }
    printf("\n");
}

void initDiscs(Stack* source, int n) {
    for (int i = n; i >= 1; i--) {
        push(source, i);
    }
}

int main() {
    Stack source, target, auxiliary;
    int n;

    printf("Enter the number of disks (1 - %d): ", MAX_DISCS);
    scanf("%d", &n);

    if (n < 1 || n > MAX_DISCS) {
        printf("Invalid number of disks. Please enter a value between 1 and %d.\n", MAX_DISCS);
        return 1;
    }

    initialize(&source);
    initialize(&target);
    initialize(&auxiliary);
    initDiscs(&source, n);

    printf("Problem starting...\n");
    displayStacks(&source, &target, &auxiliary, n);
    
    hanoi(n, &source, &target, &auxiliary, 1, 3, 2);

    printf("All disks moved successfully!\n");
    displayStacks(&source, &target, &auxiliary, n);

    return 0;
}