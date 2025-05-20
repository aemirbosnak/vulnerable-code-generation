//Falcon-180B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LENGTH 100

int main() {
    char input[MAX_LENGTH];
    double num1, num2;
    char operation;

    printf("Enter an expression in infix notation (e.g., 2 + 3 * 4): ");
    fgets(input, MAX_LENGTH, stdin);

    // Remove newline character from input
    input[strcspn(input, "\n")] = '\0';

    // Tokenize the input string
    char *token = strtok(input, " ");
    while (token!= NULL) {
        if (isdigit(token[0])) {
            num1 = atof(token);
        } else if (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/') {
            operation = token[0];
        }
        token = strtok(NULL, " ");
    }

    num2 = atof(input);

    // Perform the calculation based on the operation
    switch (operation) {
        case '+':
            printf("%.2f + %.2f = %.2f\n", num1, num2, num1 + num2);
            break;
        case '-':
            printf("%.2f - %.2f = %.2f\n", num1, num2, num1 - num2);
            break;
        case '*':
            printf("%.2f * %.2f = %.2f\n", num1, num2, num1 * num2);
            break;
        case '/':
            if (num2 == 0) {
                printf("Error: Division by zero\n");
            } else {
                printf("%.2f / %.2f = %.2f\n", num1, num2, num1 / num2);
            }
            break;
        default:
            printf("Invalid operation\n");
    }

    return 0;
}