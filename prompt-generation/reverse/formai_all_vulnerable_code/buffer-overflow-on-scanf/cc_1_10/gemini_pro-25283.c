//GEMINI-pro DATASET v1.0 Category: Prime Number Generator ; Style: Sherlock Holmes
// The Adventure of the Prime Numbers, a C program in the style of Sherlock Holmes.
// Dr. Watson, fetch me my pipe and magnifying glass!

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to determine if a number is prime.
int isPrime(int number) {
    int divisor;
    if (number <= 1) {
        return 0;  // 1 is not prime.
    }
    for (divisor = 2; divisor <= sqrt(number); divisor++) {
        if (number % divisor == 0) {
            return 0;  // Found a divisor, so not prime.
        }
    }
    return 1;  // No divisors found, so prime.
}

// Function to print the first n prime numbers.
void printPrimes(int n) {
    int count = 0;
    int number = 2;
    printf("The first %d prime numbers are:\n", n);
    while (count < n) {
        if (isPrime(number)) {
            printf("%3d ", number);
            count++;
        }
        number++;
    }
    printf("\n");
}

// Function to find all prime numbers within a given range.
void findPrimesInRange(int start, int end) {
    printf("The prime numbers between %d and %d are:\n", start, end);
    for (int number = start; number <= end; number++) {
        if (isPrime(number)) {
            printf("%4d ", number);
        }
    }
    printf("\n");
}

// Main function to start the investigation.
int main() {
    int choice;
    int n;
    int start, end;
    while (1) {
        printf("\nElementary, my dear Watson! Enter your choice:\n");
        printf("1. Print the first n prime numbers\n");
        printf("2. Find all prime numbers within a given range\n");
        printf("3. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("How many prime numbers would you like to see, my dear Watson?\n");
                scanf("%d", &n);
                printPrimes(n);
                break;
            case 2:
                printf("Elementary, my dear Watson! Enter the starting and ending numbers of the range:\n");
                scanf("%d %d", &start, &end);
                findPrimesInRange(start, end);
                break;
            case 3:
                printf("The game is afoot! Until next time, my dear Watson.\n");
                return 0;
            default:
                printf("Invalid choice, my dear Watson!\n");
        }
    }
    return 0;
}