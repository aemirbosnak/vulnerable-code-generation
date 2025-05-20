//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: imaginative
#include <stdio.h>

// Function prototypes
int is_prime(int num);
void sieve_of_eratosthenes(int n);

int main() {
    int n;

    // Taking input from user
    printf("Enter a positive integer: ");
    scanf("%d", &n);

    // Checking if the input is valid
    if (n <= 0) {
        printf("Invalid input\n");
        return 0;
    }

    // Printing the prime numbers up to n using Sieve of Eratosthenes
    printf("Prime numbers up to %d:\n", n);
    sieve_of_eratosthenes(n);

    return 0;
}

// Function to check if a number is prime or not
int is_prime(int num) {
    int i;

    // 1 is not a prime number
    if (num == 1) {
        return 0;
    }

    // 2 is a prime number
    if (num == 2) {
        return 1;
    }

    // Check for even numbers
    if (num % 2 == 0) {
        return 0;
    }

    // Check odd numbers
    for (i = 3; i <= num / 2; i += 2) {
        if (num % i == 0) {
            return 0;
        }
    }

    return 1;
}

// Function to print prime numbers up to n using Sieve of Eratosthenes
void sieve_of_eratosthenes(int n) {
    int i, j;
    int prime[n + 1];

    // Initialize all entries as prime
    for (i = 2; i <= n; i++) {
        prime[i] = 1;
    }

    // Mark non-prime numbers as 0
    for (i = 2; i * i <= n; i++) {
        if (prime[i] == 1) {
            for (j = i * i; j <= n; j += i) {
                prime[j] = 0;
            }
        }
    }

    // Print prime numbers
    for (i = 2; i <= n; i++) {
        if (prime[i] == 1) {
            printf("%d ", i);
        }
    }
}