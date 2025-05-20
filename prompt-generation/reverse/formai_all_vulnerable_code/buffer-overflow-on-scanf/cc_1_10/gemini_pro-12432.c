//GEMINI-pro DATASET v1.0 Category: User Input Sanitizer ; Style: brave
#include <stdio.h>
#include <stdlib.h>

// Define the maximum size of the input buffer
#define MAX_BUFFER_SIZE 1024

// Define the sanitizer function
char *sanitize_input(char *input) {
  char *sanitized_input = malloc(MAX_BUFFER_SIZE);
  int i = 0;
  int j = 0;
  
  // Loop through the input string
  while (input[i] != '\0') {
    // If the character is alphanumeric, add it to the sanitized string
    if (isalnum(input[i])) {
      sanitized_input[j++] = input[i];
    }
    
    // Increment the input index
    i++;
  }
  
  // Terminate the sanitized string
  sanitized_input[j] = '\0';
  
  // Return the sanitized string
  return sanitized_input;
}

// Define the main function
int main() {
  // Declare the input buffer
  char input[MAX_BUFFER_SIZE];
  
  // Prompt the user for input
  printf("Enter your input: ");
  scanf("%s", input);
  
  // Sanitize the input
  char *sanitized_input = sanitize_input(input);
  
  // Print the sanitized input
  printf("Sanitized input: %s\n", sanitized_input);
  
  // Free the allocated memory
  free(sanitized_input);
  
  return 0;
}