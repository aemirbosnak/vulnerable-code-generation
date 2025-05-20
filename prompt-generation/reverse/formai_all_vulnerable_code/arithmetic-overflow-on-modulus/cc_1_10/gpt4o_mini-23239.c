//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: optimized
#include <stdio.h>

// Function prototypes
int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
float divide(int a, int b);
int modulo(int a, int b);
int gcd(int a, int b);
int lcm(int a, int b);
void displayResults(int a, int b);

int main() {
    int a, b;
    // User input
    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);

    // Display computed results
    displayResults(a, b);

    return 0;
}

// Function to add two numbers
int add(int a, int b) {
    return a + b;
}

// Function to subtract two numbers
int subtract(int a, int b) {
    return a - b;
}

// Function to multiply two numbers
int multiply(int a, int b) {
    return a * b;
}

// Function to divide two numbers
float divide(int a, int b) {
    if (b != 0)
        return (float)a / b;
    else {
        printf("Error: Division by zero.\n");
        return 0; // Return 0 for undefined division
    }
}

// Function to find modular of two numbers
int modulo(int a, int b) {
    if (b != 0)
        return a % b;
    else {
        printf("Error: Modulo by zero.\n");
        return 0; // Return 0 for undefined modulo
    }
}

// Function to find the GCD of two numbers using Euclid's algorithm
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to find the LCM of two numbers
int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

// Function to display results of arithmetic operations
void displayResults(int a, int b) {
    printf("Arithmetic Results:\n");
    printf("Addition: %d + %d = %d\n", a, b, add(a, b));
    printf("Subtraction: %d - %d = %d\n", a, b, subtract(a, b));
    printf("Multiplication: %d * %d = %d\n", a, b, multiply(a, b));
    printf("Division: %d / %d = %.2f\n", a, b, divide(a, b));
    printf("Modulo: %d %% %d = %d\n", a, b, modulo(a, b));
    printf("GCD: gcd(%d, %d) = %d\n", a, b, gcd(a, b));
    printf("LCM: lcm(%d, %d) = %d\n", a, b, lcm(a, b));
}

// Enhanced functionality of processing multiple pairs of numbers
void processMultiplePairs() {
    int n;
    printf("How many pairs of integers do you want to process? ");
    scanf("%d", &n);

    int pair[n][2]; // Array to store pairs of integers
    for (int i = 0; i < n; i++) {
        printf("Enter pair %d: ", i + 1);
        scanf("%d %d", &pair[i][0], &pair[i][1]);
    }

    printf("\nResults for multiple pairs:\n");
    for (int i = 0; i < n; i++) {
        printf("\nFor pair %d (%d, %d):\n", i + 1, pair[i][0], pair[i][1]);
        displayResults(pair[i][0], pair[i][1]);
    }
}