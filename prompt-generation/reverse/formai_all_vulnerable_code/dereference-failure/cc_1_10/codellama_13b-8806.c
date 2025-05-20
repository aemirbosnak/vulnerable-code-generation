//Code Llama-13B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_OPERANDS 3

enum Operators {
    ADD = 0,
    SUBTRACT,
    MULTIPLY,
    DIVIDE,
    POWER
};

void print_usage(char *program_name) {
    printf("Usage: %s <operator> <operand1> <operand2>\n", program_name);
    printf("Supported operators: +\n");
    printf("                      -\n");
    printf("                      *\n");
    printf("                      /\n");
    printf("                      ^");
}

double calculate(enum Operators op, double operand1, double operand2) {
    switch (op) {
        case ADD:
            return operand1 + operand2;
        case SUBTRACT:
            return operand1 - operand2;
        case MULTIPLY:
            return operand1 * operand2;
        case DIVIDE:
            return operand1 / operand2;
        case POWER:
            return pow(operand1, operand2);
        default:
            printf("Invalid operator\n");
            exit(1);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        print_usage(argv[0]);
        exit(1);
    }

    enum Operators op = atoi(argv[1]);
    double operand1 = atof(argv[2]);
    double operand2 = atof(argv[3]);

    double result = calculate(op, operand1, operand2);

    printf("Result: %f\n", result);

    return 0;
}