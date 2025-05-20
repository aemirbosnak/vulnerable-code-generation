//GPT-4o-mini DATASET v1.0 Category: Math exercise ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function Prototypes
void displayMenu();
int getChoice();
void calculateFactorial();
void calculateFibonacci();
void calculatePower();
void calculateSquareRoot();
void calculateGCD();

int main() {
    int choice;

    do {
        displayMenu();
        choice = getChoice();

        switch (choice) {
            case 1:
                calculateFactorial();
                break;
            case 2:
                calculateFibonacci();
                break;
            case 3:
                calculatePower();
                break;
            case 4:
                calculateSquareRoot();
                break;
            case 5:
                calculateGCD();
                break;
            case 0:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

        printf("\n");
    } while (choice != 0);

    return 0;
}

// Function to display the available options
void displayMenu() {
    printf("===== Math Exercise Menu =====\n");
    printf("1. Calculate Factorial\n");
    printf("2. Calculate Fibonacci Series\n");
    printf("3. Calculate Power\n");
    printf("4. Calculate Square Root\n");
    printf("5. Calculate GCD\n");
    printf("0. Exit\n");
    printf("==============================\n");
}

// Function to get user's choice
int getChoice() {
    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

// Function to calculate factorial
void calculateFactorial() {
    int n;
    unsigned long long factorial = 1;

    printf("Enter a positive integer: ");
    scanf("%d", &n);
    
    if (n < 0) {
        printf("Factorial is not defined for negative numbers.\n");
        return;
    }

    for (int i = 1; i <= n; ++i) {
        factorial *= i;
    }

    printf("Factorial of %d = %llu\n", n, factorial);
}

// Function to calculate Fibonacci series
void calculateFibonacci() {
    int n;
    int t1 = 0, t2 = 1, nextTerm = 0;

    printf("Enter the number of terms in the Fibonacci series: ");
    scanf("%d", &n);
    
    printf("Fibonacci Series: ");

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

// Function to calculate power
void calculatePower() {
    double base;
    int exponent;
    double result = 1;

    printf("Enter base and exponent: ");
    scanf("%lf %d", &base, &exponent);
    
    for (int i = 0; i < abs(exponent); i++) {
        result *= base;
    }
    
    if (exponent < 0) {
        result = 1 / result;
    }

    printf("%lf to the power of %d = %lf\n", base, exponent, result);
}

// Function to calculate square root
void calculateSquareRoot() {
    double number;
    
    printf("Enter a number to find its square root: ");
    scanf("%lf", &number);
    
    if (number < 0) {
        printf("Square root is not defined for negative numbers.\n");
        return;
    }

    double result = sqrt(number);
    printf("Square root of %lf = %lf\n", number, result);
}

// Function to calculate the GCD using Euclidean algorithm
void calculateGCD() {
    int a, b;
    
    printf("Enter two integers to find their GCD: ");
    scanf("%d %d", &a, &b);
    
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }

    printf("GCD = %d\n", a);
}