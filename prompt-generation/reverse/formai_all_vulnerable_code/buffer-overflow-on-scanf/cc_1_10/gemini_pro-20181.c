//GEMINI-pro DATASET v1.0 Category: User Input Sanitizer ; Style: happy
#include <stdio.h>
#include <stdlib.h>

// Function to check if a string contains only digits
int is_numeric(const char *str) {
  while (*str) {
    if (*str < '0' || *str > '9') {
      return 0;
    }
    str++;
  }
  return 1;
}

// Function to sanitize user input
char *sanitize_input(const char *input) {
  char *sanitized_input = malloc(strlen(input) + 1);
  if (sanitized_input == NULL) {
    return NULL;
  }

  int i = 0;
  int j = 0;
  while (input[i] != '\0') {
    if (input[i] >= 'a' && input[i] <= 'z') {
      sanitized_input[j++] = input[i];
    } else if (input[i] >= 'A' && input[i] <= 'Z') {
      sanitized_input[j++] = input[i];
    } else if (input[i] >= '0' && input[i] <= '9') {
      sanitized_input[j++] = input[i];
    } else if (input[i] == ' ') {
      sanitized_input[j++] = input[i];
    }
    i++;
  }
  sanitized_input[j] = '\0';

  return sanitized_input;
}

int main() {
  char input[100];

  printf("Enter your name: ");
  scanf("%s", input);

  // Check if the input contains only digits
  if (is_numeric(input)) {
    printf("Your name cannot contain only digits.\n");
    return 1;
  }

  // Sanitize the input
  char *sanitized_input = sanitize_input(input);
  if (sanitized_input == NULL) {
    printf("Error allocating memory.\n");
    return 1;
  }

  // Print the sanitized input
  printf("Your sanitized name is: %s\n", sanitized_input);

  // Free the allocated memory
  free(sanitized_input);

  return 0;
}