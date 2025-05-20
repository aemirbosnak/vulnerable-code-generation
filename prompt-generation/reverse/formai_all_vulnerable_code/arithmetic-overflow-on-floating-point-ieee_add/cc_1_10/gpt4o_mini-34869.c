//GPT-4o-mini DATASET v1.0 Category: Error handling ; Style: lively
#include <stdio.h>
#include <stdlib.h>

// Function Declarations
void performAddition();
void performSubtraction();
void performMultiplication();
void performDivision();
void displayMenu();
void handleError(const char *message);

// Main function
int main() {
    int choice;
    printf("Welcome to RoboCalc - Your Friendly Math Robot! 🤖\n");
    
    while (1) {
        displayMenu();
        printf("What operation would you like to perform? (1-5 or 0 to exit): ");
        if (scanf("%d", &choice) != 1) {
            handleError("Invalid input! Please enter a number.");
            while(getchar() != '\n'); // Clear invalid input
            continue;
        }
        
        switch (choice) {
            case 0:
                printf("Goodbye! RoboCalc signs off. ✌️\n");
                exit(0);
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
                printf("Thanks for using RoboCalc! Have a great day! ☀️\n");
                break;
            default:
                handleError("Invalid choice! Please choose a valid operation.");
                break;
        }
    }
    return 0;
}

void displayMenu() {
    printf("\n--- RoboCalc Operations Menu ---\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Exit\n");
    printf("--------------------------------\n");
}

void handleError(const char *message) {
    fprintf(stderr, "Error: %s\n", message);
}

void performAddition() {
    double a, b;
    printf("Let's add some numbers! 🤗\n");
    printf("Enter the first number: ");
    if (scanf("%lf", &a) != 1) {
        handleError("Invalid input for the first number.");
        while(getchar() != '\n'); // Clear invalid input
        return;
    }
    printf("Enter the second number: ");
    if (scanf("%lf", &b) != 1) {
        handleError("Invalid input for the second number.");
        while(getchar() != '\n'); // Clear invalid input
        return;
    }
    printf("🎉 Result: %.2lf + %.2lf = %.2lf\n", a, b, a + b);
}

void performSubtraction() {
    double a, b;
    printf("Let's subtract some numbers! 🎈\n");
    printf("Enter the first number: ");
    if (scanf("%lf", &a) != 1) {
        handleError("Invalid input for the first number.");
        while(getchar() != '\n'); // Clear invalid input
        return;
    }
    printf("Enter the second number: ");
    if (scanf("%lf", &b) != 1) {
        handleError("Invalid input for the second number.");
        while(getchar() != '\n'); // Clear invalid input
        return;
    }
    printf("🎉 Result: %.2lf - %.2lf = %.2lf\n", a, b, a - b);
}

void performMultiplication() {
    double a, b;
    printf("Let's multiply some numbers! 💪\n");
    printf("Enter the first number: ");
    if (scanf("%lf", &a) != 1) {
        handleError("Invalid input for the first number.");
        while(getchar() != '\n'); // Clear invalid input
        return;
    }
    printf("Enter the second number: ");
    if (scanf("%lf", &b) != 1) {
        handleError("Invalid input for the second number.");
        while(getchar() != '\n'); // Clear invalid input
        return;
    }
    printf("🎉 Result: %.2lf * %.2lf = %.2lf\n", a, b, a * b);
}

void performDivision() {
    double a, b;
    printf("Let's divide some numbers! ⚖️\n");
    printf("Enter the numerator: ");
    if (scanf("%lf", &a) != 1) {
        handleError("Invalid input for the numerator.");
        while(getchar() != '\n'); // Clear invalid input
        return;
    }
    printf("Enter the denominator: ");
    if (scanf("%lf", &b) != 1) {
        handleError("Invalid input for the denominator.");
        while(getchar() != '\n'); // Clear invalid input
        return;
    }
    if (b == 0) {
        handleError("Cannot divide by zero! Please try again.");
    } else {
        printf("🎉 Result: %.2lf / %.2lf = %.2lf\n", a, b, a / b);
    }
}