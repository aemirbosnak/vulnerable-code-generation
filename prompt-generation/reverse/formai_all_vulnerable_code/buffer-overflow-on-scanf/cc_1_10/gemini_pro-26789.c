//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the minimum password length
#define MIN_PASSWORD_LENGTH 8

// Define the maximum password length
#define MAX_PASSWORD_LENGTH 32

// Define the minimum number of character types required
#define MIN_CHARACTER_TYPES 3

// Define the character types
#define CHARACTER_TYPE_LOWER 0
#define CHARACTER_TYPE_UPPER 1
#define CHARACTER_TYPE_DIGIT 2
#define CHARACTER_TYPE_SYMBOL 3

// Define the number of character types
#define NUM_CHARACTER_TYPES 4

// Define the password strength levels
#define PASSWORD_STRENGTH_WEAK 0
#define PASSWORD_STRENGTH_MEDIUM 1
#define PASSWORD_STRENGTH_STRONG 2

// Declare the password strength function
int checkPasswordStrength(char *password);

int main() {
  // Declare the password variable
  char password[MAX_PASSWORD_LENGTH + 1];

  // Get the password from the user
  printf("Enter your password: ");
  scanf("%s", password);

  // Check the password strength
  int passwordStrength = checkPasswordStrength(password);

  // Print the password strength
  switch (passwordStrength) {
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

// Define the password strength function
int checkPasswordStrength(char *password) {
  // Check the password length
  if (strlen(password) < MIN_PASSWORD_LENGTH) {
    return PASSWORD_STRENGTH_WEAK;
  }

  // Check the number of character types
  int characterTypes[NUM_CHARACTER_TYPES] = {0};
  for (int i = 0; i < strlen(password); i++) {
    if (password[i] >= 'a' && password[i] <= 'z') {
      characterTypes[CHARACTER_TYPE_LOWER] = 1;
    } else if (password[i] >= 'A' && password[i] <= 'Z') {
      characterTypes[CHARACTER_TYPE_UPPER] = 1;
    } else if (password[i] >= '0' && password[i] <= '9') {
      characterTypes[CHARACTER_TYPE_DIGIT] = 1;
    } else {
      characterTypes[CHARACTER_TYPE_SYMBOL] = 1;
    }
  }
  int numCharacterTypes = 0;
  for (int i = 0; i < NUM_CHARACTER_TYPES; i++) {
    numCharacterTypes += characterTypes[i];
  }
  if (numCharacterTypes < MIN_CHARACTER_TYPES) {
    return PASSWORD_STRENGTH_WEAK;
  }

  // Check the password for common patterns
  char commonPatterns[][10] = {"123456", "password", "qwerty", "12345678", "123456789"};
  int numCommonPatterns = sizeof(commonPatterns) / sizeof(commonPatterns[0]);
  for (int i = 0; i < numCommonPatterns; i++) {
    if (strstr(password, commonPatterns[i]) != NULL) {
      return PASSWORD_STRENGTH_WEAK;
    }
  }

  // The password is strong
  return PASSWORD_STRENGTH_STRONG;
}