//LLAMA2-13B DATASET v1.0 Category: Math exercise ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_LENGTH 100
#define MIN_VALUE -1000
#define MAX_VALUE 1000

// Function to calculate the factorial of a given number
int factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n-1);
    }
}

// Function to calculate the sum of the digits of a given number
int sumOfDigits(int n) {
    int sum = 0;
    while (n != 0) {
        sum = (sum + (n % 10)) % 10;
        n /= 10;
    }
    return sum;
}

// Function to calculate the sum of the factors of a given number
int sumOfFactors(int n) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            sum += i;
        }
    }
    return sum;
}

int main() {
    int n, m;
    char str[MAX_LENGTH];

    // Input the number to be checked for factorability
    printf("Enter a positive integer: ");
    scanf("%d", &n);

    // Check if the number is a perfect square
    if (n == factorial(sqrt(n))) {
        printf("The given number, %d, is a perfect square.\n", n);
    } else {
        // Check if the number is a sum of two perfect squares
        int a = factorial(sqrt(n / 2));
        int b = factorial(sqrt(n / 2));
        if (a + b == n) {
            printf("The given number, %d, can be expressed as a sum of two perfect squares: %d + %d.\n", n, a, b);
        } else {
            // Check if the number is a sum of three perfect squares
            int c = factorial(sqrt(n / 3));
            if (a + b + c == n) {
                printf("The given number, %d, can be expressed as a sum of three perfect squares: %d + %d + %d.\n", n, a, b, c);
            } else {
                printf("The given number, %d, is not a perfect square or a sum of two perfect squares or three perfect squares.\n", n);
            }
        }
    }

    // Calculate the sum of the digits of the number
    int sumOfDigits_n = sumOfDigits(n);
    printf("The sum of the digits of %d is %d.\n", n, sumOfDigits_n);

    // Calculate the sum of the factors of the number
    int sumOfFactors_n = sumOfFactors(n);
    printf("The sum of the factors of %d is %d.\n", n, sumOfFactors_n);

    // Calculate the product of the digits of the number
    int productOfDigits_n = 1;
    for (int i = 1; i <= n; i++) {
        productOfDigits_n *= (n % 10);
    }
    printf("The product of the digits of %d is %d.\n", n, productOfDigits_n);

    // Calculate the product of the factors of the number
    int productOfFactors_n = 1;
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            productOfFactors_n *= i;
        }
    }
    printf("The product of the factors of %d is %d.\n", n, productOfFactors_n);

    // Calculate the number of prime factors of the number
    int primeFactors_n = 0;
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            primeFactors_n += (i > 1) ? 1 : 0;
        }
    }
    printf("The number of prime factors of %d is %d.\n", n, primeFactors_n);

    // Calculate the number of unique digits in the number
    int uniqueDigits_n = 0;
    for (int i = 1; i <= n; i++) {
        if (n % 10 == 0) {
            uniqueDigits_n++;
        }
    }
    printf("The number of unique digits in %d is %d.\n", n, uniqueDigits_n);

    // Calculate the number of trailing zeros in the number
    int trailingZeros_n = 0;
    for (int i = 1; i <= n; i++) {
        if (n % 10 == 0) {
            trailingZeros_n++;
        }
    }
    printf("The number of trailing zeros in %d is %d.\n", n, trailingZeros_n);

    return 0;
}