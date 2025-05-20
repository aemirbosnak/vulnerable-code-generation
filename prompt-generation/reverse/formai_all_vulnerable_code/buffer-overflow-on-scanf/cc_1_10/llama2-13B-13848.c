//LLAMA2-13B DATASET v1.0 Category: Math exercise ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define a function to calculate the factorial of a given integer
int factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n-1);
    }
}

// Define a function to calculate the sum of the first n natural numbers
int sum_natural(int n) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i;
    }
    return sum;
}

// Define a function to calculate the product of the first n natural numbers
int product_natural(int n) {
    int product = 1;
    for (int i = 1; i <= n; i++) {
        product *= i;
    }
    return product;
}

int main() {
    int n;
    printf("Enter a positive integer: ");
    scanf("%d", &n);

    // Calculate the factorial of n
    int factorial_n = factorial(n);
    printf("The factorial of %d is %d\n", n, factorial_n);

    // Calculate the sum of the first n natural numbers
    int sum_n = sum_natural(n);
    printf("The sum of the first %d natural numbers is %d\n", n, sum_n);

    // Calculate the product of the first n natural numbers
    int product_n = product_natural(n);
    printf("The product of the first %d natural numbers is %d\n", n, product_n);

    return 0;
}