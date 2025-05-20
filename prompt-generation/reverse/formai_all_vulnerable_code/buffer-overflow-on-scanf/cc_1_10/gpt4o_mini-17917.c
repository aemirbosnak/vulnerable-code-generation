//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: brave
#include <stdio.h>

// Function prototypes
void display_menu();
int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
float divide(int a, int b);
void execute_operation(int choice);

int main() {
    int choice = -1;

    printf("Welcome to the Arithmetic Adventure!\n");
    printf("======================================\n");

    while (choice != 0) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 0) {
            printf("Exiting the Arithmetic Adventure... Goodbye!\n");
            break;
        } else if (choice > 4 || choice < 0) {
            printf("Invalid choice. Please choose a valid option!\n");
        } else {
            execute_operation(choice);
        }
    }

    return 0;
}

void display_menu() {
    printf("\nAvailable Operations:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("0. Exit\n");
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
        printf("Error: Division by zero is not allowed!\n");
        return 0; // Return 0 as a placeholder for invalid division
    }
    return (float)a / b;
}

void execute_operation(int choice) {
    int num1, num2, result;
    float div_result;

    printf("Enter two integers: ");
    scanf("%d %d", &num1, &num2);

    switch (choice) {
        case 1:
            result = add(num1, num2);
            printf("Result of %d + %d = %d\n", num1, num2, result);
            break;
        case 2:
            result = subtract(num1, num2);
            printf("Result of %d - %d = %d\n", num1, num2, result);
            break;
        case 3:
            result = multiply(num1, num2);
            printf("Result of %d * %d = %d\n", num1, num2, result);
            break;
        case 4:
            div_result = divide(num1, num2);
            if (num2 != 0) {  // Only print result if division was successful
                printf("Result of %d / %d = %.2f\n", num1, num2, div_result);
            }
            break;
        default:
            printf("Something went wrong! Please try again.\n");
            break;
    }
}