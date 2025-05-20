//Falcon-180B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: post-apocalyptic
#include <stdio.h>

// Define the main calculator function
int calculator(double num1, char operation, double num2) {
    double result = 0;
    switch (operation) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            if (num2 == 0) {
                printf("Error: Division by zero\n");
                return 1;
            }
            result = num1 / num2;
            break;
        default:
            printf("Invalid operation\n");
            return 1;
    }
    printf("Result: %.2f\n", result);
    return 0;
}

int main() {
    char operation;
    double num1, num2;

    // Post-apocalyptic intro
    printf("Welcome to the Wasteland Calculator\n");
    printf("In this desolate world, only the strong survive\n");
    printf("And the strong know how to do math\n\n");

    // Main calculator loop
    while (1) {
        printf("Enter first number: ");
        scanf("%lf", &num1);

        printf("Enter operation (+, -, *, /): ");
        scanf(" %c", &operation);

        printf("Enter second number: ");
        scanf("%lf", &num2);

        calculator(num1, operation, num2);

        printf("\nDo you want to continue? (y/n): ");
        char choice;
        scanf(" %c", &choice);
        if (choice == 'n') {
            break;
        }
    }

    return 0;
}