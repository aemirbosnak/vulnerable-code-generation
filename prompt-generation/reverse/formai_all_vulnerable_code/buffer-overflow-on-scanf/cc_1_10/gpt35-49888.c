//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: Claude Shannon
// C Prime Number Generator Program in a Claude Shannon Style

#include <stdio.h>

int checkPrime(int num);
void printPrimes(int start, int end);

int main() {

    int start, end;

    printf("Enter the starting number:\n");
    scanf("%d", &start);
    
    printf("Enter the ending number:\n");
    scanf("%d", &end);

    printf("The prime numbers between %d and %d are:\n", start, end);
    printPrimes(start, end);
    
    return 0;
}

// Function to check if a number is prime or not
int checkPrime(int num) {
    int i;

    if (num <= 1) {
        return 0;
    }

    for (i = 2; i <= num / 2; ++i) {
        if (num % i == 0) {
            return 0;
        }
    }

    return 1;
}

// Function to print all prime numbers within a range
void printPrimes(int start, int end) {
    int i, isPrime;

    for (i = start; i <= end; ++i) {
        // Check if current number is prime
        isPrime = checkPrime(i);

        if (isPrime == 1) {
            printf("%d\n", i);
        }
    }
}