//GPT-4o-mini DATASET v1.0 Category: Math exercise ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

void add(double a, double b) {
    printf("Result: %.2f + %.2f = %.2f\n", a, b, a + b);
}

void subtract(double a, double b) {
    printf("Result: %.2f - %.2f = %.2f\n", a, b, a - b);
}

void multiply(double a, double b) {
    printf("Result: %.2f * %.2f = %.2f\n", a, b, a * b);
}

void divide(double a, double b) {
    if (b != 0) {
        printf("Result: %.2f / %.2f = %.2f\n", a, b, a / b);
    } else {
        printf("Error: Division by zero is not allowed.\n");
    }
}

void power(double base, double exponent) {
    double result = 1.0;
    for (int i = 0; i < (int)exponent; i++) {
        result *= base;
    }
    printf("Result: %.2f ^ %.2f = %.2f\n", base, exponent, result);
}

void modulus(int a, int b) {
    if (b != 0) {
        printf("Result: %d %% %d = %d\n", a, b, a % b);
    } else {
        printf("Error: Modulus by zero is not allowed.\n");
    }
}

int main() {
    int choice;
    double num1, num2;

    while (1) {
        printf("\nSimple Calculator in C\n");
        printf("1. Add\n");
        printf("2. Subtract\n");
        printf("3. Multiply\n");
        printf("4. Divide\n");
        printf("5. Power\n");
        printf("6. Modulus\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 0) {
            printf("Exiting the calculator. Bye!\n");
            break;
        }

        if (choice >= 1 && choice <= 6) {
            printf("Enter first number: ");
            scanf("%lf", &num1);

            if (choice == 6) {
                int int_num1, int_num2;
                int_num1 = (int)num1;
                printf("Enter second integer number: ");
                scanf("%lf", &num2);
                int_num2 = (int)num2;
                modulus(int_num1, int_num2);
            } else {
                printf("Enter second number: ");
                scanf("%lf", &num2);
                switch (choice) {
                    case 1: add(num1, num2); break;
                    case 2: subtract(num1, num2); break;
                    case 3: multiply(num1, num2); break;
                    case 4: divide(num1, num2); break;
                    case 5: power(num1, num2); break;
                }
            }
        } else {
            printf("Invalid choice! Please select a valid operation.\n");
        }
    }

    return 0;
}