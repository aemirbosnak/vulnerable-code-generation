//Code Llama-13B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define a struct to store the calculator state
typedef struct {
    double value1;
    double value2;
    char operation;
} Calculator;

// Define the calculator operations
void add(Calculator *calc) {
    calc->value1 += calc->value2;
}

void subtract(Calculator *calc) {
    calc->value1 -= calc->value2;
}

void multiply(Calculator *calc) {
    calc->value1 *= calc->value2;
}

void divide(Calculator *calc) {
    calc->value1 /= calc->value2;
}

// Define the calculator functions
void calculate(Calculator *calc) {
    switch (calc->operation) {
        case '+':
            add(calc);
            break;
        case '-':
            subtract(calc);
            break;
        case '*':
            multiply(calc);
            break;
        case '/':
            divide(calc);
            break;
        default:
            break;
    }
}

// Define the calculator input function
void input(Calculator *calc) {
    char input[100];
    scanf("%s", input);
    if (input[0] == '=') {
        calculate(calc);
    } else if (input[0] == '+') {
        calc->operation = '+';
        calc->value2 = atof(input + 1);
    } else if (input[0] == '-') {
        calc->operation = '-';
        calc->value2 = atof(input + 1);
    } else if (input[0] == '*') {
        calc->operation = '*';
        calc->value2 = atof(input + 1);
    } else if (input[0] == '/') {
        calc->operation = '/';
        calc->value2 = atof(input + 1);
    } else {
        calc->value1 = atof(input);
    }
}

// Define the calculator output function
void output(Calculator *calc) {
    printf("%f\n", calc->value1);
}

// Define the main function
int main() {
    Calculator calc;
    calc.value1 = 0;
    calc.value2 = 0;
    calc.operation = '\0';
    while (1) {
        input(&calc);
        output(&calc);
    }
    return 0;
}