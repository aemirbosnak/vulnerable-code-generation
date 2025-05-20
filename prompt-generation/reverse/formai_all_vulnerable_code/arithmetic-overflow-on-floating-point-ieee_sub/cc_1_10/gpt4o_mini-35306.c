//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

void displayMenu() {
    printf("\n==================== Calculator ====================\n");
    printf("1. Addition (+)\n");
    printf("2. Subtraction (-)\n");
    printf("3. Multiplication (*)\n");
    printf("4. Division (/)\n");
    printf("5. Exit\n");
    printf("=====================================================\n");
    printf("Enter your choice (1-5): ");
}

void performOperation(int choice) {
    float num1, num2, result;

    printf("Enter first number: ");
    if (scanf("%f", &num1) != 1) {
        printf("Invalid input. Please enter a valid number.\n");
        exit(1);
    }
    
    printf("Enter second number: ");
    if (scanf("%f", &num2) != 1) {
        printf("Invalid input. Please enter a valid number.\n");
        exit(1);
    }

    switch (choice) {
        case 1:
            result = num1 + num2;
            printf("Result of %.2f + %.2f = %.2f\n", num1, num2, result);
            break;
        case 2:
            result = num1 - num2;
            printf("Result of %.2f - %.2f = %.2f\n", num1, num2, result);
            break;
        case 3:
            result = num1 * num2;
            printf("Result of %.2f * %.2f = %.2f\n", num1, num2, result);
            break;
        case 4:
            if (num2 != 0) {
                result = num1 / num2;
                printf("Result of %.2f / %.2f = %.2f\n", num1, num2, result);
            } else {
                printf("Error: Division by zero is not allowed.\n");
            }
            break;
        default:
            printf("Invalid choice. Please select a valid operation.\n");
            break;
    }
}

int main() {
    int choice;

    printf("Welcome to the Simple Calculator!\n");
    while (1) {
        displayMenu();
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number between 1 and 5.\n");
            exit(1);
        }

        if (choice == 5) {
            printf("Exiting the calculator. Goodbye!\n");
            break;
        }
        
        if (choice < 1 || choice > 5) {
            printf("Please select a number between 1 and 5.\n");
            continue;
        }

        performOperation(choice);
    }

    return 0;
}