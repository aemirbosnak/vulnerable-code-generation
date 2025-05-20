//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define PASSWORD_MAX_LENGTH 128

int main() {
  char password[PASSWORD_MAX_LENGTH];
  int password_length;
  int strength = 0;

  printf("Enter a password: ");
  scanf("%s", password);
  password_length = strlen(password);

  if (password_length < 8) {
    strength = strength + 1;
  }

  if (hasUppercase(password)) {
    strength = strength + 1;
  }

  if (hasNumber(password)) {
    strength = strength + 1;
  }

  if (hasSymbol(password)) {
    strength = strength + 1;
  }

  switch (strength) {
    case 0:
      printf("Password strength: Weak\n");
      break;
    case 1:
      printf("Password strength: Moderate\n");
      break;
    case 2:
      printf("Password strength: Strong\n");
      break;
    case 3:
      printf("Password strength: Very Strong\n");
      break;
    default:
      printf("Error: Invalid password strength\n");
  }

  return 0;
}

int hasUppercase(char *password) {
  for (int i = 0; password[i] != '\0'; i++) {
    if (password[i] >= 'A' && password[i] <= 'Z') {
      return 1;
    }
  }

  return 0;
}

int hasNumber(char *password) {
  for (int i = 0; password[i] != '\0'; i++) {
    if (password[i] >= '0' && password[i] <= '9') {
      return 1;
    }
  }

  return 0;
}

int hasSymbol(char *password) {
  for (int i = 0; password[i] != '\0'; i++) {
    if (password[i] >= '!' && password[i] <= '~') {
      return 1;
    }
  }

  return 0;
}