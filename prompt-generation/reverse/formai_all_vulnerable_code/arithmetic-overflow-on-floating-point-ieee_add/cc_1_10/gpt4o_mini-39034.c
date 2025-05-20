//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: systematic
#include <stdio.h>

void displayMenu() {
    printf("\nArithmetic Operations Menu:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Modulus\n");
    printf("6. Exit\n");
    printf("Select an option (1-6): ");
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
    if (b == 0) {
        printf("Error: Division by zero!\n");
        return 0;
    }
    return a / b;
}

int modulus(int a, int b) {
    if (b == 0) {
        printf("Error: Modulus by zero!\n");
        return 0;
    }
    return a % b;
}

int main() {
    float num1, num2;
    int choice, intNum1, intNum2;

    printf("Welcome to the C Arithmetic Program!\n");
    
    // Taking input from the user
    printf("Enter the first number (float): ");
    scanf("%f", &num1);
    printf("Enter the second number (float): ");
    scanf("%f", &num2);
    
    // Taking input for integers for modulus operation
    intNum1 = (int)num1; // Casting float to int for modulus
    intNum2 = (int)num2; // Casting float to int for modulus

    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Addition of %.2f and %.2f is: %.2f\n", num1, num2, add(num1, num2));
                break;
            case 2:
                printf("Subtraction of %.2f from %.2f is: %.2f\n", num2, num1, subtract(num1, num2));
                break;
            case 3:
                printf("Multiplication of %.2f and %.2f is: %.2f\n", num1, num2, multiply(num1, num2));
                break;
            case 4:
                printf("Division of %.2f by %.2f is: %.2f\n", num1, num2, divide(num1, num2));
                break;
            case 5:
                printf("Modulus of %d and %d is: %d\n", intNum1, intNum2, modulus(intNum1, intNum2));
                break;
            case 6:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please select a valid option.\n");
        }
    } while (choice != 6);

    return 0;
}