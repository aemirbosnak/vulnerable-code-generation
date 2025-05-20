//Falcon-180B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define MAX_INPUT_SIZE 1000
#define MAX_OUTPUT_SIZE 1000

// Function to evaluate the expression
double evaluate(char *expression) {
    double result = 0;
    int i = 0;
    char *temp = strtok(expression, " ");
    while (temp!= NULL) {
        if (isdigit(temp[0])) {
            result += atof(temp);
        } else if (temp[0] == '+') {
            result += evaluate(temp + 1);
        } else if (temp[0] == '-') {
            result -= evaluate(temp + 1);
        } else if (temp[0] == '*') {
            result *= evaluate(temp + 1);
        } else if (temp[0] == '/') {
            result /= evaluate(temp + 1);
        } else if (temp[0] == '^') {
            result = pow(result, evaluate(temp + 1));
        }
        temp = strtok(NULL, " ");
    }
    return result;
}

// Function to print the result
void print_result(double result) {
    if (result == floor(result)) {
        printf("%.0f\n", result);
    } else {
        printf("%.2f\n", result);
    }
}

// Main function to get user input and display the result
int main() {
    char input[MAX_INPUT_SIZE];
    char output[MAX_OUTPUT_SIZE];
    printf("Enter the expression: ");
    fgets(input, MAX_INPUT_SIZE, stdin);
    int input_len = strlen(input);
    input[input_len - 1] = '\0'; // Remove newline character
    double result = evaluate(input);
    sprintf(output, "Result: %s", input);
    print_result(result);
    return 0;
}