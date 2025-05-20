//GEMINI-pro DATASET v1.0 Category: User Input Sanitizer ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if a string contains only digits
int is_digits(char *str) {
  for (int i = 0; str[i] != '\0'; i++) {
    if (str[i] < '0' || str[i] > '9') {
      return 0;
    }
  }
  return 1;
}

// Function to check if a string contains only alphabetic characters
int is_alphabetic(char *str) {
  for (int i = 0; str[i] != '\0'; i++) {
    if ((str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z')) {
      return 0;
    }
  }
  return 1;
}

// Function to check if a string contains only alphanumeric characters
int is_alphanumeric(char *str) {
  for (int i = 0; str[i] != '\0'; i++) {
    if ((str[i] < '0' || str[i] > '9') && (str[i] < 'a' || str[i] > 'z') &&
        (str[i] < 'A' || str[i] > 'Z')) {
      return 0;
    }
  }
  return 1;
}

int main() {
  char input[100];

  // Prompt the user to enter a string
  printf("Enter a string: ");
  scanf("%s", input);

  // Check if the string is valid
  if (is_digits(input)) {
    printf("The string '%s' contains only digits.\n", input);
  } else if (is_alphabetic(input)) {
    printf("The string '%s' contains only alphabetic characters.\n", input);
  } else if (is_alphanumeric(input)) {
    printf("The string '%s' contains only alphanumeric characters.\n", input);
  } else {
    printf("The string '%s' is invalid.\n", input);
  }

  return 0;
}