//GEMINI-pro DATASET v1.0 Category: Scientific Calculator Implementation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Function to clear the screen
void clrscr() {
    system("cls");
}

// Function to display a message
void display(char *msg) {
    printf("%s", msg);
}

// Function to get a number from the user
double get_number() {
    char num[100];
    scanf("%s", num);
    return atof(num);
}

// Function to perform an operation
double operate(char op, double num1, double num2) {
    switch (op) {
        case '+':
            return num1 + num2;
        case '-':
            return num1 - num2;
        case '*':
            return num1 * num2;
        case '/':
            if (num2 == 0) {
                display("Error: Division by zero is undefined.\n");
                return NAN;
            } else {
                return num1 / num2;
            }
        case '^':
            return pow(num1, num2);
        default:
            display("Error: Invalid operator.\n");
            return NAN;
    }
}

// Function to evaluate a mathematical expression
double evaluate(char *expr) {
    char *tokens[100];
    int num_tokens = 0;
    char *token = strtok(expr, " ");
    while (token != NULL) {
        tokens[num_tokens++] = token;
        token = strtok(NULL, " ");
    }
    if (num_tokens < 3 || num_tokens % 2 == 0) {
        display("Error: Invalid expression.\n");
        return NAN;
    }
    double stack[100];
    int top = -1;
    for (int i = 0; i < num_tokens; i++) {
        if (strcmp(tokens[i], "+") == 0 || strcmp(tokens[i], "-") == 0 || strcmp(tokens[i], "*") == 0 || strcmp(tokens[i], "/") == 0 || strcmp(tokens[i], "^") == 0) {
            double num2 = stack[top--];
            double num1 = stack[top--];
            double result = operate(tokens[i][0], num1, num2);
            stack[++top] = result;
        } else {
            stack[++top] = atof(tokens[i]);
        }
    }
    if (top != 0) {
        display("Error: Invalid expression.\n");
        return NAN;
    }
    return stack[top];
}

// Main function
int main() {
    char expr[100];
    while (1) {
        clrscr();
        display("Scientific Calculator\n");
        display("Enter an expression (e.g., 1 + 2, 3 * 4, 5 ^ 6): ");
        gets(expr);
        if (strcmp(expr, "exit") == 0) {
            break;
        }
        double result = evaluate(expr);
        if (!isnan(result)) {
            printf("Result: %.2f\n", result);
        }
        system("pause");
    }
    return 0;
}