//Falcon-180B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: Alan Turing
#include <stdio.h>

#define MAX 100

int fibonacci[MAX];
int top = -1;

void push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    top++;
    fibonacci[top] = value;
}

int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    int value = fibonacci[top];
    top--;
    return value;
}

int main() {
    int n, choice, num1 = 0, num2 = 1, nextTerm;

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    printf("Fibonacci Sequence:\n");
    printf("0 1 ");

    for (int i = 2; i < n; i++) {
        nextTerm = num1 + num2;
        push(nextTerm);
        num1 = num2;
        num2 = nextTerm;
    }

    while (top!= -1) {
        num1 = pop();
        printf("%d ", num1);
        num2 = pop();
    }

    return 0;
}