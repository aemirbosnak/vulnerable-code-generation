//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: safe
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

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
        printf("Error: Division by zero is not allowed!\n");
        exit(EXIT_FAILURE);
    }
    return (float)a / b;
}

void displayMenu() {
    printf("Simple Arithmetic Operations Menu:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Exit\n");
    printf("Please choose an option (1-5): ");
}

void getTwoNumbers(int *a, int *b) {
    printf("Enter first number: ");
    scanf("%d", a);
    printf("Enter second number: ");
    scanf("%d", b);
}

int main() {
    int choice;
    int num1, num2;

    while (1) {
        displayMenu();
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number between 1 and 5.\n");
            while (getchar() != '\n'); // clear invalid input
            continue;
        }

        switch (choice) {
            case 1:
                getTwoNumbers(&num1, &num2);
                printf("Result: %d + %d = %d\n", num1, num2, add(num1, num2));
                break;
            case 2:
                getTwoNumbers(&num1, &num2);
                printf("Result: %d - %d = %d\n", num1, num2, subtract(num1, num2));
                break;
            case 3:
                getTwoNumbers(&num1, &num2);
                printf("Result: %d * %d = %d\n", num1, num2, multiply(num1, num2));
                break;
            case 4:
                getTwoNumbers(&num1, &num2);
                printf("Result: %d / %d = %.2f\n", num1, num2, divide(num1, num2));
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                exit(EXIT_SUCCESS);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}