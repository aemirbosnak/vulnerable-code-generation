//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void display(int n, long long int fib[n]) {
    printf("Fibonacci Sequence: ");
    for (int i = 0; i < n; i++) {
        printf("%lld ", fib[i]);
    }
    printf("\n\n");
}

int main()
{
    int n;
    printf("Enter the number of terms in Fibonacci Sequence: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid input. Please enter a positive integer for number of terms. \n");
        exit(0);
    }

    long long int fib[n];
    fib[0] = 0; // First term of Fibonacci sequence is always 0
    if (n > 1) {
        fib[1] = 1; // Second term of Fibonacci sequence is always 1
    }

    // Loop to calculate all Fibonacci numbers:
    for (int i = 2; i < n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    display(n, fib);

    bool isAscending = true;
    bool printed = false;

    printf("Visualized Fibonacci Sequence: \n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < fib[i]; j++) {
            if (isAscending) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        if (isAscending) {
            if (i == n - 1) {
                isAscending = false;
            } else if (fib[i+1] < fib[i]) {
                isAscending = false;
            }
        } else {
            if (!printed) {
                printf("\n");
                printed = true;
            }
            if (i == n - 1) {
                printf("\n");
            } else if (fib[i+1] > fib[i]) {
                printf("\n");
                printed = false;
                isAscending = true;
            }
        }
    }

    return 0;
}