//LLAMA2-13B DATASET v1.0 Category: Math exercise ; Style: calm
#include <stdio.h>
#include <math.h>

// Define a function to calculate the factorial of a given integer
int factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

// Define a function to calculate the sum of the first n natural numbers
int sum_of_natural_numbers(int n) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i;
    }
    return sum;
}

// Define a function to calculate the product of the first n natural numbers
int product_of_natural_numbers(int n) {
    int product = 1;
    for (int i = 1; i <= n; i++) {
        product *= i;
    }
    return product;
}

int main() {
    int n, m;
    float ratio;

    // Calculate the factorial of a given integer
    printf("Enter a positive integer: ");
    scanf("%d", &n);
    printf("The factorial of %d is %d\n", n, factorial(n));

    // Calculate the sum of the first n natural numbers
    printf("Enter a positive integer: ");
    scanf("%d", &n);
    printf("The sum of the first %d natural numbers is %d\n", n, sum_of_natural_numbers(n));

    // Calculate the product of the first n natural numbers
    printf("Enter a positive integer: ");
    scanf("%d", &n);
    printf("The product of the first %d natural numbers is %d\n", n, product_of_natural_numbers(n));

    // Calculate the ratio of the product to the sum
    printf("Enter two positive integers: ");
    scanf("%d%d", &m, &n);
    ratio = (float)product_of_natural_numbers(m) / (float)sum_of_natural_numbers(n);
    printf("The ratio of the product of the first %d natural numbers to the sum of the first %d natural numbers is %f\n", m, n, ratio);

    return 0;
}