//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the minimum password length
#define MIN_PASSWORD_LENGTH 8

// Define the maximum password length
#define MAX_PASSWORD_LENGTH 64

// Define the character classes
#define CHAR_CLASS_UPPERCASE 0x01
#define CHAR_CLASS_LOWERCASE 0x02
#define CHAR_CLASS_NUMBER 0x04
#define CHAR_CLASS_SYMBOL 0x08

// Define the password strength levels
#define PASSWORD_STRENGTH_WEAK 0
#define PASSWORD_STRENGTH_MEDIUM 1
#define PASSWORD_STRENGTH_STRONG 2

// Define the password strength messages
#define PASSWORD_STRENGTH_WEAK_MESSAGE "Your password is weak. Please try again."
#define PASSWORD_STRENGTH_MEDIUM_MESSAGE "Your password is medium. Please try again."
#define PASSWORD_STRENGTH_STRONG_MESSAGE "Your password is strong. Good job!"

// Declare the password strength checker function
int check_password_strength(char *password);

// Main function
int main() {
  // Declare the password variable
  char password[MAX_PASSWORD_LENGTH + 1];

  // Prompt the user to enter a password
  printf("Enter a password: ");
  scanf("%s", password);

  // Check the password strength
  int password_strength = check_password_strength(password);

  // Print the password strength message
  switch (password_strength) {
    case PASSWORD_STRENGTH_WEAK:
      printf("%s\n", PASSWORD_STRENGTH_WEAK_MESSAGE);
      break;
    case PASSWORD_STRENGTH_MEDIUM:
      printf("%s\n", PASSWORD_STRENGTH_MEDIUM_MESSAGE);
      break;
    case PASSWORD_STRENGTH_STRONG:
      printf("%s\n", PASSWORD_STRENGTH_STRONG_MESSAGE);
      break;
  }

  return 0;
}

// Password strength checker function
int check_password_strength(char *password) {
  // Check the password length
  if (strlen(password) < MIN_PASSWORD_LENGTH) {
    return PASSWORD_STRENGTH_WEAK;
  } else if (strlen(password) > MAX_PASSWORD_LENGTH) {
    return PASSWORD_STRENGTH_WEAK;
  }

  // Check the password character classes
  int character_classes = 0;
  for (int i = 0; i < strlen(password); i++) {
    char character = password[i];
    if (character >= 'A' && character <= 'Z') {
      character_classes |= CHAR_CLASS_UPPERCASE;
    } else if (character >= 'a' && character <= 'z') {
      character_classes |= CHAR_CLASS_LOWERCASE;
    } else if (character >= '0' && character <= '9') {
      character_classes |= CHAR_CLASS_NUMBER;
    } else {
      character_classes |= CHAR_CLASS_SYMBOL;
    }
  }

  // Check the password strength
  if (character_classes == CHAR_CLASS_UPPERCASE | CHAR_CLASS_LOWERCASE | CHAR_CLASS_NUMBER | CHAR_CLASS_SYMBOL) {
    return PASSWORD_STRENGTH_STRONG;
  } else if (character_classes == CHAR_CLASS_UPPERCASE | CHAR_CLASS_LOWERCASE | CHAR_CLASS_NUMBER) {
    return PASSWORD_STRENGTH_MEDIUM;
  } else {
    return PASSWORD_STRENGTH_WEAK;
  }
}