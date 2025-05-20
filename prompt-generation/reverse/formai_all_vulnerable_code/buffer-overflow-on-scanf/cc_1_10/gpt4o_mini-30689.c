//GPT-4o-mini DATASET v1.0 Category: Math exercise ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

// Function to calculate factorial
unsigned long long factorial(int n) {
    if (n < 0) {
        return 0; // Factorial for negative numbers is not defined
    }
    unsigned long long result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

// Function to check if a number is prime
int is_prime(int n) {
    if (n <= 1) return 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

// Function to generate Fibonacci series
void fibonacci_series(int n) {
    unsigned long long a = 0, b = 1, next;
    printf("Fibonacci Series up to %d terms:\n", n);
    for (int i = 0; i < n; i++) {
        printf("%llu ", a);
        next = a + b;
        a = b;
        b = next;
    }
    printf("\n");
}

// Function to display menu
void display_menu() {
    printf("-------- Math Exercise Program --------\n");
    printf("1. Calculate Factorial\n");
    printf("2. Check Prime Number\n");
    printf("3. Generate Fibonacci Series\n");
    printf("4. Exit\n");
    printf("---------------------------------------\n");
}

// Main function
int main() {
    int choice;
    int num;

    while (1) {
        display_menu();
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            // Clear the input buffer
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter a number to calculate its factorial: ");
                scanf("%d", &num);
                printf("Factorial of %d is %llu\n", num, factorial(num));
                break;
            case 2:
                printf("Enter a number to check if it is prime: ");
                scanf("%d", &num);
                if (is_prime(num)) {
                    printf("%d is a prime number.\n", num);
                } else {
                    printf("%d is not a prime number.\n", num);
                }
                break;
            case 3:
                printf("Enter the number of terms for the Fibonacci series: ");
                scanf("%d", &num);
                fibonacci_series(num);
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please select a valid option.\n");
        }
        printf("\n");
    }

    return 0;
}