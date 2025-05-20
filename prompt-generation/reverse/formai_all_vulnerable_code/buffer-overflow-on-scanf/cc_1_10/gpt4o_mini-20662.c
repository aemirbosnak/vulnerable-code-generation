//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: Dennis Ritchie
#include <stdio.h>

#define MAX_SIZE 100

// Function declarations
void displayMenu();
void performArithmetic(int choice);
void addNumbers();
void subtractNumbers();
void multiplyNumbers();
void divideNumbers();
void findModulus();
void exponentiation();
void inputNumbers(double *a, double *b);

int main() {
    int userChoice;

    printf("Welcome to the C Arithmetic Program!\n");
    printf("This program performs various arithmetic operations.\n");

    do {
        displayMenu();
        printf("Enter your choice (1-7) or 0 to exit: ");
        scanf("%d", &userChoice);
        
        if (userChoice < 0 || userChoice > 7) {
            printf("Invalid choice! Please try again.\n");
        } else if (userChoice != 0) {
            performArithmetic(userChoice);
        }

    } while (userChoice != 0);

    printf("Thank you for using the arithmetic program. Goodbye!\n");
    return 0;
}

void displayMenu() {
    printf("\nArithmetic Operations Menu:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Modulus\n");
    printf("6. Exponentiation\n");
    printf("7. Square Root\n");
    printf("0. Exit\n");
}

void performArithmetic(int choice) {
    switch(choice) {
        case 1:
            addNumbers();
            break;
        case 2:
            subtractNumbers();
            break;
        case 3:
            multiplyNumbers();
            break;
        case 4:
            divideNumbers();
            break;
        case 5:
            findModulus();
            break;
        case 6:
            exponentiation();
            break;
        case 7:
            printf("Feature not implemented yet. Stay tuned!\n");
            break;
        default:
            printf("Unknown operation\n");
    }
}

void inputNumbers(double *a, double *b) {
    printf("Enter the first number: ");
    scanf("%lf", a);
    printf("Enter the second number: ");
    scanf("%lf", b);
}

void addNumbers() {
    double num1, num2, result;
    inputNumbers(&num1, &num2);
    result = num1 + num2;
    printf("The sum of %.2f and %.2f is %.2f\n", num1, num2, result);
}

void subtractNumbers() {
    double num1, num2, result;
    inputNumbers(&num1, &num2);
    result = num1 - num2;
    printf("The difference between %.2f and %.2f is %.2f\n", num1, num2, result);
}

void multiplyNumbers() {
    double num1, num2, result;
    inputNumbers(&num1, &num2);
    result = num1 * num2;
    printf("The product of %.2f and %.2f is %.2f\n", num1, num2, result);
}

void divideNumbers() {
    double num1, num2, result;
    inputNumbers(&num1, &num2);
    if (num2 == 0) {
        printf("Error: Division by zero is undefined.\n");
    } else {
        result = num1 / num2;
        printf("The quotient of %.2f divided by %.2f is %.2f\n", num1, num2, result);
    }
}

void findModulus() {
    int num1, num2, result;
    printf("Modulus operation requires integers.\n");
    printf("Enter the first integer: ");
    scanf("%d", &num1);
    printf("Enter the second integer: ");
    scanf("%d", &num2);
    if (num2 == 0) {
        printf("Error: Modulus by zero is undefined.\n");
    } else {
        result = num1 % num2;
        printf("The modulus of %d and %d is %d\n", num1, num2, result);
    }
}

void exponentiation() {
    double base, exponent, result = 1.0;
    printf("Enter the base: ");
    scanf("%lf", &base);
    printf("Enter the exponent: ");
    scanf("%lf", &exponent);
    for (int i = 0; i < exponent; i++) {
        result *= base;
    }
    printf("%.2f raised to the power of %.2f is %.2f\n", base, exponent, result);
}