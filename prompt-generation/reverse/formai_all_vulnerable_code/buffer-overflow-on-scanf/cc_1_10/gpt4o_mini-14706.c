//GPT-4o-mini DATASET v1.0 Category: Math exercise ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void showWelcomeMessage() {
    printf("***************************************\n");
    printf("*    Welcome to the Math Adventure!   *\n");
    printf("***************************************\n\n");
}

void showMenu() {
    printf("Choose a mathematical operation:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Square\n");
    printf("6. Square Root\n");
    printf("7. Exit\n");
    printf("Please enter your choice (1-7): ");
}

void performAddition() {
    float a, b;
    printf("Enter two numbers to add:\n");
    scanf("%f %f", &a, &b);
    printf("Result: %.2f + %.2f = %.2f\n\n", a, b, a + b);
}

void performSubtraction() {
    float a, b;
    printf("Enter two numbers to subtract:\n");
    scanf("%f %f", &a, &b);
    printf("Result: %.2f - %.2f = %.2f\n\n", a, b, a - b);
}

void performMultiplication() {
    float a, b;
    printf("Enter two numbers to multiply:\n");
    scanf("%f %f", &a, &b);
    printf("Result: %.2f * %.2f = %.2f\n\n", a, b, a * b);
}

void performDivision() {
    float a, b;
    printf("Enter two numbers to divide (numerator and denominator):\n");
    scanf("%f %f", &a, &b);
    if (b == 0) {
        printf("Error: Cannot divide by zero!\n\n");
    } else {
        printf("Result: %.2f / %.2f = %.2f\n\n", a, b, a / b);
    }
}

void performSquare() {
    float a;
    printf("Enter a number to find its square:\n");
    scanf("%f", &a);
    printf("Result: %.2f^2 = %.2f\n\n", a, a * a);
}

void performSquareRoot() {
    float a;
    printf("Enter a number to find its square root:\n");
    scanf("%f", &a);
    if (a < 0) {
        printf("Error: Cannot compute the square root of a negative number!\n\n");
    } else {
        printf("Result: sqrt(%.2f) = %.2f\n\n", a, sqrt(a));
    }
}

int main() {
    int choice;
    showWelcomeMessage();
    
    while (1) {
        showMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                performAddition();
                break;
            case 2:
                performSubtraction();
                break;
            case 3:
                performMultiplication();
                break;
            case 4:
                performDivision();
                break;
            case 5:
                performSquare();
                break;
            case 6:
                performSquareRoot();
                break;
            case 7:
                printf("Thank you for participating in the Math Adventure!\n");
                exit(0);
            default:
                printf("Invalid choice! Please select a number between 1 and 7.\n\n");
        }
    }
    
    return 0;
}