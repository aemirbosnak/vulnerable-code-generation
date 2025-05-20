//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: systematic
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

void printHeader();
bool isPrime(int number);
void generatePrimes(int limit);
void printFooter();

int main() {
    printHeader();

    int limit;
    
    printf("Enter the upper limit for generating prime numbers: ");
    scanf("%d", &limit);

    if (limit < 2) {
        printf("There are no prime numbers less than 2.\n");
    } else {
        generatePrimes(limit);
    }

    printFooter();
    return 0;
}

void printHeader() {
    printf("========================================\n");
    printf("         Prime Number Generator         \n");
    printf("========================================\n");
    printf("This program generates all prime numbers\n");
    printf("up to the specified upper limit.\n");
    printf("========================================\n");
}

bool isPrime(int number) {
    if (number < 2) {
        return false;
    }
    if (number == 2) {
        return true;
    }
    if (number % 2 == 0) {
        return false;
    }
    
    int sqrtNum = (int)sqrt(number);
    for (int i = 3; i <= sqrtNum; i += 2) {
        if (number % i == 0) {
            return false;
        }
    }
    return true;
}

void generatePrimes(int limit) {
    printf("Generating prime numbers up to %d:\n", limit);
    
    int primeCount = 0; // To count the number of primes found
    for (int num = 2; num <= limit; num++) {
        if (isPrime(num)) {
            printf("%d ", num);
            primeCount++;
        }
    }

    printf("\nTotal number of prime numbers found: %d\n", primeCount);
}

void printFooter() {
    printf("========================================\n");
    printf("Thank you for using the Prime Number Generator!\n");
    printf("========================================\n");
}