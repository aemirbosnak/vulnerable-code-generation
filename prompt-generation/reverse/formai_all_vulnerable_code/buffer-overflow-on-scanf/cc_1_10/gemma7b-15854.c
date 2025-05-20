//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define PASSWORD_MAX_LENGTH 256

typedef struct PasswordStrength {
  int strength;
  char message[128];
} PasswordStrength;

PasswordStrength checkPasswordStrength(char *password) {
  PasswordStrength strength = {0, ""};

  if (strlen(password) < 8) {
    strength.strength = 1;
    strcpy(strength.message, "Password too short!");
  } else if (strlen(password) >= 8 && strlen(password) < 12) {
    strength.strength = 2;
    strcpy(strength.message, "Weak password!");
  } else if (strlen(password) >= 12) {
    strength.strength = 3;
    strcpy(strength.message, "Strong password!");
  }

  return strength;
}

int main() {
  char password[PASSWORD_MAX_LENGTH];

  printf("Enter your password: ");
  scanf("%s", password);

  PasswordStrength strength = checkPasswordStrength(password);

  switch (strength.strength) {
    case 1:
      printf("Error: Password too short! Please use at least 8 characters.\n");
      break;
    case 2:
      printf("Warning: Weak password! Please use more characters or special symbols.\n");
      break;
    case 3:
      printf("Good: Strong password! You're safe.\n");
      break;
  }

  return 0;
}