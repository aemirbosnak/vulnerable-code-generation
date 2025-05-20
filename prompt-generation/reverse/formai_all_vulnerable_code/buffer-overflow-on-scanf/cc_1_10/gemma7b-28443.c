//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: ultraprecise
#include <stdio.h>
#include <string.h>

#define MIN_PASSWORD_LENGTH 8

int main() {
  char password[MIN_PASSWORD_LENGTH];

  printf("Enter a password: ");
  scanf("%s", password);

  int passwordStrength = checkPasswordStrength(password);

  switch (passwordStrength) {
    case 0:
      printf("Password is very weak.\n");
      break;
    case 1:
      printf("Password is weak.\n");
      break;
    case 2:
      printf("Password is moderately strong.\n");
      break;
    case 3:
      printf("Password is strong.\n");
      break;
    case 4:
      printf("Password is very strong.\n");
      break;
  }

  return 0;
}

int checkPasswordStrength(char *password) {
  int passwordLength = strlen(password);

  if (passwordLength < MIN_PASSWORD_LENGTH) {
    return 0;
  }

  int hasUppercase = 0;
  int hasLowercase = 0;
  int hasNumbers = 0;
  int hasSymbols = 0;

  for (int i = 0; i < passwordLength; i++) {
    if (isupper(password[i])) {
      hasUppercase = 1;
    } else if (islower(password[i])) {
      hasLowercase = 1;
    } else if (isdigit(password[i])) {
      hasNumbers = 1;
    } else if (ispunct(password[i])) {
      hasSymbols = 1;
    }
  }

  int strength = 0;

  if (hasUppercase && hasLowercase && hasNumbers) {
    strength++;
  }

  if (hasSymbols) {
    strength++;
  }

  return strength;
}