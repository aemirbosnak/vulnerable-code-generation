//LLAMA2-13B DATASET v1.0 Category: Educational ; Style: mathematical
#include <stdio.h>
#include <math.h>

// Function to calculate the factorial of a given number
int factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n-1);
    }
}

// Function to calculate the Fibonacci sequence
int fibonacci(int n) {
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

int main() {
    int n, k;

    // Problem 1: Find the factorial of 5
    printf("The factorial of 5 is: %d\n", factorial(5));

    // Problem 2: Find the Fibonacci sequence up to n=8
    printf("The Fibonacci sequence up to n=8 is: ");
    for (k = 0; k <= 8; k++) {
        printf("%d ", fibonacci(k));
    }
    printf("\n");

    // Problem 3: Find the sum of the first n natural numbers
    printf("The sum of the first n natural numbers is: %d\n",
           sum_natural_numbers(n));

    // Problem 4: Find the product of the first n natural numbers
    printf("The product of the first n natural numbers is: %d\n",
           product_natural_numbers(n));

    return 0;
}

// Function to calculate the sum of the first n natural numbers
int sum_natural_numbers(int n) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i;
    }
    return sum;
}

// Function to calculate the product of the first n natural numbers
int product_natural_numbers(int n) {
    int product = 1;
    for (int i = 1; i <= n; i++) {
        product *= i;
    }
    return product;
}