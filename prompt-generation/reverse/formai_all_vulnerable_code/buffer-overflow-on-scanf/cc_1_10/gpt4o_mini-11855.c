//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <time.h>

#define MAX_NUMBER 1000
#define BUFFER_SIZE 100

// Function to check if a number is prime
bool is_prime(int num) {
    // Edge cases
    if (num <= 1) return false;
    if (num <= 3) return true; // 2 and 3 are prime

    // Check for factors from 2 to sqrt(num)
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

// Function to generate prime numbers up to a maximum limit
void generate_primes(int max) {
    printf("\nInitializing the Neon Prime Generator... \n");
    printf("Scanning the digital wasteland for prime values...\n");

    // Using a sleep to simulate processing (cyberpunk style)
    for (int num = 2; num <= max; num++) {
        if (is_prime(num)) {
            printf("Prime found: %d\n", num);
            usleep(100000); // Sleep for 0.1 seconds for dramatic effect
        }
    }

    printf("\nScan complete. The neon lights blink in numerical harmony.\n");
}

// Function to display the main menu
void display_menu() {
    printf("====================================\n");
    printf("    Cyberpunk Prime Number Nexus    \n");
    printf("====================================\n");
    printf("1. Generate primes up to 1000\n");
    printf("2. Query a specific number\n");
    printf("3. Exit the Neon Nexus\n");
    printf("====================================\n");
    printf("Select your option: ");
}

// Function to query if a specific number is prime
void query_number(int num) {
    printf("Querying number: %d...\n", num);
    usleep(500000); // Simulate processing delay
    if (is_prime(num)) {
        printf("Result: The number %d is a PRIME in this digital dystopia.\n", num);
    } else {
        printf("Result: The number %d is NOT a prime, just a ghost in the code.\n", num);
    }
}

int main() {
    int choice, number;

    while (true) {
        display_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                generate_primes(MAX_NUMBER);
                break;
            case 2:
                printf("Enter the number to query: ");
                scanf("%d", &number);
                query_number(number);
                break;
            case 3:
                printf("Exiting the Neon Nexus...\n");
                exit(0);
            default:
                printf("Invalid option, please try again!\n");
        }
    }
    
    return 0;
}