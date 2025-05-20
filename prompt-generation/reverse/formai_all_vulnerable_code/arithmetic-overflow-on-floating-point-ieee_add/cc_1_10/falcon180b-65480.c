//Falcon-180B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_LEN 100

char input[MAX_LEN];
char *token = NULL;
double num1, num2, result;
char operator;

int get_operator_precedence(char op);
double perform_operation(char op, double num1, double num2);

int main() {
    printf("Enter an expression in infix notation (e.g., 2 + 3 * 4): ");
    fgets(input, MAX_LEN, stdin);

    token = strtok(input, " ");
    while (token!= NULL) {
        if (isdigit(token[0])) {
            num1 = atof(token);
        } else {
            operator = token[0];
            num2 = atof(token + 1);
            result = perform_operation(operator, num1, num2);
            num1 = result;
        }
        token = strtok(NULL, " ");
    }

    printf("Result: %lf\n", num1);

    return 0;
}

int get_operator_precedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return -1;
    }
}

double perform_operation(char op, double num1, double num2) {
    switch (op) {
        case '+':
            return num1 + num2;
        case '-':
            return num1 - num2;
        case '*':
            return num1 * num2;
        case '/':
            if (num2 == 0) {
                printf("Error: Division by zero\n");
                exit(1);
            }
            return num1 / num2;
        default:
            printf("Error: Invalid operator\n");
            exit(1);
    }
}