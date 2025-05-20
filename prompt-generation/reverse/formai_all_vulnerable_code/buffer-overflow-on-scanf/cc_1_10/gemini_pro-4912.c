//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the minimum password length
#define MIN_PASSWORD_LENGTH 8

// Define the maximum password length
#define MAX_PASSWORD_LENGTH 64

// Define the password strength levels
#define PASSWORD_STRENGTH_WEAK 0
#define PASSWORD_STRENGTH_MEDIUM 1
#define PASSWORD_STRENGTH_STRONG 2

// Define the password character types
#define PASSWORD_CHARACTER_TYPE_UPPERCASE 0
#define PASSWORD_CHARACTER_TYPE_LOWERCASE 1
#define PASSWORD_CHARACTER_TYPE_DIGIT 2
#define PASSWORD_CHARACTER_TYPE_SYMBOL 3

// Define the password character type weights
#define PASSWORD_CHARACTER_TYPE_WEIGHT_UPPERCASE 3
#define PASSWORD_CHARACTER_TYPE_WEIGHT_LOWERCASE 2
#define PASSWORD_CHARACTER_TYPE_WEIGHT_DIGIT 1
#define PASSWORD_CHARACTER_TYPE_WEIGHT_SYMBOL 4

// Define the password strength calculation function
int calculate_password_strength(char *password) {
  // Initialize the password strength
  int password_strength = PASSWORD_STRENGTH_WEAK;

  // Check the password length
  if (strlen(password) < MIN_PASSWORD_LENGTH) {
    return PASSWORD_STRENGTH_WEAK;
  } else if (strlen(password) > MAX_PASSWORD_LENGTH) {
    return PASSWORD_STRENGTH_WEAK;
  }

  // Check the password character types
  int password_character_types[4] = {0, 0, 0, 0};
  for (int i = 0; i < strlen(password); i++) {
    if (password[i] >= 'A' && password[i] <= 'Z') {
      password_character_types[PASSWORD_CHARACTER_TYPE_UPPERCASE] = 1;
    } else if (password[i] >= 'a' && password[i] <= 'z') {
      password_character_types[PASSWORD_CHARACTER_TYPE_LOWERCASE] = 1;
    } else if (password[i] >= '0' && password[i] <= '9') {
      password_character_types[PASSWORD_CHARACTER_TYPE_DIGIT] = 1;
    } else {
      password_character_types[PASSWORD_CHARACTER_TYPE_SYMBOL] = 1;
    }
  }

  // Calculate the password strength
  for (int i = 0; i < 4; i++) {
    password_strength += password_character_types[i] * PASSWORD_CHARACTER_TYPE_WEIGHT_UPPERCASE;
  }

  return password_strength;
}

// Define the main function
int main() {
  // Get the password from the user
  char password[MAX_PASSWORD_LENGTH + 1];
  printf("Enter your password: ");
  scanf("%s", password);

  // Calculate the password strength
  int password_strength = calculate_password_strength(password);

  // Print the password strength
  switch (password_strength) {
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