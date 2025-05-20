//GPT-4o-mini DATASET v1.0 Category: Math exercise ; Style: protected
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void print_menu();
void calculate_factorial();
void check_prime();
void generate_fibonacci();
int factorial(int n);
int is_prime(int n);
void fibonacci_series(int n);

int main() {
    int choice;

    while (1) {
        print_menu();
        printf("Enter your choice (1-4, or 0 to exit): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                calculate_factorial();
                break;
            case 2:
                check_prime();
                break;
            case 3:
                generate_fibonacci();
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
        printf("\n");
    }
    return 0;
}

void print_menu() {
    printf("Welcome to the Math Exercise Program!\n");
    printf("1. Calculate Factorial\n");
    printf("2. Check Prime Number\n");
    printf("3. Generate Fibonacci Series\n");
    printf("4. Exit\n");
}

void calculate_factorial() {
    int num;
    printf("Enter a non-negative integer to calculate its factorial: ");
    scanf("%d", &num);
    
    if (num < 0) {
        printf("Factorial is not defined for negative numbers.\n");
    } else {
        printf("Factorial of %d is %d.\n", num, factorial(num));
    }
}

int factorial(int n) {
    if (n == 0) return 1; // Base case
    return n * factorial(n - 1); // Recursive case
}

void check_prime() {
    int num;
    printf("Enter a positive integer to check if it is prime: ");
    scanf("%d", &num);
    
    if (num < 2) {
        printf("%d is not a prime number.\n", num);
    } else {
        if (is_prime(num)) {
            printf("%d is a prime number.\n", num);
        } else {
            printf("%d is not a prime number.\n", num);
        }
    }
}

int is_prime(int n) {
    for (int i = 2; i <= n / 2; i++) {
        if (n % i == 0) {
            return 0; // Not a prime
        }
    }
    return 1; // Is a prime
}

void generate_fibonacci() {
    int terms;
    printf("Enter the number of terms for the Fibonacci series: ");
    scanf("%d", &terms);
    
    if (terms <= 0) {
        printf("Please enter a positive integer.\n");
    } else {
        printf("Fibonacci series up to %d terms:\n", terms);
        fibonacci_series(terms);
    }
}

void fibonacci_series(int n) {
    int t1 = 0, t2 = 1, nextTerm;

    for (int i = 1; i <= n; ++i) {
        if (i == 1) {
            printf("%d, ", t1);
            continue;
        }
        if (i == 2) {
            printf("%d, ", t2);
            continue;
        }
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
        printf("%d, ", nextTerm);
    }
    printf("\n");
}