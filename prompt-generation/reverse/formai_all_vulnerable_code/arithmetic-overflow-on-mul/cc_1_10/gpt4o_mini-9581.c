//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: active
#include <stdio.h>

void printMenu() {
    printf("Welcome to the Interactive Arithmetic Calculator!\n");
    printf("Please choose an operation:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Modulus\n");
    printf("6. Exit\n");
    printf("Enter your choice (1-6): ");
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
    if (b == 0) {
        printf("Error: Division by zero is undefined.\n");
        return 0; // Return 0 as a placeholder
    }
    return (float)a / (float)b;
}

int modulus(int a, int b) {
    if (b == 0) {
        printf("Error: Modulus by zero is undefined.\n");
        return 0; // Return 0 as a placeholder
    }
    return a % b;
}

void performOperation(int choice) {
    int num1, num2;
    
    printf("Enter first number: ");
    scanf("%d", &num1);
    printf("Enter second number: ");
    scanf("%d", &num2);

    switch (choice) {
        case 1:
            printf("Result: %d + %d = %d\n", num1, num2, add(num1, num2));
            break;
        case 2:
            printf("Result: %d - %d = %d\n", num1, num2, subtract(num1, num2));
            break;
        case 3:
            printf("Result: %d * %d = %d\n", num1, num2, multiply(num1, num2));
            break;
        case 4:
            printf("Result: %d / %d = %.2f\n", num1, num2, divide(num1, num2));
            break;
        case 5:
            printf("Result: %d %% %d = %d\n", num1, num2, modulus(num1, num2));
            break;
        case 6:
            printf("Exiting the calculator. Goodbye!\n");
            return;
        default:
            printf("Invalid choice. Please select a valid operation.\n");
    }
}

int main() {
    int choice;
    
    while (1) {
        printMenu();
        scanf("%d", &choice);

        if (choice == 6) {
            performOperation(choice);
            break;
        }
        
        performOperation(choice);
        printf("\n");
    }
    
    return 0;
}