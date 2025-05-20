//GEMINI-pro DATASET v1.0 Category: User Input Sanitizer ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Sanitize user input function
char *sanitize_input(char *input) {
  // Allocate memory for the sanitized input
  char *sanitized_input = malloc(strlen(input) + 1);
  if (!sanitized_input) {
    // Oh my gosh, we couldn't allocate memory! Run for the hills!
    fprintf(stderr, "Oh my stars, we're doomed! We couldn't allocate memory!\n");
    exit(EXIT_FAILURE);
  }

  // Copy the input into the sanitized input buffer
  strcpy(sanitized_input, input);

  // Analyze every character in the input
  for (int i = 0; i < strlen(sanitized_input); i++) {
    // Check if the character is ASCII code 0-31 or 127. These are control characters that could be malicious!
    if (sanitized_input[i] < 32 || sanitized_input[i] == 127) {
      // Oh noes! We found a control character! Bleep it out!
      sanitized_input[i] = '?';
    }
    // Check if the character is a whitespace character. These could indicate line breaks or other formatting that could be used for injection attacks!
    else if (isspace(sanitized_input[i])) {
      // Argh! We found a whitespace character! Convert it to a harmless space!
      sanitized_input[i] = ' ';
    }
    // Check if the character is a non-printable character. These could be used to hide malicious code!
    else if (!isprint(sanitized_input[i])) {
      // Sweet mother of pearl! We found a non-printable character! Time to wave goodbye to it!
      sanitized_input[i] = '?';
    }
  }

  // Oh my, we're almost done! Now, let's make sure the input doesn't contain any malicious HTML tags!
  char *filtered_html = strtok(sanitized_input, "<");
  while (filtered_html) {
    char *end_tag = strstr(filtered_html, ">");
    if (end_tag) {
      *end_tag = '\0';
    }
    filtered_html = strtok(NULL, "<");
  }

  // Phew! We're finally done! Return the sanitized input!
  return sanitized_input;
}

int main() {
  // Prompt the user for input
  char input[1024];
  printf("Oh, hello there! Please give us your precious input!\n");
  scanf(" %s", input);

  // Sanitize the user input
  char *sanitized_input = sanitize_input(input);

  // Print the sanitized input
  printf("Gotcha! Here's your squeaky-clean input:\n%s\n", sanitized_input);

  // Free the memory allocated for the sanitized input
  free(sanitized_input);

  // All's well that ends well! We've protected ourselves from those pesky attackers!
  return EXIT_SUCCESS;
}