//LLAMA2-13B DATASET v1.0 Category: Math exercise ; Style: modular
#include <stdio.h>
#include <math.h>

// Function to calculate the factorial of a given number
int factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

// Function to calculate the sum of the first n natural numbers
int sum_natural(int n) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i;
    }
    return sum;
}

// Function to calculate the product of the first n natural numbers
int product_natural(int n) {
    int product = 1;
    for (int i = 1; i <= n; i++) {
        product *= i;
    }
    return product;
}

int main() {
    int n, m;
    printf("Enter a positive integer: ");
    scanf("%d", &n);

    // Calculate the factorial of n
    printf("The factorial of %d is: %d\n", n, factorial(n));

    // Calculate the sum of the first n natural numbers
    printf("The sum of the first %d natural numbers is: %d\n", n, sum_natural(n));

    // Calculate the product of the first n natural numbers
    printf("The product of the first %d natural numbers is: %d\n", n, product_natural(n));

    // Ask the user for another positive integer
    printf("Enter another positive integer: ");
    scanf("%d", &m);

    // Calculate the factorial of m
    printf("The factorial of %d is: %d\n", m, factorial(m));

    return 0;
}