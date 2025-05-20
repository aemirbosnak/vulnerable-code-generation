//GPT-4o-mini DATASET v1.0 Category: Math exercise ; Style: inquisitive
#include <stdio.h>
#include <math.h>

// Function to check if a number is prime
int is_prime(int num) {
    if (num <= 1) return 0;
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) return 0;
    }
    return 1;
}

// Function to generate prime numbers up to a limit
void generate_primes(int limit) {
    printf("Prime numbers up to %d:\n", limit);
    for (int i = 2; i <= limit; i++) {
        if (is_prime(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

// Function to calculate the factorial of a number
long long factorial(int n) {
    long long result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

// Function to calculate permutations of n distinct objects taken r at a time
long long permutations(int n, int r) {
    return factorial(n) / factorial(n - r);
}

// Function to calculate combinations of n distinct objects taken r at a time
long long combinations(int n, int r) {
    return factorial(n) / (factorial(r) * factorial(n - r));
}

// Function to explore Pythagorean triples
void explore_pythagorean_triples(int limit) {
    printf("Pythagorean triples up to %d:\n", limit);
    for (int a = 1; a <= limit; a++) {
        for (int b = a; b <= limit; b++) {
            for (int c = b; c <= limit; c++) {
                if (a * a + b * b == c * c) {
                    printf("(%d, %d, %d)\n", a, b, c);
                }
            }
        }
    }
}

// Main function to prompt user and perform calculations
int main() {
    int choice, limit, n, r;

    while (1) {
        printf("\nMath Application Menu:\n");
        printf("1. Generate Prime Numbers\n");
        printf("2. Calculate Factorial\n");
        printf("3. Calculate Permutations\n");
        printf("4. Calculate Combinations\n");
        printf("5. Explore Pythagorean Triples\n");
        printf("6. Exit\n");
        printf("Choose an option (1-6): ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter the limit for prime numbers: ");
                scanf("%d", &limit);
                generate_primes(limit);
                break;
            case 2:
                printf("Enter a number to calculate its factorial: ");
                scanf("%d", &n);
                if (n < 0) {
                    printf("Factorial is not defined for negative numbers!\n");
                } else {
                    printf("Factorial of %d is %lld\n", n, factorial(n));
                }
                break;
            case 3:
                printf("Enter n (total objects): ");
                scanf("%d", &n);
                printf("Enter r (selected objects): ");
                scanf("%d", &r);
                if (r > n || r < 0) {
                    printf("Invalid selection! r must be between 0 and n.\n");
                } else {
                    printf("Permutations of %d taken %d at a time: %lld\n", n, r, permutations(n, r));
                }
                break;
            case 4:
                printf("Enter n (total objects): ");
                scanf("%d", &n);
                printf("Enter r (selected objects): ");
                scanf("%d", &r);
                if (r > n || r < 0) {
                    printf("Invalid selection! r must be between 0 and n.\n");
                } else {
                    printf("Combinations of %d taken %d at a time: %lld\n", n, r, combinations(n, r));
                }
                break;
            case 5:
                printf("Enter the limit for Pythagorean triples: ");
                scanf("%d", &limit);
                explore_pythagorean_triples(limit);
                break;
            case 6:
                printf("Exiting the program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice! Please select between 1 and 6.\n");
        }
    }
    return 0;
}