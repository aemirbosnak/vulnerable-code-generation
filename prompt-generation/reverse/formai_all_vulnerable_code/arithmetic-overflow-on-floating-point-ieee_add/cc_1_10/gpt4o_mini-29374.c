//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: accurate
#include <stdio.h>

void add(double a, double b) {
    printf("Addition: %.2lf + %.2lf = %.2lf\n", a, b, a + b);
}

void subtract(double a, double b) {
    printf("Subtraction: %.2lf - %.2lf = %.2lf\n", a, b, a - b);
}

void multiply(double a, double b) {
    printf("Multiplication: %.2lf * %.2lf = %.2lf\n", a, b, a * b);
}

void divide(double a, double b) {
    if (b != 0) {
        printf("Division: %.2lf / %.2lf = %.2lf\n", a, b, a / b);
    } else {
        printf("Error: Division by zero is undefined.\n");
    }
}

void modulus(int a, int b) {
    if (b != 0) {
        printf("Modulus: %d %% %d = %d\n", a, b, a % b);
    } else {
        printf("Error: Division by zero is undefined for modulus.\n");
    }
}

void displayMenu() {
    printf("\nChoose an operation:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Modulus\n");
    printf("6. Exit\n");
}

int main() {
    int choice;
    double num1, num2;
    
    do {
        displayMenu();
        printf("Enter your choice: ");
        
        // Validate user input for choice
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter an integer.\n");
            // Clear the invalid input
            while(getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter two numbers: ");
                if (scanf("%lf %lf", &num1, &num2) != 2) {
                    printf("Invalid input! Please enter valid numbers.\n");
                    while(getchar() != '\n');
                    break;
                }
                add(num1, num2);
                break;

            case 2:
                printf("Enter two numbers: ");
                if (scanf("%lf %lf", &num1, &num2) != 2) {
                    printf("Invalid input! Please enter valid numbers.\n");
                    while(getchar() != '\n');
                    break;
                }
                subtract(num1, num2);
                break;

            case 3:
                printf("Enter two numbers: ");
                if (scanf("%lf %lf", &num1, &num2) != 2) {
                    printf("Invalid input! Please enter valid numbers.\n");
                    while(getchar() != '\n');
                    break;
                }
                multiply(num1, num2);
                break;

            case 4:
                printf("Enter two numbers: ");
                if (scanf("%lf %lf", &num1, &num2) != 2) {
                    printf("Invalid input! Please enter valid numbers.\n");
                    while(getchar() != '\n');
                    break;
                }
                divide(num1, num2);
                break;

            case 5:
                {
                    int a, b;
                    printf("Enter two integers: ");
                    if (scanf("%d %d", &a, &b) != 2) {
                        printf("Invalid input! Please enter valid integers.\n");
                        while(getchar() != '\n');
                        break;
                    }
                    modulus(a, b);
                }
                break;

            case 6:
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice! Please choose a number between 1 to 6.\n");
        }
    } while (choice != 6);

    return 0;
}