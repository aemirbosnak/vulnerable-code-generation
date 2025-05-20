//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: ephemeral
#include <stdio.h>

void displayWelcomeMessage() {
    printf("***************************\n");
    printf("Welcome to the Arithmetic Joyride!\n");
    printf("***************************\n");
}

void displayMenu() {
    printf("Please choose an arithmetic operation:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Modulus\n");
    printf("6. Exit\n");
}

float add(float a, float b) {
    return a + b;
}

float subtract(float a, float b) {
    return a - b;
}

float multiply(float a, float b) {
    return a * b;
}

float divide(float a, float b) {
    if (b != 0) {
        return a / b;
    } else {
        printf("Division by zero is not allowed!\n");
        return 0; // Just returning 0 or could throw errors but keeping it simple
    }
}

int modulus(int a, int b) {
    if (b != 0) {
        return a % b;
    } else {
        printf("Modulus by zero is not allowed!\n");
        return 0; // Same consideration for simplicity
    }
}

void arithmeticOperations() {
    int choice;
    float num1, num2;
    int intNum1, intNum2;

    while (1) {
        displayMenu();
        printf("Select your choice: ");
        scanf("%d", &choice);

        if (choice == 6) {
            printf("Exiting the program. Thank you!\n");
            break;
        }

        printf("Enter first number: ");
        scanf("%f", &num1);
        printf("Enter second number: ");
        scanf("%f", &num2);
        
        switch (choice) {
            case 1:
                printf("Result of %.2f + %.2f = %.2f\n", num1, num2, add(num1, num2));
                break;
            case 2:
                printf("Result of %.2f - %.2f = %.2f\n", num1, num2, subtract(num1, num2));
                break;
            case 3:
                printf("Result of %.2f * %.2f = %.2f\n", num1, num2, multiply(num1, num2));
                break;
            case 4:
                printf("Result of %.2f / %.2f = %.2f\n", num1, num2, divide(num1, num2));
                break;
            case 5:
                // For modulus, work with integers
                intNum1 = (int)num1;
                intNum2 = (int)num2;
                printf("Result of %d %% %d = %d\n", intNum1, intNum2, modulus(intNum1, intNum2));
                break;
            default:
                printf("Invalid choice! Please choose a valid option.\n");
        }
        printf("\n");
    }
}

int main() {
    displayWelcomeMessage();
    arithmeticOperations();
    return 0;
}