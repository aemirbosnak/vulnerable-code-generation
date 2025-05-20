//GPT-4o-mini DATASET v1.0 Category: Recursive ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

// Function to compute the Fibonacci sequence
int fibonacci(int n) {
    if (n <= 0) return 0;         // Base case: fib(0) = 0
    else if (n == 1) return 1;    // Base case: fib(1) = 1
    else return fibonacci(n - 1) + fibonacci(n - 2); // Recursive case
}

// Function to print Fibonacci sequence
void printFibonacci(int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", fibonacci(i));
    }
    printf("\n");
}

// Function to calculate factorial
int factorial(int n) {
    if (n < 0) return -1; // Error case, negative numbers have no factorial
    if (n == 0) return 1; // Base case: factorial(0) = 1
    return n * factorial(n - 1); // Recursive case
}

// Function to print factorials
void printFactorials(int n) {
    for (int i = 0; i <= n; i++) {
        int result = factorial(i);
        if (result == -1) {
            printf("Factorial of negative number is undefined\n");
            continue;
        }
        printf("%d! = %d\n", i, result);
    }
}

// Function to calculate sum of digits
int sumOfDigits(int n) {
    if (n == 0) return 0; // Base case
    return (n % 10) + sumOfDigits(n / 10); // Recursive case
}

// Function to sum the digits of numbers
void printSumOfDigits(int n) {
    printf("Sum of digits of %d is %d\n", n, sumOfDigits(n));
}

// Function to reverse a string
void reverseString(char str[], int start, int end) {
    if (start >= end) return; // Base case
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;

    // Calling the function recursively with the next pair
    reverseString(str, start + 1, end - 1);
}

// Function to read string and reverse it
void readAndReverseString() {
    char str[100];
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    
    // Remove newline character if present
    size_t len = strlen(str);
    if(len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }

    reverseString(str, 0, strlen(str) - 1);
    printf("Reversed string: %s\n", str);
}

// Function to calculate power of a number
double power(double base, int exp) {
    if (exp < 0) return 1.0 / power(base, -exp); // Handle negative exponent
    if (exp == 0) return 1; // Base case: any number to the power of 0 is 1
    return base * power(base, exp - 1); // Recursive case
}

// Function to read base and exponent for power calculation
void readAndCalculatePower() {
    double base;
    int exp;
    printf("Enter base: ");
    scanf("%lf", &base);
    printf("Enter exponent: ");
    scanf("%d", &exp);
    
    double result = power(base, exp);
    printf("%.2lf raised to the power of %d is %.2lf\n", base, exp, result);
}

// Main function
int main() {
    int choice = 0;
    while (1) {
        printf("\nRecursive Functions Menu:\n");
        printf("1. Print Fibonacci Sequence\n");
        printf("2. Print Factorials\n");
        printf("3. Sum of Digits\n");
        printf("4. Reverse a String\n");
        printf("5. Calculate Power of a Number\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: {
                int n;
                printf("Enter the number of Fibonacci terms: ");
                scanf("%d", &n);
                printFibonacci(n);
                break;
            }
            case 2: {
                int n;
                printf("Enter a number to calculate factorials up to: ");
                scanf("%d", &n);
                printFactorials(n);
                break;
            }
            case 3: {
                int number;
                printf("Enter a number to sum its digits: ");
                scanf("%d", &number);
                printSumOfDigits(number);
                break;
            }
            case 4:
                readAndReverseString();
                break;
            case 5:
                readAndCalculatePower();
                break;
            case 0:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}