//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

void printHistogram(int* primes, int count) {
    printf("\nPrime Numbers Histogram:\n");
    for (int i = 0; i < count; i++) {
        printf("%3d: ", primes[i]);
        for (int j = 0; j < primes[i]; j++) {
            if (j % 10 == 0 && j != 0) {
                printf("|");
            }
            printf("*");
        }
        printf("\n");
    }
}

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    
    for (int i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

void generatePrimes(int limit, int* primes, int* count) {
    *count = 0;
    for (int num = 2; num <= limit; num++) {
        if (isPrime(num)) {
            primes[*count] = num;
            (*count)++;
        }
    }
}

void displayMenu() {
    printf("\nPrime Number Generator\n");
    printf("1. Generate Primes up to a limit\n");
    printf("2. Exit\n");
    printf("Choose an option: ");
}

int main() {
    int limit;
    int primes[1000]; // Array to hold prime numbers
    int count = 0;
    int option;

    do {
        displayMenu();
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Enter the limit up to which primes are to be generated: ");
                scanf("%d", &limit);

                if (limit < 2) {
                    printf("Please enter a number greater than or equal to 2.\n");
                    break;
                }

                generatePrimes(limit, primes, &count);

                printf("\nGenerated Prime Numbers up to %d:\n", limit);
                for (int i = 0; i < count; i++) {
                    printf("%d ", primes[i]);
                }
                printf("\n");
                printHistogram(primes, count);
                break;

            case 2:
                printf("Exiting program. Goodbye!\n");
                break;

            default:
                printf("Invalid option! Please choose again.\n");
        }
    } while (option != 2);

    return 0;
}