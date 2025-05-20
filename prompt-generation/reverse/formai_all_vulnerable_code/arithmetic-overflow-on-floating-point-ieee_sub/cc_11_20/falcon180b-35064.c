//Falcon-180B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: Cryptic
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 100

int main() {
    char input[MAX_LEN];
    int i = 0, j, is_operator, is_number;
    double num1, num2, result = 0;
    char operator;

    printf("Enter expression: ");
    fgets(input, MAX_LEN, stdin);

    for (j = 0; input[j]!= '\0'; j++) {
        if (isalnum(input[j])) {
            if (is_number) {
                result = result * (input[j] - '0');
            } else {
                num1 = num1 * 10 + (input[j] - '0');
            }
            is_number = 1;
        } else {
            switch (input[j]) {
                case '+':
                case '-':
                case '*':
                case '/':
                    is_operator = 1;
                    break;
                default:
                    printf("Invalid character found!\n");
                    return 0;
            }
        }
    }

    if (is_operator) {
        num2 = num1;
        num1 = result;
        result = 0;
    }

    switch (operator) {
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
            if (num2 == 0) {
                printf("Division by zero is not allowed!\n");
                return 0;
            }
            result = num1 / num2;
            break;
    }

    printf("Result: %lf\n", result);

    return 0;
}