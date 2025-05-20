//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the password strength levels
#define WEAK 0
#define MEDIUM 1
#define STRONG 2

// Define the minimum password length
#define MIN_PASSWORD_LENGTH 8

// Define the maximum password length
#define MAX_PASSWORD_LENGTH 32

// Define the character set
#define CHARSET "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789~!@#$%^&*()"

// Define the password strength score calculation function
int calculate_password_strength(char *password) {
  int score = 0;

  // Check the password length
  if (strlen(password) < MIN_PASSWORD_LENGTH) {
    score += 1;
  } else if (strlen(password) > MAX_PASSWORD_LENGTH) {
    score += 1;
  }

  // Check the password character set
  int has_uppercase = 0;
  int has_lowercase = 0;
  int has_digit = 0;
  int has_special_character = 0;
  for (int i = 0; i < strlen(password); i++) {
    if (isupper(password[i])) {
      has_uppercase = 1;
    } else if (islower(password[i])) {
      has_lowercase = 1;
    } else if (isdigit(password[i])) {
      has_digit = 1;
    } else {
      has_special_character = 1;
    }
  }
  score += (has_uppercase + has_lowercase + has_digit + has_special_character);

  // Check the password for common patterns
  char *common_patterns[] = {"password", "123456", "qwerty", "abc123"};
  for (int i = 0; i < sizeof(common_patterns) / sizeof(char *); i++) {
    if (strstr(password, common_patterns[i]) != NULL) {
      score -= 1;
    }
  }

  // Return the password strength score
  return score;
}

// Define the main function
int main() {
  // Prompt the user to enter a password
  printf("Enter a password: ");
  char password[MAX_PASSWORD_LENGTH + 1];
  scanf("%s", password);

  // Calculate the password strength score
  int score = calculate_password_strength(password);

  // Print the password strength level
  switch (score) {
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