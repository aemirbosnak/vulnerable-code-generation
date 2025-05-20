//FormAI DATASET v1.0 Category: Arithmetic ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_INPUT_SIZE 100

double get_operand(char *input, int *i) {
    int j = *i;
    int decimal = 0;
    double result = 0;
    int divisor = 1;
    int negative = 1;

    if (input[j] == '-') {
        negative = -1;
        j++;
    }

    while (isdigit(input[j]) || input[j] == '.') {
        if (input[j] == '.') {
            decimal = 1;
        } else if (decimal) {
            divisor *= 10;
            result += (input[j] - '0') / (double) divisor;
        } else {
            result = result * 10 + input[j] - '0';
        }

        j++;
    }

    *i = j;
    return result * negative;
}

int main() {
    char input[MAX_INPUT_SIZE];
    double operands[MAX_INPUT_SIZE];
    char operators[MAX_INPUT_SIZE];
    int operand_count = 0;
    int operator_count = 0;
    int i = 0;

    printf("Enter an arithmetic expression: ");
    fgets(input, MAX_INPUT_SIZE, stdin);

    while (input[i] != '\0') {
        if (isspace(input[i])) {
            i++;
        } else if (isdigit(input[i]) || input[i] == '-') {
            operands[operand_count] = get_operand(input, &i);
            operand_count++;
        } else if (strchr("+-*/%", input[i])) {
            operators[operator_count] = input[i];
            operator_count++;
            i++;
        } else {
            printf("Invalid character in input: %c\n", input[i]);
            exit(EXIT_FAILURE);
        }
    }

    double result = operands[0];

    for (int j = 0; j < operator_count; j++) {
        switch (operators[j]) {
            case '+':
                result += operands[j + 1];
                break;
            case '-':
                result -= operands[j + 1];
                break;
            case '*':
                result *= operands[j + 1];
                break;
            case '/':
                result /= operands[j + 1];
                break;
            case '%':
                result = fmod(result, operands[j + 1]);
                break;
            default:
                break;
        }
    }

    printf("Result: %g\n", result);

    return 0;
}