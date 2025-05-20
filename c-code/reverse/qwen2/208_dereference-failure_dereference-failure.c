#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

#define MAX_SIZE 10

typedef struct {
    int data[MAX_SIZE];
    int top;
} Stack;

void push(Stack *s, int value) {
    s->data[++s->top] = value;
}

int pop(Stack *s) {
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
    source.top = -1;
    auxiliary.top = -1;
    destination.top = -1;

    for (int i = MAX_SIZE; i > 0; i--) {
        push(&source, i);
    }

    towerOfHanoi(MAX_SIZE, &source, &auxiliary, &destination);

    while (!destination.top == -1) {
        printf("%d ", pop(&destination));
    }

    return 0;
}
