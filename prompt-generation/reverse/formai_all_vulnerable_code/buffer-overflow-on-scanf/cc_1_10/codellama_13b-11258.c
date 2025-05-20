//Code Llama-13B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define a structure to store the calculator's state
typedef struct {
    double num1;
    double num2;
    char op;
} calculator_state_t;

// Define the calculator's functions
calculator_state_t calculator_init(void) {
    calculator_state_t state;
    state.num1 = 0;
    state.num2 = 0;
    state.op = '+';
    return state;
}

double calculator_add(calculator_state_t *state, double num) {
    state->num1 += num;
    return state->num1;
}

double calculator_subtract(calculator_state_t *state, double num) {
    state->num1 -= num;
    return state->num1;
}

double calculator_multiply(calculator_state_t *state, double num) {
    state->num1 *= num;
    return state->num1;
}

double calculator_divide(calculator_state_t *state, double num) {
    state->num1 /= num;
    return state->num1;
}

// Define the calculator's main function
int main(void) {
    // Initialize the calculator's state
    calculator_state_t state = calculator_init();

    // Get the user's input
    double num;
    char op;
    printf("Enter a number: ");
    scanf("%lf", &num);
    printf("Enter an operator (+, -, *, /): ");
    scanf(" %c", &op);

    // Perform the operation
    switch (op) {
        case '+':
            calculator_add(&state, num);
            break;
        case '-':
            calculator_subtract(&state, num);
            break;
        case '*':
            calculator_multiply(&state, num);
            break;
        case '/':
            calculator_divide(&state, num);
            break;
        default:
            printf("Invalid operator\n");
            return 1;
    }

    // Print the result
    printf("Result: %lf\n", state.num1);

    return 0;
}