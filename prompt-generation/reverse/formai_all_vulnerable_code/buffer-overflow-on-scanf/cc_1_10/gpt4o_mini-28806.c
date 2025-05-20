//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void print_menu() {
    printf("\nPrime Number Generator\n");
    printf("=======================\n");
    printf("1. Generate primes up to N\n");
    printf("2. Generate nth prime number\n");
    printf("3. Display previous generated primes\n");
    printf("4. Exit\n");
    printf("Choose an option (1-4): ");
}

bool is_prime(int number) {
    if (number <= 1) return false;
    for (int i = 2; i * i <= number; i++) {
        if (number % i == 0) return false;
    }
    return true;
}

void generate_primes_up_to_n(int n) {
    printf("Prime numbers up to %d:\n", n);
    for (int i = 2; i <= n; i++) {
        if (is_prime(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

int generate_nth_prime(int n) {
    int count = 0;
    int number = 1;

    while (count < n) {
        number++;
        if (is_prime(number)) {
            count++;
        }
    }
    return number;
}

void display_previous_primes(int *primes, int count) {
    printf("Previous generated primes:\n");
    for (int i = 0; i < count; i++) {
        printf("%d ", primes[i]);
    }
    printf("\n");
}

int main() {
    int choice;
    int *previous_primes = NULL;
    int primes_count = 0;

    while (1) {
        print_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int n;
                printf("Enter a positive integer N: ");
                scanf("%d", &n);
                generate_primes_up_to_n(n);
                
                // Store generated primes
                previous_primes = realloc(previous_primes, (primes_count + n/2) * sizeof(int));
                
                int index = primes_count;                
                for (int i = 2; i <= n; i++) {
                    if (is_prime(i)) {
                        previous_primes[index++] = i;
                    }
                }
                primes_count = index;
                break;
            }
            case 2: {
                int n;
                printf("Enter which prime to find (n): ");
                scanf("%d", &n);
                int nth_prime = generate_nth_prime(n);
                printf("The %d-th prime number is: %d\n", n, nth_prime);

                // Store generated primes
                previous_primes = realloc(previous_primes, (primes_count + 1) * sizeof(int));
                previous_primes[primes_count++] = nth_prime;
                break;
            }
            case 3: 
                display_previous_primes(previous_primes, primes_count);
                break;
            case 4:
                if (previous_primes) free(previous_primes);
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid option! Please choose again.\n");
                break;
        }
    }
    
    if (previous_primes) free(previous_primes);
    return 0;
}