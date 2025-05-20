//GPT-4o-mini DATASET v1.0 Category: Math exercise ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

void display_menu() {
    printf("*********************************\n");
    printf("          Simple Calculator      \n");
    printf("*********************************\n");
    printf("Choose an option:\n");
    printf("1. Addition (+)\n");
    printf("2. Subtraction (-)\n");
    printf("3. Multiplication (*)\n");
    printf("4. Division (/)\n");
    printf("5. Exit\n");
    printf("Enter your choice (1-5): ");
}

double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

double divide(double a, double b) {
    if (b == 0) {
        printf("Error: Division by zero is not allowed!\n");
        return 0; // Return 0 as a placeholder
    }
    return a / b;
}

void perform_calculation(int choice) {
    double num1, num2, result;
    
    printf("Enter first number: ");
    scanf("%lf", &num1);
    printf("Enter second number: ");
    scanf("%lf", &num2);

    switch (choice) {
        case 1:
            result = add(num1, num2);
            printf("Result: %.2lf + %.2lf = %.2lf\n", num1, num2, result);
            break;
        case 2:
            result = subtract(num1, num2);
            printf("Result: %.2lf - %.2lf = %.2lf\n", num1, num2, result);
            break;
        case 3:
            result = multiply(num1, num2);
            printf("Result: %.2lf * %.2lf = %.2lf\n", num1, num2, result);
            break;
        case 4:
            result = divide(num1, num2);
            if (num2 != 0) { // Only print result if not division by zero
                printf("Result: %.2lf / %.2lf = %.2lf\n", num1, num2, result);
            }
            break;
        default:
            printf("Invalid option! Please choose a valid operation.\n");
            break;
    }
}

int main() {
    int choice;

    do {
        display_menu();
        scanf("%d", &choice);

        if (choice >= 1 && choice <= 4) {
            perform_calculation(choice); // Perform valid operation
        } else if (choice == 5) {
            printf("Thanks for using the Simple Calculator! Goodbye!\n");
        } else {
            printf("Invalid choice! Please select a valid option from the menu.\n");
        }

        printf("\n"); // For spacing between iterations

    } while (choice != 5); // Continue until the user chooses to exit

    return 0;
}