//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: Dennis Ritchie
#include <stdio.h>

void printWelcomeMessage() {
    printf("Welcome to the Arithmetic Operations Program!\n");
    printf("You can perform addition, subtraction, multiplication, and division.\n");
    printf("Please follow the prompts to enter your choices.\n\n");
}

void add(int a, int b) {
    printf("Result of Addition: %d + %d = %d\n", a, b, a + b);
}

void subtract(int a, int b) {
    printf("Result of Subtraction: %d - %d = %d\n", a, b, a - b);
}

void multiply(int a, int b) {
    printf("Result of Multiplication: %d * %d = %d\n", a, b, a * b);
}

void divide(int a, int b) {
    if (b != 0) {
        printf("Result of Division: %d / %d = %.2f\n", a, b, (float)a / b);
    } else {
        printf("Error: Division by zero is undefined.\n");
    }
}

int main() {
    int choice;
    int num1, num2;

    printWelcomeMessage();

    do {
        printf("\nSelect an operation:\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        if (choice >= 1 && choice <= 4) {
            printf("Enter two integers: ");
            scanf("%d %d", &num1, &num2);
        }

        switch (choice) {
            case 1:
                add(num1, num2);
                break;
            case 2:
                subtract(num1, num2);
                break;
            case 3:
                multiply(num1, num2);
                break;
            case 4:
                divide(num1, num2);
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice, please enter a number between 1 and 5.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}