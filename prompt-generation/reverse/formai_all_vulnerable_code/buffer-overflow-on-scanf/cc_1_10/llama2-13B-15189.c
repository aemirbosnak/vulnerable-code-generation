//LLAMA2-13B DATASET v1.0 Category: File handling ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to calculate the factorial of a given number
int factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n-1);
    }
}

// Function to calculate the nth Fibonacci number
int fibonacci(int n) {
    if (n == 0 || n == 1) {
        return n;
    } else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

int main() {
    int n, m, result;

    // Calculate the factorial of a given number
    printf("Enter a positive integer: ");
    scanf("%d", &n);
    result = factorial(n);
    printf("The factorial of %d is %d\n", n, result);

    // Calculate the nth Fibonacci number
    printf("Enter a positive integer: ");
    scanf("%d", &n);
    result = fibonacci(n);
    printf("The nth Fibonacci number is %d\n", n, result);

    // Calculate the sum of the first n natural numbers
    printf("Enter a positive integer: ");
    scanf("%d", &n);
    result = 0;
    for (int i = 1; i <= n; i++) {
        result += i;
    }
    printf("The sum of the first %d natural numbers is %d\n", n, result);

    // Calculate the product of the first n positive integers
    printf("Enter a positive integer: ");
    scanf("%d", &n);
    result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    printf("The product of the first %d positive integers is %d\n", n, result);

    return 0;
}