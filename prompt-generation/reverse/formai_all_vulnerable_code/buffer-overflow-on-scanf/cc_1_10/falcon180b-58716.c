//Falcon-180B DATASET v1.0 Category: Recursive ; Style: rigorous
#include <stdio.h>

// Function to print a number recursively
void print_num(int n) {
    if (n == 0) {
        return;
    }
    printf("%d ", n);
    print_num(n-1);
}

// Function to calculate the factorial of a number recursively
int factorial(int n) {
    if (n == 0) {
        return 1;
    }
    return n * factorial(n-1);
}

// Function to calculate the Fibonacci sequence recursively
int fibonacci(int n) {
    if (n == 0 || n == 1) {
        return n;
    }
    return fibonacci(n-1) + fibonacci(n-2);
}

// Function to calculate the sum of odd numbers in a range recursively
int sum_odd(int start, int end) {
    if (start > end) {
        return 0;
    }
    return start + sum_odd(start+2, end);
}

int main() {
    int n, m;

    // Print a number recursively
    printf("Enter a number: ");
    scanf("%d", &n);
    print_num(n);
    printf("\n");

    // Calculate the factorial of a number recursively
    printf("Enter a number: ");
    scanf("%d", &n);
    printf("Factorial of %d is %d\n", n, factorial(n));

    // Calculate the Fibonacci sequence recursively
    printf("Enter a number: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("%d ", fibonacci(i));
    }
    printf("\n");

    // Calculate the sum of odd numbers in a range recursively
    printf("Enter the start number: ");
    scanf("%d", &n);
    printf("Enter the end number: ");
    scanf("%d", &m);
    printf("Sum of odd numbers between %d and %d is %d\n", n, m, sum_odd(n, m));

    return 0;
}