//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>

#define MAX_PASSWD_LENGTH 128

typedef struct PasswordStrength {
  int score;
  char message[256];
} PasswordStrength;

int validatePasswordStrength(char *password) {
  int passwordLength = strlen(password);
  PasswordStrength strength = { 0, "" };

  if (passwordLength < 8) {
    strength.score = 1;
    strcpy(strength.message, "Password too short!");
  } else if (passwordLength >= 8 && passwordLength < 16) {
    strength.score = 2;
    strcpy(strength.message, "Password length is adequate.");
  } else if (passwordLength >= 16) {
    strength.score = 3;
    strcpy(strength.message, "Strong password!");
  }

  return strength.score;
}

int main() {
  char password[MAX_PASSWD_LENGTH];

  printf("Enter a password: ");
  scanf("%s", password);

  int strength = validatePasswordStrength(password);

  switch (strength) {
    case 1:
      printf("Password strength: Weak\n");
      break;
    case 2:
      printf("Password strength: Moderate\n");
      break;
    case 3:
      printf("Password strength: Strong\n");
      break;
  }

  return 0;
}