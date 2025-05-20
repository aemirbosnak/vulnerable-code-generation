//FormAI DATASET v1.0 Category: Recursive ; Style: complex
#include <stdio.h>

// Recursive function to calculate factorial of a number
int factorial(int num) {
    // Base case
    if (num == 0) {
        return 1;
    }
    // Recursive case
    else {
        return num * factorial(num - 1);
    }
}

// Recursive function to calculate nth Fibonacci number
int fibonacci(int num) {
    // Base case
    if (num == 0 || num == 1) {
        return num;
    }
    // Recursive case
    else {
        return fibonacci(num - 1) + fibonacci(num - 2);
    }
}

// Recursive function to calculate nth prime number
int prime(int num) {
    // Counter to check number of primes
    static int count = 0;
    
    // Check for prime number
    int isPrime = 1;
    for (int i = 2; i <= num / 2; i++) {
        if (num % i == 0) {
            isPrime = 0;
            break;
        }
    }
    
    // Recursive case for prime number
    if (isPrime == 1) {
        count++;
        if (count == num) {
            return num;
        }
        else {
            return prime(num + 1);
        }
    }
    // Recursive case for non-prime number
    else {
        return prime(num + 1);
    }
}

int main() {
    int choice;
    printf("Enter your choice:\n1 - Factorial\n2 - Fibonacci\n3 - Prime\n");
    scanf("%d", &choice);
    
    switch (choice) {
        case 1: {
            int num, fact;
            printf("Enter a number: ");
            scanf("%d", &num);
            fact = factorial(num);
            printf("Factorial of %d is %d\n", num, fact);
            break;
        }
        case 2: {
            int num, fib;
            printf("Enter a number: ");
            scanf("%d", &num);
            fib = fibonacci(num);
            printf("%dth Fibonacci number is %d\n", num, fib);
            break;
        }
        case 3: {
            int num, p;
            printf("Enter a number: ");
            scanf("%d", &num);
            p = prime(num);
            printf("%dth prime number is %d\n", num, p);
            break;
        }
        default: {
            printf("Invalid choice\n");
        }
    }
    
    return 0;
}