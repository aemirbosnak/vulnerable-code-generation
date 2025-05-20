//GPT-4o-mini DATASET v1.0 Category: Math exercise ; Style: curious
#include <stdio.h>

// Function declaration
void calculateFibonacci(int n);
int isPrime(int num);
int gcd(int a, int b);

int main() {
    int choice, num, i, n;

    printf("Welcome to the Curious Math Adventure!\n");
    printf("Choose an operation:\n");
    printf("1. Calculate Fibonacci Sequence\n");
    printf("2. Check Prime Number\n");
    printf("3. Find GCD of two numbers\n");
    printf("Enter your choice (1-3): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter the number of Fibonacci terms to calculate: ");
            scanf("%d", &n);
            printf("Fibonacci Sequence of %d terms:\n", n);
            calculateFibonacci(n);
            break;

        case 2:
            printf("Enter a number to check if it is prime: ");
            scanf("%d", &num);
            if (isPrime(num)) {
                printf("%d is a prime number!\n", num);
            } else {
                printf("%d is not a prime number!\n", num);
            }
            break;

        case 3:
            printf("Enter the first number: ");
            scanf("%d", &num);
            printf("Enter the second number: ");
            scanf("%d", &n);
            printf("The GCD of %d and %d is: %d\n", num, n, gcd(num, n));
            break;

        default:
            printf("Invalid choice! Please run the program again.\n");
            break;
    }

    return 0;
}

// Function to calculate the Fibonacci sequence
void calculateFibonacci(int n) {
    int first = 0, second = 1, next, i;

    if (n <= 0) {
        printf("Please enter a positive integer.\n");
        return;
    }

    for (i = 0; i < n; i++) {
        if (i <= 1) {
            next = i; // The first two terms are 0 and 1
        } else {
            next = first + second; // Next term is the sum of the previous two
            first = second;        // Update values for next iteration
            second = next;
        }
        printf("%d ", next); // Print each term
    }
    printf("\n"); // Newline at the end
}

// Function to check if a number is prime
int isPrime(int num) {
    if (num <= 1) {
        return 0; // 0 and 1 are not prime numbers
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return 0; // Not a prime number if divisible by any number up to its square root
        }
    }
    return 1; // Is a prime number
}

// Function to find GCD using the Euclidean algorithm
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b; // Remainder
        a = temp;  // Update a to the previous value of b
    }
    return a; // GCD found
}