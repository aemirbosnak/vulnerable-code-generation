//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constants for password strength levels
#define STRENGTH_WEAK 0
#define STRENGTH_MEDIUM 1
#define STRENGTH_STRONG 2

// Function to check password strength
int checkPasswordStrength(char *password) {
  int strength = 0;

  // Check for length
  if (strlen(password) < 8) {
    strength++;
  }

  // Check for uppercase characters
  int hasUppercase = 0;
  for (int i = 0; i < strlen(password); i++) {
    if (password[i] >= 'A' && password[i] <= 'Z') {
      hasUppercase = 1;
      break;
    }
  }
  if (!hasUppercase) {
    strength++;
  }

  // Check for lowercase characters
  int hasLowercase = 0;
  for (int i = 0; i < strlen(password); i++) {
    if (password[i] >= 'a' && password[i] <= 'z') {
      hasLowercase = 1;
      break;
    }
  }
  if (!hasLowercase) {
    strength++;
  }

  // Check for digits
  int hasDigits = 0;
  for (int i = 0; i < strlen(password); i++) {
    if (password[i] >= '0' && password[i] <= '9') {
      hasDigits = 1;
      break;
    }
  }
  if (!hasDigits) {
    strength++;
  }

  // Check for special characters
  int hasSpecial = 0;
  for (int i = 0; i < strlen(password); i++) {
    if (password[i] < ' ' || password[i] > '~') {
      hasSpecial = 1;
      break;
    }
  }
  if (!hasSpecial) {
    strength++;
  }

  return strength;
}

// Main function
int main() {
  char password[100];

  // Get password from user
  printf("Enter password: ");
  scanf("%s", password);

  // Check password strength
  int strength = checkPasswordStrength(password);

  // Print password strength
  switch (strength) {
    case STRENGTH_WEAK:
      printf("Password is weak\n");
      break;
    case STRENGTH_MEDIUM:
      printf("Password is medium\n");
      break;
    case STRENGTH_STRONG:
      printf("Password is strong\n");
      break;
  }

  return 0;
}