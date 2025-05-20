//GEMINI-pro DATASET v1.0 Category: User Input Sanitizer ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 1024

int main() {
  char input[MAX_INPUT_LENGTH];
  int i;

  printf("Enter your input: ");
  fgets(input, MAX_INPUT_LENGTH, stdin);

  // Remove leading and trailing whitespace
  i = 0;
  while (isspace(input[i])) {
    i++;
  }
  strcpy(input, input + i);

  i = strlen(input) - 1;
  while (isspace(input[i])) {
    input[i] = '\0';
    i--;
  }

  // Escape special characters
  i = 0;
  while (input[i] != '\0') {
    switch (input[i]) {
      case '&':
        input[i] = '&';
        break;
      case '<':
        input[i] = '<';
        break;
      case '>':
        input[i] = '>';
        break;
      case '"':
        input[i] = '"';
        break;
      case '\'':
        input[i] = '\'';
        break;
    }
    i++;
  }

  // Output the sanitized input
  printf("Sanitized input: %s\n", input);

  return 0;
}