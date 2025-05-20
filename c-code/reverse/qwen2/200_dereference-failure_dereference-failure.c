#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#define MAX 3

typedef struct {
    int arr[MAX];
    int top;
} Stack;

void push(Stack *s, int value) {
    if (s->top == MAX - 1) return;
    s->arr[++s->top] = value;
}

int pop(Stack *s) {
    if (s->top == -1) return -1;
    return s->arr[s->top--];
}

void moveDisk(Stack *src, Stack *dest) {
    int disk = pop(src);
    if (disk == -1) return;
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
    Stack src, aux, dest;
    src.top = -1; aux.top = -1; dest.top = -1;
    for (int i = MAX; i >= 1; i--) push(&src, i);

    towerOfHanoi(MAX, &src, &aux, &dest);

    // Intentional bug: Accessing an empty stack
    printf("%d\n", pop(&dest));

    return 0;
}
