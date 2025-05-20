//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_OPERands 10
#define MAX_EXPR_LENGTH 100

// Global variables
int num1 = 0, num2 = 0, res = 0;
char op[MAX_OPERands][20] = {"+"};
char expr[MAX_EXPR_LENGTH][20] = {""};

// Function to get input from user
void getInput() {
    printf("Enter the first number: ");
    scanf("%d", &num1);
    printf("Enter the second number: ");
    scanf("%d", &num2);
    printf("Enter the operation (+, -, *, /): ");
    scanf("%s", op);
    printf("Enter the expression (e.g. 2+3): ");
    scanf("%s", expr);
}

// Function to evaluate the expression
int evaluate() {
    int i, j;
    int sum = 0;

    // Parse the expression
    for (i = 0; i < strlen(expr); i++) {
        if (expr[i] == '+') {
            // Add the numbers
            for (j = 0; j < strlen(op); j++) {
                if (op[j] == '+') {
                    sum += atoi(expr[i + j + 1]) * atoi(expr[i + j + 2]);
                } else {
                    sum += atoi(expr[i + j + 1]);
                }
            }
        } else if (expr[i] == '-') {
            // Subtract the numbers
            for (j = 0; j < strlen(op); j++) {
                if (op[j] == '-') {
                    sum -= atoi(expr[i + j + 1]) * atoi(expr[i + j + 2]);
                } else {
                    sum -= atoi(expr[i + j + 1]);
                }
            }
        } else if (expr[i] == '*') {
            // Multiply the numbers
            for (j = 0; j < strlen(op); j++) {
                if (op[j] == '*') {
                    sum *= atoi(expr[i + j + 1]) * atoi(expr[i + j + 2]);
                } else {
                    sum *= atoi(expr[i + j + 1]);
                }
            }
        } else if (expr[i] == '/') {
            // Divide the numbers
            for (j = 0; j < strlen(op); j++) {
                if (op[j] == '/') {
                    sum /= atoi(expr[i + j + 1]) * atoi(expr[i + j + 2]);
                } else {
                    sum /= atoi(expr[i + j + 1]);
                }
            }
        }
    }
    return sum;
}

int main() {
    srand(time(NULL));

    do {
        // Display the menu
        printf("Welcome to the Arithmetic Game!\n");
        printf("Choose an operation (+, -, *, /)\n");
        printf("Enter the first number: ");
        getInput();
        printf("Enter the second number: ");
        getInput();
        printf("Enter the expression (e.g. 2+3): ");
        getInput();

        // Evaluate the expression
        int result = evaluate();

        // Display the result
        printf("Result: %d\n", result);

    } while (1);

    return 0;
}