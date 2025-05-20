//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Function to check if the password is strong
bool isStrongPassword(char *password) {
  // Check if the password is at least 8 characters long
  if (strlen(password) < 8) {
    return false;
  }

  // Check if the password contains at least one uppercase letter
  bool hasUppercase = false;
  for (int i = 0; i < strlen(password); i++) {
    if (password[i] >= 'A' && password[i] <= 'Z') {
      hasUppercase = true;
      break;
    }
  }
  if (!hasUppercase) {
    return false;
  }

  // Check if the password contains at least one lowercase letter
  bool hasLowercase = false;
  for (int i = 0; i < strlen(password); i++) {
    if (password[i] >= 'a' && password[i] <= 'z') {
      hasLowercase = true;
      break;
    }
  }
  if (!hasLowercase) {
    return false;
  }

  // Check if the password contains at least one digit
  bool hasDigit = false;
  for (int i = 0; i < strlen(password); i++) {
    if (password[i] >= '0' && password[i] <= '9') {
      hasDigit = true;
      break;
    }
  }
  if (!hasDigit) {
    return false;
  }

  // Check if the password contains at least one special character
  bool hasSpecialCharacter = false;
  for (int i = 0; i < strlen(password); i++) {
    if (password[i] == '!' || password[i] == '@' || password[i] == '#' || password[i] == '$' || password[i] == '%') {
      hasSpecialCharacter = true;
      break;
    }
  }
  if (!hasSpecialCharacter) {
    return false;
  }

  // If all the checks pass, the password is strong
  return true;
}

int main() {
  // Get the password from the user
  char password[101];  
  printf("Enter a strong password: ");
  gets(password);

  // Check if the password is strong
  if (isStrongPassword(password)) {
    printf("The password is strong.\n");
  } else {
    printf("The password is not strong.\n");
  }

  return 0;
}