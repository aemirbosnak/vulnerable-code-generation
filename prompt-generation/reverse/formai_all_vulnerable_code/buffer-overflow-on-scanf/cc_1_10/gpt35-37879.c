//FormAI DATASET v1.0 Category: Syntax parsing ; Style: scientific
#include <stdio.h>

/* This program demonstrates the parsing of C syntax using a recursive descent approach */

char input[100];
int position = 0;

int expression();

int factor() {
    if (input[position] >= '0' && input[position] <= '9') {
        int num = input[position] - '0';
        position++;
        return num;
    } else if (input[position] == '(') {
        position++;
        int result = expression();
        if (input[position] == ')') {
            position++;
            return result;
        } else {
            printf("Error: expected ')' at position %d\n", position);
            exit(1);
        }
    } else {
        printf("Error: expected a digit or '(' at position %d\n", position);
        exit(1);
    }
}

int term() {
    int result = factor();
    while (input[position] == '*' || input[position] == '/') {
        if (input[position] == '*') {
            position++;
            result *= factor();
        } else {
            position++;
            int divisor = factor();
            if (divisor == 0) {
                printf("Error: division by zero at position %d\n", position);
                exit(1);
            }
            result /= divisor;
        }
    }
    return result;
}

int expression() {
    int result = term();
    while (input[position] == '+' || input[position] == '-') {
        if (input[position] == '+') {
            position++;
            result += term();
        } else {
            position++;
            result -= term();
        }
    }
    return result;
}

int main() {
    printf("Enter an arithmetic expression: ");
    scanf("%s", input);
    int result = expression();
    if (input[position] != '\0') {
        printf("Error: unexpected symbol at position %d\n", position);
        exit(1);
    }
    printf("Result = %d\n", result);
    return 0;
}