//GPT-4o-mini DATASET v1.0 Category: Syntax parsing ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_LENGTH 100

typedef struct {
    char operation;
    int leftOperand;
    int rightOperand;
} expression_t;

void parseExpression(const char *input, expression_t *expr) {
    char operator;
    int left, right;

    sscanf(input, "%d %c %d", &left, &operator, &right);

    expr->leftOperand = left;
    expr->operation = operator;
    expr->rightOperand = right;
}

int calculate(const expression_t *expr) {
    int result = 0;
    switch (expr->operation) {
        case '+':
            result = expr->leftOperand + expr->rightOperand;
            break;
        case '-':
            result = expr->leftOperand - expr->rightOperand;
            break;
        case '*':
            result = expr->leftOperand * expr->rightOperand;
            break;
        case '/':
            if (expr->rightOperand == 0) {
                fprintf(stderr, "Error: Division by zero.\n");
                exit(EXIT_FAILURE);
            }
            result = expr->leftOperand / expr->rightOperand;
            break;
        default:
            fprintf(stderr, "Error: Unsupported operation '%c'.\n", expr->operation);
            exit(EXIT_FAILURE);
    }
    return result;
}

int main() {
    char input[MAX_LENGTH];
    expression_t expr;

    printf("Enter your expression (e.g. 4 + 5): ");
    fgets(input, sizeof(input), stdin);
    
    // Remove newline character from input
    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }

    parseExpression(input, &expr);

    int result = calculate(&expr);

    printf("Result: %d %c %d = %d\n", expr.leftOperand, expr.operation, expr.rightOperand, result);

    return 0;
}