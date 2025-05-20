//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: portable
#include <stdio.h>

void displayMenu() {
    printf("Simple Arithmetic Calculator\n");
    printf("Choose an operation:\n");
    printf("1. Addition (+)\n");
    printf("2. Subtraction (-)\n");
    printf("3. Multiplication (*)\n");
    printf("4. Division (/)\n");
    printf("5. Exit\n");
}

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
    if (b == 0) {
        printf("Error: Division by zero is not allowed!\n");
        return 0; // Return 0 for error case
    }
    return a / b;
}

int main() {
    int choice;
    double num1, num2, result;

    while (1) {
        displayMenu();
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        if (choice == 5) {
            printf("Exiting the calculator. Goodbye!\n");
            break; // Exit the loop and terminate the program
        }

        if (choice < 1 || choice > 5) {
            printf("Invalid choice! Please choose again.\n");
            continue; // Goes back to start of the loop
        }

        printf("Enter first number: ");
        scanf("%lf", &num1);
        printf("Enter second number: ");
        scanf("%lf", &num2);

        switch (choice) {
            case 1:
                result = add(num1, num2);
                printf("Result: %.2lf + %.2lf = %.2lf\n", num1, num2, result);
                break;
            case 2:
                result = subtract(num1, num2);
                printf("Result: %.2lf - %.2lf = %.2lf\n", num1, num2, result);
                break;
            case 3:
                result = multiply(num1, num2);
                printf("Result: %.2lf * %.2lf = %.2lf\n", num1, num2, result);
                break;
            case 4:
                result = divide(num1, num2);
                if (num2 != 0) { // Only display result if no division by zero
                    printf("Result: %.2lf / %.2lf = %.2lf\n", num1, num2, result);
                }
                break;
            default:
                printf("Unexpected error!\n");
                break;
        }
        printf("\n"); // Print new line for better readability
    }
    
    return 0; // End of program
}