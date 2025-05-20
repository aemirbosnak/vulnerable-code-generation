//Falcon-180B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_SIZE 100
#define MAX_OUTPUT_SIZE 100

// Function to evaluate a mathematical expression
int evaluate(char* expression, double* result) {
    char* token = strtok(expression, " ");
    while (token!= NULL) {
        if (isdigit(token[0])) {
            *result += atof(token);
        } else if (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/') {
            double operand1 = *result;
            double operand2 = atof(strtok(NULL, " "));
            if (token[0] == '+') {
                *result = operand1 + operand2;
            } else if (token[0] == '-') {
                *result = operand1 - operand2;
            } else if (token[0] == '*') {
                *result = operand1 * operand2;
            } else if (token[0] == '/') {
                *result = operand1 / operand2;
            }
        }
        token = strtok(NULL, " ");
    }
    return 0;
}

// Function to print the result of a mathematical expression
void print_result(double result) {
    if (result == 0) {
        printf("0\n");
    } else if (result > 0) {
        printf("%.2f\n", result);
    } else {
        printf("-%.2f\n", result);
    }
}

// Function to clear the input buffer
void clear_buffer() {
    int c;
    while ((c = getchar())!= '\n' && c!= EOF) {
        // Do nothing
    }
}

// Main function
int main() {
    char input[MAX_INPUT_SIZE];
    double result = 0;
    while (1) {
        printf("Enter a mathematical expression: ");
        fgets(input, MAX_INPUT_SIZE, stdin);
        evaluate(input, &result);
        print_result(result);
        clear_buffer();
    }
    return 0;
}