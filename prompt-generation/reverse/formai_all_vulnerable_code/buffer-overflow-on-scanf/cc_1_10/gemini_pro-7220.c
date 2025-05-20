//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: rigorous
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MIN_PASS_LEN 8
#define MAX_PASS_LEN 128

// Function to check if a character is a lowercase letter
int is_lowercase(char c) {
  return (c >= 'a' && c <= 'z');
}

// Function to check if a character is an uppercase letter
int is_uppercase(char c) {
  return (c >= 'A' && c <= 'Z');
}

// Function to check if a character is a digit
int is_digit(char c) {
  return (c >= '0' && c <= '9');
}

// Function to check if a character is a special character
int is_special(char c) {
  return (c == '!' || c == '@' || c == '#' || c == '$' || c == '%');
}

// Function to check if a password is valid
int is_valid_password(char *password) {
  int len = strlen(password);

  // Check if the password is the correct length
  if (len < MIN_PASS_LEN || len > MAX_PASS_LEN) {
    return 0;
  }

  // Check if the password contains at least one lowercase letter
  int has_lowercase = 0;
  for (int i = 0; i < len; i++) {
    if (is_lowercase(password[i])) {
      has_lowercase = 1;
      break;
    }
  }
  if (!has_lowercase) {
    return 0;
  }

  // Check if the password contains at least one uppercase letter
  int has_uppercase = 0;
  for (int i = 0; i < len; i++) {
    if (is_uppercase(password[i])) {
      has_uppercase = 1;
      break;
    }
  }
  if (!has_uppercase) {
    return 0;
  }

  // Check if the password contains at least one digit
  int has_digit = 0;
  for (int i = 0; i < len; i++) {
    if (is_digit(password[i])) {
      has_digit = 1;
      break;
    }
  }
  if (!has_digit) {
    return 0;
  }

  // Check if the password contains at least one special character
  int has_special = 0;
  for (int i = 0; i < len; i++) {
    if (is_special(password[i])) {
      has_special = 1;
      break;
    }
  }
  if (!has_special) {
    return 0;
  }

  // The password is valid
  return 1;
}

// Main function
int main() {
  // Get the password from the user
  char password[MAX_PASS_LEN + 1];
  printf("Please enter your password: ");
  scanf("%s", password);

  // Check if the password is valid
  int valid = is_valid_password(password);

  // Print the result
  if (valid) {
    printf("Your password is valid.\n");
  } else {
    printf("Your password is invalid.\n");
  }

  return 0;
}