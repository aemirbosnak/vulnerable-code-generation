//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: beginner-friendly
#include <stdio.h>
#include <math.h>

// Function to calculate the factorial of a number
long long factorial(int n) {
    long long result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

// Function to calculate the Fibonacci sequence up to a given number of terms
void fibonacci(int n) {
    int t1 = 0, t2 = 1, nextTerm;

    printf("Fibonacci sequence up to %d terms:\n", n);
    printf("0 1 ");

    for (int i = 2; i < n; i++) {
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
        printf("%d ", t2);
    }
}

int main() {
    int choice, numTerms;

    printf("1. Calculate factorial\n");
    printf("2. Calculate Fibonacci sequence\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter a number to calculate its factorial: ");
            scanf("%d", &numTerms);
            printf("Factorial of %d = %lld\n", numTerms, factorial(numTerms));
            break;
        case 2:
            printf("Enter the number of terms for the Fibonacci sequence: ");
            scanf("%d", &numTerms);
            fibonacci(numTerms);
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}