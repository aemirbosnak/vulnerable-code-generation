//Code Llama-13B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the calculator operations
enum Operations {
    ADD,
    SUB,
    MUL,
    DIV,
    MOD
};

// Define the calculator state
struct CalculatorState {
    enum Operations operation;
    double firstOperand;
    double secondOperand;
    double result;
};

// Define the calculator functions
void update_operation(struct CalculatorState* state, enum Operations operation) {
    state->operation = operation;
}

void update_operands(struct CalculatorState* state, double firstOperand, double secondOperand) {
    state->firstOperand = firstOperand;
    state->secondOperand = secondOperand;
}

void calculate_result(struct CalculatorState* state) {
    switch (state->operation) {
        case ADD:
            state->result = state->firstOperand + state->secondOperand;
            break;
        case SUB:
            state->result = state->firstOperand - state->secondOperand;
            break;
        case MUL:
            state->result = state->firstOperand * state->secondOperand;
            break;
        case DIV:
            state->result = state->firstOperand / state->secondOperand;
            break;
        case MOD:
            state->result = fmod(state->firstOperand, state->secondOperand);
            break;
        default:
            break;
    }
}

// Define the calculator interface
void display_result(struct CalculatorState* state) {
    printf("Result: %f\n", state->result);
}

// Define the calculator main function
int main() {
    // Initialize the calculator state
    struct CalculatorState state;
    state.operation = ADD;
    state.firstOperand = 0.0;
    state.secondOperand = 0.0;
    state.result = 0.0;

    // Initialize the calculator interface
    display_result(&state);

    // Loop until the user exits the program
    while (1) {
        // Get the user's input
        char input[256];
        printf("Enter operation (e.g. 1 2 +): ");
        fgets(input, 256, stdin);

        // Parse the user's input
        char* token = strtok(input, " ");
        int operation = atoi(token);
        token = strtok(NULL, " ");
        double firstOperand = atof(token);
        token = strtok(NULL, " ");
        double secondOperand = atof(token);

        // Update the calculator state
        update_operation(&state, operation);
        update_operands(&state, firstOperand, secondOperand);
        calculate_result(&state);

        // Display the result
        display_result(&state);
    }

    return 0;
}