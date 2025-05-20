//Falcon-180B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

int main() {
    double num1, num2, result;
    char operation;

    // Initialize variables
    num1 = 0;
    num2 = 0;
    result = 0;

    // Main loop
    while (1) {
        // Print menu
        printf("SURREALIST SCIENTIFIC CALCULATOR\n");
        printf("Enter an operation (+, -, *, /, sin, cos, tan, sqrt, log, exp, pow): ");
        scanf("%c", &operation);

        // Input numbers
        if (operation!='s' && operation!= 'c' && operation!= 't' && operation!= 'q' && operation!= 'e' && operation!= 'p') {
            printf("Enter first number: ");
            scanf("%lf", &num1);
        }
        if (operation!='s' && operation!= 'c' && operation!= 't' && operation!= 'q' && operation!= 'p') {
            printf("Enter second number: ");
            scanf("%lf", &num2);
        }

        // Perform operation
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
                } else {
                    result = num1 / num2;
                }
                break;
            case's':
                result = sin(num1);
                break;
            case 'c':
                result = cos(num1);
                break;
            case 't':
                result = tan(num1);
                break;
            case 'q':
                result = sqrt(num1);
                break;
            case 'e':
                result = exp(num1);
                break;
            case 'p':
                if (num2 == 0) {
                    printf("Error: Raising to the power of zero is not allowed.\n");
                } else {
                    result = pow(num1, num2);
                }
                break;
            default:
                printf("Invalid operation.\n");
        }

        // Print result
        printf("Result: %.4lf\n", result);
    }

    return 0;
}