//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN_LENGTH 8
#define MAX_LENGTH 64

#define STRENGTH_WEAK 0
#define STRENGTH_MEDIUM 1
#define STRENGTH_STRONG 2

int main() {
  char password[MAX_LENGTH + 1];
  int strength;

  printf("Enter a password: ");
  scanf("%s", password);

  // Check the length of the password.
  if (strlen(password) < MIN_LENGTH) {
    strength = STRENGTH_WEAK;
  } else if (strlen(password) >= MIN_LENGTH && strlen(password) <= MAX_LENGTH) {
    // Check the complexity of the password.
    int hasUppercase = 0;
    int hasLowercase = 0;
    int hasDigit = 0;
    int hasSpecialCharacter = 0;

    for (int i = 0; i < strlen(password); i++) {
      if (password[i] >= 'A' && password[i] <= 'Z') {
        hasUppercase = 1;
      } else if (password[i] >= 'a' && password[i] <= 'z') {
        hasLowercase = 1;
      } else if (password[i] >= '0' && password[i] <= '9') {
        hasDigit = 1;
      } else {
        hasSpecialCharacter = 1;
      }
    }

    if (hasUppercase && hasLowercase && hasDigit && hasSpecialCharacter) {
      strength = STRENGTH_STRONG;
    } else if ((hasUppercase && hasLowercase) || (hasUppercase && hasDigit) || (hasLowercase && hasDigit)) {
      strength = STRENGTH_MEDIUM;
    } else {
      strength = STRENGTH_WEAK;
    }
  } else {
    strength = STRENGTH_WEAK;
  }

  // Print the strength of the password.
  switch (strength) {
    case STRENGTH_WEAK:
      printf("Your password is weak.\n");
      break;
    case STRENGTH_MEDIUM:
      printf("Your password is medium.\n");
      break;
    case STRENGTH_STRONG:
      printf("Your password is strong.\n");
      break;
  }

  return 0;
}