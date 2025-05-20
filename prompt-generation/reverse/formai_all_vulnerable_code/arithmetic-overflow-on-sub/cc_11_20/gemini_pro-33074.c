//GEMINI-pro DATASET v1.0 Category: User Input Sanitizer ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char *input = NULL;
  size_t len = 0;
  ssize_t nread;

  printf("Enter your input: ");
  nread = getline(&input, &len, stdin);
  if (nread == -1) {
    perror("getline");
    return EXIT_FAILURE;
  }

  // Remove newline character
  if (input[nread - 1] == '\n')
    input[nread - 1] = '\0';

  // Check for invalid characters
  for (int i = 0; i < nread; i++) {
    if (!isalnum(input[i]) && input[i] != '.' && input[i] != '_') {
      printf("Invalid character '%c' found.\n", input[i]);
      free(input);
      return EXIT_FAILURE;
    }
  }

  // Check for leading or trailing whitespace
  if (isspace(input[0]) || isspace(input[nread - 1])) {
    printf("Leading or trailing whitespace found.\n");
    free(input);
    return EXIT_FAILURE;
  }

  // Check for consecutive dots or underscores
  for (int i = 0; i < nread - 1; i++) {
    if ((input[i] == '.' || input[i] == '_') && (input[i + 1] == '.' || input[i + 1] == '_')) {
      printf("Consecutive dots or underscores found.\n");
      free(input);
      return EXIT_FAILURE;
    }
  }

  // Check for leading or trailing dots or underscores
  if (input[0] == '.' || input[0] == '_' || input[nread - 1] == '.' || input[nread - 1] == '_') {
    printf("Leading or trailing dots or underscores found.\n");
    free(input);
    return EXIT_FAILURE;
  }

  // Input is valid, do something with it
  printf("Input is valid: %s\n", input);
  free(input);
  return EXIT_SUCCESS;
}