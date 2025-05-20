#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_DISKS 100

typedef struct {
    int data[MAX_DISKS];
    int top;
} Stack;

void initStack(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

int isFull(Stack *s) {
    return s->top == MAX_DISKS - 1;
}

void push(Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack Overflow\n");
        exit(1);
    }
    s->data[++s->top] = value;
}

int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return s->data[s->top--];
}

void moveDisk(Stack *src, Stack *dest) {
    int disk = pop(src);
    push(dest, disk);
}

void towerOfHanoi(int n, Stack *src, Stack *aux, Stack *dest) {
    if (n == 1) {
        moveDisk(src, dest);
        return;
    }
    towerOfHanoi(n - 1, src, dest, aux);
    moveDisk(src, dest);
    towerOfHanoi(n - 1, aux, src, dest);
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    Stack src, aux, dest;
    initStack(&src);
    initStack(&aux);
    initStack(&dest);

    for (int i = n; i > 0; i--) {
        push(&src, i);
    }

    towerOfHanoi(n, &src, &aux, &dest);

    printf("Tower of Hanoi solved!\n");

    return 0;
}
