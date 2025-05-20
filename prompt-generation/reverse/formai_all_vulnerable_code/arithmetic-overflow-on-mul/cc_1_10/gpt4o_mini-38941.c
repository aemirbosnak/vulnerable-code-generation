//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: high level of detail
#include <stdio.h>

// Function declarations for arithmetic operations
int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
float divide(float a, float b);
int modulus(int a, int b);
void displayMenu();
void performOperation(int choice);

int main() {
    int choice;

    // Welcome message
    printf("===================================\n");
    printf("Welcome to the Arithmetic Operations Program!\n");
    printf("===================================\n");

    // Loop until the user chooses to exit
    do {
        displayMenu();
        printf("Enter your choice (0 to exit): ");
        scanf("%d", &choice);
        
        if (choice >= 1 && choice <= 5) {
            performOperation(choice);
        } else if (choice != 0) {
            printf("Invalid choice! Please try again.\n");
        }

    } while (choice != 0);

    // Exit message
    printf("Thank you for using the program. Goodbye!\n");
    return 0;
}

// Function to display the menu of operations
void displayMenu() {
    printf("\nSelect an operation:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Modulus\n");
    printf("0. Exit\n");
}

// Function to perform the operation based on user choice
void performOperation(int choice) {
    int num1, num2;
    float result;

    // Get input from user
    printf("Enter first number: ");
    scanf("%d", &num1);
    printf("Enter second number: ");
    scanf("%d", &num2);

    // Switch case for different operations
    switch (choice) {
        case 1:
            result = add(num1, num2);
            printf("Result of Addition: %d + %d = %d\n", num1, num2, (int)result);
            break;
        case 2:
            result = subtract(num1, num2);
            printf("Result of Subtraction: %d - %d = %d\n", num1, num2, (int)result);
            break;
        case 3:
            result = multiply(num1, num2);
            printf("Result of Multiplication: %d * %d = %d\n", num1, num2, (int)result);
            break;
        case 4:
            if (num2 != 0) {
                result = divide(num1, num2);
                printf("Result of Division: %d / %d = %.2f\n", num1, num2, result);
            } else {
                printf("Error: Division by zero is not allowed.\n");
            }
            break;
        case 5:
            result = modulus(num1, num2);
            printf("Result of Modulus: %d %% %d = %d\n", num1, num2, (int)result);
            break;
        default:
            printf("An unexpected error occurred.\n");
    }
}

// Function to add two integers
int add(int a, int b) {
    return a + b;
}

// Function to subtract one integer from another
int subtract(int a, int b) {
    return a - b;
}

// Function to multiply two integers
int multiply(int a, int b) {
    return a * b;
}

// Function to divide one floating point number by another
float divide(float a, float b) {
    return a / b;
}

// Function to perform modulus operation on two integers
int modulus(int a, int b) {
    return a % b;
}