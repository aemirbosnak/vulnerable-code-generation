//FormAI DATASET v1.0 Category: Scientific ; Style: imaginative
#include <stdio.h>

int main() {
    // Let's imagine we are creating a scientific calculator for students
    printf("Welcome to the SciCal - the ultimate scientific calculator for students!\n");

    float num1, num2, result;
    char operator;

    // First, let's take input from the user - two numbers and an operator
    printf("Enter the first number: ");
    scanf("%f", &num1);

    printf("Enter the operator (+, -, *, /): ");
    scanf("%s", &operator);

    printf("Enter the second number: ");
    scanf("%f", &num2);

    // Now, let's perform the calculation based on the operator
    switch (operator) {
        case '+':
            result = num1 + num2;
            printf("%.2f %c %.2f = %.2f\n", num1, operator, num2, result);
            break;
        case '-':
            result = num1 - num2;
            printf("%.2f %c %.2f = %.2f\n", num1, operator, num2, result);
            break;
        case '*':
            result = num1 * num2;
            printf("%.2f %c %.2f = %.2f\n", num1, operator, num2, result);
            break;
        case '/':
            if (num2 == 0) {
                printf("Error: division by zero\n");
            } else {
                result = num1 / num2;
                printf("%.2f %c %.2f = %.2f\n", num1, operator, num2, result);
            }
            break;
        default:
            printf("Error: invalid operator\n");
    }

    // Now, let's add some scientific calculations
    printf("Here are some scientific calculations you can do with SciCal:\n");

    int choice;
    float base, exponent;

    do {
        printf("Choose a calculation:\n");
        printf("1. Square root\n");
        printf("2. Power\n");
        printf("3. Exit scientific calculations\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a number: ");
                scanf("%f", &num1);
                result = sqrt(num1);
                printf("The square root of %.2f is %.2f\n", num1, result);
                break;
            case 2:
                printf("Enter a base: ");
                scanf("%f", &base);
                printf("Enter an exponent: ");
                scanf("%f", &exponent);
                result = powf(base, exponent);
                printf("%.2f to the power of %.2f is %.2f\n", base, exponent, result);
                break;
            case 3:
                printf("Exiting scientific calculations...\n");
                break;
            default:
                printf("Error: invalid choice\n");
        }
    } while (choice != 3);

    // Thank the user and exit the program
    printf("Thank you for using SciCal - the ultimate scientific calculator for students!\n");
    return 0;
}