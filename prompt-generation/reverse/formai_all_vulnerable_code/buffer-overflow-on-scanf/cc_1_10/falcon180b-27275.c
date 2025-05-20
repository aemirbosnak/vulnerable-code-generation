//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define a function to calculate the factorial of a given number
long long factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    long long result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

int main() {
    int n;
    printf("Enter a positive integer: ");
    scanf("%d", &n);

    // Calculate the factorial of the given number
    long long fact = factorial(n);

    // Calculate the sum of the digits of the factorial
    int sum = 0;
    while (fact!= 0) {
        sum += fact % 10;
        fact /= 10;
    }

    // Calculate the product of the digits of the factorial
    long long prod = 1;
    while (fact!= 0) {
        prod *= fact % 10;
        fact /= 10;
    }

    // Calculate the sum of the squares of the digits of the factorial
    int square_sum = 0;
    while (fact!= 0) {
        square_sum += pow(fact % 10, 2);
        fact /= 10;
    }

    // Calculate the cube of the sum of the digits of the factorial
    long long cube_sum = 0;
    while (fact!= 0) {
        cube_sum += pow(fact % 10, 3);
        fact /= 10;
    }

    // Display the results
    printf("Factorial of %d is: %lld\n", n, fact);
    printf("Sum of the digits of the factorial: %d\n", sum);
    printf("Product of the digits of the factorial: %lld\n", prod);
    printf("Sum of the squares of the digits of the factorial: %d\n", square_sum);
    printf("Cube of the sum of the digits of the factorial: %lld\n", cube_sum);

    return 0;
}