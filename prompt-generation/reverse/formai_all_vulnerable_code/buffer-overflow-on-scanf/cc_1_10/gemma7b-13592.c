//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: Cyberpunk
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define PASSWORD_MAX_LENGTH 256

typedef struct PasswordStrength {
  int strength;
  char message[256];
} PasswordStrength;

PasswordStrength check_password_strength(char *password) {
  PasswordStrength strength = {0, ""};

  if (strlen(password) < 8) {
    strength.strength = 1;
    strcpy(strength.message, "Password too short!");
  } else if (strlen(password) < 16) {
    strength.strength = 2;
    strcpy(strength.message, "Password needs more characters!");
  } else if (strlen(password) < 24) {
    strength.strength = 3;
    strcpy(strength.message, "Password is acceptable!");
  } else {
    strength.strength = 4;
    strcpy(strength.message, "Strong password!");
  }

  return strength;
}

int main() {
  char password[PASSWORD_MAX_LENGTH];

  printf("Enter your password: ");
  scanf("%s", password);

  PasswordStrength strength = check_password_strength(password);

  switch (strength.strength) {
    case 1:
      printf("Password too short!\n");
      break;
    case 2:
      printf("Password needs more characters!\n");
      break;
    case 3:
      printf("Password is acceptable!\n");
      break;
    case 4:
      printf("Strong password!\n");
      break;
  }

  return 0;
}