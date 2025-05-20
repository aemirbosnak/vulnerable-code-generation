//Falcon-180B DATASET v1.0 Category: Prime Number Generator ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NUMBER 1000000

// Function to check if a number is prime or not
bool isPrime(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

// Function to generate prime numbers
void generatePrimes(int start, int end) {
    printf("Prime numbers between %d and %d:\n", start, end);
    for (int i = start; i <= end; i++) {
        if (isPrime(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

int main() {
    int start, end;

    // Get input from user
    printf("Enter start number: ");
    scanf("%d", &start);
    printf("Enter end number: ");
    scanf("%d", &end);

    if (start > end) {
        printf("Invalid input. Start number should be less than or equal to end number.\n");
        return 1;
    }

    if (start < 2) {
        printf("Prime numbers start from 2.\n");
        return 1;
    }

    if (end > MAX_NUMBER) {
        printf("End number should be less than or equal to %d.\n", MAX_NUMBER);
        return 1;
    }

    // Call generatePrimes function
    generatePrimes(start, end);

    return 0;
}