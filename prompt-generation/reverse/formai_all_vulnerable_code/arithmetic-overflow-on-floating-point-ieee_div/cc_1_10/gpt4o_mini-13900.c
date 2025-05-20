//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: genius
#include <stdio.h>
#include <stdlib.h>

void displayMenu() {
    printf("Welcome to the Genius Arithmetic Calculator!\n");
    printf("Choose an operation:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Exit\n");
    printf("Please enter your choice (1-5): ");
}

void performArithmetic(int choice) {
    double num1, num2, result;

    printf("Enter the first number: ");
    scanf("%lf", &num1);
    printf("Enter the second number: ");
    scanf("%lf", &num2);

    switch (choice) {
        case 1:
            result = num1 + num2;
            printf("Result of %.2lf + %.2lf = %.2lf\n", num1, num2, result);
            break;
        case 2:
            result = num1 - num2;
            printf("Result of %.2lf - %.2lf = %.2lf\n", num1, num2, result);
            break;
        case 3:
            result = num1 * num2;
            printf("Result of %.2lf * %.2lf = %.2lf\n", num1, num2, result);
            break;
        case 4:
            if (num2 != 0) {
                result = num1 / num2;
                printf("Result of %.2lf / %.2lf = %.2lf\n", num1, num2, result);
            } else {
                printf("Error: Division by zero is undefined!\n");
            }
            break;
        default:
            printf("Invalid operation!\n");
            break;
    }
}

int main() {
    int choice;

    do {
        displayMenu();
        scanf("%d", &choice);
        
        if (choice >= 1 && choice <= 4) {
            performArithmetic(choice);
        } else if (choice == 5) {
            printf("Thank you for using the Genius Arithmetic Calculator! Goodbye!\n");
        } else {
            printf("Invalid choice! Please select a number between 1 and 5.\n");
        }

        printf("\n");
    } while (choice != 5);
    
    return 0;
}