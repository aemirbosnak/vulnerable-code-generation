//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_PASSWORD_LENGTH 256

void check_password_strength(char *password) {
  int password_length = strlen(password);
  int has_upper = 0, has_lower = 0, has_number = 0, has_symbol = 0;

  // Check for uppercase letter
  for (int i = 0; i < password_length; i++) {
    if (password[i] >= 'A' && password[i] <= 'Z') {
      has_upper = 1;
    }
  }

  // Check for lowercase letter
  for (int i = 0; i < password_length; i++) {
    if (password[i] >= 'a' && password[i] <= 'z') {
      has_lower = 1;
    }
  }

  // Check for number
  for (int i = 0; i < password_length; i++) {
    if (password[i] >= '0' && password[i] <= '9') {
      has_number = 1;
    }
  }

  // Check for symbol
  for (int i = 0; i < password_length; i++) {
    if (password[i] >= '!' && password[i] <= '~') {
      has_symbol = 1;
    }
  }

  // Check for minimum length
  if (password_length < 8) {
    printf("Error: Password must be at least 8 characters long.\n");
  } else if (!has_upper) {
    printf("Error: Password must contain an uppercase letter.\n");
  } else if (!has_lower) {
    printf("Error: Password must contain a lowercase letter.\n");
  } else if (!has_number) {
    printf("Error: Password must contain a number.\n");
  } else if (!has_symbol) {
    printf("Error: Password must contain a symbol.\n");
  } else {
    printf("Password is strong.\n");
  }
}

int main() {
  char password[MAX_PASSWORD_LENGTH];

  printf("Enter your password: ");
  scanf("%s", password);

  check_password_strength(password);

  return 0;
}