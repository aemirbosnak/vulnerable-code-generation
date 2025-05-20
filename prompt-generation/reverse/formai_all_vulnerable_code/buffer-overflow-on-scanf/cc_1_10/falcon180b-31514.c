//Falcon-180B DATASET v1.0 Category: Prime Number Generator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NUM 1000000 // define maximum number to check for prime

// function to check if a number is prime
bool isPrime(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i <= num / 2; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

// function to generate prime numbers
void generatePrimes(int start, int end) {
    printf("Generating prime numbers between %d and %d...\n", start, end);
    for (int i = start; i <= end; i++) {
        if (isPrime(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

int main() {
    int start, end;

    // prompt user for start and end numbers
    printf("Enter start number: ");
    scanf("%d", &start);
    printf("Enter end number: ");
    scanf("%d", &end);

    // check if start number is greater than end number
    if (start > end) {
        printf("Invalid input: start number cannot be greater than end number.\n");
        return 1;
    }

    // generate prime numbers between start and end numbers
    generatePrimes(start, end);

    return 0;
}