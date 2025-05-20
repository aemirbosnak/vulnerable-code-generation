//GPT-4o-mini DATASET v1.0 Category: Math exercise ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void printPrimeNumbers(int limit);
void printPerfectSquares(int limit);
int isPrime(int num);
int isPerfectSquare(int num);
void findNumbersWithProperties(int lower, int upper);

int main() {
    int lower, upper;

    printf("Elementary, my dear Watson! Let us unravel the mysteries of numbers.\n");
    printf("Enter the lower limit of the number range: ");
    scanf("%d", &lower);
    printf("Enter the upper limit of the number range: ");
    scanf("%d", &upper);

    findNumbersWithProperties(lower, upper);

    return 0;
}

void findNumbersWithProperties(int lower, int upper) {
    printf("\nDetecting properties of numbers in the range %d to %d...\n", lower, upper);
    printf("Here's what we found:\n");

    printf("\nPrime Numbers:\n");
    printPrimeNumbers(upper);
    
    printf("\nPerfect Squares:\n");
    printPerfectSquares(upper);
    
    printf("\nMystery numbers between %d and %d that are both primes and perfect squares (if any):\n", lower, upper);
    for(int num = lower; num <= upper; num++) {
        if(isPerfectSquare(num) && isPrime(num)) {
            printf("%d is both a prime number and a perfect square.\n", num);
        }
    }
}

void printPrimeNumbers(int limit) {
    printf("The following prime numbers were identified:\n");
    for (int i = 2; i <= limit; i++) {
        if (isPrime(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

int isPrime(int num) {
    if (num <= 1) return 0;
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

void printPerfectSquares(int limit) {
    printf("The following perfect squares were identified:\n");
    for (int i = 1; i * i <= limit; i++) {
        printf("%d ", i * i);
    }
    printf("\n");
}

int isPerfectSquare(int num) {
    int sqrtNum = sqrt(num);
    return (sqrtNum * sqrtNum == num);
}