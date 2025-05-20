//FormAI DATASET v1.0 Category: Syntax parsing ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPR_LEN 100

char expr[MAX_EXPR_LEN];
int pos, len;

int parseExpr();
int parseTerm();
int parseFactor();

int main() {
    printf("Enter an arithmetic expression: ");
    fgets(expr, MAX_EXPR_LEN, stdin);
    len = strlen(expr) - 1;
    expr[len] = '\0';
    int result = parseExpr();
    printf("Result: %d\n", result);
    return 0;
}

int parseExpr() {
    int result = parseTerm();
    while (pos < len && (expr[pos] == '+' || expr[pos] == '-')) {
        if (expr[pos] == '+') {
            pos++;
            result += parseTerm();
        } else {
            pos++;
            result -= parseTerm();
        }
    }
    return result;
}

int parseTerm() {
    int result = parseFactor();
    while (pos < len && (expr[pos] == '*' || expr[pos] == '/')) {
        if (expr[pos] == '*') {
            pos++;
            result *= parseFactor();
        } else {
            pos++;
            int factor = parseFactor();
            if (factor == 0) {
                printf("Division by zero error!\n");
                exit(1);
            }
            result /= factor;
        }
    }
    return result;
}

int parseFactor() {
    if (expr[pos] == '(') {
        pos++;
        int result = parseExpr();
        if (expr[pos] != ')') {
            printf("Mismatched parenthesis error!\n");
            exit(1);
        }
        pos++;
        return result;
    } else if (isdigit(expr[pos])) {
        int result = 0;
        while (pos < len && isdigit(expr[pos])) {
            result = result * 10 + (expr[pos] - '0');
            pos++;
        }
        return result;
    } else {
        printf("Syntax error!\n");
        exit(1);
    }
}