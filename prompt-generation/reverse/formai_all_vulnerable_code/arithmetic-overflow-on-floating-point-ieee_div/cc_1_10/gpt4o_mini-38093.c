//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: detailed
#include <stdio.h>

// Function to perform arithmetic operations
void performArithmeticOperations(float a, float b) {
    printf("Performing operations on a = %.2f and b = %.2f\n", a, b);
    
    // Addition
    float addition = a + b;
    printf("Addition (a + b): %.2f\n", addition);
    
    // Subtraction
    float subtraction = a - b;
    printf("Subtraction (a - b): %.2f\n", subtraction);
    
    // Multiplication
    float multiplication = a * b;
    printf("Multiplication (a * b): %.2f\n", multiplication);
    
    // Division with a check for division by zero
    if (b != 0) {
        float division = a / b;
        printf("Division (a / b): %.2f\n", division);
    } else {
        printf("Division by zero is not allowed!\n");
    }
    
    // Modulus (only works with integers)
    int int_a = (int)a;
    int int_b = (int)b;
    if (int_b != 0) {
        int modulus = int_a % int_b;
        printf("Modulus (a %% b): %d\n", modulus);
    } else {
        printf("Modulus by zero is not allowed!\n");
    }
    
    // Increment and Decrement
    printf("Initial value of a: %.2f\n", a);
    a++;
    printf("After Increment (a++): %.2f\n", a);
    a--;
    printf("After Decrement (a--): %.2f\n", a);
}

// Function to calculate factorial
unsigned long long factorial(int n) {
    if (n < 0) {
        printf("Factorial is not defined for negative numbers!\n");
        return 0;
    }
    
    unsigned long long result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

// Function to calculate power
float power(float base, int exp) {
    float result = 1;
    for (int i = 0; i < abs(exp); i++) {
        result *= base;
    }
    return (exp >= 0) ? result : 1 / result;
}

// Main function
int main() {
    float num1, num2;
    int n, exp;
    
    // Input from user
    printf("Enter two numbers (num1 and num2): ");
    scanf("%f %f", &num1, &num2);
    performArithmeticOperations(num1, num2);
    
    // Factorial Calculation
    printf("Enter a non-negative integer for factorial: ");
    scanf("%d", &n);
    unsigned long long fact = factorial(n);
    if (fact != 0) {
        printf("Factorial of %d is: %llu\n", n, fact);
    }
    
    // Power Calculation
    printf("Enter the base number and exponent (integer): ");
    scanf("%f %d", &num1, &exp);
    float result = power(num1, exp);
    printf("%.2f raised to the power of %d is: %.2f\n", num1, exp, result);
    
    // Housekeeping to release resources
    printf("Arithmetic operation program completed successfully!\n");
    
    return 0;
}