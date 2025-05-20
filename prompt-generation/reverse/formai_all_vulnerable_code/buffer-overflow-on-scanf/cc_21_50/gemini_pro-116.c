//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN_PASS_LEN 8

int main() {
  char password[100];
  int passwordStrength;

  printf("Enter your password: ");
  scanf("%s", password);

  // Check password length
  if (strlen(password) < MIN_PASS_LEN) {
    passwordStrength = 0;
    printf("Password is too short.\n");
  } else {
    // Check for uppercase letters
    int hasUppercase = 0;
    for (int i = 0; i < strlen(password); i++) {
      if (password[i] >= 'A' && password[i] <= 'Z') {
        hasUppercase = 1;
        break;
      }
    }

    // Check for lowercase letters
    int hasLowercase = 0;
    for (int i = 0; i < strlen(password); i++) {
      if (password[i] >= 'a' && password[i] <= 'z') {
        hasLowercase = 1;
        break;
      }
    }

    // Check for numbers
    int hasNumber = 0;
    for (int i = 0; i < strlen(password); i++) {
      if (password[i] >= '0' && password[i] <= '9') {
        hasNumber = 1;
        break;
      }
    }

    // Check for special characters
    int hasSpecialChar = 0;
    for (int i = 0; i < strlen(password); i++) {
      if (password[i] < 'A' || password[i] > 'Z' && password[i] < 'a' || password[i] > 'z' && password[i] < '0' || password[i] > '9') {
        hasSpecialChar = 1;
        break;
      }
    }

    // Calculate password strength
    passwordStrength = hasUppercase + hasLowercase + hasNumber + hasSpecialChar;

    // Print password strength
    switch (passwordStrength) {
      case 0:
        printf("Password strength: Very weak\n");
        break;
      case 1:
        printf("Password strength: Weak\n");
        break;
      case 2:
        printf("Password strength: Moderate\n");
        break;
      case 3:
        printf("Password strength: Strong\n");
        break;
      case 4:
        printf("Password strength: Very strong\n");
        break;
    }
  }

  return 0;
}