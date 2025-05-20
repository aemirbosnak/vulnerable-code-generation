//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: invasive
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
  char password[101];
  int strength;

  printf("Enter your password: ");
  scanf("%s", password);

  strength = 0;

  // Check the password length.
  if (strlen(password) >= 8) {
    strength++;
  }

  // Check for uppercase letters.
  for (int i = 0; i < strlen(password); i++) {
    if (isupper(password[i])) {
      strength++;
      break;
    }
  }

  // Check for lowercase letters.
  for (int i = 0; i < strlen(password); i++) {
    if (islower(password[i])) {
      strength++;
      break;
    }
  }

  // Check for digits.
  for (int i = 0; i < strlen(password); i++) {
    if (isdigit(password[i])) {
      strength++;
      break;
    }
  }

  // Check for special characters.
  for (int i = 0; i < strlen(password); i++) {
    if (!isalnum(password[i])) {
      strength++;
      break;
    }
  }

  // Check for common passwords.
  char common_passwords[][101] = {"password", "123456", "12345678", "qwerty", "abc123"};
  for (int i = 0; i < sizeof(common_passwords) / sizeof(common_passwords[0]); i++) {
    if (strcmp(password, common_passwords[i]) == 0) {
      strength = 0;
      break;
    }
  }

  // Print the password strength.
  switch (strength) {
    case 0:
      printf("Your password is very weak.\n");
      break;
    case 1:
      printf("Your password is weak.\n");
      break;
    case 2:
      printf("Your password is moderate.\n");
      break;
    case 3:
      printf("Your password is strong.\n");
      break;
    case 4:
      printf("Your password is very strong.\n");
      break;
    default:
      printf("Your password is not valid.\n");
  }

  return 0;
}