//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MIN_LENGTH 8
#define MAX_LENGTH 64

int check_password_strength(char *password);

int main() {
  char password[MAX_LENGTH + 1];

  printf("Enter a password: ");
  scanf("%s", password);

  int strength = check_password_strength(password);

  switch (strength) {
    case 0:
      printf("The password is very weak.\n");
      break;
    case 1:
      printf("The password is weak.\n");
      break;
    case 2:
      printf("The password is strong.\n");
      break;
    case 3:
      printf("The password is very strong.\n");
      break;
  }

  return 0;
}

int check_password_strength(char *password) {
  int strength = 0;

  // Check the length of the password.
  if (strlen(password) < MIN_LENGTH) {
    return 0;
  } else if (strlen(password) > MAX_LENGTH) {
    return 0;
  }

  // Check for uppercase letters.
  int has_uppercase = 0;
  for (int i = 0; i < strlen(password); i++) {
    if (isupper(password[i])) {
      has_uppercase = 1;
      break;
    }
  }

  // Check for lowercase letters.
  int has_lowercase = 0;
  for (int i = 0; i < strlen(password); i++) {
    if (islower(password[i])) {
      has_lowercase = 1;
      break;
    }
  }

  // Check for digits.
  int has_digit = 0;
  for (int i = 0; i < strlen(password); i++) {
    if (isdigit(password[i])) {
      has_digit = 1;
      break;
    }
  }

  // Check for special characters.
  int has_special = 0;
  for (int i = 0; i < strlen(password); i++) {
    if (!isalnum(password[i])) {
      has_special = 1;
      break;
    }
  }

  // Assign strength based on the checks.
  if (has_uppercase && has_lowercase && has_digit && has_special) {
    strength = 3;
  } else if (has_uppercase && has_lowercase && has_digit) {
    strength = 2;
  } else if (has_uppercase && has_lowercase) {
    strength = 1;
  }

  return strength;
}