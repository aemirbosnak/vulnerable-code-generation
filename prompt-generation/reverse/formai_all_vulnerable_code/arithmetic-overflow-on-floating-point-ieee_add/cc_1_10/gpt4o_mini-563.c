//GPT-4o-mini DATASET v1.0 Category: Math exercise ; Style: modular
#include <stdio.h>

// Function prototypes
void printMenu();
void add();
void subtract();
void multiply();
void divide();
void factorial();
void power();
void getInput(double *num1, double *num2);
int getIntegerInput();
long long factorialCalc(int num);
double powerCalc(double base, int exponent);

int main() {
    int choice;

    do {
        printMenu();
        choice = getIntegerInput();

        switch (choice) {
            case 1: add(); break;
            case 2: subtract(); break;
            case 3: multiply(); break;
            case 4: divide(); break;
            case 5: factorial(); break;
            case 6: power(); break;
            case 7: printf("Exiting...\n"); break;
            default: printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 7);

    return 0;
}

// Function to print the menu
void printMenu() {
    printf("\n====== Simple Modular Calculator ======\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Factorial\n");
    printf("6. Power\n");
    printf("7. Exit\n");
    printf("Please enter your choice: ");
}

// Function to add two numbers
void add() {
    double num1, num2;
    getInput(&num1, &num2);
    printf("Result: %.2f\n", num1 + num2);
}

// Function to subtract two numbers
void subtract() {
    double num1, num2;
    getInput(&num1, &num2);
    printf("Result: %.2f\n", num1 - num2);
}

// Function to multiply two numbers
void multiply() {
    double num1, num2;
    getInput(&num1, &num2);
    printf("Result: %.2f\n", num1 * num2);
}

// Function to divide two numbers
void divide() {
    double num1, num2;
    getInput(&num1, &num2);
    
    if (num2 != 0) {
        printf("Result: %.2f\n", num1 / num2);
    } else {
        printf("Error: Division by zero is not allowed.\n");
    }
}

// Function to calculate factorial
void factorial() {
    int num;
    printf("Enter a non-negative integer for factorial: ");
    num = getIntegerInput();
    
    if (num < 0) {
        printf("Error: Factorial is not defined for negative numbers.\n");
    } else {
        printf("Factorial of %d is %lld\n", num, factorialCalc(num));
    }
}

// Function to calculate power
void power() {
    double base;
    int exponent;

    printf("Enter base: ");
    scanf("%lf", &base);
    printf("Enter exponent: ");
    exponent = getIntegerInput();

    printf("Result: %.2f\n", powerCalc(base, exponent));
}

// Function to get two double inputs from the user
void getInput(double *num1, double *num2) {
    printf("Enter first number: ");
    scanf("%lf", num1);
    printf("Enter second number: ");
    scanf("%lf", num2);
}

// Function to get integer input
int getIntegerInput() {
    int input;
    scanf("%d", &input);
    return input;
}

// Function to calculate factorial
long long factorialCalc(int num) {
    if (num == 0 || num == 1) {
        return 1;
    }
    return num * factorialCalc(num - 1);
}

// Function to calculate power
double powerCalc(double base, int exponent) {
    if (exponent == 0) {
        return 1;
    }
    return base * powerCalc(base, exponent - 1);
}