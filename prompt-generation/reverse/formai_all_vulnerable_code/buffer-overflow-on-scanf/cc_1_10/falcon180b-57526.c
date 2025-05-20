//Falcon-180B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: Donald Knuth
#include <stdio.h>

#define MAX_FIB_NUM 10000

int fib[MAX_FIB_NUM];
int top = -1;

void push(int n) {
    if (top >= MAX_FIB_NUM - 1) {
        printf("Stack overflow\n");
        return;
    }
    fib[++top] = n;
}

int pop() {
    if (top < 0) {
        printf("Stack underflow\n");
        return 0;
    }
    return fib[top--];
}

int peek() {
    if (top < 0) {
        printf("Stack is empty\n");
        return 0;
    }
    return fib[top];
}

void print_fib() {
    if (top < 0) {
        printf("No Fibonacci numbers generated yet.\n");
        return;
    }
    printf("Fibonacci numbers generated:\n");
    for (int i = 0; i <= top; i++) {
        printf("%d ", fib[i]);
    }
    printf("\n");
}

int main() {
    int n1 = 0, n2 = 1, next_term;
    printf("Enter the number of Fibonacci terms to generate: ");
    scanf("%d", &next_term);
    push(n1);
    push(n2);
    int count = 2;
    while (count < next_term) {
        next_term = pop() + pop();
        push(next_term);
        count++;
    }
    print_fib();
    return 0;
}