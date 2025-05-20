//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the password strength levels
#define WEAK 0
#define MEDIUM 1
#define STRONG 2

// Define the minimum password length
#define MIN_PASSWORD_LENGTH 8

// Function to check if the password is strong
int check_password_strength(char *password) {
  // Check if the password is long enough
  if (strlen(password) < MIN_PASSWORD_LENGTH) {
    return WEAK;
  }

  // Check if the password contains at least one uppercase letter
  int has_uppercase = 0;
  for (int i = 0; i < strlen(password); i++) {
    if (password[i] >= 'A' && password[i] <= 'Z') {
      has_uppercase = 1;
      break;
    }
  }

  // Check if the password contains at least one lowercase letter
  int has_lowercase = 0;
  for (int i = 0; i < strlen(password); i++) {
    if (password[i] >= 'a' && password[i] <= 'z') {
      has_lowercase = 1;
      break;
    }
  }

  // Check if the password contains at least one digit
  int has_digit = 0;
  for (int i = 0; i < strlen(password); i++) {
    if (password[i] >= '0' && password[i] <= '9') {
      has_digit = 1;
      break;
    }
  }

  // Check if the password contains at least one special character
  int has_special_character = 0;
  for (int i = 0; i < strlen(password); i++) {
    if (password[i] == '!' || password[i] == '@' || password[i] == '#' || password[i] == '$' || password[i] == '%') {
      has_special_character = 1;
      break;
    }
  }

  // Return the password strength level
  if (has_uppercase && has_lowercase && has_digit && has_special_character) {
    return STRONG;
  } else if (has_uppercase && has_lowercase && has_digit) {
    return MEDIUM;
  } else {
    return WEAK;
  }
}

// Main function
int main() {
  // Get the password from the user
  char password[100];
  printf("Enter your password: ");
  scanf("%s", password);

  // Check the password strength
  int strength = check_password_strength(password);

  // Print the password strength level
  switch (strength) {
    case WEAK:
      printf("Your password is weak.\n");
      break;
    case MEDIUM:
      printf("Your password is medium.\n");
      break;
    case STRONG:
      printf("Your password is strong.\n");
      break;
  }

  return 0;
}