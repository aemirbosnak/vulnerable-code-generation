//LLAMA2-13B DATASET v1.0 Category: Math exercise ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAGIC_NUMBER 42

// Function to generate a random number between 1 and 10
int get_random_number() {
    return (rand() % 10) + 1;
}

// Function to calculate the factorial of a given number
int factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

// Function to calculate the value of Euler's totient function for a given number
int phi(int n) {
    int i, r;
    long double sum = 0;

    // Calculate the prime factors of n
    for (i = 1; i <= n; i++) {
        r = n % i;
        if (r == 0) {
            sum += i;
            n /= i;
        }
    }

    // Return the sum of the prime factors
    return sum;
}

// Function to calculate the value of the golden ratio
double golden_ratio(int n) {
    return (sqrt(n * (n + 1)) + n) / (2 * n + 1);
}

// Function to calculate the value of the Fibonacci sequence at a given position
int fibonacci(int pos) {
    if (pos == 0) {
        return 0;
    } else if (pos == 1) {
        return 1;
    } else {
        return fibonacci(pos - 1) + fibonacci(pos - 2);
    }
}

int main() {
    int n, m;
    char magic_word[10];

    // Ask the user for a number and a word
    printf("Enter a number and a word: ");
    scanf("%d%s", &n, magic_word);

    // Calculate the factorial of the number
    int fact = factorial(n);

    // Calculate the value of Euler's totient function for the number
    int phi_n = phi(n);

    // Calculate the value of the golden ratio for the number
    double golden_n = golden_ratio(n);

    // Calculate the value of the Fibonacci sequence at the number
    int fib = fibonacci(n);

    // Check if the number is magic
    if (fact == phi_n && golden_n == 1.61803398875 && fib == 5) {
        printf("The number %d is magic!", n);
    } else {
        printf("The number %d is not magic :(.", n);
    }

    return 0;
}