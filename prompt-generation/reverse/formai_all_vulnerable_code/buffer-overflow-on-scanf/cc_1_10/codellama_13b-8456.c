//Code Llama-13B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: protected
// Scientific Calculator Implementation in C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_LENGTH 100

// Enum for different mathematical operations
enum Operations {
    ADD,
    SUBTRACT,
    MULTIPLY,
    DIVIDE,
    POWER,
    SQRT
};

// Structure for storing numerical values and operations
typedef struct {
    double num1;
    double num2;
    enum Operations op;
} Calculation;

// Function to perform mathematical operations
double perform_operation(double num1, double num2, enum Operations op) {
    switch (op) {
        case ADD:
            return num1 + num2;
        case SUBTRACT:
            return num1 - num2;
        case MULTIPLY:
            return num1 * num2;
        case DIVIDE:
            return num1 / num2;
        case POWER:
            return pow(num1, num2);
        case SQRT:
            return sqrt(num1);
        default:
            return 0;
    }
}

// Function to read input from user
void read_input(Calculation *calc) {
    char str[MAX_LENGTH];
    printf("Enter first number: ");
    scanf("%lf", &calc->num1);
    printf("Enter second number: ");
    scanf("%lf", &calc->num2);
    printf("Enter operation (+, -, *, /, ^, sqrt): ");
    scanf("%s", str);
    if (strcmp(str, "+") == 0) {
        calc->op = ADD;
    } else if (strcmp(str, "-") == 0) {
        calc->op = SUBTRACT;
    } else if (strcmp(str, "*") == 0) {
        calc->op = MULTIPLY;
    } else if (strcmp(str, "/") == 0) {
        calc->op = DIVIDE;
    } else if (strcmp(str, "^") == 0) {
        calc->op = POWER;
    } else if (strcmp(str, "sqrt") == 0) {
        calc->op = SQRT;
    } else {
        printf("Invalid operation\n");
        exit(1);
    }
}

// Function to print output
void print_output(double result) {
    printf("Result: %f\n", result);
}

int main() {
    Calculation calc;
    read_input(&calc);
    double result = perform_operation(calc.num1, calc.num2, calc.op);
    print_output(result);
    return 0;
}