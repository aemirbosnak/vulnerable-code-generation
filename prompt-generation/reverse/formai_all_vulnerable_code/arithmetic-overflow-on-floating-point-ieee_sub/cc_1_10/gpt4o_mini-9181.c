//GPT-4o-mini DATASET v1.0 Category: Game ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function prototypes
void displayMenu();
void performOperation(int choice);
void add();
void subtract();
void multiply();
void divide();
void sine();
void cosine();
void squareRoot();

int main() {
    int choice;

    do {
        displayMenu();
        printf("Enter your choice (1-7, or 0 to exit): ");
        scanf("%d", &choice);
        
        if (choice < 0 || choice > 7) {
            printf("Invalid choice. Please try again.\n");
        } else if (choice != 0) {
            performOperation(choice);
        }

    } while (choice != 0);

    printf("Exiting the calculator. Thank you!\n");
    return 0;
}

void displayMenu() {
    printf("Scientific Calculator\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Sine\n");
    printf("6. Cosine\n");
    printf("7. Square Root\n");
}

void performOperation(int choice) {
    switch (choice) {
        case 1:
            add();
            break;
        case 2:
            subtract();
            break;
        case 3:
            multiply();
            break;
        case 4:
            divide();
            break;
        case 5:
            sine();
            break;
        case 6:
            cosine();
            break;
        case 7:
            squareRoot();
            break;
        default:
            printf("Something went wrong. Please try again.\n");
            break;
    }
}

void add() {
    double a, b;
    printf("Enter two numbers to add: ");
    scanf("%lf %lf", &a, &b);
    printf("Result: %.2lf\n", a + b);
}

void subtract() {
    double a, b;
    printf("Enter two numbers to subtract: ");
    scanf("%lf %lf", &a, &b);
    printf("Result: %.2lf\n", a - b);
}

void multiply() {
    double a, b;
    printf("Enter two numbers to multiply: ");
    scanf("%lf %lf", &a, &b);
    printf("Result: %.2lf\n", a * b);
}

void divide() {
    double a, b;
    printf("Enter two numbers to divide (numerator and denominator): ");
    scanf("%lf %lf", &a, &b);
    if (b != 0) {
        printf("Result: %.2lf\n", a / b);
    } else {
        printf("Error: Division by zero is not allowed.\n");
    }
}

void sine() {
    double angle;
    printf("Enter an angle in degrees: ");
    scanf("%lf", &angle);
    // Convert degrees to radians
    angle = angle * (M_PI / 180.0);
    printf("Sine of the angle: %.2lf\n", sin(angle));
}

void cosine() {
    double angle;
    printf("Enter an angle in degrees: ");
    scanf("%lf", &angle);
    // Convert degrees to radians
    angle = angle * (M_PI / 180.0);
    printf("Cosine of the angle: %.2lf\n", cos(angle));
}

void squareRoot() {
    double number;
    printf("Enter a number to find the square root: ");
    scanf("%lf", &number);
    if (number >= 0) {
        printf("Square root: %.2lf\n", sqrt(number));
    } else {
        printf("Error: Cannot compute the square root of a negative number.\n");
    }
}