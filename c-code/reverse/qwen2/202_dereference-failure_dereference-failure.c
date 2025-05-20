#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct {
    int data[MAX];
    int top;
} Stack;

void init(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

int isFull(Stack *s) {
    return s->top == MAX - 1;
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

void towerOfHanoi(int n, Stack *source, Stack *auxiliary, Stack *destination) {
    if (n == 1) {
        push(destination, pop(source));
        return;
    }

    towerOfHanoi(n - 1, source, destination, auxiliary);

    push(destination, pop(source));

    towerOfHanoi(n - 1, auxiliary, source, destination);
}

int main() {
    Stack source, auxiliary, destination;
    init(&source);
    init(&auxiliary);
    init(&destination);

    for (int i = MAX; i > 0; i--) {
        push(&source, i);
    }

    towerOfHanoi(MAX, &source, &auxiliary, &destination);

    return 0;
}
