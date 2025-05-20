//GPT-4o-mini DATASET v1.0 Category: Performance-Critical Component ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

// Function to find the nth Fibonacci number recursively
unsigned long long fibonacci(int n) {
    if (n <= 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

// Function to calculate the factorial of a number recursively
unsigned long long factorial(int n) {
    if (n < 0) {
        return 0; // Factorial is not defined for negative numbers
    } else if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

// Function to calculate the greatest common divisor (GCD) recursively
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

// Function to calculate the power of a number recursively
double power(double base, int exp) {
    if (exp == 0) {
        return 1.0; // Base case: any number to the power of 0 is 1
    } 
    if (exp < 0) {
        return 1.0 / power(base, -exp); // Handle negative exponent
    }
    return base * power(base, exp - 1);
}

// Helper function to print a triangle of numbers recursively
void printTriangle(int rows, int current) {
    if (current > rows) {
        return;
    }
    for (int i = 0; i < current; i++) {
        printf("* ");
    }
    printf("\n");
    printTriangle(rows, current + 1);
}

// Function to sum the digits of a number recursively
int sumDigits(int num) {
    if (num == 0) {
        return 0;
    }
    return (num % 10) + sumDigits(num / 10);
}

// Function to reverse a string recursively
void reverseString(char* str, int start, int end) {
    if (start >= end) {
        return;
    }
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;
    reverseString(str, start + 1, end - 1);
}

// Main function
int main() {
    int n, choice;

    printf("Performance-Critical Recursive Functions:\n");
    printf("1. Fibonacci\n2. Factorial\n3. GCD\n4. Power\n5. Print Triangle\n6. Sum Digits\n7. Reverse String\n");
    printf("Select an option (1-7): ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Enter a positive integer for Fibonacci: ");
            scanf("%d", &n);
            printf("Fibonacci(%d) = %llu\n", n, fibonacci(n));
            break;

        case 2:
            printf("Enter a non-negative integer for Factorial: ");
            scanf("%d", &n);
            printf("Factorial(%d) = %llu\n", n, factorial(n));
            break;

        case 3:
            printf("Enter two integers for GCD: ");
            int a, b;
            scanf("%d %d", &a, &b);
            printf("GCD(%d, %d) = %d\n", a, b, gcd(a, b));
            break;

        case 4:
            printf("Enter base and exponent for Power: ");
            double base;
            int exp;
            scanf("%lf %d", &base, &exp);
            printf("%lf raised to power %d = %lf\n", base, exp, power(base, exp));
            break;

        case 5:
            printf("Enter number of rows for triangle: ");
            scanf("%d", &n);
            printTriangle(n, 1);
            break;

        case 6:
            printf("Enter an integer to sum its digits: ");
            scanf("%d", &n);
            printf("Sum of digits of %d = %d\n", n, sumDigits(n));
            break;

        case 7:
            printf("Enter a string to reverse: ");
            char str[100];
            scanf("%s", str);
            int len = 0;
            while (str[len] != '\0') len++; // Calculate length 
            reverseString(str, 0, len - 1);
            printf("Reversed string: %s\n", str);
            break;

        default:
            printf("Invalid choice, please select a number between 1 and 7.\n");
            break;
    }

    return 0;
}