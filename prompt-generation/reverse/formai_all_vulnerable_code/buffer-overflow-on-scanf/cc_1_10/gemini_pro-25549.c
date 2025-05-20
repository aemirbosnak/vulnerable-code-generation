//GEMINI-pro DATASET v1.0 Category: Prime Number Generator ; Style: modular
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// Function to check if a number is prime
bool isPrime(int number) {
    if (number <= 1) {
        return false;
    }

    for (int i = 2; i <= number / 2; i++) {
        if (number % i == 0) {
            return false;
        }
    }

    return true;
}

// Function to generate a list of prime numbers up to a given number
int* generatePrimeNumbers(int n) {
    int* primeNumbers = (int*)malloc(n * sizeof(int));

    int count = 0;
    for (int i = 2; i <= n; i++) {
        if (isPrime(i)) {
            primeNumbers[count++] = i;
        }
    }

    return primeNumbers;
}

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    int* primeNumbers = generatePrimeNumbers(n);

    printf("The prime numbers up to %d are:\n", n);
    for (int i = 0; i < n; i++) {
        printf("%d ", primeNumbers[i]);
    }

    printf("\n");

    free(primeNumbers);

    return 0;
}