//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PI 3.14159

int main() {
    char operator;
    float num1, num2, result;
    int choice;

    system("clear");
    printf("Welcome to the Scientific Calculator!\n");

    // Menu options
    printf("1. Basic Calculator\n");
    printf("2. Trigonometric Functions\n");
    printf("3. Logarithmic Functions\n");
    printf("Please select an option: ");

    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter two numbers: ");
            scanf("%f %f", &num1, &num2);

            printf("Enter an operator (+, -, *, /): ");
            scanf(" %c", &operator);

            switch (operator) {
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
                        printf("Cannot divide by zero.\n");
                    } else {
                        result = num1 / num2;
                    }
                    break;
                default:
                    printf("Invalid operator.\n");
            }

            printf("The result is: %.2f\n", result);
            break;
        case 2:
            // Implement trigonometric functions
            break;
        case 3:
            // Implement logarithmic functions
            break;
        default:
            printf("Invalid choice.\n");
    }

    system("pause");
    return 0;
}