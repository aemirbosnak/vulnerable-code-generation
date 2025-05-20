//GEMINI-pro DATASET v1.0 Category: User Input Sanitizer ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if the input string is a valid integer
int is_valid_int(char *str) {
  int i;
  int len = strlen(str);

  // Check if the string is empty
  if (len == 0) {
    return 0;
  }

  // Check if the first character is a minus sign
  if (str[0] == '-') {
    i = 1;
  } else {
    i = 0;
  }

  // Check if the remaining characters are digits
  for (; i < len; i++) {
    if (!isdigit(str[i])) {
      return 0;
    }
  }

  // If all checks pass, return 1
  return 1;
}

// Function to check if the input string is a valid float
int is_valid_float(char *str) {
  int i;
  int len = strlen(str);
  int decimal_count = 0;

  // Check if the string is empty
  if (len == 0) {
    return 0;
  }

  // Check if the first character is a minus sign
  if (str[0] == '-') {
    i = 1;
  } else {
    i = 0;
  }

  // Check if the remaining characters are digits or a decimal point
  for (; i < len; i++) {
    if (!isdigit(str[i])) {
      if (str[i] == '.' && decimal_count == 0) {
        decimal_count++;
      } else {
        return 0;
      }
    }
  }

  // If all checks pass, return 1
  return 1;
}

// Function to sanitize the input string
char *sanitize_input(char *str) {
  int i;
  int len = strlen(str);
  char *sanitized_str = malloc(len + 1);

  // Copy the valid characters to the sanitized string
  for (i = 0; i < len; i++) {
    if (isdigit(str[i]) || str[i] == '.' || str[i] == '-') {
      sanitized_str[i] = str[i];
    }
  }

  // Terminate the sanitized string
  sanitized_str[i] = '\0';

  // Return the sanitized string
  return sanitized_str;
}

// Main function
int main() {
  char *input_str;
  char *sanitized_str;

  // Get the input string from the user
  printf("Enter a string: ");
  input_str = malloc(100);
  scanf("%s", input_str);

  // Check if the input string is a valid integer
  if (is_valid_int(input_str)) {
    printf("The input string is a valid integer.\n");
  } else {
    printf("The input string is not a valid integer.\n");
  }

  // Check if the input string is a valid float
  if (is_valid_float(input_str)) {
    printf("The input string is a valid float.\n");
  } else {
    printf("The input string is not a valid float.\n");
  }

  // Sanitize the input string
  sanitized_str = sanitize_input(input_str);

  // Print the sanitized string
  printf("The sanitized string is: %s\n", sanitized_str);

  // Free the allocated memory
  free(input_str);
  free(sanitized_str);

  return 0;
}