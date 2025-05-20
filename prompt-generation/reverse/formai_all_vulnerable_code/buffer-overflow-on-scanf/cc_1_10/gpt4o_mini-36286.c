//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool is_prime(int number) {
    if (number <= 1) return false; // 0 and 1 are not prime numbers
    for (int i = 2; i * i <= number; i++) {
        if (number % i == 0) {
            return false; // Found a divisor, hence not prime
        }
    }
    return true; // If no divisors found, it is prime
}

int* generate_primes(int start, int end, int* count) {
    if (start < 2) start = 2; // Start from 2 for prime numbers
    int* primes = malloc((end - start + 1) * sizeof(int)); // Dynamically allocate memory
    *count = 0; // Initialize prime count

    for (int i = start; i <= end; i++) {
        if (is_prime(i)) {
            primes[(*count)++] = i; // Store prime and increment count
        }
    }
    return primes; // Return the array of primes
}

void display_primes(int* primes, int count) {
    printf("Prime numbers found:\n");
    for (int i = 0; i < count; i++) {
        printf("%d ", primes[i]);
    }
    printf("\n");
}

void free_memory(int* array) {
    free(array); // Free allocated memory
}

int main() {
    int start, end;
    
    while (1) {
        printf("Enter the range to generate prime numbers (start and end, separated by space): ");
        if (scanf("%d %d", &start, &end) != 2 || start > end) {
            printf("Invalid input. Please enter two integers where the first is less than or equal to the second.\n");
            while(getchar() != '\n'); // Clear the input buffer
            continue; // Restart the loop
        }

        int count;
        int* primes = generate_primes(start, end, &count);

        if (count > 0) {
            display_primes(primes, count);
        } else {
            printf("No prime numbers found in the given range.\n");
        }
        
        free_memory(primes); // Free the dynamically allocated memory

        char choice;
        printf("Do you want to generate another set of primes? (y/n): ");
        while(getchar() != '\n'); // Clear the input buffer
        choice = getchar();
        if (choice != 'y' && choice != 'Y') {
            break; // Exit the loop if user does not want to continue
        }
    }
    
    printf("Thank you for using the Prime Number Generator!\n");
    return 0;
}