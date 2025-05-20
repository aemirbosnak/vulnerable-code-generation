//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: happy
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 256

int main() {
  char buffer[MAX_BUFFER_SIZE] = "";
  int i = 0;
  float num1, num2, result;
  char operator;

  printf("Welcome to the Scientific Calculator!\n");

  // Loop to get input from the user
  while (1) {
    printf("Enter an operator (+, -, *, /, %): ");
    scanf("%c", &operator);

    // Check if the operator is valid
    if (operator != '+' && operator != '-' && operator != '*' && operator != '/') {
      printf("Invalid operator.\n");
      continue;
    }

    // Get the first number
    printf("Enter the first number: ");
    scanf("%f", &num1);

    // Get the second number
    printf("Enter the second number: ");
    scanf("%f", &num2);

    // Perform the operation
    switch (operator) {
      case '+':
        result = num1 + num2;
        break;
      case '-':
        result = num1 - num2;
        break;
      case '*':
        result = num1 * num2;
        break;
      case '/':
        if (num2 == 0) {
          printf("Cannot divide by zero.\n");
          continue;
        }
        result = num1 / num2;
        break;
    }

    // Display the result
    printf("The result is: %.2f\n", result);

    // Clear the buffer
    i = 0;
    buffer[0] = '\0';

    // Ask the user if they want to continue
    printf("Do you want to continue? (Y/N): ");
    scanf("%s", buffer);

    // Check if the user wants to continue
    if (strcmp(buffer, "Y") == 0) {
      continue;
    } else {
      break;
    }
  }

  // Thank the user
  printf("Thank you for using the Scientific Calculator!\n");

  return 0;
}