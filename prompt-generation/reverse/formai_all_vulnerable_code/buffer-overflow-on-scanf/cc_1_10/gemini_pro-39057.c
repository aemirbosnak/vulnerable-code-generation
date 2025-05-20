//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare the shock function
void shock(const char *message);

int main(void) {
  // Get the password from the user
  char password[101];
  printf("Enter your password: ");
  scanf("%s", password);

  // Check the length of the password
  int length = strlen(password);
  if (length < 8) {
    shock("Your password is too short!");
    return 1;
  }

  // Check for uppercase letters
  int hasUppercase = 0;
  for (int i = 0; i < length; i++) {
    if (password[i] >= 'A' && password[i] <= 'Z') {
      hasUppercase = 1;
      break;
    }
  }
  if (!hasUppercase) {
    shock("Your password does not contain any uppercase letters!");
    return 1;
  }

  // Check for lowercase letters
  int hasLowercase = 0;
  for (int i = 0; i < length; i++) {
    if (password[i] >= 'a' && password[i] <= 'z') {
      hasLowercase = 1;
      break;
    }
  }
  if (!hasLowercase) {
    shock("Your password does not contain any lowercase letters!");
    return 1;
  }

  // Check for digits
  int hasDigit = 0;
  for (int i = 0; i < length; i++) {
    if (password[i] >= '0' && password[i] <= '9') {
      hasDigit = 1;
      break;
    }
  }
  if (!hasDigit) {
    shock("Your password does not contain any digits!");
    return 1;
  }

  // Check for special characters
  int hasSpecialChar = 0;
  for (int i = 0; i < length; i++) {
    if (!isalnum(password[i])) {
      hasSpecialChar = 1;
      break;
    }
  }
  if (!hasSpecialChar) {
    shock("Your password does not contain any special characters!");
    return 1;
  }

  // If all the checks pass, the password is strong
  printf("Your password is strong!\n");
  return 0;
}

// Define the shock function
void shock(const char *message) {
  printf("\n%s\n\n", message);
  exit(1);
}