//Code Llama-13B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: creative
#include <stdio.h>
#include <stdlib.h>

// Define a struct to hold the calculator state
typedef struct {
  double result;
  double operand1;
  double operand2;
  char operation;
} calculator_state_t;

// Define a function to perform the operation
void perform_operation(calculator_state_t* state) {
  switch (state->operation) {
    case '+':
      state->result = state->operand1 + state->operand2;
      break;
    case '-':
      state->result = state->operand1 - state->operand2;
      break;
    case '*':
      state->result = state->operand1 * state->operand2;
      break;
    case '/':
      state->result = state->operand1 / state->operand2;
      break;
    default:
      printf("Invalid operation\n");
      exit(1);
  }
}

// Define a function to display the result
void display_result(calculator_state_t* state) {
  printf("%f %c %f = %f\n", state->operand1, state->operation, state->operand2, state->result);
}

// Define a function to handle user input
void handle_input(calculator_state_t* state) {
  char input[100];
  scanf("%s", input);

  // Check if the input is a number
  if (isdigit(input[0])) {
    // If the input is a number, it is an operand
    if (state->operation == '\0') {
      // If there is no operation, it is the first operand
      state->operand1 = atof(input);
    } else {
      // If there is an operation, it is the second operand
      state->operand2 = atof(input);
      perform_operation(state);
      display_result(state);
    }
  } else {
    // If the input is not a number, it is an operation
    state->operation = input[0];
    if (state->operation == '=') {
      perform_operation(state);
      display_result(state);
    } else if (state->operation == 'c') {
      // If the input is 'c', clear the calculator state
      state->result = 0;
      state->operand1 = 0;
      state->operand2 = 0;
      state->operation = '\0';
    } else {
      printf("Invalid operation\n");
      exit(1);
    }
  }
}

int main() {
  calculator_state_t state;
  state.result = 0;
  state.operand1 = 0;
  state.operand2 = 0;
  state.operation = '\0';

  while (1) {
    handle_input(&state);
  }

  return 0;
}