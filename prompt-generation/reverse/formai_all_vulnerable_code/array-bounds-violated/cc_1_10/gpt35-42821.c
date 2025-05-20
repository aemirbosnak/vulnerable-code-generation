//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORD_LENGTH 20

int checkLength(char* password) {
  return strlen(password) >= 8 && strlen(password) <= MAX_PASSWORD_LENGTH;
}

int checkUppercase(char* password) {
  int is_uppercase = 0;
  for (int i = 0; i < strlen(password); i++) {
    if (isupper(password[i])) {
      is_uppercase = 1;
      break;
    }
  }
  return is_uppercase;
}

int checkLowercase(char* password) {
  int is_lowercase = 0;
  for (int i = 0; i < strlen(password); i++) {
    if (islower(password[i])) {
      is_lowercase = 1;
      break;
    }
  }
  return is_lowercase;
}

int checkDigit(char* password) {
  int has_digit = 0;
  for (int i = 0; i < strlen(password); i++) {
    if (isdigit(password[i])) {
      has_digit = 1;
      break;
    }
  }
  return has_digit;
}

int checkSymbol(char* password) {
  int has_symbol = 0;
  for (int i = 0; i < strlen(password); i++) {
    if (!(isdigit(password[i]) || isalpha(password[i]))) {
      has_symbol = 1;
      break;
    }
  }
  return has_symbol;
}

int main() {
  printf("Welcome to the Password Strength Checker!\n");
  printf("Please enter your password: ");

  char password[MAX_PASSWORD_LENGTH + 1];
  fgets(password, MAX_PASSWORD_LENGTH + 1, stdin);

  if (password[strlen(password) - 1] == '\n') {
    password[strlen(password) - 1] = '\0';
  }

  if (!checkLength(password)) {
    printf("Your password must be between 8 and %d characters long.\n", MAX_PASSWORD_LENGTH);
    exit(0);
  }

  if (!checkUppercase(password)) {
    printf("Your password must contain at least one uppercase letter.\n");
    exit(0);
  }

  if (!checkLowercase(password)) {
    printf("Your password must contain at least one lowercase letter.\n");
    exit(0);
  }

  if (!checkDigit(password)) {
    printf("Your password must contain at least one digit.\n");
    exit(0);
  }

  if (!checkSymbol(password)) {
    printf("Your password must contain at least one symbol.\n");
    exit(0);
  }

  printf("Your password is strong!\n");
  return 0;
}