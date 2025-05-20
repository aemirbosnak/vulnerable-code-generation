//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to calculate the factorial of a given integer
int factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

// Function to calculate the value of a given expression
int evaluate(char *expression) {
    int num1, num2, res;
    char op;

    // Parse the expression and extract the operands and operator
    sscanf(expression, "%d%c%d", &num1, &op, &num2);

    // Perform the operation
    switch (op) {
        case '+':
            res = num1 + num2;
            break;
        case '-':
            res = num1 - num2;
            break;
        case '*':
            res = num1 * num2;
            break;
        case '/':
            res = num1 / num2;
            break;
        default:
            res = -1;
            break;
    }

    return res;
}

int main() {
    int num1, num2, res;
    char expression[100];

    // Get the first operand from the user
    printf("Enter the first operand: ");
    scanf("%d", &num1);

    // Get the second operand from the user
    printf("Enter the second operand: ");
    scanf("%d", &num2);

    // Get the expression from the user
    printf("Enter the expression: ");
    fgets(expression, 100, stdin);

    // Evaluate the expression
    res = evaluate(expression);

    // Print the result
    printf("Result: %d\n", res);

    return 0;
}