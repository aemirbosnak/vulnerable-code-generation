//Falcon-180B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_SIZE 100

// Function to perform basic arithmetic operations
int performOperation(char operation, double num1, double num2) {
    switch(operation) {
        case '+':
            return num1 + num2;
        case '-':
            return num1 - num2;
        case '*':
            return num1 * num2;
        case '/':
            if(num2 == 0) {
                printf("Error: Division by zero\n");
                exit(1);
            }
            return num1 / num2;
        default:
            printf("Error: Invalid operation\n");
            exit(1);
    }
}

// Function to evaluate a mathematical expression
double evaluateExpression(char *expression) {
    char *token = strtok(expression, " ");
    double num1 = atof(token);
    char operation = token[strcspn(token, "+-*/")] ;

    while((token = strtok(NULL, " "))!= NULL) {
        double num2 = atof(token);
        num1 = performOperation(operation, num1, num2);
    }

    return num1;
}

// Function to print the result
void printResult(double result) {
    printf("Result: %.2f\n", result);
}

// Main function
int main() {
    char input[MAX_INPUT_SIZE];
    printf("Enter the expression: ");
    fgets(input, MAX_INPUT_SIZE, stdin);

    double result = evaluateExpression(input);
    printResult(result);

    return 0;
}