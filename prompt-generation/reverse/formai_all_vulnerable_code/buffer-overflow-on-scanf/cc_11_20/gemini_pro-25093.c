//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN_LENGTH 8
#define MAX_LENGTH 64

// Function to check password strength
int checkPasswordStrength(char *password) {
  int strength = 0;

  // Check password length
  if (strlen(password) < MIN_LENGTH) {
    strength += 1;
  } else if (strlen(password) > MAX_LENGTH) {
    strength += 1;
  }

  // Check password for lowercase characters
  int hasLowercase = 0;
  for (int i = 0; i < strlen(password); i++) {
    if (password[i] >= 'a' && password[i] <= 'z') {
      hasLowercase = 1;
    }
  }
  if (!hasLowercase) {
    strength += 1;
  }

  // Check password for uppercase characters
  int hasUppercase = 0;
  for (int i = 0; i < strlen(password); i++) {
    if (password[i] >= 'A' && password[i] <= 'Z') {
      hasUppercase = 1;
    }
  }
  if (!hasUppercase) {
    strength += 1;
  }

  // Check password for digits
  int hasDigit = 0;
  for (int i = 0; i < strlen(password); i++) {
    if (password[i] >= '0' && password[i] <= '9') {
      hasDigit = 1;
    }
  }
  if (!hasDigit) {
    strength += 1;
  }

  // Check password for special characters
  int hasSpecialChar = 0;
  for (int i = 0; i < strlen(password); i++) {
    if (!((password[i] >= 'a' && password[i] <= 'z') ||
            (password[i] >= 'A' && password[i] <= 'Z') ||
            (password[i] >= '0' && password[i] <= '9'))) {
      hasSpecialChar = 1;
    }
  }
  if (!hasSpecialChar) {
    strength += 1;
  }

  // Return password strength
  return strength;
}

// Main function
int main() {
  // Get password from user
  char password[MAX_LENGTH + 1];
  printf("Enter password: ");
  scanf("%s", password);

  // Check password strength
  int strength = checkPasswordStrength(password);

  // Print password strength
  switch (strength) {
    case 0:
      printf("Password is very strong!\n");
      break;
    case 1:
      printf("Password is strong!\n");
      break;
    case 2:
      printf("Password is moderate!\n");
      break;
    case 3:
      printf("Password is weak!\n");
      break;
    case 4:
      printf("Password is very weak!\n");
      break;
    default:
      printf("Invalid password!\n");
  }

  return 0;
}