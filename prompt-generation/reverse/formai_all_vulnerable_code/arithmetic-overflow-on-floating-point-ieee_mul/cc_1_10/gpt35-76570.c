//FormAI DATASET v1.0 Category: Syntax parsing ; Style: mind-bending
#include <stdio.h>

// Define a custom struct for operators
typedef struct Operator {
    char symbol;
    int precedence;
    int associativity;
} Operator;

// Define the operators and their properties
Operator ops[] = {
    {'+', 1, 0},
    {'-', 1, 0},
    {'*', 2, 0},
    {'/', 2, 0},
    {'^', 3, 1}
};

int isOperator(char c) {
    for (int i = 0; i < sizeof(ops)/sizeof(Operator); i++) {
        if (ops[i].symbol == c) {
            return 1;
        }
    }
    return 0;
}

Operator getOperator(char c) {
    for (int i = 0; i < sizeof(ops)/sizeof(Operator); i++) {
        if (ops[i].symbol == c) {
            return ops[i];
        }
    }
    // If no operator is found, return an empty operator
    Operator empty = {'\0', 0, 0};
    return empty;
}

int shouldDoFirst(char c1, char c2) {
    Operator op1 = getOperator(c1);
    Operator op2 = getOperator(c2);

    // If operators are of equal precedence and left associative, do first operation
    if (op1.precedence == op2.precedence && op1.associativity == 0) {
        return 1;
    }
    // If first operator has higher precedence, do first operation
    else if (op1.precedence > op2.precedence) {
        return 1;
    }
    // If the second operator has higher precedence or the operators are of equal precedence and right associative, do second operation
    else {
        return 0;
    }
}

double parseExpression(char* expression, int start, int end) {
    double total = 0;
    char lastOperator = '\0';

    for (int i = start; i < end; i++) {
        char c = expression[i];

        if (isdigit(c)) {
            // Convert digit to number and add to total
            double num = c - '0';
            total = total * 10 + num;
        }
        else if (isOperator(c)) {
            if (lastOperator != '\0' && shouldDoFirst(lastOperator, c)) {
                // If last operator should be done first, parse the rest of the expression and perform the operation
                double next = parseExpression(expression, i, end);
                Operator op = getOperator(lastOperator);
                if (op.symbol == '+') {
                    total += next;
                }
                else if (op.symbol == '-') {
                    total -= next;
                }
                else if (op.symbol == '*') {
                    total *= next;
                }
                else if (op.symbol == '/') {
                    total /= next;
                }
                else if (op.symbol == '^') {
                    total = pow(total, next);
                }
                return total;
            }
            else {
                // Set last operator and continue parsing
                lastOperator = c;
            }
        }
    }

    // If reached end of expression, return total
    return total;
}

int main() {
    char expression[] = "2+3*4^2-5/2";

    double result = parseExpression(expression, 0, sizeof(expression)/sizeof(char));
    printf("Result: %f\n", result);

    return 0;
}