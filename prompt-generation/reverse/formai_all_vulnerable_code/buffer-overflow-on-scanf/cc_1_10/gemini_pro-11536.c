//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: future-proof
#include <stdio.h>
#include <string.h>

// Define the minimum password length
#define MIN_PASSWORD_LENGTH 8

// Define the maximum password length
#define MAX_PASSWORD_LENGTH 64

// Define the character classes
#define CHAR_CLASS_LOWERCASE 0x01
#define CHAR_CLASS_UPPERCASE 0x02
#define CHAR_CLASS_DIGIT 0x04
#define CHAR_CLASS_SPECIAL 0x08

// Define the password strength levels
#define PASSWORD_STRENGTH_WEAK 0
#define PASSWORD_STRENGTH_MEDIUM 1
#define PASSWORD_STRENGTH_STRONG 2

// Define the password strength messages
#define PASSWORD_STRENGTH_WEAK_MESSAGE "Weak"
#define PASSWORD_STRENGTH_MEDIUM_MESSAGE "Medium"
#define PASSWORD_STRENGTH_STRONG_MESSAGE "Strong"

// Function to check if a character is lowercase
int is_lowercase(char c) {
  return (c >= 'a' && c <= 'z');
}

// Function to check if a character is uppercase
int is_uppercase(char c) {
  return (c >= 'A' && c <= 'Z');
}

// Function to check if a character is a digit
int is_digit(char c) {
  return (c >= '0' && c <= '9');
}

// Function to check if a character is a special character
int is_special(char c) {
  return (!is_lowercase(c) && !is_uppercase(c) && !is_digit(c));
}

// Function to calculate the password strength
int calculate_password_strength(char *password) {
  int strength = 0;

  // Check the password length
  if (strlen(password) < MIN_PASSWORD_LENGTH) {
    return PASSWORD_STRENGTH_WEAK;
  } else if (strlen(password) > MAX_PASSWORD_LENGTH) {
    return PASSWORD_STRENGTH_WEAK;
  }

  // Check the character classes
  int char_classes = 0;
  if (is_lowercase(password[0])) {
    char_classes |= CHAR_CLASS_LOWERCASE;
  }
  if (is_uppercase(password[0])) {
    char_classes |= CHAR_CLASS_UPPERCASE;
  }
  if (is_digit(password[0])) {
    char_classes |= CHAR_CLASS_DIGIT;
  }
  if (is_special(password[0])) {
    char_classes |= CHAR_CLASS_SPECIAL;
  }

  for (int i = 1; i < strlen(password); i++) {
    if (is_lowercase(password[i])) {
      char_classes |= CHAR_CLASS_LOWERCASE;
    } else if (is_uppercase(password[i])) {
      char_classes |= CHAR_CLASS_UPPERCASE;
    } else if (is_digit(password[i])) {
      char_classes |= CHAR_CLASS_DIGIT;
    } else if (is_special(password[i])) {
      char_classes |= CHAR_CLASS_SPECIAL;
    }
  }

  // Calculate the strength based on the character classes
  if (char_classes == CHAR_CLASS_LOWERCASE) {
    strength = PASSWORD_STRENGTH_WEAK;
  } else if (char_classes == (CHAR_CLASS_LOWERCASE | CHAR_CLASS_UPPERCASE)) {
    strength = PASSWORD_STRENGTH_MEDIUM;
  } else if (char_classes == (CHAR_CLASS_LOWERCASE | CHAR_CLASS_UPPERCASE | CHAR_CLASS_DIGIT)) {
    strength = PASSWORD_STRENGTH_STRONG;
  } else if (char_classes == (CHAR_CLASS_LOWERCASE | CHAR_CLASS_UPPERCASE | CHAR_CLASS_DIGIT | CHAR_CLASS_SPECIAL)) {
    strength = PASSWORD_STRENGTH_STRONG;
  }

  return strength;
}

// Main function
int main() {
  // Get the password from the user
  char password[MAX_PASSWORD_LENGTH + 1];
  printf("Enter your password: ");
  scanf("%s", password);

  // Calculate the password strength
  int strength = calculate_password_strength(password);

  // Print the password strength message
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