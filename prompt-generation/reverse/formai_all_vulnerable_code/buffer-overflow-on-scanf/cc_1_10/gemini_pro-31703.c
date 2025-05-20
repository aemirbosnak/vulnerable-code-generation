//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the minimum password length.
#define MIN_PASSWORD_LENGTH 8

// Define the maximum password length.
#define MAX_PASSWORD_LENGTH 64

// Define the character classes used in the password strength check.
#define CHARACTER_CLASS_LOWERCASE 0x01
#define CHARACTER_CLASS_UPPERCASE 0x02
#define CHARACTER_CLASS_DIGIT 0x04
#define CHARACTER_CLASS_SYMBOL 0x08

// Define the password strength levels.
#define PASSWORD_STRENGTH_WEAK 0
#define PASSWORD_STRENGTH_MEDIUM 1
#define PASSWORD_STRENGTH_STRONG 2

// Define the password strength messages.
const char *password_strength_messages[] = {
  "Weak",
  "Medium",
  "Strong"
};

// Check the password strength of a given password.
int check_password_strength(const char *password) {
  // Initialize the password strength to weak.
  int password_strength = PASSWORD_STRENGTH_WEAK;

  // Check the password length.
  if (strlen(password) < MIN_PASSWORD_LENGTH) {
    // The password is too short.
    return password_strength;
  } else if (strlen(password) > MAX_PASSWORD_LENGTH) {
    // The password is too long.
    return password_strength;
  }

  // Initialize the character class flags.
  int character_classes = 0;

  // Check the password characters.
  for (int i = 0; i < strlen(password); i++) {
    // Check if the character is lowercase.
    if (password[i] >= 'a' && password[i] <= 'z') {
      character_classes |= CHARACTER_CLASS_LOWERCASE;
    }
    // Check if the character is uppercase.
    else if (password[i] >= 'A' && password[i] <= 'Z') {
      character_classes |= CHARACTER_CLASS_UPPERCASE;
    }
    // Check if the character is a digit.
    else if (password[i] >= '0' && password[i] <= '9') {
      character_classes |= CHARACTER_CLASS_DIGIT;
    }
    // Check if the character is a symbol.
    else {
      character_classes |= CHARACTER_CLASS_SYMBOL;
    }
  }

  // Check if the password contains all four character classes.
  if (character_classes == (CHARACTER_CLASS_LOWERCASE | CHARACTER_CLASS_UPPERCASE | CHARACTER_CLASS_DIGIT | CHARACTER_CLASS_SYMBOL)) {
    // The password is strong.
    password_strength = PASSWORD_STRENGTH_STRONG;
  } else if (character_classes == (CHARACTER_CLASS_LOWERCASE | CHARACTER_CLASS_UPPERCASE | CHARACTER_CLASS_DIGIT)) {
    // The password is medium.
    password_strength = PASSWORD_STRENGTH_MEDIUM;
  }

  // Return the password strength.
  return password_strength;
}

// Get the password strength message for a given password strength.
const char *get_password_strength_message(int password_strength) {
  // Return the password strength message.
  return password_strength_messages[password_strength];
}

// Main function.
int main(void) {
  // Get the password from the user.
  char password[MAX_PASSWORD_LENGTH + 1];
  printf("Enter your password: ");
  scanf("%s", password);

  // Check the password strength.
  int password_strength = check_password_strength(password);

  // Get the password strength message.
  const char *password_strength_message = get_password_strength_message(password_strength);

  // Print the password strength message.
  printf("Your password strength is: %s\n", password_strength_message);

  // Return 0 to indicate success.
  return 0;
}