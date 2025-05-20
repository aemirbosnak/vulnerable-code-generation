//GEMINI-pro DATASET v1.0 Category: Prime Number Generator ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

int main() {

    // Set up some variables
    int num, i, j, flag;

    // Get a number from the user
    printf("Enter a positive integer: ");
    scanf("%d", &num);

    // Check if the number is valid
    if (num <= 1) {
        printf("Invalid input. Please enter a positive integer greater than 1.\n");
        return 1;
    }

    // Create an array to store the prime numbers
    int primes[num];

    // Initialize the array
    for (i = 0; i < num; i++) {
        primes[i] = 0;
    }

    // Find all the prime numbers up to the given number
    for (i = 2; i <= num; i++) {

        // Assume the number is prime
        flag = 1;

        // Check if the number is divisible by any number from 2 to the square root of the number
        for (j = 2; j <= i / 2; j++) {
            if (i % j == 0) {
                flag = 0;
                break;
            }
        }

        // If the number is prime, add it to the array
        if (flag == 1) {
            primes[i] = 1;
        }
    }

    // Print the prime numbers
    printf("The prime numbers up to %d are:\n", num);
    for (i = 2; i <= num; i++) {
        if (primes[i] == 1) {
            printf("%d ", i);
        }
    }

    printf("\n");

    return 0;
}