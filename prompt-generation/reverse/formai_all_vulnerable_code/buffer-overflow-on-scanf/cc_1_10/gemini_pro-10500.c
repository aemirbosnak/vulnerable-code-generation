//GEMINI-pro DATASET v1.0 Category: User Input Sanitizer ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to sanitize user input
char *sanitize_input(char *input) {
  // Allocate memory for the sanitized input
  char *sanitized_input = malloc(strlen(input) + 1);

  // Initialize the sanitized input to empty
  sanitized_input[0] = '\0';

  // Iterate over the input string
  for (int i = 0; input[i] != '\0'; i++) {
    // Check if the current character is a valid character
    if (input[i] >= 'a' && input[i] <= 'z') {
      // If the character is a lowercase letter, add it to the sanitized input
      strcat(sanitized_input, &input[i]);
    } else if (input[i] >= 'A' && input[i] <= 'Z') {
      // If the character is an uppercase letter, convert it to lowercase and add it to the sanitized input
      strcat(sanitized_input, &input[i] + 32);
    } else if (input[i] >= '0' && input[i] <= '9') {
      // If the character is a digit, add it to the sanitized input
      strcat(sanitized_input, &input[i]);
    } else if (input[i] == ' ') {
      // If the character is a space, add it to the sanitized input
      strcat(sanitized_input, &input[i]);
    }
  }

  // Return the sanitized input
  return sanitized_input;
}

// Main function
int main() {
  // Get user input
  char *input = malloc(100);
  printf("Enter your input: ");
  scanf("%s", input);

  // Sanitize the user input
  char *sanitized_input = sanitize_input(input);

  // Print the sanitized input
  printf("Sanitized input: %s\n", sanitized_input);

  // Free the allocated memory
  free(input);
  free(sanitized_input);

  return 0;
}