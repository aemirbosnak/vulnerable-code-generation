//Falcon-180B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: configurable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MAX_INPUT_SIZE 100
#define MAX_RESULT_SIZE 50

// Function to evaluate the expression
void evaluate_expression(char* expression, double* result) {
    char* token = strtok(expression, " ");
    while (token!= NULL) {
        if (isdigit(token[0])) {
            *result += atof(token);
        } else {
            switch(token[0]) {
                case '+':
                    *result += atof(strtok(NULL, " "));
                    break;
                case '-':
                    *result -= atof(strtok(NULL, " "));
                    break;
                case '*':
                    *result *= atof(strtok(NULL, " "));
                    break;
                case '/':
                    if (atof(strtok(NULL, " ")) == 0) {
                        printf("Error: Division by zero\n");
                        exit(1);
                    }
                    *result /= atof(strtok(NULL, " "));
                    break;
                case '^':
                    *result = pow(atof(strtok(NULL, " ")), atof(strtok(NULL, " ")));
                    break;
                case's':
                    *result = sin(atof(strtok(NULL, " ")));
                    break;
                case 'c':
                    *result = cos(atof(strtok(NULL, " ")));
                    break;
                case 't':
                    *result = tan(atof(strtok(NULL, " ")));
                    break;
                case 'l':
                    *result = log(atof(strtok(NULL, " ")));
                    break;
            }
        }
        token = strtok(NULL, " ");
    }
}

// Function to print the usage instructions
void print_usage() {
    printf("Usage:./calculator <expression>\n");
    printf("Supported operators: + - * / ^ s c t l\n");
    printf("Supported functions: sin(x) cos(x) tan(x) log(x)\n");
}

int main(int argc, char* argv[]) {
    if (argc!= 2) {
        print_usage();
        return 1;
    }

    char input_buffer[MAX_INPUT_SIZE];
    strcpy(input_buffer, argv[1]);

    double result;
    evaluate_expression(input_buffer, &result);

    printf("Result: %.2f\n", result);

    return 0;
}