//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

// This function checks if a number is a prime number
bool is_prime(int number) {
    if (number <= 1) return false; // 0 and 1 are not prime numbers
    if (number <= 3) return true; // 2 and 3 are prime numbers
    if (number % 2 == 0 || number % 3 == 0) return false; // Eliminate multiples of 2 and 3

    for (int i = 5; i <= sqrt(number); i += 6) {
        if (number % i == 0 || number % (i + 2) == 0) return false; // Check factors 6k ± 1
    }
    return true;
}

// Function to generate prime numbers up to a given limit
void generate_primes(int limit) {
    if (limit < 2) {
        printf("There are no prime numbers less than %d.\n", limit);
        return;
    }

    printf("Prime numbers up to %d:\n", limit);
    for (int num = 2; num <= limit; num++) {
        if (is_prime(num)) {
            printf("%d ", num);
        }
    }
    printf("\n");
}

// Function to calculate and return the sum of prime numbers up to a given limit
int sum_of_primes(int limit) {
    int sum = 0;
    for (int num = 2; num <= limit; num++) {
        if (is_prime(num)) {
            sum += num;
        }
    }
    return sum;
}

// Function to return an array of prime numbers up to a given limit
int* array_of_primes(int limit, int* size) {
    *size = 0;
    int* primes = malloc(limit * sizeof(int)); // Allocate memory dynamically

    for (int num = 2; num <= limit; num++) {
        if (is_prime(num)) {
            primes[(*size)++] = num; // Store prime number and increment size
        }
    }
    return primes;
}

// Shape-shifting function to display primes in different styles
void display_primes(int* primes, int size, const char* style) {
    if (strcmp(style, "default") == 0) {
        printf("Default style:\n");
        for (int i = 0; i < size; i++) {
            printf("%d ", primes[i]);
        }
    } else if (strcmp(style, "vertical") == 0) {
        printf("Vertical style:\n");
        for (int i = 0; i < size; i++) {
            printf("%d\n", primes[i]);
        }
    } else if (strcmp(style, "starred") == 0) {
        printf("Starred style:\n");
        for (int i = 0; i < size; i++) {
            printf("*%d*\n", primes[i]);
        }
    } else {
        printf("Unknown style.\n");
    }
    printf("\n");
}

int main() {
    int limit;
    printf("Enter the limit for generating prime numbers: ");
    scanf("%d", &limit);

    generate_primes(limit);
    
    int size;
    int* primes = array_of_primes(limit, &size);
    
    if (size > 0) {
        int sum = sum_of_primes(limit);
        printf("Sum of prime numbers up to %d is: %d\n", limit, sum);
        
        display_primes(primes, size, "default");
        display_primes(primes, size, "vertical");
        display_primes(primes, size, "starred");
    }

    // Free dynamically allocated memory
    free(primes);
    
    return 0;
}