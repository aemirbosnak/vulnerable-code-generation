//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define the minimum password length.
#define MIN_PASSWORD_LENGTH 8

// Define the maximum password length.
#define MAX_PASSWORD_LENGTH 64

// Define the character classes for password strength.
#define CHAR_CLASS_LOWER 0x01
#define CHAR_CLASS_UPPER 0x02
#define CHAR_CLASS_DIGIT 0x04
#define CHAR_CLASS_SPECIAL 0x08

// Define the password strength levels.
#define PASSWORD_STRENGTH_WEAK 0
#define PASSWORD_STRENGTH_MEDIUM 1
#define PASSWORD_STRENGTH_STRONG 2

// Function to check if a character is in a given character class.
int char_in_class(char c, int char_class) {
  switch (char_class) {
    case CHAR_CLASS_LOWER:
      return islower(c);
    case CHAR_CLASS_UPPER:
      return isupper(c);
    case CHAR_CLASS_DIGIT:
      return isdigit(c);
    case CHAR_CLASS_SPECIAL:
      return strchr("!@#$%^&*()-_=+.", c) != NULL;
    default:
      return 0;
  }
}

// Function to calculate the password strength.
int password_strength(char *password) {
  int strength = 0;
  int char_classes = 0;

  // Check the password length.
  if (strlen(password) < MIN_PASSWORD_LENGTH) {
    return PASSWORD_STRENGTH_WEAK;
  } else if (strlen(password) > MAX_PASSWORD_LENGTH) {
    return PASSWORD_STRENGTH_WEAK;
  }

  // Check the character classes.
  for (int i = 0; i < strlen(password); i++) {
    if (char_in_class(password[i], CHAR_CLASS_LOWER)) {
      char_classes |= CHAR_CLASS_LOWER;
    } else if (char_in_class(password[i], CHAR_CLASS_UPPER)) {
      char_classes |= CHAR_CLASS_UPPER;
    } else if (char_in_class(password[i], CHAR_CLASS_DIGIT)) {
      char_classes |= CHAR_CLASS_DIGIT;
    } else if (char_in_class(password[i], CHAR_CLASS_SPECIAL)) {
      char_classes |= CHAR_CLASS_SPECIAL;
    }
  }

  // Check the password strength.
  if (char_classes == (CHAR_CLASS_LOWER | CHAR_CLASS_UPPER | CHAR_CLASS_DIGIT | CHAR_CLASS_SPECIAL)) {
    strength = PASSWORD_STRENGTH_STRONG;
  } else if (char_classes == (CHAR_CLASS_LOWER | CHAR_CLASS_UPPER | CHAR_CLASS_DIGIT)) {
    strength = PASSWORD_STRENGTH_MEDIUM;
  } else {
    strength = PASSWORD_STRENGTH_WEAK;
  }

  return strength;
}

// Main function.
int main() {
  char password[MAX_PASSWORD_LENGTH + 1];

  // Get the password from the user.
  printf("Enter your password: ");
  scanf("%s", password);

  // Check the password strength.
  int strength = password_strength(password);

  // Print the password strength.
  switch (strength) {
    case PASSWORD_STRENGTH_WEAK:
      printf("Your password is weak.\n");
      break;
    case PASSWORD_STRENGTH_MEDIUM:
      printf("Your password is medium.\n");
      break;
    case PASSWORD_STRENGTH_STRONG:
      printf("Your password is strong.\n");
      break;
  }

  return 0;
}