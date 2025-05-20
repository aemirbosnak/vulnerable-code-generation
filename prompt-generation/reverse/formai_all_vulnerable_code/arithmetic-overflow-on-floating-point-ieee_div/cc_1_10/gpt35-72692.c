//FormAI DATASET v1.0 Category: Syntax parsing ; Style: mathematical
// Mathematical-style C code for parsing expressions

#include <stdio.h>

// declare functions
float add(float a, float b);
float subtract(float a, float b);
float multiply(float a, float b);
float divide(float a, float b);
float parse_expression(char* expression);

int main() {
  // examples
  char* expression1 = "2 + 3 * 4";
  char* expression2 = "(7 - 2) * 5 / 3";
  char* expression3 = "4 - 6 / (2 + 1)";

  // parse expressions and print results
  printf("Result of '%s' is %f\n", expression1, parse_expression(expression1));
  printf("Result of '%s' is %f\n", expression2, parse_expression(expression2));
  printf("Result of '%s' is %f\n", expression3, parse_expression(expression3));

  return 0;
}

/*
 * Function: add
 * Description: Adds two numbers.
 */
float add(float a, float b) {
  return a + b;
}

/*
 * Function: subtract
 * Description: Subtracts one number from another.
 */
float subtract(float a, float b) {
  return a - b;
}

/*
 * Function: multiply
 * Description: Multiplies two numbers.
 */
float multiply(float a, float b) {
  return a * b;
}

/*
 * Function: divide
 * Description: Divides one number by another.
 */
float divide(float a, float b) {
  return a / b;
}

/*
 * Function: parse_expression
 * Description: Parses a mathematical expression in the form
 *              of a string and returns the result.
 */
float parse_expression(char* expression) {
  float result = 0;
  float current_number = 0;
  float previous_number = 0;
  char previous_operator = '+';
  char current_character;

  // loop through expression characters
  for (int i = 0; expression[i] != '\0'; i++) {
    current_character = expression[i];

    // if character is a digit, add it to current number
    if (current_character >= '0' && current_character <= '9') {
      current_number = current_number * 10 + (current_character - '0');
    }
    // if not a digit and not a space, evaluate previous operation
    else if (current_character != ' ') {
      switch (previous_operator) {
        case '+':
          result = add(result, previous_number);
          previous_number = current_number;
          break;
        case '-':
          result = subtract(result, previous_number);
          previous_number = current_number;
          break;
        case '*':
          previous_number = multiply(previous_number, current_number);
          break;
        case '/':
          previous_number = divide(previous_number, current_number);
          break;
      }
      // set current_operator as previous_operator
      previous_operator = current_character;
      // reset current_number
      current_number = 0;
    }
  }
  // evaluate final operation
  switch (previous_operator) {
    case '+':
      result += previous_number;
      break;
    case '-':
      result -= previous_number;
      break;
    case '*':
      result = multiply(result, previous_number);
      break;
    case '/':
      result = divide(result, previous_number);
      break;
  }
  return result;
}