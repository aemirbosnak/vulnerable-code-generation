//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

void displayMenu() {
    printf("\n--- Arithmetic Operations Menu ---\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Modulus\n");
    printf("6. Exit\n");
    printf("-----------------------------------\n");
    printf("Please select an option (1-6): ");
}

void performAddition(float a, float b) {
    printf("Result of %.2f + %.2f = %.2f\n", a, b, a + b);
}

void performSubtraction(float a, float b) {
    printf("Result of %.2f - %.2f = %.2f\n", a, b, a - b);
}

void performMultiplication(float a, float b) {
    printf("Result of %.2f * %.2f = %.2f\n", a, b, a * b);
}

void performDivision(float a, float b) {
    if (b != 0) {
        printf("Result of %.2f / %.2f = %.2f\n", a, b, a / b);
    } else {
        printf("Error: Division by zero is not allowed.\n");
    }
}

void performModulus(int a, int b) {
    if (b != 0) {
        printf("Result of %d %% %d = %d\n", a, b, a % b);
    } else {
        printf("Error: Modulus by zero is not allowed.\n");
    }
}

int main() {
    float num1, num2;
    int choice;

    printf("Welcome to the Arithmetic Operations Program!\n");
    
    // Inputting two numbers
    printf("Please enter the first number: ");
    scanf("%f", &num1);
    printf("Please enter the second number: ");
    scanf("%f", &num2);
    
    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                performAddition(num1, num2);
                break;
            case 2:
                performSubtraction(num1, num2);
                break;
            case 3:
                performMultiplication(num1, num2);
                break;
            case 4:
                performDivision(num1, num2);
                break;
            case 5:
                // Casting to int for modulus operation
                performModulus((int)num1, (int)num2);
                break;
            case 6:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }

    } while (choice != 6);

    return 0;
}