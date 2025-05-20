//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int check_password_strength(char *password) {
  // Check for length
  if (strlen(password) < 8) {
    return -1;
  }

  // Check for lowercase, uppercase, digit
  int has_lowercase = 0;
  int has_uppercase = 0;
  int has_digit = 0;
  for (int i = 0; i < strlen(password); i++) {
    if (islower(password[i])) {
      has_lowercase = 1;
    } else if (isupper(password[i])) {
      has_uppercase = 1;
    } else if (isdigit(password[i])) {
      has_digit = 1;
    }
  }

  if (!has_lowercase || !has_uppercase || !has_digit) {
    return -2;
  }

  // Check for common passwords
  char *common_passwords[] = {"password", "123456", "12345678", "qwerty", "abc123", "monkey", "letmein", "dragon", "baseball", "iloveyou"};
  for (int i = 0; i < 10; i++) {
    if (strcmp(password, common_passwords[i]) == 0) {
      return -3;
    }
  }

  // Password is strong
  return 0;
}

int main() {
  // Get password from user
  char password[100];
  printf("Enter password: ");
  scanf("%s", password);

  // Check password strength
  int strength = check_password_strength(password);

  // Print result
  if (strength == -1) {
    printf("Password is too short.\n");
  } else if (strength == -2) {
    printf("Password must contain at least one lowercase letter, one uppercase letter, and one digit.\n");
  } else if (strength == -3) {
    printf("Password is too common.\n");
  } else {
    printf("Password is strong.\n");
  }

  return 0;
}