//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

void display_menu() {
    printf("Arithmetic Operations Menu:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Modulus\n");
    printf("6. Exit\n");
}

void get_input(int *num1, int *num2) {
    printf("Enter the first number: ");
    scanf("%d", num1);
    printf("Enter the second number: ");
    scanf("%d", num2);
}

void addition(int num1, int num2) {
    printf("Result of addition: %d + %d = %d\n", num1, num2, num1 + num2);
}

void subtraction(int num1, int num2) {
    printf("Result of subtraction: %d - %d = %d\n", num1, num2, num1 - num2);
}

void multiplication(int num1, int num2) {
    printf("Result of multiplication: %d * %d = %d\n", num1, num2, num1 * num2);
}

void division(int num1, int num2) {
    if (num2 == 0) {
        printf("Error: Division by zero is not allowed\n");
    } else {
        printf("Result of division: %d / %d = %.2f\n", num1, num2, (float)num1 / num2);
    }
}

void modulus(int num1, int num2) {
    if (num2 == 0) {
        printf("Error: Modulus by zero is not allowed\n");
    } else {
        printf("Result of modulus: %d %% %d = %d\n", num1, num2, num1 % num2);
    }
}

int main() {
    int choice;
    int num1, num2;

    while (1) {
        display_menu();
        printf("Please enter your choice (1-6): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Addition
                get_input(&num1, &num2);
                addition(num1, num2);
                break;
            case 2: // Subtraction
                get_input(&num1, &num2);
                subtraction(num1, num2);
                break;
            case 3: // Multiplication
                get_input(&num1, &num2);
                multiplication(num1, num2);
                break;
            case 4: // Division
                get_input(&num1, &num2);
                division(num1, num2);
                break;
            case 5: // Modulus
                get_input(&num1, &num2);
                modulus(num1, num2);
                break;
            case 6: // Exit
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please enter a number between 1 and 6.\n");
                break;
        }
        printf("\n");
    }

    return 0;
}