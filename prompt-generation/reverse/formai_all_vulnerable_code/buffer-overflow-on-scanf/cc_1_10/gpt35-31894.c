//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: grateful
#include <stdio.h>

int isPrime(int n) {
    if (n <= 1) {
        return 0;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

void printSieve(int n) {
    int primes[n + 1];
    for (int i = 0; i <= n; i++) {
        primes[i] = 1;
    }
    primes[0] = primes[1] = 0;
    for (int i = 2; i <= n; i++) {
        if (primes[i]) {
            printf("%d\n", i);
            for (int j = i * i; j <= n; j += i) {
                primes[j] = 0;
            }
        }
    }
}

int main() {
    int choice, num, i;
    do {
        printf("1. Check if a number is prime\n");
        printf("2. Generate prime numbers up to a given number\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter a number: ");
                scanf("%d", &num);
                if (isPrime(num)) {
                    printf("%d is prime.\n", num);
                } else {
                    printf("%d is not prime.\n", num);
                }
                break;
            case 2:
                printf("Enter a number: ");
                scanf("%d", &num);
                printf("All prime numbers up to %d are:\n", num);
                printSieve(num);
                break;
            case 3:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 3);
    return 0;
}