//GEMINI-pro DATASET v1.0 Category: User Input Sanitizer ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if a string contains only digits
int is_digits(char *str) {
  while (*str) {
    if (*str < '0' || *str > '9') {
      return 0;
    }
    str++;
  }
  return 1;
}

// Function to check if a string contains only letters
int is_letters(char *str) {
  while (*str) {
    if ((*str < 'a' || *str > 'z') && (*str < 'A' || *str > 'Z')) {
      return 0;
    }
    str++;
  }
  return 1;
}

// Function to check if a string contains only special characters
int is_special(char *str) {
  while (*str) {
    if ((*str < '!' || *str > '/') && (*str < ':' || *str > '@') && (*str < '[' || *str > '`') && (*str < '{' || *str > '~')) {
      return 0;
    }
    str++;
  }
  return 1;
}

// Function to sanitize user input
char *sanitize_input(char *str) {
  // Remove leading and trailing whitespace
  while (*str == ' ') {
    str++;
  }
  while (*str) {
    if (*str == ' ') {
      *str = '\0';
      break;
    }
    str++;
  }

  // Check if the input is valid
  if (is_digits(str) || is_letters(str) || is_special(str)) {
    return str;
  } else {
    return NULL;
  }
}

// Main function
int main() {
  // Get user input
  char input[100];
  printf("Enter your input: ");
  gets(input);

  // Sanitize the input
  char *sanitized_input = sanitize_input(input);

  // Check if the input is valid
  if (sanitized_input) {
    printf("Your sanitized input is: %s\n", sanitized_input);
  } else {
    printf("Invalid input. Please try again.\n");
  }

  return 0;
}