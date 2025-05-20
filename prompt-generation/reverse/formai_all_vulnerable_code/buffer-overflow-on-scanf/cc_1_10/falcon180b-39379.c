//Falcon-180B DATASET v1.0 Category: Recursive ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int x) {
    if (top >= MAX - 1) {
        printf("Stack overflow\n");
        exit(0);
    }
    else {
        top++;
        stack[top] = x;
    }
}

int pop() {
    if (top < 0) {
        printf("Stack underflow\n");
        exit(0);
    }
    else {
        int x = stack[top];
        top--;
        return x;
    }
}

int main() {
    int n, i, j, k, m, sum = 0;

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    printf("Enter the terms:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &stack[++top]);
    }

    for (i = 0; i < n; i++) {
        m = pop();
        sum += m;
        for (j = i + 1; j <= n; j++) {
            k = pop();
            push(m + k);
        }
    }

    printf("Sum of the series: %d\n", sum);

    return 0;
}