//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define MAX_NUM 10000
#define MIN_NUM 2

// Function to check if a number is prime
bool is_prime(int num) {
    if (num <= 1) return false;
    if (num <= 3) return true;
    if (num % 2 == 0 || num % 3 == 0) return false;

    for (int i = 5; i <= sqrt(num); i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

// Function to generate and print prime numbers up to a limit
void generate_primes(int limit) {
    printf("Prime Numbers up to %d:\n", limit);
    for (int i = MIN_NUM; i <= limit; i++) {
        if (is_prime(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

// Function to validate user input
int get_user_input() {
    int num;
    char term;

    printf("Enter an upper limit to generate prime numbers (between %d and %d): ", MIN_NUM, MAX_NUM);
    
    while (1) {
        if (scanf("%d%c", &num, &term) != 2 || term != '\n' || num < MIN_NUM || num > MAX_NUM) {
            printf("Invalid input. Please enter a valid integer between %d and %d: ", MIN_NUM, MAX_NUM);
            while(getchar() != '\n'); // Clear the input buffer
        } else {
            break;
        }
    }
    return num;
}

// Function to display prime numbers in a formatted manner
void display_primes(int *primes, int count) {
    printf("Prime Numbers List:\n");
    for (int i = 0; i < count; i++) {
        printf("%d ", primes[i]);
        if ((i + 1) % 10 == 0) {
            printf("\n");
        }
    }
    printf("\n");
}

// Function to count how many prime numbers are there
int count_primes(int limit) {
    int count = 0;
    for (int i = MIN_NUM; i <= limit; i++) {
        if (is_prime(i)) {
            count++;
        }
    }
    return count;
}

// Main function to execute the program
int main() {
    printf("Welcome to the Prime Number Generator!\n");
    
    int limit = get_user_input();
    int prime_count = count_primes(limit);

    int *primes = (int *)malloc(prime_count * sizeof(int));
    int index = 0;

    if (primes == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        return 1;
    }

    for (int i = MIN_NUM; i <= limit; i++) {
        if (is_prime(i)) {
            primes[index++] = i;
        }
    }

    display_primes(primes, prime_count);
    free(primes);

    printf("Thank you for using the Prime Number Generator!\n");
    
    return 0;
}