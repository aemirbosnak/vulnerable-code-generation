//Code Llama-13B DATASET v1.0 Category: User Input Sanitizer ; Style: Dennis Ritchie
// User Input Sanitizer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Define a struct to hold the sanitized input
typedef struct {
  char *input;
  bool is_valid;
} SanitizedInput;

// Define a function to sanitize the input
SanitizedInput sanitize_input(char *input) {
  SanitizedInput sanitized;
  sanitized.input = input;
  sanitized.is_valid = true;

  // Check if the input is not NULL
  if (input == NULL) {
    sanitized.is_valid = false;
    return sanitized;
  }

  // Check if the input is empty
  if (strlen(input) == 0) {
    sanitized.is_valid = false;
    return sanitized;
  }

  // Check if the input contains any non-alphanumeric characters
  for (int i = 0; i < strlen(input); i++) {
    if (!isalnum(input[i])) {
      sanitized.is_valid = false;
      return sanitized;
    }
  }

  return sanitized;
}

// Define a function to print the sanitized input
void print_sanitized_input(SanitizedInput sanitized) {
  if (sanitized.is_valid) {
    printf("Sanitized input: %s\n", sanitized.input);
  } else {
    printf("Invalid input: %s\n", sanitized.input);
  }
}

int main() {
  char input[100];
  printf("Enter input: ");
  scanf("%s", input);

  SanitizedInput sanitized = sanitize_input(input);
  print_sanitized_input(sanitized);

  return 0;
}