//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if the password is strong enough
int checkPasswordStrength(char *password) {
  int score = 0;
  int length = strlen(password);

  // Check the length of the password
  if (length < 8) {
    printf("Password is too short! ");
  } else if (length > 20) {
    printf("Password is too long! ");
  } else {
    score += 4;
  }

  // Check for uppercase letters
  int hasUppercase = 0;
  for (int i = 0; i < length; i++) {
    if (password[i] >= 'A' && password[i] <= 'Z') {
      hasUppercase = 1;
      break;
    }
  }
  if (hasUppercase) {
    score += 2;
  }

  // Check for lowercase letters
  int hasLowercase = 0;
  for (int i = 0; i < length; i++) {
    if (password[i] >= 'a' && password[i] <= 'z') {
      hasLowercase = 1;
      break;
    }
  }
  if (hasLowercase) {
    score += 2;
  }

  // Check for digits
  int hasDigit = 0;
  for (int i = 0; i < length; i++) {
    if (password[i] >= '0' && password[i] <= '9') {
      hasDigit = 1;
      break;
    }
  }
  if (hasDigit) {
    score += 2;
  }

  // Check for special characters
  int hasSpecialCharacter = 0;
  for (int i = 0; i < length; i++) {
    if (password[i] == '!' || password[i] == '@' || password[i] == '#' || password[i] == '$' || password[i] == '%' || password[i] == '^' || password[i] == '&' || password[i] == '*') {
      hasSpecialCharacter = 1;
      break;
    }
  }
  if (hasSpecialCharacter) {
    score += 2;
  }

  // Return the score
  return score;
}

int main() {
  // Get the password from the user
  char password[100];
  printf("Enter your password: ");
  scanf("%s", password);

  // Check the strength of the password
  int score = checkPasswordStrength(password);

  // Print the result
  if (score >= 8) {
    printf("Your password is strong! ");
  } else if (score >= 6) {
    printf("Your password is medium! ");
  } else {
    printf("Your password is weak! ");
  }

  return 0;
}