//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TRUE 1
#define FALSE 0
#define MAX_TERMS 100

/* Function to calculate the n-th Fibonacci number */
int fibonacci(int n) {
    int fib[MAX_TERMS];
    int i;

    fib[0] = 0;
    fib[1] = 1;

    for (i = 2; i <= n; i++) {
        fib[i] = fib[i-1] + fib[i-2];
    }

    return fib[n];
}

/* Function to calculate the sum of even Fibonacci numbers up to n */
int sum_even_fibonacci(int n) {
    int fib_sum = 0;
    int i;

    for (i = 0; i <= n; i++) {
        if (fibonacci(i) % 2 == 0) {
            fib_sum += fibonacci(i);
        }
    }

    return fib_sum;
}

int main() {
    int n;

    printf("Enter a positive integer: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid input!\n");
    } else {
        int sum = sum_even_fibonacci(n);
        printf("The sum of even Fibonacci numbers up to %d is %d.\n", n, sum);
    }

    return 0;
}