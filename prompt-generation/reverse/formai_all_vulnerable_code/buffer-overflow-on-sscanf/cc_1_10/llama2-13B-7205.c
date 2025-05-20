//LLAMA2-13B DATASET v1.0 Category: Math exercise ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NUM 100
#define MAX_OPER 5

typedef struct {
    char op[2];   // operator (e.g. +, -, *, /)
    double num1, num2; // numbers being operated
} expression;

// Function to parse input string and create an expression struct
expression parse_expression(char *str) {
    expression exp;

    // Tokenize the input string
    char *token = strtok(str, " ");
    while (token != NULL && strcmp(token, "") != 0) {
        // Check if the token is a number
        if (sscanf(token, "%lf", &exp.num1) == 1) {
            exp.op[0] = '+';
        } else if (sscanf(token, "%lf", &exp.num2) == 1) {
            exp.op[0] = '-';
        } else if (strcmp(token, "+") == 0) {
            exp.op[0] = '+';
        } else if (strcmp(token, "-") == 0) {
            exp.op[0] = '-';
        } else if (strcmp(token, "*") == 0) {
            exp.op[0] = '*';
        } else if (strcmp(token, "/") == 0) {
            exp.op[0] = '/';
        } else {
            printf("Invalid token: %s\n", token);
            return exp; // return an invalid expression
        }
        token = strtok(NULL, " ");
    }

    return exp;
}

// Function to evaluate an expression
double evaluate(expression exp) {
    double result = 0;

    // Evaluate the expression based on the operator and numbers
    if (exp.op[0] == '+') {
        result = exp.num1 + exp.num2;
    } else if (exp.op[0] == '-') {
        result = exp.num1 - exp.num2;
    } else if (exp.op[0] == '*') {
        result = exp.num1 * exp.num2;
    } else if (exp.op[0] == '/') {
        result = exp.num1 / exp.num2;
    } else {
        printf("Invalid expression: %c %lf %lf\n", exp.op[0], exp.num1, exp.num2);
        return 0; // return an invalid result
    }

    return result;
}

int main() {
    // Create a list of expressions to evaluate
    char *expressions[] = {
        "+ 2 3",
        "- 4 5",
        "3 * 2",
        "5 / 2",
        "2 + 2",
        "2 - 2",
        "2 * 3",
        "2 / 3"
    };

    // Create a list of results to store the evaluation results
    double results[] = {
        -1,
        -1,
        6,
        2.5,
        4,
        0,
        6,
        0.67
    };

    // Loop through the list of expressions and evaluate each one
    for (int i = 0; i < sizeof(expressions) / sizeof(char *); i++) {
        expression exp = parse_expression(expressions[i]);
        results[i] = evaluate(exp);
    }

    // Print the results
    for (int i = 0; i < sizeof(results) / sizeof(double); i++) {
        printf("%d. %s = %lf\n", i + 1, expressions[i], results[i]);
    }

    return 0;
}