//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

void displayMenu() {
    printf("\n====== Simple Calculator ======\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Exit\n");
    printf("==============================\n");
    printf("Choose an option (1-5): ");
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
    if (b != 0)
        return a / b;
    else {
        printf("Error: Division by zero is undefined.\n");
        exit(EXIT_FAILURE);
    }
}

int main() {
    float num1, num2, result;
    int choice;

    printf("Welcome to the Simple Calculator!\n");

    do {
        displayMenu();
        scanf("%d", &choice);

        if (choice < 1 || choice > 5) {
            printf("Invalid option! Please select a valid menu number.\n");
            continue;
        }

        if (choice == 5) {
            printf("Thank you for using the Simple Calculator! Goodbye!\n");
            break;
        }

        printf("Enter first number: ");
        scanf("%f", &num1);
        printf("Enter second number: ");
        scanf("%f", &num2);

        switch (choice) {
            case 1:
                result = add(num1, num2);
                printf("%.2f + %.2f = %.2f\n", num1, num2, result);
                break;
            case 2:
                result = subtract(num1, num2);
                printf("%.2f - %.2f = %.2f\n", num1, num2, result);
                break;
            case 3:
                result = multiply(num1, num2);
                printf("%.2f * %.2f = %.2f\n", num1, num2, result);
                break;
            case 4:
                result = divide(num1, num2);
                printf("%.2f / %.2f = %.2f\n", num1, num2, result);
                break;
            default:
                printf("Unexpected error occurred!\n");
                break;
        }
    } while (1);

    return 0;
}