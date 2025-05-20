//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: authentic
#include <stdio.h>

// Function prototypes
void display_menu();
void add_numbers();
void subtract_numbers();
void multiply_numbers();
void divide_numbers();
void modulus_numbers();

// Main function
int main() {
    int choice;
    do {
        display_menu();
        printf("Enter your choice (1-6 or 0 to exit): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_numbers();
                break;
            case 2:
                subtract_numbers();
                break;
            case 3:
                multiply_numbers();
                break;
            case 4:
                divide_numbers();
                break;
            case 5:
                modulus_numbers();
                break;
            case 0:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 0);

    return 0;
}

// Function to display the menu
void display_menu() {
    printf("\n----- Simple Arithmetic Operations -----\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Modulus\n");
    printf("0. Exit\n");
}

// Function to add two numbers
void add_numbers() {
    float num1, num2, result;
    printf("You selected Addition.\n");
    printf("Enter first number: ");
    scanf("%f", &num1);
    printf("Enter second number: ");
    scanf("%f", &num2);
    result = num1 + num2;
    printf("Result: %.2f + %.2f = %.2f\n", num1, num2, result);
}

// Function to subtract two numbers
void subtract_numbers() {
    float num1, num2, result;
    printf("You selected Subtraction.\n");
    printf("Enter first number: ");
    scanf("%f", &num1);
    printf("Enter second number: ");
    scanf("%f", &num2);
    result = num1 - num2;
    printf("Result: %.2f - %.2f = %.2f\n", num1, num2, result);
}

// Function to multiply two numbers
void multiply_numbers() {
    float num1, num2, result;
    printf("You selected Multiplication.\n");
    printf("Enter first number: ");
    scanf("%f", &num1);
    printf("Enter second number: ");
    scanf("%f", &num2);
    result = num1 * num2;
    printf("Result: %.2f * %.2f = %.2f\n", num1, num2, result);
}

// Function to divide two numbers
void divide_numbers() {
    float num1, num2, result;
    printf("You selected Division.\n");
    printf("Enter numerator: ");
    scanf("%f", &num1);
    printf("Enter denominator: ");
    scanf("%f", &num2);

    // Checking for division by zero
    if (num2 == 0) {
        printf("Error: Division by zero is undefined!\n");
    } else {
        result = num1 / num2;
        printf("Result: %.2f / %.2f = %.2f\n", num1, num2, result);
    }
}

// Function to compute modulus of two integers
void modulus_numbers() {
    int num1, num2, result;
    printf("You selected Modulus.\n");
    printf("Enter first integer: ");
    scanf("%d", &num1);
    printf("Enter second integer: ");
    scanf("%d", &num2);

    // Checking for modulus by zero
    if (num2 == 0) {
        printf("Error: Modulus by zero is undefined!\n");
    } else {
        result = num1 % num2;
        printf("Result: %d %% %d = %d\n", num1, num2, result);
    }
}