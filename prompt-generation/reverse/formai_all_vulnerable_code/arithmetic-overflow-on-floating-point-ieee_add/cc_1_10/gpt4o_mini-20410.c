//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: thoughtful
#include <stdio.h>

void displayMenu() {
    printf("\nSimple Arithmetic Operations Menu:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Modulus\n");
    printf("6. Exit\n");
    printf("Choose an option: ");
}

float performAddition(float a, float b) {
    return a + b;
}

float performSubtraction(float a, float b) {
    return a - b;
}

float performMultiplication(float a, float b) {
    return a * b;
}

float performDivision(float a, float b) {
    if (b == 0) {
        printf("Error: Division by zero is undefined.\n");
        return 0; // Return 0 for error handling
    }
    return a / b;
}

int performModulus(int a, int b) {
    if (b == 0) {
        printf("Error: Modulus by zero is undefined.\n");
        return 0; // Return 0 for error handling
    }
    return a % b;
}

void getInput(float *num1, float *num2) {
    printf("Enter first number: ");
    scanf("%f", num1);
    printf("Enter second number: ");
    scanf("%f", num2);
}

int main() {
    int choice;
    float num1, num2;
    int intNum1, intNum2;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                getInput(&num1, &num2);
                printf("Result: %.2f\n", performAddition(num1, num2));
                break;

            case 2:
                getInput(&num1, &num2);
                printf("Result: %.2f\n", performSubtraction(num1, num2));
                break;

            case 3:
                getInput(&num1, &num2);
                printf("Result: %.2f\n", performMultiplication(num1, num2));
                break;

            case 4:
                getInput(&num1, &num2);
                printf("Result: %.2f\n", performDivision(num1, num2));
                break;

            case 5:
                printf("Enter two integers for modulus operation:\n");
                printf("Enter first integer: ");
                scanf("%d", &intNum1);
                printf("Enter second integer: ");
                scanf("%d", &intNum2);
                printf("Result: %d\n", performModulus(intNum1, intNum2));
                break;

            case 6:
                printf("Exiting the program. Thank you!\n");
                return 0;

            default:
                printf("Invalid option! Please choose a valid option from the menu.\n");
                break;
        }
    }

    return 0;
}