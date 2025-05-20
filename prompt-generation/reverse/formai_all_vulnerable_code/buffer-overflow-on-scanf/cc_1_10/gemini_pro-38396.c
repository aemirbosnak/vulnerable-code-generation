//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the password strength levels
#define STRENGTH_WEAK 0
#define STRENGTH_OK 1
#define STRENGTH_STRONG 2
#define STRENGTH_VERY_STRONG 3

// Define the minimum password length
#define MIN_PASSWORD_LENGTH 8

// Define the maximum password length
#define MAX_PASSWORD_LENGTH 32

// Define the character classes
#define CHAR_CLASS_UPPERCASE 0x01
#define CHAR_CLASS_LOWERCASE 0x02
#define CHAR_CLASS_NUMBER 0x04
#define CHAR_CLASS_SYMBOL 0x08

// Define the password strength requirements
#define REQUIREMENT_LENGTH 0x01
#define REQUIREMENT_UPPERCASE 0x02
#define REQUIREMENT_LOWERCASE 0x04
#define REQUIREMENT_NUMBER 0x08
#define REQUIREMENT_SYMBOL 0x10

// Define the password strength calculation function
int calculate_password_strength(char *password) {
  // Initialize the password strength
  int strength = STRENGTH_WEAK;

  // Check the password length
  if (strlen(password) < MIN_PASSWORD_LENGTH) {
    return strength;
  }

  // Check the password for uppercase characters
  if (strchr(password, 'A') || strchr(password, 'Z')) {
    strength |= REQUIREMENT_UPPERCASE;
  }

  // Check the password for lowercase characters
  if (strchr(password, 'a') || strchr(password, 'z')) {
    strength |= REQUIREMENT_LOWERCASE;
  }

  // Check the password for numbers
  if (strchr(password, '0') || strchr(password, '9')) {
    strength |= REQUIREMENT_NUMBER;
  }

  // Check the password for symbols
  if (strchr(password, '!') || strchr(password, '?') || strchr(password, '$') || strchr(password, '%')) {
    strength |= REQUIREMENT_SYMBOL;
  }

  // Return the password strength
  return strength;
}

// Define the main function
int main(void) {
  // Declare the password
  char password[MAX_PASSWORD_LENGTH + 1];

  // Get the password from the user
  printf("Enter your password: ");
  scanf("%s", password);

  // Calculate the password strength
  int strength = calculate_password_strength(password);

  // Print the password strength
  switch (strength) {
    case STRENGTH_WEAK:
      printf("Your password is weak.\n");
      break;
    case STRENGTH_OK:
      printf("Your password is ok.\n");
      break;
    case STRENGTH_STRONG:
      printf("Your password is strong.\n");
      break;
    case STRENGTH_VERY_STRONG:
      printf("Your password is very strong.\n");
      break;
  }

  // Return 0
  return 0;
}