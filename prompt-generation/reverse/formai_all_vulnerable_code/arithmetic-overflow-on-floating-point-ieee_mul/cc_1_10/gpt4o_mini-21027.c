//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: enthusiastic
#include <stdio.h>

void display_menu() {
    printf("\n========================================\n");
    printf("           Mini Calculator Adventure     \n");
    printf("========================================\n");
    printf("Choose an action to embark on your journey:\n");
    printf("1. Add\n");
    printf("2. Subtract\n");
    printf("3. Multiply\n");
    printf("4. Divide\n");
    printf("5. Remainder\n");
    printf("6. Power\n");
    printf("7. Exit Adventure\n");
    printf("========================================\n");
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
    if (b != 0) {
        return a / b;
    } else {
        printf("Oh no! Division by zero is not allowed!\n");
        return 0;
    }
}

int remainder(int a, int b) {
    if (b != 0) {
        return a % b;
    } else {
        printf("Oh no! Remainder by zero is not valid!\n");
        return 0;
    }
}

double power(double base, int exponent) {
    double result = 1.0;
    for (int i = 0; i < exponent; i++) {
        result *= base;
    }
    return result;
}

int main() {
    int choice;
    double num1, num2;
    printf("Welcome to the Mini Calculator Adventure!\n");

    while (1) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 7) {
            printf("Thank you for taking this mathematical journey with us!\n");
            break;
        }

        if (choice < 1 || choice > 7) {
            printf("Invalid choice! Please try again.\n");
            continue;
        }

        printf("Enter the first number: ");
        scanf("%lf", &num1);

        if (choice == 6) {
            int exponent;
            printf("Enter the exponent: ");
            scanf("%d", &exponent);
            double result = power(num1, exponent);
            printf("The result of %.2f raised to the power of %d is %.2f\n", num1, exponent, result);
        } else {
            printf("Enter the second number: ");
            scanf("%lf", &num2);
            double result;

            switch (choice) {
                case 1:
                    result = add(num1, num2);
                    printf("The sum of %.2f and %.2f is %.2f\n", num1, num2, result);
                    break;
                case 2:
                    result = subtract(num1, num2);
                    printf("The difference of %.2f and %.2f is %.2f\n", num1, num2, result);
                    break;
                case 3:
                    result = multiply(num1, num2);
                    printf("The product of %.2f and %.2f is %.2f\n", num1, num2, result);
                    break;
                case 4:
                    result = divide(num1, num2);
                    if (num2 != 0)
                        printf("The quotient of %.2f divided by %.2f is %.2f\n", num1, num2, result);
                    break;
                case 5:
                    if (num1 == (int)num1 && num2 == (int)num2) {
                        int intNum1 = (int)num1;
                        int intNum2 = (int)num2;
                        int rem = remainder(intNum1, intNum2);
                        printf("The remainder of %d divided by %d is %d\n", intNum1, intNum2, rem);
                    } else {
                        printf("Remainder operation is only valid for integers!\n");
                    }
                    break;
            }
        }
    }
    return 0;
}