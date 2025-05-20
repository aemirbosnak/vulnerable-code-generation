//GPT-4o-mini DATASET v1.0 Category: Recursive ; Style: visionary
#include <stdio.h>

// Function to calculate Fibonacci number using recursion
int fibonacci(int n) {
    if (n <= 1) 
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// Function to print the Fibonacci series up to n terms
void printFibonacci(int n) {
    for (int i = 0; i < n; ++i) {
        printf("%d ", fibonacci(i));
    }
    printf("\n");
}

// Function to count the number of digits in a number
int countDigits(int num) {
    if (num == 0)
        return 1;
    if (num < 10)
        return 1;
    return 1 + countDigits(num / 10);
}

// Function to reverse a number
int reverseNumber(int num) {
    static int reversedNum = 0; 
    if (num == 0)
        return reversedNum;
    reversedNum = reversedNum * 10 + num % 10;
    return reverseNumber(num / 10);
}

// Wrapper function to initiate the reverse number calculation
int reverse(int num) {
    return reverseNumber(num);
}

// Function to print a pattern of stars recursively
void printStars(int n) {
    if (n <= 0) 
        return;
    printStars(n - 1);
    for (int i = 0; i < n; ++i)
        printf("* ");
    printf("\n");
}

// Function to calculate the power of a number recursively
double power(double base, int exp) {
    if (exp == 0)
        return 1;
    if (exp < 0)
        return 1 / power(base, -exp);
    return base * power(base, exp - 1);
}

// Main function to demonstrate the recursive functions
int main() {
    printf("===== Fibonacci Series =====\n");
    int terms;
    printf("Enter the number of terms for Fibonacci series: ");
    scanf("%d", &terms);
    printFibonacci(terms);

    printf("\n===== Number of Digits =====\n");
    int num;
    printf("Enter a number to count digits: ");
    scanf("%d", &num);
    printf("Number of digits in %d: %d\n", num, countDigits(num));

    printf("\n===== Reverse a Number =====\n");
    printf("Enter a number to reverse: ");
    scanf("%d", &num);
    printf("Reversed number: %d\n", reverse(num));
    
    printf("\n===== Print Star Pattern =====\n");
    int lines;
    printf("Enter the number of lines for star pattern: ");
    scanf("%d", &lines);
    printStars(lines);

    printf("\n===== Power Calculation =====\n");
    double base;
    int exponent;
    printf("Enter base: ");
    scanf("%lf", &base);
    printf("Enter exponent: ");
    scanf("%d", &exponent);
    printf("%.2f raised to the power of %d is: %.2f\n", base, exponent, power(base, exponent));

    return 0;
}