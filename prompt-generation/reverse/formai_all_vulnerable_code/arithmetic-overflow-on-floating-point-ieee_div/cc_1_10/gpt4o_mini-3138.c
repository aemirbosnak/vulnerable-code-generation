//GPT-4o-mini DATASET v1.0 Category: Scientific Calculator Implementation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// Function prototypes
void displayMenu();
void performOperation(int choice);
double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);
double divide(double a, double b);
double power(double base, double exp);
double squareRoot(double num);

int main() {
    int choice = 0;

    printf("Welcome to the Curious C Scientific Calculator!\n");
    printf("Let's embark on a numerical adventure...\n");

    while (choice != 6) {
        displayMenu();
        printf("Enter your choice (1-6): ");
        scanf("%d", &choice);

        if (choice >= 1 && choice <= 5) {
            performOperation(choice);
        } else if (choice == 6) {
            printf("Thank you for using the Curious C Scientific Calculator! Goodbye!\n");
        } else {
            printf("Oops! That's not a valid choice. Try again...\n");
        }
    }

    return 0;
}

// Displays the menu of operations
void displayMenu() {
    printf("\n--- Main Menu ---\n");
    printf("1. Add\n");
    printf("2. Subtract\n");
    printf("3. Multiply\n");
    printf("4. Divide\n");
    printf("5. Square Root\n");
    printf("6. Exit\n");
}

// Executes the chosen operation
void performOperation(int choice) {
    double a, b, result = 0.0;

    if (choice == 5) { // Square root operation only needs one operand
        printf("Enter a number: ");
        scanf("%lf", &a);
        result = squareRoot(a);
        printf("The square root of %.2lf is %.2lf.\n", a, result);
    } else { // Other operations need two operands
        printf("Enter first number: ");
        scanf("%lf", &a);
        printf("Enter second number: ");
        scanf("%lf", &b);

        switch (choice) {
            case 1:
                result = add(a, b);
                printf("The sum of %.2lf and %.2lf is %.2lf.\n", a, b, result);
                break;
            case 2:
                result = subtract(a, b);
                printf("The difference of %.2lf and %.2lf is %.2lf.\n", a, b, result);
                break;
            case 3:
                result = multiply(a, b);
                printf("The product of %.2lf and %.2lf is %.2lf.\n", a, b, result);
                break;
            case 4:
                if (b != 0) {
                    result = divide(a, b);
                    printf("The division of %.2lf by %.2lf is %.2lf.\n", a, b, result);
                } else {
                    printf("Error: Division by zero is not defined!\n");
                }
                break;
            default:
                printf("This shouldn't happen... getting you back to the menu!\n");
                break;
        }
    }
}

// Mathematical operations implementation
double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

double divide(double a, double b) {
    return a / b;
}

double squareRoot(double num) {
    if (num < 0) {
        printf("Error: Cannot compute square root of a negative number!\n");
        return -1; // Indicating an error
    }
    return sqrt(num);
}