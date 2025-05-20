//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: satisfied
#include <stdio.h>

// Function Prototypes
void displayMenu();
int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
int divide(int a, int b);
int modulus(int a, int b);
void performOperation(int choice, int a, int b);

// Main function
int main() {
    int choice;
    int num1, num2;

    printf("Welcome to the Arithmetic Operations Program!\n");

    while (1) {
        displayMenu();
        printf("Enter your choice (1-6), or 0 to exit: ");
        scanf("%d", &choice);

        if (choice == 0) {
            printf("Thank you for using the program. Exiting...\n");
            break;
        }

        if (choice < 1 || choice > 6) {
            printf("Invalid choice! Please choose a valid operation.\n");
            continue;
        }

        printf("Enter first number: ");
        scanf("%d", &num1);
        printf("Enter second number: ");
        scanf("%d", &num2);

        performOperation(choice, num1, num2);
    }

    return 0;
}

// Function to display the menu
void displayMenu() {
    printf("----- Menu -----\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Modulus\n");
    printf("6. Exit\n");
    printf("-----------------\n");
}

// Function to perform addition
int add(int a, int b) {
    return a + b;
}

// Function to perform subtraction
int subtract(int a, int b) {
    return a - b;
}

// Function to perform multiplication
int multiply(int a, int b) {
    return a * b;
}

// Function to perform division
int divide(int a, int b) {
    if (b == 0) {
        printf("Error! Division by zero.\n");
        return 0;
    }
    return a / b;
}

// Function to perform modulus
int modulus(int a, int b) {
    if (b == 0) {
        printf("Error! Modulus by zero.\n");
        return 0;
    }
    return a % b;
}

// Function to perform the selected operation
void performOperation(int choice, int a, int b) {
    int result;

    switch (choice) {
        case 1:
            result = add(a, b);
            printf("Result of %d + %d = %d\n", a, b, result);
            break;
        case 2:
            result = subtract(a, b);
            printf("Result of %d - %d = %d\n", a, b, result);
            break;
        case 3:
            result = multiply(a, b);
            printf("Result of %d * %d = %d\n", a, b, result);
            break;
        case 4:
            result = divide(a, b);
            if (b != 0) {
                printf("Result of %d / %d = %d\n", a, b, result);
            }
            break;
        case 5:
            result = modulus(a, b);
            if (b != 0) {
                printf("Result of %d %% %d = %d\n", a, b, result);
            }
            break;
        default:
            printf("Invalid operation chosen!\n");
            break;
    }

    printf("\n"); // New line for better readability
}