//Falcon-180B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_OPERANDS 10
#define MAX_OPERATORS 5

// Function to perform arithmetic operations
int perform_operation(char *operators, int operands[MAX_OPERANDS]) {
    int result = operands[0];
    for (int i = 1; i < MAX_OPERANDS; i++) {
        switch (operators[i]) {
            case '+':
                result += operands[i];
                break;
            case '-':
                result -= operands[i];
                break;
            case '*':
                result *= operands[i];
                break;
            case '/':
                if (operands[i] == 0) {
                    printf("Error: Division by zero\n");
                    return 0;
                }
                result /= operands[i];
                break;
        }
    }
    return result;
}

// Function to evaluate the expression
int evaluate_expression(char *expression) {
    char *operators = strtok(expression, " ");
    int operands[MAX_OPERANDS];
    int num_operands = 0;

    while (operators!= NULL) {
        if (num_operands >= MAX_OPERANDS) {
            printf("Error: Too many operands\n");
            return 0;
        }
        if (isdigit(operators[0])) {
            operands[num_operands++] = atoi(operators);
        } else if (operators[0] == '(') {
            char *sub_expression = strtok(NULL, " ");
            int sub_result = evaluate_expression(sub_expression);
            if (sub_result == 0) {
                return 0;
            }
            operands[num_operands++] = sub_result;
        } else if (operators[0] == ')') {
            break;
        }
        operators = strtok(NULL, " ");
    }

    if (num_operands < 2) {
        printf("Error: Not enough operands\n");
        return 0;
    }

    int result = perform_operation(operators, operands);
    return result;
}

int main() {
    char expression[100];
    printf("Enter an expression: ");
    scanf("%s", expression);

    int result = evaluate_expression(expression);
    if (result == 0) {
        return 0;
    }

    printf("Result: %d\n", result);
    return 0;
}