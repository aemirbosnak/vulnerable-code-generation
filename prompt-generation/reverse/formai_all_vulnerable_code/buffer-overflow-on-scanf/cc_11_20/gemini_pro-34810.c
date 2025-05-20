//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the password strength levels
#define WEAK 0
#define MEDIUM 1
#define STRONG 2

// Define the password requirements
#define MIN_LENGTH 8
#define MAX_LENGTH 16
#define REQUIRED_NUMBERS 1
#define REQUIRED_LETTERS 1
#define REQUIRED_SYMBOLS 1

// Function to check the password strength
int check_password_strength(char *password) {
  // Check the password length
  if (strlen(password) < MIN_LENGTH || strlen(password) > MAX_LENGTH) {
    return WEAK;
  }

  // Check the password for numbers
  int has_numbers = 0;
  for (int i = 0; i < strlen(password); i++) {
    if (password[i] >= '0' && password[i] <= '9') {
      has_numbers = 1;
      break;
    }
  }
  if (!has_numbers) {
    return WEAK;
  }

  // Check the password for letters
  int has_letters = 0;
  for (int i = 0; i < strlen(password); i++) {
    if ((password[i] >= 'a' && password[i] <= 'z') || (password[i] >= 'A' && password[i] <= 'Z')) {
      has_letters = 1;
      break;
    }
  }
  if (!has_letters) {
    return WEAK;
  }

  // Check the password for symbols
  int has_symbols = 0;
  for (int i = 0; i < strlen(password); i++) {
    if (password[i] < '0' || password[i] > '9' && password[i] < 'a' || password[i] > 'z' && password[i] < 'A' || password[i] > 'Z') {
      has_symbols = 1;
      break;
    }
  }
  if (!has_symbols) {
    return WEAK;
  }

  // If all the requirements are met, return STRONG
  return STRONG;
}

// Main function
int main() {
  // Get the password from the user
  char password[MAX_LENGTH];
  printf("Enter your password: ");
  scanf("%s", password);

  // Check the password strength
  int strength = check_password_strength(password);

  // Print the password strength
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