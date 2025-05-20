//Falcon-180B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

// Function prototypes
double add(double num1, double num2);
double subtract(double num1, double num2);
double multiply(double num1, double num2);
double divide(double num1, double num2);
double power(double num1, double num2);
double squareRoot(double num);
double absolute(double num);

// Main function
int main() {
    char operation[100];
    double num1, num2, result;

    printf("Welcome to the Scientific Calculator!\n");
    printf("Enter an expression (e.g. 5+3*2) or type 'quit' to exit:\n");

    while (1) {
        scanf("%s", operation);

        // Check if user wants to quit
        if (strcmp(operation, "quit") == 0) {
            break;
        }

        // Split the input string into tokens
        char *token = strtok(operation, " ");
        while (token!= NULL) {
            // Convert each token to a number
            num1 = atof(token);

            // Check for invalid input
            if (isnan(num1)) {
                printf("Invalid input.\n");
                return 1;
            }

            // Perform the operation on the previous result and the current number
            switch (*operation) {
                case '+':
                    result = add(result, num1);
                    break;
                case '-':
                    result = subtract(result, num1);
                    break;
                case '*':
                    result = multiply(result, num1);
                    break;
                case '/':
                    result = divide(result, num1);
                    break;
                case '^':
                    result = power(result, num1);
                    break;
                default:
                    printf("Invalid operation.\n");
                    return 1;
            }

            token = strtok(NULL, " ");
        }
    }

    printf("The result is: %.2f\n", result);

    return 0;
}

// Function definitions
double add(double num1, double num2) {
    return num1 + num2;
}

double subtract(double num1, double num2) {
    return num1 - num2;
}

double multiply(double num1, double num2) {
    return num1 * num2;
}

double divide(double num1, double num2) {
    if (num2 == 0) {
        printf("Cannot divide by zero.\n");
        return 0;
    }
    return num1 / num2;
}

double power(double num1, double num2) {
    return pow(num1, num2);
}

double squareRoot(double num) {
    return sqrt(num);
}

double absolute(double num) {
    return fabs(num);
}