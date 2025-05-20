//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

void displayMenu() {
    printf("Choose an operation:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Modulus\n");
    printf("6. Exit\n");
}

int getInput(int *num1, int *num2) {
    printf("Enter the first number: ");
    if (scanf("%d", num1) != 1) {
        printf("Invalid input! Please enter an integer.\n");
        return 0;
    }
    
    printf("Enter the second number: ");
    if (scanf("%d", num2) != 1) {
        printf("Invalid input! Please enter an integer.\n");
        return 0;
    }
    return 1;
}

void performAddition(int num1, int num2) {
    printf("Result of Addition: %d + %d = %d\n", num1, num2, num1 + num2);
}

void performSubtraction(int num1, int num2) {
    printf("Result of Subtraction: %d - %d = %d\n", num1, num2, num1 - num2);
}

void performMultiplication(int num1, int num2) {
    printf("Result of Multiplication: %d * %d = %d\n", num1, num2, num1 * num2);
}

void performDivision(int num1, int num2) {
    if (num2 == 0) {
        printf("Error! Division by zero is undefined.\n");
    } else {
        printf("Result of Division: %d / %d = %.2f\n", num1, num2, (float)num1 / num2);
    }
}

void performModulus(int num1, int num2) {
    if (num2 == 0) {
        printf("Error! Modulus by zero is undefined.\n");
    } else {
        printf("Result of Modulus: %d %% %d = %d\n", num1, num2, num1 % num2);
    }
}

int main() {
    int choice, num1, num2;

    while (1) {
        displayMenu();
        printf("Enter your choice (1-6): ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number between 1 and 6.\n");
            while (getchar() != '\n'); // clear the input buffer
            continue;
        }

        switch (choice) {
            case 1:
                if (getInput(&num1, &num2)) {
                    performAddition(num1, num2);
                }
                break;
            case 2:
                if (getInput(&num1, &num2)) {
                    performSubtraction(num1, num2);
                }
                break;
            case 3:
                if (getInput(&num1, &num2)) {
                    performMultiplication(num1, num2);
                }
                break;
            case 4:
                if (getInput(&num1, &num2)) {
                    performDivision(num1, num2);
                }
                break;
            case 5:
                if (getInput(&num1, &num2)) {
                    performModulus(num1, num2);
                }
                break;
            case 6:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please select a valid option.\n");
        }
        printf("\n"); // Add new line for formatting
    }
    return 0;
}