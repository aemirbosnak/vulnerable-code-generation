//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main() {
    srand(time(NULL));
    int num1, num2, operation;
    double result;
    char repeat;

    // Loop until user decides to quit
    while (1) {
        printf("Enter two numbers separated by space: ");
        scanf("%d %d", &num1, &num2);
        printf("Enter operation (+, -, *, /): ");
        scanf(" %c", &operation);

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
                    printf("Error: Division by zero is not allowed.\n");
                    continue;
                }
                result = (double)num1 / num2;
                break;
            default:
                printf("Error: Invalid operation.\n");
                continue;
        }

        printf("Result: %.2f\n", result);
        printf("Do you want to continue? (y/n): ");
        scanf(" %c", &repeat);

        if (repeat == 'n') {
            break;
        }
    }

    return 0;
}