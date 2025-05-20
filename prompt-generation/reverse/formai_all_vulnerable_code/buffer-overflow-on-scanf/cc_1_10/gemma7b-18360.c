//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

#define PASSWORD_MAX_LENGTH 256

typedef struct PasswordStrength {
  int strength;
  char message[256];
} PasswordStrength;

PasswordStrength check_password_strength(char *password) {
  PasswordStrength ps;
  ps.strength = 0;
  ps.message[0] = '\0';

  if (strlen(password) < 8) {
    strcat(ps.message, "Password too short. ");
  } else if (strlen(password) >= 8 && strlen(password) < 16) {
    ps.strength = 1;
    strcat(ps.message, "Weak password. ");
  } else if (strlen(password) >= 16) {
    ps.strength = 2;
    strcat(ps.message, "Strong password. ");
  }

  if (strstr(password, "admin") || strstr(password, "root") || strstr(password, "password")) {
    strcat(ps.message, "Avoid using common words. ");
  }

  if (islower(password[0]) || isupper(password[0])) {
    strcat(ps.message, "Consider using a lowercase or uppercase letter. ");
  }

  if (isdigit(password[0]) || isalpha(password[0])) {
    strcat(ps.message, "Consider using a letter or symbol instead of a number. ");
  }

  return ps;
}

int main() {
  char password[PASSWORD_MAX_LENGTH];
  printf("Enter your password: ");
  scanf("%s", password);

  PasswordStrength ps = check_password_strength(password);

  if (ps.strength == 0) {
    printf("Your password is very weak. Please try again.\n");
  } else if (ps.strength == 1) {
    printf("Your password is weak. Please consider changing it.\n");
  } else if (ps.strength == 2) {
    printf("Your password is strong. Good job!\n");
  }

  printf("Message: %s\n", ps.message);

  return 0;
}