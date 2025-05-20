//Gemma-7B DATASET v1.0 Category: Syntax parsing ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char str[100];
  scanf("%s", str);

  // Parse the C syntax
  int is_valid = 1;
  for (int i = 0; str[i] != '\0'; i++) {
    // Keywords
    if (str[i] == 'if' || str[i] == 'else' || str[i] == 'for' || str[i] == 'while' || str[i] == 'switch' || str[i] == 'case' || str[i] == 'default') {
      // Check for valid keyword placement
      if (i == 0 || str[i - 1] == ')') {
        is_valid = 0;
      }
    }

    // Operators
    else if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/') {
      // Check for valid operator placement
      if (i == 0 || str[i - 1] == ')') {
        is_valid = 0;
      }
    }

    // Parentheses
    else if (str[i] == '(' || str[i] == ')') {
      // Check for valid parenthesis placement
      if (i == 0 || str[i - 1] == ')') {
        is_valid = 0;
      }
    }

    // Comments
    else if (str[i] == '/' && str[i + 1] == '/') {
      // Ignore comments
    }

    // Other characters
    else if (str[i] >= 'a' && str[i] <= 'z') {
      // Check for valid variable name
      if (i == 0 || str[i - 1] == ')') {
        is_valid = 0;
      }
    } else {
      // Invalid character
      is_valid = 0;
    }
  }

  // Print the result
  if (is_valid) {
    printf("The C syntax is valid.\n");
  } else {
    printf("The C syntax is invalid.\n");
  }

  return 0;
}