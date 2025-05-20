//GEMINI-pro DATASET v1.0 Category: User Input Sanitizer ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LEN 1024

int main(void) {
  char input[MAX_INPUT_LEN];
  char sanitized_input[MAX_INPUT_LEN];
  int i, j;

  printf("Enter a string: ");
  fgets(input, MAX_INPUT_LEN, stdin);

  // Remove leading and trailing whitespace
  i = 0;
  while (input[i] == ' ' || input[i] == '\t') {
    i++;
  }
  j = strlen(input) - 1;
  while (input[j] == ' ' || input[j] == '\t') {
    j--;
  }
  strncpy(sanitized_input, input + i, j - i + 1);
  sanitized_input[j - i + 1] = '\0';

  // Remove any HTML tags
  i = 0;
  j = 0;
  while (sanitized_input[i] != '\0') {
    if (sanitized_input[i] == '<') {
      while (sanitized_input[i] != '>' && sanitized_input[i] != '\0') {
        i++;
      }
      if (sanitized_input[i] == '>') {
        i++;
      }
    } else {
      sanitized_input[j++] = sanitized_input[i++];
    }
  }
  sanitized_input[j] = '\0';

  // Remove any non-alphanumeric characters
  i = 0;
  j = 0;
  while (sanitized_input[i] != '\0') {
    if (isalnum(sanitized_input[i])) {
      sanitized_input[j++] = sanitized_input[i++];
    } else {
      i++;
    }
  }
  sanitized_input[j] = '\0';

  // Output the sanitized input
  printf("Sanitized input: %s\n", sanitized_input);

  return 0;
}