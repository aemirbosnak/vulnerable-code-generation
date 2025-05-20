//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: all-encompassing
#include <stdio.h>

void displayMenu() {
    printf("\nSelect an operation to perform:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Exit\n");
}

void performAddition(float a, float b) {
    printf("Result: %.2f + %.2f = %.2f\n", a, b, a + b);
}

void performSubtraction(float a, float b) {
    printf("Result: %.2f - %.2f = %.2f\n", a, b, a - b);
}

void performMultiplication(float a, float b) {
    printf("Result: %.2f * %.2f = %.2f\n", a, b, a * b);
}

void performDivision(float a, float b) {
    if (b == 0) {
        printf("Error: Division by zero is not allowed.\n");
    } else {
        printf("Result: %.2f / %.2f = %.2f\n", a, b, a / b);
    }
}

int main() {
    float num1, num2;
    int choice;

    do {
        displayMenu();
        printf("Enter your choice (1-5): ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number between 1 and 5.\n");
            while(getchar() != '\n'); // clear the input buffer
            continue;
        }

        if (choice < 1 || choice > 5) {
            printf("Invalid choice. Please choose a number between 1 and 5.\n");
            continue;
        }

        if (choice == 5) {
            printf("Exiting the program. Goodbye!\n");
            break;
        }

        printf("Enter two numbers: ");
        while (scanf("%f %f", &num1, &num2) != 2) {
            printf("Invalid input. Please enter two numbers separated by space: ");
            while(getchar() != '\n'); // clear the input buffer
        }

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
            default:
                printf("Invalid operation.\n");
                break;
        }

    } while (1);

    return 0;
}