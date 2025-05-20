//Falcon-180B DATASET v1.0 Category: Error handling ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int n, result;
    double x, y, z;
    char operation;

    // Input validation loop
    while (1) {
        printf("Enter an integer: ");
        if (scanf("%d", &n)!= 1) {
            printf("Invalid input. Please enter an integer.\n");
            fflush(stdin);
            continue;
        }
        break;
    }

    // Calculation loop
    while (1) {
        printf("Enter an operation (+, -, *, /): ");
        scanf(" %c", &operation);

        switch (operation) {
            case '+':
                printf("Enter two numbers: ");
                if (scanf("%lf %lf", &x, &y)!= 2) {
                    printf("Invalid input. Please enter two numbers.\n");
                    fflush(stdin);
                    continue;
                }
                z = x + y;
                printf("Result: %lf\n", z);
                break;
            case '-':
                printf("Enter two numbers: ");
                if (scanf("%lf %lf", &x, &y)!= 2) {
                    printf("Invalid input. Please enter two numbers.\n");
                    fflush(stdin);
                    continue;
                }
                z = x - y;
                printf("Result: %lf\n", z);
                break;
            case '*':
                printf("Enter two numbers: ");
                if (scanf("%lf %lf", &x, &y)!= 2) {
                    printf("Invalid input. Please enter two numbers.\n");
                    fflush(stdin);
                    continue;
                }
                z = x * y;
                printf("Result: %lf\n", z);
                break;
            case '/':
                printf("Enter two numbers: ");
                if (scanf("%lf %lf", &x, &y)!= 2 || y == 0) {
                    printf("Invalid input. Please enter two non-zero numbers.\n");
                    fflush(stdin);
                    continue;
                }
                z = x / y;
                printf("Result: %lf\n", z);
                break;
            default:
                printf("Invalid operation. Please enter a valid operation.\n");
        }
    }

    return 0;
}