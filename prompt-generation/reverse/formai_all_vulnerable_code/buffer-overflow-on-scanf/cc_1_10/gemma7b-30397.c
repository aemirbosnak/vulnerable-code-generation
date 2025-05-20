//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: modular
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_PASSWORD_LENGTH 128

typedef struct PasswordStrength {
  int strength;
  char message[256];
} PasswordStrength;

PasswordStrength check_password_strength(char *password) {
  PasswordStrength strength = {0, ""};

  // Check for minimum length
  if (strlen(password) < 8) {
    strength.strength = 1;
    strcpy(strength.message, "Password is too short.");
  }

  // Check for uppercase letter
  if (!strchr(password, 'A')) {
    strength.strength = 2;
    strcpy(strength.message, "Password needs an uppercase letter.");
  }

  // Check for lowercase letter
  if (!strchr(password, 'a')) {
    strength.strength = 3;
    strcpy(strength.message, "Password needs a lowercase letter.");
  }

  // Check for number
  if (!strchr(password, '0') || !strchr(password, '9')) {
    strength.strength = 4;
    strcpy(strength.message, "Password needs a number.");
  }

  // Check for special character
  if (!strchr(password, '$') && !strchr(password, '%') && !strchr(password, '^') &&
    !strchr(password, '&') && !strchr(password, '*')) {
    strength.strength = 5;
    strcpy(strength.message, "Password needs a special character.");
  }

  return strength;
}

int main() {
  char password[MAX_PASSWORD_LENGTH];

  printf("Enter password: ");
  scanf("%s", password);

  PasswordStrength strength = check_password_strength(password);

  switch (strength.strength) {
    case 0:
      printf("Password is strong.\n");
      break;
    case 1:
      printf("Password is weak. %s\n", strength.message);
      break;
    case 2:
      printf("Password is weak. %s\n", strength.message);
      break;
    case 3:
      printf("Password is weak. %s\n", strength.message);
      break;
    case 4:
      printf("Password is weak. %s\n", strength.message);
      break;
    case 5:
      printf("Password is weak. %s\n", strength.message);
      break;
  }

  return 0;
}