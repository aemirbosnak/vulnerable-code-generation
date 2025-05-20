//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: sophisticated
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#define MAX_LIMIT 10000

void printBanner() {
    printf("===========================================\n");
    printf("    Prime Number Generator v1.0           \n");
    printf("===========================================\n");
}

bool isPrime(int number) {
    if (number <= 1) {
        return false;
    }
    if (number == 2) {
        return true;
    }
    if (number % 2 == 0) {
        return false; 
    }
    for (int i = 3; i <= sqrt(number); i += 2) {
        if (number % i == 0) {
            return false;
        }
    }
    return true;
}

void generatePrimes(int limit) {
    printf("Prime numbers up to %d:\n", limit);
    for (int i = 2; i <= limit; i++) {
        if (isPrime(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

int main() {
    printBanner();
    
    int choice;
    int limit;

    while (1) {
        printf("Enter a limit for prime number generation (1 to %d) or 0 to exit: ", MAX_LIMIT);
        scanf("%d", &limit);

        if (limit == 0) {
            printf("Exiting the program. Goodbye!\n");
            break;
        } else if (limit < 1 || limit > MAX_LIMIT) {
            printf("Invalid input! Please enter a value between 1 and %d.\n", MAX_LIMIT);
            continue;
        }

        generatePrimes(limit);
        printf("\nWould you like to generate more primes? (1 for Yes, 0 for No): ");
        scanf("%d", &choice);

        if (choice == 0) {
            printf("Exiting the program. Goodbye!\n");
            break;
        } else if (choice != 1) {
            printf("Invalid choice! Please enter 1 to continue or 0 to exit.\n");
        }
    }

    return 0;
}