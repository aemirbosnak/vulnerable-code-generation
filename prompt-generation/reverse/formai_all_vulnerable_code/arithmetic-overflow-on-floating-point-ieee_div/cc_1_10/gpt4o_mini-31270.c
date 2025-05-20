//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: active
#include <stdio.h>

void displayMenu() {
    printf("\nWelcome to the Arithmetic Operations Program!\n");
    printf("Please choose an operation:\n");
    printf("1. Addition (+)\n");
    printf("2. Subtraction (-)\n");
    printf("3. Multiplication (*)\n");
    printf("4. Division (/)\n");
    printf("5. Exit\n");
}

int main() {
    int choice;
    double num1, num2, result;

    do {
        displayMenu();
        printf("Enter your choice (1-5): ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number between 1 and 5.\n");
            while(getchar() != '\n'); // Clear the input buffer
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter two numbers to add: ");
                if (scanf("%lf %lf", &num1, &num2) == 2) {
                    result = num1 + num2;
                    printf("The result of %.2lf + %.2lf = %.2lf\n", num1, num2, result);
                } else {
                    printf("Invalid input. Please enter two numbers.\n");
                    while(getchar() != '\n'); // Clear input buffer
                }
                break;
            case 2:
                printf("Enter two numbers to subtract: ");
                if (scanf("%lf %lf", &num1, &num2) == 2) {
                    result = num1 - num2;
                    printf("The result of %.2lf - %.2lf = %.2lf\n", num1, num2, result);
                } else {
                    printf("Invalid input. Please enter two numbers.\n");
                    while(getchar() != '\n'); // Clear input buffer
                }
                break;
            case 3:
                printf("Enter two numbers to multiply: ");
                if (scanf("%lf %lf", &num1, &num2) == 2) {
                    result = num1 * num2;
                    printf("The result of %.2lf * %.2lf = %.2lf\n", num1, num2, result);
                } else {
                    printf("Invalid input. Please enter two numbers.\n");
                    while(getchar() != '\n'); // Clear input buffer
                }
                break;
            case 4:
                printf("Enter two numbers to divide: ");
                if (scanf("%lf %lf", &num1, &num2) == 2) {
                    if (num2 != 0) {
                        result = num1 / num2;
                        printf("The result of %.2lf / %.2lf = %.2lf\n", num1, num2, result);
                    } else {
                        printf("Error: Cannot divide by zero.\n");
                    }
                } else {
                    printf("Invalid input. Please enter two numbers.\n");
                    while(getchar() != '\n'); // Clear input buffer
                }
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please select a valid option (1-5).\n");
                break;
        }
    } while (choice != 5);

    return 0;
}