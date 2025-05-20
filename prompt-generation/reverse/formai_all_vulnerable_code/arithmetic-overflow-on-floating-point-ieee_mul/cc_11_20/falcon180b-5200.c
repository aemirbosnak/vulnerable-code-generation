//Falcon-180B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MAX_SIZE 100

int main() {
    char input[MAX_SIZE];
    int i = 0;
    double num1, num2, result;
    char operator;

    printf("Enter the expression: ");
    fgets(input, MAX_SIZE, stdin);

    for (i = 0; input[i]!= '\0'; i++) {
        if (isdigit(input[i]) || input[i] == '.') {
            continue;
        } else if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/') {
            operator = input[i];
        } else {
            printf("Invalid expression\n");
            return 0;
        }
    }

    num1 = atof(input);

    i = 0;
    while (input[i]!= '\0') {
        if (isdigit(input[i]) || input[i] == '.') {
            i++;
        } else if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/') {
            operator = input[i];
            break;
        } else {
            printf("Invalid expression\n");
            return 0;
        }
    }

    num2 = atof(input + i + 1);

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
                printf("Division by zero\n");
                return 0;
            }
            result = num1 / num2;
            break;
        default:
            printf("Invalid operator\n");
            return 0;
    }

    printf("Result: %.2f\n", result);

    return 0;
}