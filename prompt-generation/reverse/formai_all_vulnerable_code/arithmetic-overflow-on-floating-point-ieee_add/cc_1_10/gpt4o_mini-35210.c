//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

void displayMenu();
void performAddition(float a, float b);
void performSubtraction(float a, float b);
void performMultiplication(float a, float b);
void performDivision(float a, float b);
void performModulus(int a, int b);
void clearInputBuffer();

int main() {
    float num1, num2;
    int choice;

    printf("Welcome to the Arithmetic Operations Program!\n");
    
    while (1) {
        printf("Please enter the first number: ");
        if (scanf("%f", &num1) != 1) {
            printf("Invalid input. Please enter a valid number.\n");
            clearInputBuffer();
            continue;
        }

        printf("Please enter the second number: ");
        if (scanf("%f", &num2) != 1) {
            printf("Invalid input. Please enter a valid number.\n");
            clearInputBuffer();
            continue;
        }

        displayMenu();
        printf("Choose an operation (1-5) or 0 to exit: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a valid option.\n");
            clearInputBuffer();
            continue;
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
            case 5:
                performModulus((int)num1, (int)num2);
                break;
            case 0:
                printf("Exiting the program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

void displayMenu() {
    printf("\n=== Arithmetic Operations Menu ===\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Modulus (integer only)\n");
    printf("===================================\n");
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
    if (b == 0) {
        printf("Error: Division by zero is undefined!\n");
    } else {
        printf("Result of %.2f / %.2f = %.2f\n", a, b, a / b);
    }
}

void performModulus(int a, int b) {
    if (b == 0) {
        printf("Error: Modulus by zero is undefined!\n");
    } else {
        printf("Result of %d %% %d = %d\n", a, b, a % b);
    }
}

void clearInputBuffer() {
    while(getchar() != '\n');
}