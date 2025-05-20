//LLAMA2-13B DATASET v1.0 Category: Educational ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAGIC_NUMBER 42

// Function to calculate the factorial of a given number
int factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n-1);
    }
}

// Function to calculate the sum of the digits of a given number
int sum_digits(int n) {
    int sum = 0;
    while (n != 0) {
        sum = (sum + (n % 10)) % 10;
        n /= 10;
    }
    return sum;
}

// Function to calculate the number of prime factors of a given number
int count_primes(int n) {
    int count = 0;
    while (n != 0) {
        if (isprime(n)) {
            count++;
        }
        n /= 10;
    }
    return count;
}

// Function to check if a given number is prime
int isprime(int n) {
    if (n == 1 || n == 0) {
        return 0;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int n, m, sum, count;
    char str[10];

    // Input the number to calculate the factorial of
    printf("Enter a number: ");
    scanf("%d", &n);

    // Calculate the factorial of the given number
    printf("The factorial of %d is %d\n", n, factorial(n));

    // Input the number to calculate the sum of the digits of
    printf("Enter another number: ");
    scanf("%d", &m);

    // Calculate the sum of the digits of the given number
    sum = sum_digits(m);
    printf("The sum of the digits of %d is %d\n", m, sum);

    // Input the number to calculate the number of prime factors of
    printf("Enter a third number: ");
    scanf("%d", &count);

    // Calculate the number of prime factors of the given number
    count = count_primes(count);
    printf("The number of prime factors of %d is %d\n", count, count);

    // Print a magic message
    printf("The answer to the ultimate question of life, the universe, and everything is %d\n", MAGIC_NUMBER);

    return 0;
}