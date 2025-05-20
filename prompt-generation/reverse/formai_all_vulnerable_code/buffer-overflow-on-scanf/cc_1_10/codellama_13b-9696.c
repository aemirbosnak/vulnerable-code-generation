//Code Llama-13B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: imaginative
// Scientific Calculator Implementation in C

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_INPUT_SIZE 100

// Function to evaluate a given expression
double evaluate(char* expression) {
    double result = 0;
    char* token = strtok(expression, "+-*/^");
    while (token != NULL) {
        if (token[0] == '+') {
            result += atof(token + 1);
        } else if (token[0] == '-') {
            result -= atof(token + 1);
        } else if (token[0] == '*') {
            result *= atof(token + 1);
        } else if (token[0] == '/') {
            result /= atof(token + 1);
        } else if (token[0] == '^') {
            result = pow(result, atof(token + 1));
        } else {
            result = atof(token);
        }
        token = strtok(NULL, "+-*/^");
    }
    return result;
}

// Function to convert a number to a string
char* num_to_string(double num) {
    char* str = malloc(MAX_INPUT_SIZE);
    sprintf(str, "%.2f", num);
    return str;
}

int main() {
    char input[MAX_INPUT_SIZE];
    double result;

    printf("Enter an expression: ");
    scanf("%s", input);

    result = evaluate(input);
    printf("Result: %s\n", num_to_string(result));

    return 0;
}