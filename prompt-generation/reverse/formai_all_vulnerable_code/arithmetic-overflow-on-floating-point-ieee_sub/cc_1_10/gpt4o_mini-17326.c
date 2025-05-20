//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: Alan Turing
#include <stdio.h>

void displayMenu() {
    printf("Welcome to the Arithmetic Operations Program!\n");
    printf("Please select an operation:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Modulus\n");
    printf("6. Exit\n");
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
    if (b != 0) {
        return a / b;
    } else {
        printf("Error! Division by zero.\n");
        return 0;
    }
}

int modulus(int a, int b) {
    if (b != 0) {
        return a % b;
    } else {
        printf("Error! Modulus by zero.\n");
        return 0;
    }
}

void performOperation(int choice) {
    float num1, num2;
    int intNum1, intNum2;

    switch (choice) {
        case 1:
            printf("Enter two numbers for addition: ");
            scanf("%f %f", &num1, &num2);
            printf("Result: %.2f\n", add(num1, num2));
            break;
        case 2:
            printf("Enter two numbers for subtraction: ");
            scanf("%f %f", &num1, &num2);
            printf("Result: %.2f\n", subtract(num1, num2));
            break;
        case 3:
            printf("Enter two numbers for multiplication: ");
            scanf("%f %f", &num1, &num2);
            printf("Result: %.2f\n", multiply(num1, num2));
            break;
        case 4:
            printf("Enter two numbers for division: ");
            scanf("%f %f", &num1, &num2);
            printf("Result: %.2f\n", divide(num1, num2));
            break;
        case 5:
            printf("Enter two integers for modulus: ");
            scanf("%d %d", &intNum1, &intNum2);
            printf("Result: %d\n", modulus(intNum1, intNum2));
            break;
        case 6:
            printf("Exiting the program. Goodbye!\n");
            break;
        default:
            printf("Invalid choice! Please select a correct operation.\n");
    }
}

int main() {
    int userChoice;

    while (1) {
        displayMenu();
        printf("Your choice: ");
        scanf("%d", &userChoice);

        if (userChoice == 6) {
            break;
        }

        performOperation(userChoice);
        printf("\n");
    }

    return 0;
}