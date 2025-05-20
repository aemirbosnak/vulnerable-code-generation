//Falcon-180B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    double num1, num2, result;
    char operator;

    //initialize variables
    num1 = 0;
    num2 = 0;
    result = 0;

    //prompt user for input
    printf("Welcome to the Scientific Calculator!\n");
    printf("Enter the first number: ");
    scanf("%lf", &num1);
    printf("Enter the second number: ");
    scanf("%lf", &num2);

    //prompt user for operation
    printf("Enter the operation (+, -, *, /): ");
    scanf(" %c", &operator);

    //perform operation based on user input
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
                printf("Error: Division by zero is not allowed.\n");
                exit(1);
            }
            else {
                result = num1 / num2;
            }
            break;
        default:
            printf("Error: Invalid operation.\n");
            exit(1);
    }

    //display result
    printf("The result is: %lf\n", result);

    return 0;
}