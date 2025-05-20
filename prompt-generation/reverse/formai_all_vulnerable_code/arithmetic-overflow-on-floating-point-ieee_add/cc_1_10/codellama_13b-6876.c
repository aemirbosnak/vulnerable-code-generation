//Code Llama-13B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: scientific
// Scientific Calculator Implementation in C

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define a structure to store the input values
struct input_values {
  double num1;
  double num2;
  char op;
};

// Define a function to perform the calculation
double perform_calculation(struct input_values input) {
  switch (input.op) {
    case '+':
      return input.num1 + input.num2;
    case '-':
      return input.num1 - input.num2;
    case '*':
      return input.num1 * input.num2;
    case '/':
      return input.num1 / input.num2;
    default:
      printf("Invalid operator\n");
      return 0;
  }
}

// Define a function to print the result
void print_result(double result) {
  printf("Result: %f\n", result);
}

int main() {
  struct input_values input;
  double result;

  printf("Enter the first number: ");
  scanf("%lf", &input.num1);

  printf("Enter the second number: ");
  scanf("%lf", &input.num2);

  printf("Enter the operator (+, -, *, /): ");
  scanf(" %c", &input.op);

  result = perform_calculation(input);

  print_result(result);

  return 0;
}