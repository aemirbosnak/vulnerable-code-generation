//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

// Function to check the strength of a password
int checkPasswordStrength(char *password) {
  int strength = 0;

  // Check the length of the password
  if (strlen(password) < 8) {
    strength += 1;
  } else if (strlen(password) >= 8 && strlen(password) < 12) {
    strength += 2;
  } else if (strlen(password) >= 12) {
    strength += 3;
  }

  // Check for uppercase characters
  int hasUppercase = 0;
  for (int i = 0; i < strlen(password); i++) {
    if (password[i] >= 'A' && password[i] <= 'Z') {
      hasUppercase = 1;
      break;
    }
  }
  if (hasUppercase) {
    strength += 1;
  }

  // Check for lowercase characters
  int hasLowercase = 0;
  for (int i = 0; i < strlen(password); i++) {
    if (password[i] >= 'a' && password[i] <= 'z') {
      hasLowercase = 1;
      break;
    }
  }
  if (hasLowercase) {
    strength += 1;
  }

  // Check for digits
  int hasDigit = 0;
  for (int i = 0; i < strlen(password); i++) {
    if (password[i] >= '0' && password[i] <= '9') {
      hasDigit = 1;
      break;
    }
  }
  if (hasDigit) {
    strength += 1;
  }

  // Check for special characters
  int hasSpecialCharacter = 0;
  for (int i = 0; i < strlen(password); i++) {
    if (password[i] == '!' || password[i] == '@' || password[i] == '#' || password[i] == '$' || password[i] == '%' || password[i] == '^' || password[i] == '&' || password[i] == '*') {
      hasSpecialCharacter = 1;
      break;
    }
  }
  if (hasSpecialCharacter) {
    strength += 1;
  }

  return strength;
}

int main() {
  char password[100];

  printf("Enter your password: ");
  scanf("%s", password);

  int strength = checkPasswordStrength(password);

  if (strength == 1) {
    printf("Your password is weak. Please try again.\n");
  } else if (strength == 2) {
    printf("Your password is moderate. Please try again.\n");
  } else if (strength == 3) {
    printf("Your password is strong. Good job!\n");
  } else if (strength == 4) {
    printf("Your password is very strong. Congratulations!\n");
  } else {
    printf("Your password is extremely strong. You're a security expert!\n");
  }

  return 0;
}