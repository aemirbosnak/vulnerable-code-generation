//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: careful
#include <stdio.h>
#include <string.h>

// Define the minimum password length.
#define MIN_PASSWORD_LENGTH 8

// Define the maximum password length.
#define MAX_PASSWORD_LENGTH 64

// Define the character classes.
#define CHAR_CLASS_LOWERCASE 0x01
#define CHAR_CLASS_UPPERCASE 0x02
#define CHAR_CLASS_DIGIT 0x04
#define CHAR_CLASS_SPECIAL 0x08

// Define the password strength levels.
#define PASSWORD_STRENGTH_WEAK 0x01
#define PASSWORD_STRENGTH_MEDIUM 0x02
#define PASSWORD_STRENGTH_STRONG 0x04

// Define the error codes.
#define ERROR_INVALID_PASSWORD_LENGTH -1
#define ERROR_INVALID_CHARACTER_CLASS -2

// Function to check the password length.
int check_password_length(char *password) {
  int length = strlen(password);

  if (length < MIN_PASSWORD_LENGTH || length > MAX_PASSWORD_LENGTH) {
    return ERROR_INVALID_PASSWORD_LENGTH;
  }

  return 0;
}

// Function to check the password character classes.
int check_password_character_classes(char *password) {
  int character_classes = 0;

  for (int i = 0; i < strlen(password); i++) {
    char character = password[i];

    if (character >= 'a' && character <= 'z') {
      character_classes |= CHAR_CLASS_LOWERCASE;
    } else if (character >= 'A' && character <= 'Z') {
      character_classes |= CHAR_CLASS_UPPERCASE;
    } else if (character >= '0' && character <= '9') {
      character_classes |= CHAR_CLASS_DIGIT;
    } else {
      character_classes |= CHAR_CLASS_SPECIAL;
    }
  }

  if (character_classes == 0) {
    return ERROR_INVALID_CHARACTER_CLASS;
  }

  return 0;
}

// Function to check the password strength.
int check_password_strength(char *password) {
  int strength = 0;

  int length = strlen(password);
  int character_classes = check_password_character_classes(password);

  if (length >= MIN_PASSWORD_LENGTH && length <= MAX_PASSWORD_LENGTH) {
    strength |= PASSWORD_STRENGTH_WEAK;
  }

  if (character_classes & CHAR_CLASS_LOWERCASE && character_classes & CHAR_CLASS_UPPERCASE && character_classes & CHAR_CLASS_DIGIT && character_classes & CHAR_CLASS_SPECIAL) {
    strength |= PASSWORD_STRENGTH_STRONG;
  } else if (character_classes & CHAR_CLASS_LOWERCASE && character_classes & CHAR_CLASS_UPPERCASE && character_classes & CHAR_CLASS_DIGIT) {
    strength |= PASSWORD_STRENGTH_MEDIUM;
  } else if (character_classes & CHAR_CLASS_LOWERCASE && character_classes & CHAR_CLASS_UPPERCASE) {
    strength |= PASSWORD_STRENGTH_WEAK;
  }

  return strength;
}

// Main function.
int main() {
  char password[MAX_PASSWORD_LENGTH + 1];

  printf("Enter a password: ");
  scanf("%s", password);

  int length_error = check_password_length(password);
  int character_class_error = check_password_character_classes(password);
  int strength = check_password_strength(password);

  if (length_error == ERROR_INVALID_PASSWORD_LENGTH) {
    printf("The password must be between %d and %d characters long.\n", MIN_PASSWORD_LENGTH, MAX_PASSWORD_LENGTH);
  } else if (character_class_error == ERROR_INVALID_CHARACTER_CLASS) {
    printf("The password must contain at least one lowercase letter, one uppercase letter, one digit, and one special character.\n");
  } else {
    switch (strength) {
      case PASSWORD_STRENGTH_WEAK:
        printf("The password is weak.\n");
        break;
      case PASSWORD_STRENGTH_MEDIUM:
        printf("The password is medium.\n");
        break;
      case PASSWORD_STRENGTH_STRONG:
        printf("The password is strong.\n");
        break;
    }
  }

  return 0;
}