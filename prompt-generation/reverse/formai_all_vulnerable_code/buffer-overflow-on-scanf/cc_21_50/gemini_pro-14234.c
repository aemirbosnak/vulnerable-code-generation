//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MIN_LENGTH 8
#define MAX_LENGTH 64

int main() {
  char password[MAX_LENGTH + 1];

  printf("Enter a password: ");
  scanf("%s", password);

  int strength = 0;

  // Check the length of the password.
  if (strlen(password) < MIN_LENGTH) {
    printf("Password is too short. It must be at least %d characters long.\n", MIN_LENGTH);
  } else if (strlen(password) > MAX_LENGTH) {
    printf("Password is too long. It must be at most %d characters long.\n", MAX_LENGTH);
  } else {
    strength++;
  }

  // Check if the password contains at least one uppercase letter.
  int has_uppercase = 0;
  for (int i = 0; i < strlen(password); i++) {
    if (isupper(password[i])) {
      has_uppercase = 1;
      break;
    }
  }
  if (has_uppercase) {
    strength++;
  }

  // Check if the password contains at least one lowercase letter.
  int has_lowercase = 0;
  for (int i = 0; i < strlen(password); i++) {
    if (islower(password[i])) {
      has_lowercase = 1;
      break;
    }
  }
  if (has_lowercase) {
    strength++;
  }

  // Check if the password contains at least one digit.
  int has_digit = 0;
  for (int i = 0; i < strlen(password); i++) {
    if (isdigit(password[i])) {
      has_digit = 1;
      break;
    }
  }
  if (has_digit) {
    strength++;
  }

  // Check if the password contains at least one special character.
  int has_special = 0;
  for (int i = 0; i < strlen(password); i++) {
    if (!isalnum(password[i])) {
      has_special = 1;
      break;
    }
  }
  if (has_special) {
    strength++;
  }

  // Print the password strength.
  switch (strength) {
    case 0:
      printf("Password is very weak.\n");
      break;
    case 1:
      printf("Password is weak.\n");
      break;
    case 2:
      printf("Password is mediocre.\n");
      break;
    case 3:
      printf("Password is strong.\n");
      break;
    case 4:
      printf("Password is very strong.\n");
      break;
    case 5:
      printf("Password is extremely strong.\n");
      break;
  }

  return 0;
}