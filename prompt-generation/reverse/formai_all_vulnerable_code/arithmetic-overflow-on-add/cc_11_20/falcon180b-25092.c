//Falcon-180B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LENGTH 100

int main() {
    char input[MAX_LENGTH];
    char operation = '\0';
    int num1, num2, result;
    double decimal_num1, decimal_num2, decimal_result;
    int i, j, k;
    int is_decimal = 0;

    printf("Welcome to the Cheerful Scientific Calculator!\n");
    printf("Enter your expression (up to %d characters): ", MAX_LENGTH);
    fgets(input, MAX_LENGTH, stdin);

    // Remove trailing newline character
    input[strcspn(input, "\n")] = '\0';

    // Evaluate expression
    for (i = 0; input[i]!= '\0'; i++) {
        if (isdigit(input[i])) {
            if (is_decimal) {
                decimal_num1 = decimal_num1 * 10 + input[i] - '0';
            } else {
                num1 = num1 * 10 + input[i] - '0';
            }
        } else if (input[i] == '.') {
            is_decimal = 1;
        } else {
            switch (input[i]) {
                case '+':
                    operation = '+';
                    break;
                case '-':
                    operation = '-';
                    break;
                case '*':
                    operation = '*';
                    break;
                case '/':
                    operation = '/';
                    break;
            }
        }
    }

    // Perform operation
    if (operation!= '\0') {
        num2 = num1;
        for (i = 0; input[i]!= '\0'; i++) {
            if (isdigit(input[i])) {
                if (is_decimal) {
                    decimal_num2 = decimal_num2 * 10 + input[i] - '0';
                } else {
                    num2 = num2 * 10 + input[i] - '0';
                }
            } else if (input[i] == '.') {
                is_decimal = 1;
            }
        }

        switch (operation) {
            case '+':
                result = num1 + num2;
                break;
            case '-':
                result = num1 - num2;
                break;
            case '*':
                result = num1 * num2;
                break;
            case '/':
                result = num1 / num2;
                break;
        }

        if (is_decimal) {
            printf("Result: %.2f\n", (double)result / 100);
        } else {
            printf("Result: %d\n", result);
        }
    } else {
        printf("Invalid expression.\n");
    }

    return 0;
}