//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the main function
int main() {
    char operator;
    double num1, num2, result;

    printf("Welcome to Alan Turing's Scientific Calculator!\n\n");

    while(1) {
        printf("Enter an operator (+, -, *, /, sqrt): ");
        scanf("%c", &operator);

        if (operator == 'q') {
            printf("Bye!\n");
            exit(0);
        }

        printf("Enter two operands: ");
        scanf("%lf %lf", &num1, &num2);

        switch(operator) {
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
                if(num2 == 0) {
                    printf("Error: division by zero\n\n");
                    continue;
                }
                result = num1 / num2;
                break;

            case 's':
                if(num1 < 0) {
                    printf("Error: square root of negative number\n\n");
                    continue;
                }
                result = sqrt(num1);
                break;

            default:
                printf("Error: Invalid operator\n\n");
                continue;
        }

        printf("The result of %.2lf %c %.2lf is: %.2lf\n\n", num1, operator, num2, result);

        // Clear input buffer
        while ((getchar()) != '\n');
    }

    return 0;
}