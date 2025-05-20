//FormAI DATASET v1.0 Category: Syntax parsing ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 100

int main() {
    char expression[MAX_LENGTH];
    printf("Enter an arithmetic expression:\n");
    fgets(expression, MAX_LENGTH, stdin);
    
    // Parsing the expression
    char operator;
    int operand1, operand2, i = 0;
    while(expression[i] != '\n') {
        if(expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/') {
            operator = expression[i];
        } else if(expression[i] >= '0' && expression[i] <= '9') {
            if(operand1 == 0) {
                operand1 = expression[i] - '0';
            } else {
                operand2 = expression[i] - '0';
            }
        }
        i++;
    }
    
    // Calculating the result
    int result;
    switch(operator) {
        case '+':
            result = operand1 + operand2;
            break;
        case '-':
            result = operand1 - operand2;
            break;
        case '*':
            result = operand1 * operand2;
            break;
        case '/':
            result = operand1 / operand2;
            break;
        default:
            printf("Invalid operator!");
            exit(0);
    }
    
    // Printing the result
    printf("Result: %d", result);
    
    return 0;
}