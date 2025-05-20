//GEMINI-pro DATASET v1.0 Category: User Input Sanitizer ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  // Declare the input buffer and its maximum size
  char input_buffer[1024];
  int input_buffer_size = sizeof(input_buffer) / sizeof(input_buffer[0]);

  // Prompt the user to enter input
  printf("Please enter your input: ");

  // Read the user's input into the buffer
  fgets(input_buffer, input_buffer_size, stdin);

  // Remove any leading or trailing whitespace from the input
  size_t input_length = strlen(input_buffer);
  while (input_length > 0 && (input_buffer[input_length - 1] == '\n' || input_buffer[input_length - 1] == '\r')) {
    input_length--;
  }
  input_buffer[input_length] = '\0';

  // Check if the input is empty
  if (input_length == 0) {
    printf("Error: Input cannot be empty.\n");
    return EXIT_FAILURE;
  }

  // Check if the input contains any special characters
  const char *special_characters = "!@#$%^&*()-+?_=,<>/";
  for (int i = 0; i < input_length; i++) {
    if (strchr(special_characters, input_buffer[i]) != NULL) {
      printf("Error: Input contains special characters.\n");
      return EXIT_FAILURE;
    }
  }

  // Check if the input is a valid number
  int number;
  if (sscanf(input_buffer, "%d", &number) != 1) {
    printf("Error: Input is not a valid number.\n");
    return EXIT_FAILURE;
  }

  // Check if the number is positive
  if (number <= 0) {
    printf("Error: Input must be a positive number.\n");
    return EXIT_FAILURE;
  }

  // Print the sanitized input
  printf("Sanitized input: %s\n", input_buffer);

  return EXIT_SUCCESS;
}