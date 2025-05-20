//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void display_menu();
void generate_prime_numbers(int limit);
bool is_prime(int num);
void print_primes(int *primes, int count);
void free_memory(int *primes);

int main() {
    int limit;
    int choice;
    
    do {
        display_menu();
        printf("Enter your choice (1-3): ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter the upper limit for prime number generation: ");
                scanf("%d", &limit);
                generate_prime_numbers(limit);
                break;
            case 2:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please select again.\n");
        }
        
    } while (choice != 2);
    
    return 0;
}

void display_menu() {
    printf("\n--- Prime Number Generator Menu ---\n");
    printf("1. Generate Prime Numbers\n");
    printf("2. Exit\n");
}

void generate_prime_numbers(int limit) {
    if (limit < 2) {
        printf("No prime numbers available below 2.\n");
        return;
    }

    int *primes = (int *)malloc(sizeof(int) * limit);
    if (primes == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    int count = 0;
    for (int num = 2; num <= limit; num++) {
        if (is_prime(num)) {
            primes[count] = num;
            count++;
        }
    }

    print_primes(primes, count);
    free_memory(primes);
}

bool is_prime(int num) {
    if (num <= 1) return false;
    if (num <= 3) return true;

    if (num % 2 == 0 || num % 3 == 0) return false;

    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

void print_primes(int *primes, int count) {
    printf("Prime numbers generated:\n");
    for (int i = 0; i < count; i++) {
        printf("%d ", primes[i]);
    }
    printf("\n");
}

void free_memory(int *primes) {
    free(primes);
}