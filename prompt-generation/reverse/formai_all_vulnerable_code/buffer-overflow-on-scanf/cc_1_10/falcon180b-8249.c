//Falcon-180B DATASET v1.0 Category: Recursive ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

// Function to calculate factorial using recursion
long long factorial(int n) {
    if (n == 0)
        return 1;
    else
        return(n * factorial(n - 1));
}

// Function to calculate Fibonacci series up to n terms using recursion
void fibonacci(int n) {
    int i, t1 = 0, t2 = 1, nextTerm;

    // Print first two terms of the series
    printf("Fibonacci Series: ");
    for (i = 1; i <= 2; ++i) {
        printf("%d ", t1);
        t1 = t2;
        t2 += t1;
    }

    // Calculate and print remaining terms of the series
    for (i = 3; i <= n; ++i) {
        nextTerm = t1 + t2;
        printf("%d ", nextTerm);
        t1 = t2;
        t2 = nextTerm;
    }
}

// Main function
int main() {
    int choice, n;

    printf("1. Factorial\n2. Fibonacci Series\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Enter a number: ");
            scanf("%d", &n);
            printf("Factorial of %d = %lld\n", n, factorial(n));
            break;

        case 2:
            printf("Enter the number of terms: ");
            scanf("%d", &n);
            fibonacci(n);
            break;

        default:
            printf("Invalid choice!");
    }

    return 0;
}