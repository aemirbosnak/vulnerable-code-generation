//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: standalone
#include <stdio.h>

void add(int a, int b) {
    printf("Result of %d + %d = %d\n", a, b, a + b);
}

void subtract(int a, int b) {
    printf("Result of %d - %d = %d\n", a, b, a - b);
}

void multiply(int a, int b) {
    printf("Result of %d * %d = %d\n", a, b, a * b);
}

void divide(int a, int b) {
    if (b != 0) {
        printf("Result of %d / %d = %.2f\n", a, b, (float)a / b);
    } else {
        printf("Error: Division by zero is not allowed.\n");
    }
}

void displayMenu() {
    printf("\nArithmetic Operations Menu:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Exit\n");
    printf("Choose an option (1-5): ");
}

int main() {
    int choice, num1, num2;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        if (choice == 5) {
            printf("Exiting the program. Thank you!\n");
            break;
        }

        if (choice < 1 || choice > 5) {
            printf("Invalid choice. Please select a valid option.\n");
            continue;
        }

        printf("Enter two integers: ");
        scanf("%d %d", &num1, &num2);

        switch (choice) {
            case 1:
                add(num1, num2);
                break;
            case 2:
                subtract(num1, num2);
                break;
            case 3:
                multiply(num1, num2);
                break;
            case 4:
                divide(num1, num2);
                break;
            default:
                printf("Invalid choice. Please select a valid option.\n");
        }
    }

    return 0;
}