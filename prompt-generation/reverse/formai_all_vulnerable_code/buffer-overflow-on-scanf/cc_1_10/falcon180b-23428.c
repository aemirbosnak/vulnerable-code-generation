//Falcon-180B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    double num1, num2;
    char operator;

    // Initializing the variables
    num1 = 0;
    num2 = 0;
    operator = '\0';

    // Loop to continue until user wants to exit
    while (1) {
        // Clear the screen
        system("clear");

        // Display the current state
        printf("Num1: %lf\nNum2: %lf\nOperator: %c\n", num1, num2, operator);

        // Get user input
        printf("Enter a number or operator: ");
        scanf("%lf%c", &num2, &operator);

        // Check if an operator is entered
        if (operator!= '\0') {
            // Perform the operation
            switch(operator) {
                case '+':
                    num1 += num2;
                    break;
                case '-':
                    num1 -= num2;
                    break;
                case '*':
                    num1 *= num2;
                    break;
                case '/':
                    if (num2 == 0) {
                        printf("Error: Division by zero is not allowed.\n");
                    } else {
                        num1 /= num2;
                    }
                    break;
                case '^':
                    num1 = pow(num1, num2);
                    break;
                default:
                    printf("Invalid operator entered.\n");
                    break;
            }
        } else {
            // Store the number in num1
            num1 = num2;
        }
    }

    return 0;
}