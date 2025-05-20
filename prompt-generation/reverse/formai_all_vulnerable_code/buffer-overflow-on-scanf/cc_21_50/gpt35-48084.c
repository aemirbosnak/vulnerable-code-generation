//FormAI DATASET v1.0 Category: Syntax parsing ; Style: invasive
// Invasive C Syntax Parsing Example Program

#include <stdio.h>
#include <stdlib.h>

int main() {

  // Declare variables
  char equation[1000];
  int i = 0, j = 0, flag = 0;

  // Get equation input from user
  printf("Enter an equation to parse: ");
  scanf("%s", equation);

  // Loop through each character in the equation
  while (equation[i] != '\0') {
    // Check for valid syntax of each character
    if (equation[i] == '(') {
      flag++;
    }
    else if (equation[i] == ')') {
      flag--;
      if (flag < 0) {
        printf("Invalid syntax! Extra ) found\n");
        return 0;
      }
    }
    else if (equation[i] == '+' || equation[i] == '-' || equation[i] == '*' || equation[i] == '/') {
      // Check for valid syntax of operator character
      if (i==0 || i == strlen(equation) - 1) {
        printf("Invalid syntax! Operator cannot be at beginning or end\n");
        return 0;
      }
      else if (equation[i-1] == '(' || equation[i-1] == '+' || equation[i-1] == '-' || equation[i-1] == '*' || equation[i-1] == '/' || equation[i+1] == '(' || equation[i+1] == '+' || equation[i+1] == '-' || equation[i+1] == '*' || equation[i+1] == '/') {
        printf("Invalid syntax! Operator must be surrounded by operands\n");
        return 0;
      }
    }
    else if (equation[i] < '0' || equation[i] > '9') {
      // Check for valid syntax of non-operator/non-bracket character
      printf("Invalid syntax! Only numbers, brackets and operators are allowed\n");
      return 0;
    }

    // Move on to next character in the equation
    i++;
  }

  // Check if any extra brackets have not been closed
  if (flag != 0) {
    printf("Invalid syntax! Extra ( found\n");
    return 0;
  }

  // If no invalid syntax found, print success message
  printf("Parsed equation successfully!\n");

  return 0;
}