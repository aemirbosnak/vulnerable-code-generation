//MISTRAL-7B DATASET v1.0 Category: Recursive ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void fibonacci(int n);

int main() {
    int num;

    printf("Enter the number of terms to print: ");
    scanf("%d", &num);

    if (num > MAX) {
        printf("The Fibonacci sequence of %d terms is too large.\n", num);
        exit(EXIT_FAILURE);
    }

    printf("Fibonacci sequence up to %d:\n", num);
    fibonacci(num);

    return 0;
}

void fibonacci(int n) {
    if (n == 0) {
        printf("Fibonacci[0] = %d\n", 0);
        return;
    }

    if (n == 1) {
        printf("Fibonacci[1] = %d\n", 1);
        return;
    }

    int first = 0, second = 1, next;

    printf("Fibonacci[%d] = ", n);

    for (int i = 0; i < n - 1; i++) {
        next = first + second;
        first = second;
        second = next;

        if (i != n - 2)
            printf("Fibonacci[%d] = ", i + 1);
    }

    printf("%d\n", next);

    fibonacci(n - 1);
}