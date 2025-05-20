//GPT-4o-mini DATASET v1.0 Category: Math exercise ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void displayMenu();
int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
float divide(int a, int b);
int modulus(int a, int b);

int main() {
    int choice, num1, num2;
    float result;

    while (1) {
        displayMenu();
        printf("Please enter your choice (1-6): ");
        if (scanf("%d", &choice) != 1) {
            fprintf(stderr, "Invalid input. Please enter a number between 1 and 6.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }
        
        if (choice < 1 || choice > 6) {
            fprintf(stderr, "Invalid choice! Please enter a number between 1 and 6.\n");
            continue;
        }

        if (choice == 6) {
            printf("Exiting the calculator. Goodbye!\n");
            break;
        }

        printf("Enter first number: ");
        scanf("%d", &num1);
        printf("Enter second number: ");
        scanf("%d", &num2);

        switch (choice) {
            case 1:
                result = add(num1, num2);
                printf("Result: %d + %d = %.2f\n", num1, num2, result);
                break;
            case 2:
                result = subtract(num1, num2);
                printf("Result: %d - %d = %.2f\n", num1, num2, result);
                break;
            case 3:
                result = multiply(num1, num2);
                printf("Result: %d * %d = %.2f\n", num1, num2, result);
                break;
            case 4:
                if (num2 == 0) {
                    fprintf(stderr, "Error: Division by zero is not allowed.\n");
                } else {
                    result = divide(num1, num2);
                    printf("Result: %d / %d = %.2f\n", num1, num2, result);
                }
                break;
            case 5:
                result = modulus(num1, num2);
                printf("Result: %d %% %d = %.2f\n", num1, num2, result);
                break;
        }
    }

    return 0;
}

// Function definitions
void displayMenu() {
    printf("\n====================\n");
    printf("   Basic Calculator  \n");
    printf("====================\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Modulus\n");
    printf("6. Exit\n");
    printf("====================\n");
}

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

float divide(int a, int b) {
    return (float)a / (float)b;
}

int modulus(int a, int b) {
    return a % b;
}