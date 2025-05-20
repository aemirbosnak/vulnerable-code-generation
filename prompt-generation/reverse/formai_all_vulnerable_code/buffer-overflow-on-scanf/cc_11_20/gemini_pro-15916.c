//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Password strength meter
int passwordStrength(char *password) {
  int strength = 0;

  // Check length
  if (strlen(password) >= 8) {
    strength++;
  }

  // Check for lowercase letters
  int hasLower = 0;
  for (int i = 0; i < strlen(password); i++) {
    if (password[i] >= 'a' && password[i] <= 'z') {
      hasLower = 1;
      break;
    }
  }
  if (hasLower) {
    strength++;
  }

  // Check for uppercase letters
  int hasUpper = 0;
  for (int i = 0; i < strlen(password); i++) {
    if (password[i] >= 'A' && password[i] <= 'Z') {
      hasUpper = 1;
      break;
    }
  }
  if (hasUpper) {
    strength++;
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
    strength++;
  }

  // Check for special characters
  int hasSpecial = 0;
  char specialChars[] = "!@#$%^&*()-_=+";
  for (int i = 0; i < strlen(password); i++) {
    for (int j = 0; j < strlen(specialChars); j++) {
      if (password[i] == specialChars[j]) {
        hasSpecial = 1;
        break;
      }
    }
    if (hasSpecial) {
      break;
    }
  }
  if (hasSpecial) {
    strength++;
  }

  // Check for repeated characters
  int hasRepeated = 0;
  for (int i = 0; i < strlen(password) - 1; i++) {
    if (password[i] == password[i + 1]) {
      hasRepeated = 1;
      break;
    }
  }
  if (!hasRepeated) {
    strength++;
  }

  return strength;
}

int main() {
  // Get password from user
  char password[100];
  printf("Enter password: ");
  scanf("%s", password);

  // Check password strength
  int strength = passwordStrength(password);

  // Print strength
  switch (strength) {
    case 0:
      printf("Weak");
      break;
    case 1:
      printf("Fair");
      break;
    case 2:
      printf("Good");
      break;
    case 3:
      printf("Strong");
      break;
    case 4:
      printf("Excellent");
      break;
    case 5:
      printf("Legendary");
      break;
    case 6:
      printf("Godly");
      break;
    default:
      printf("Invalid");
  }

  return 0;
}