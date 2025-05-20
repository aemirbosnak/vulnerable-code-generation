//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

int main() {
    int n, m, k;
    double x, y, z;
    char operation;

    // Prompt user for input
    printf("Enter the number of arithmetic operations to perform: ");
    scanf("%d", &n);

    // Perform arithmetic operations
    for (int i = 0; i < n; i++) {
        printf("Enter the arithmetic operation (+, -, *, /): ");
        scanf(" %c", &operation);

        printf("Enter the first number: ");
        if (scanf("%lf", &x)!= 1) {
            printf("Invalid input. Exiting program.\n");
            return 1;
        }

        printf("Enter the second number: ");
        if (scanf("%lf", &y)!= 1) {
            printf("Invalid input. Exiting program.\n");
            return 1;
        }

        switch (operation) {
            case '+':
                z = x + y;
                break;
            case '-':
                z = x - y;
                break;
            case '*':
                z = x * y;
                break;
            case '/':
                if (y == 0) {
                    printf("Division by zero is not allowed.\n");
                    exit(1);
                }
                z = x / y;
                break;
            default:
                printf("Invalid operation. Exiting program.\n");
                exit(1);
        }

        printf("The result is: %.0lf\n", z);
    }

    return 0;
}