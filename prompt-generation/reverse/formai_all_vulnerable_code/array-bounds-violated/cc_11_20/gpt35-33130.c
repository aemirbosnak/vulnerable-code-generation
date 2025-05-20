//FormAI DATASET v1.0 Category: Syntax parsing ; Style: innovative
#include <stdio.h>

int main() {
  printf("Hello, welcome to unique C Syntax parsing example program!\n");
  
  // Declare variables
  char input[100];
  int count = 0;
  
  // Ask user for input
  printf("Please enter a C syntax statement: ");
  fgets(input, 100, stdin);
  
  // Loop over each character in the input
  for (int i = 0; i < strlen(input); i++) {
    // Check if character is a space or newline
    if (input[i] == ' ' || input[i] == '\n') {
      // Ignore whitespace
      continue;
    }
    // Check if character is part of a comment
    if (input[i] == '/') {
      // Check if next character is also a '/'
      if (input[i+1] == '/') {
        // This is a single line comment, ignore rest of input
        break;
      } else if (input[i+1] == '*') {
        // This is the start of a multi-line comment
        // Loop over input until end of comment is found
        while (i < strlen(input)) {
          if (input[i] == '*' && input[i+1] == '/') {
            // End of comment found, move i past the */
            i += 2;
            break;
          }
          i++;
        }
      }
    }
    // Check if character is part of a string
    if (input[i] == '"') {
      // Loop over input until end of string is found
      while (i < strlen(input)) {
        if (input[i] == '"' && input[i-1] != '\\') {
          // End of string found, move i past the "
          i++;
          break;
        }
        i++;
      }
    }
    // Check if character is part of a character literal
    if (input[i] == '\'') {
      // Loop over input until end of character literal is found
      while (i < strlen(input)) {
        if (input[i] == '\'' && input[i-1] != '\\') {
          // End of character literal found, move i past the '
          i++;
          break;
        }
        i++;
      }
    }
    // If none of the above checks match, the character must be a valid syntax character
    count++;
  }
  
  // Print out the count of valid syntax characters
  printf("Number of valid syntax characters: %d\n", count);
  
  return 0;
}