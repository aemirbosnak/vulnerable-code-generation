//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: complex
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

void displayMenu() {
    printf("------------ Arithmetic Operations Menu ------------\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Modulus\n");
    printf("6. Power\n");
    printf("7. Exit\n");
    printf("---------------------------------------------------\n");
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
    if (b != 0) {
        return (float)a / b;
    } else {
        printf("Error: Division by zero.\n");
        return 0;
    }
}

int modulus(int a, int b) {
    if (b != 0) {
        return a % b;
    } else {
        printf("Error: Modulus by zero.\n");
        return 0;
    }
}

int power(int base, int exp) {
    if (exp < 0) {
        printf("Error: Negative exponent not supported.\n");
        return -1;
    }
    int result = 1;
    for (int i = 0; i < exp; i++) {
        result *= base;
    }
    return result;
}

void performOperation(int choice) {
    int num1, num2;
    switch (choice) {
        case 1:
            printf("Enter two integers: ");
            scanf("%d %d", &num1, &num2);
            printf("Result: %d + %d = %d\n", num1, num2, add(num1, num2));
            break;
        case 2:
            printf("Enter two integers: ");
            scanf("%d %d", &num1, &num2);
            printf("Result: %d - %d = %d\n", num1, num2, subtract(num1, num2));
            break;
        case 3:
            printf("Enter two integers: ");
            scanf("%d %d", &num1, &num2);
            printf("Result: %d * %d = %d\n", num1, num2, multiply(num1, num2));
            break;
        case 4:
            printf("Enter two integers: ");
            scanf("%d %d", &num1, &num2);
            printf("Result: %d / %d = %.2f\n", num1, num2, divide(num1, num2));
            break;
        case 5:
            printf("Enter two integers: ");
            scanf("%d %d", &num1, &num2);
            printf("Result: %d %% %d = %d\n", num1, num2, modulus(num1, num2));
            break;
        case 6:
            printf("Enter base and exponent: ");
            scanf("%d %d", &num1, &num2);
            int result = power(num1, num2);
            if (result != -1) {
                printf("Result: %d ^ %d = %d\n", num1, num2, result);
            }
            break;
        default:
            printf("Invalid choice! Please select a valid operation.\n");
            break;
    }
}

int main() {
    int choice;

    while (1) {
        displayMenu();
        printf("Select an operation (1-7): ");
        scanf("%d", &choice);
        if (choice == 7) {
            printf("Exiting the program. Thank you!\n");
            break;
        }
        performOperation(choice);
        printf("\n");
    }
    
    return 0;
}