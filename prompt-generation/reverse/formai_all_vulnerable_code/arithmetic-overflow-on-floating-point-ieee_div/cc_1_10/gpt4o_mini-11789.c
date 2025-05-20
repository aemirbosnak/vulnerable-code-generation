//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: protected
#include <stdio.h>

void displayMenu() {
    printf("---- Arithmetic Operations ----\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Exit\n");
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
        printf("Error: Division by zero is not allowed.\n");
        return 0; // Return 0 to indicate an error
    }
}

void performOperation(int choice) {
    float num1, num2;
    float result;

    printf("Enter first number: ");
    scanf("%f", &num1);
    printf("Enter second number: ");
    scanf("%f", &num2);

    switch (choice) {
        case 1:
            result = add(num1, num2);
            printf("Result: %.2f + %.2f = %.2f\n", num1, num2, result);
            break;
        case 2:
            result = subtract(num1, num2);
            printf("Result: %.2f - %.2f = %.2f\n", num1, num2, result);
            break;
        case 3:
            result = multiply(num1, num2);
            printf("Result: %.2f * %.2f = %.2f\n", num1, num2, result);
            break;
        case 4:
            result = divide(num1, num2);
            if (num2 != 0) {
                printf("Result: %.2f / %.2f = %.2f\n", num1, num2, result);
            }
            break;
        case 5:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid option. Please try again.\n");
            break;
    }
}

int main() {
    int choice;

    while (1) {
        displayMenu();
        printf("Select operation (1-5): ");
        scanf("%d", &choice);

        if (choice == 5) {
            break;
        }

        performOperation(choice);
        printf("\n");
    }

    return 0;
}