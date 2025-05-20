#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
  char input[1024];
  int i = 0;

  // Get user input of arbitrary length
  printf("Enter your command: ");
  fgets(input, 1024, stdin);

  // Stage 1: Remove whitespace and special characters
  for (i = 0; input[i] != '\0'; i++) {
    if (!isalnum(input[i]) && input[i] != ' ' && input[i] != '-') {
      input[i] = '\0';
    }
  }

  // Stage 2: Replace invalid characters with underscores
  for (i = 0; input[i] != '\0'; i++) {
    if (isupper(input[i])) {
      input[i] = tolower(input[i]);
    } else if (input[i] >= 'a' && input[i] <= 'z') {
      input[i] = '_';
    }
  }

  // Process sanitized input
  printf("Sanitized input: %s\n", input);

  return 0;
}
