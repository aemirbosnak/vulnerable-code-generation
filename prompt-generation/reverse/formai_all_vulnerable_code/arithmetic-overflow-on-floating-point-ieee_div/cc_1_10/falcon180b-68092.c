//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int i, j;
    float x, y, result;
    char operation;

    // Get user input for number of calculations
    printf("Enter the number of calculations: ");
    scanf("%d", &i);

    // Loop through the number of calculations
    for (j = 0; j < i; j++) {
        // Get user input for two numbers and an operation
        printf("Enter the first number: ");
        scanf("%f", &x);
        printf("Enter the second number: ");
        scanf("%f", &y);
        printf("Enter the operation (+, -, *, /): ");
        scanf(" %c", &operation);

        // Perform the selected operation
        switch (operation) {
            case '+':
                result = x + y;
                break;
            case '-':
                result = x - y;
                break;
            case '*':
                result = x * y;
                break;
            case '/':
                if (y == 0) {
                    printf("Error: Division by zero is not allowed.\n");
                    exit(1);
                }
                result = x / y;
                break;
            default:
                printf("Error: Invalid operation.\n");
                exit(1);
        }

        // Display the result
        printf("The result is: %.2f\n", result);
    }

    return 0;
}