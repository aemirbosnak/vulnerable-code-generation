//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the minimum and maximum password lengths
#define MIN_LENGTH 8
#define MAX_LENGTH 128

// Define the character types that are allowed in passwords
#define ALLOWED_CHARS "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()"

// Function to check if a password is strong enough
int is_strong_password(char *password) {
  // Check if the password is the correct length
  if (strlen(password) < MIN_LENGTH || strlen(password) > MAX_LENGTH) {
    return 0;
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
    if (strchr(ALLOWED_CHARS, password[i])) {
      has_special_character = 1;
      break;
    }
  }

  // Return whether the password is strong enough
  return has_uppercase && has_lowercase && has_digit && has_special_character;
}

// Main function
int main() {
  // Get the password from the user
  printf("Enter your password: ");
  char password[MAX_LENGTH];
  scanf("%s", password);

  // Check if the password is strong enough
  int is_strong = is_strong_password(password);

  // Print the result
  if (is_strong) {
    printf("Your password is strong.\n");
  } else {
    printf("Your password is not strong enough.\n");
  }

  return 0;
}