//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 1000 

void initializeSieve(bool *sieve, int size) {
    for (int i = 0; i < size; i++) {
        sieve[i] = true; // Assume all numbers are prime at first
    }
    sieve[0] = sieve[1] = false; // 0 and 1 are not prime numbers
}

void generatePrimes(bool *sieve, int size) {
    for (int p = 2; p * p < size; p++) {
        if (sieve[p]) { // If sieve[p] is still true, p is prime
            for (int multiple = p * p; multiple < size; multiple += p) {
                sieve[multiple] = false; // Mark multiples of p as not prime
            }
        }
    }
}

void printPrimes(bool *sieve, int size) {
    printf("Prime numbers up to %d:\n", size - 1);
    for (int num = 0; num < size; num++) {
        if (sieve[num]) {
            printf("%d ", num);
        }
    }
    printf("\n");
}

void findPrimesInRange(int start, int end) {
    if (start < 0 || end < 0 || end < start) {
        printf("Invalid range. Please enter non-negative numbers with 'end' greater than or equal to 'start'.\n");
        return;
    }

    bool *sieve = malloc((end + 1) * sizeof(bool));
    if (sieve == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    initializeSieve(sieve, end + 1);
    generatePrimes(sieve, end + 1);

    printf("Prime numbers in range [%d, %d]:\n", start, end);
    for (int num = start; num <= end; num++) {
        if (sieve[num]) {
            printf("%d ", num);
        }
    }
    printf("\n");

    free(sieve); // Remember to free the allocated memory
}

int main() {
    int start, end;

    printf("Welcome to the Calm Prime Number Generator!\n");

    printf("Please enter the start of the range: ");
    scanf("%d", &start);
    printf("Please enter the end of the range: ");
    scanf("%d", &end);

    findPrimesInRange(start, end);

    printf("Thank you for using the Calm Prime Number Generator. Have a great day!\n");
    return 0;
}