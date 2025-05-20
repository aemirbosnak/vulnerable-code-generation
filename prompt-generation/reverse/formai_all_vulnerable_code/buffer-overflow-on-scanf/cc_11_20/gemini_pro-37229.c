//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the password strength levels
#define STRENGTH_WEAK 0
#define STRENGTH_GOOD 1
#define STRENGTH_STRONG 2

// Define the minimum password length
#define MIN_PASSWORD_LENGTH 8

// Define the maximum password length
#define MAX_PASSWORD_LENGTH 20

// Define the character sets
#define CHARSET_LOWERCASE "abcdefghijklmnopqrstuvwxyz"
#define CHARSET_UPPERCASE "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define CHARSET_NUMBERS "0123456789"
#define CHARSET_SYMBOLS "!@#$%^&*()_+"

// Define the password strength calculation function
int calculatePasswordStrength(char *password) {
  // Check the password length
  if (strlen(password) < MIN_PASSWORD_LENGTH) {
    return STRENGTH_WEAK;
  } else if (strlen(password) > MAX_PASSWORD_LENGTH) {
    return STRENGTH_WEAK;
  }

  // Check the password for uppercase characters
  int hasUppercase = 0;
  for (int i = 0; i < strlen(password); i++) {
    if (strchr(CHARSET_UPPERCASE, password[i]) != NULL) {
      hasUppercase = 1;
      break;
    }
  }

  // Check the password for lowercase characters
  int hasLowercase = 0;
  for (int i = 0; i < strlen(password); i++) {
    if (strchr(CHARSET_LOWERCASE, password[i]) != NULL) {
      hasLowercase = 1;
      break;
    }
  }

  // Check the password for numbers
  int hasNumbers = 0;
  for (int i = 0; i < strlen(password); i++) {
    if (strchr(CHARSET_NUMBERS, password[i]) != NULL) {
      hasNumbers = 1;
      break;
    }
  }

  // Check the password for symbols
  int hasSymbols = 0;
  for (int i = 0; i < strlen(password); i++) {
    if (strchr(CHARSET_SYMBOLS, password[i]) != NULL) {
      hasSymbols = 1;
      break;
    }
  }

  // Calculate the password strength
  int strength = 0;
  if (hasUppercase && hasLowercase && hasNumbers && hasSymbols) {
    strength = STRENGTH_STRONG;
  } else if (hasUppercase && hasLowercase && hasNumbers) {
    strength = STRENGTH_GOOD;
  } else {
    strength = STRENGTH_WEAK;
  }

  return strength;
}

// Define the main function
int main() {
  // Get the password from the user
  char password[MAX_PASSWORD_LENGTH];
  printf("Enter your password: ");
  scanf("%s", password);

  // Calculate the password strength
  int strength = calculatePasswordStrength(password);

  // Print the password strength
  switch (strength) {
    case STRENGTH_WEAK:
      printf("Your password is weak.\n");
      break;
    case STRENGTH_GOOD:
      printf("Your password is good.\n");
      break;
    case STRENGTH_STRONG:
      printf("Your password is strong.\n");
      break;
  }

  return 0;
}