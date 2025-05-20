//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: ultraprecise
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MIN_PASS_LEN 8
#define MAX_PASS_LEN 64

int check_password_strength(char *password) {
  int score = 0;

  // Check password length
  if (strlen(password) < MIN_PASS_LEN) {
    score -= 10;
  } else if (strlen(password) > MAX_PASS_LEN) {
    score -= 5;
  }

  // Check for uppercase letters
  int has_upper = 0;
  for (int i = 0; i < strlen(password); i++) {
    if (isupper(password[i])) {
      has_upper = 1;
      break;
    }
  }
  if (!has_upper) {
    score -= 5;
  }

  // Check for lowercase letters
  int has_lower = 0;
  for (int i = 0; i < strlen(password); i++) {
    if (islower(password[i])) {
      has_lower = 1;
      break;
    }
  }
  if (!has_lower) {
    score -= 5;
  }

  // Check for digits
  int has_digit = 0;
  for (int i = 0; i < strlen(password); i++) {
    if (isdigit(password[i])) {
      has_digit = 1;
      break;
    }
  }
  if (!has_digit) {
    score -= 5;
  }

  // Check for special characters
  int has_special = 0;
  for (int i = 0; i < strlen(password); i++) {
    if (!isalnum(password[i])) {
      has_special = 1;
      break;
    }
  }
  if (!has_special) {
    score -= 5;
  }

  // Check for repeated characters
  int has_repeated = 0;
  for (int i = 0; i < strlen(password) - 1; i++) {
    if (password[i] == password[i + 1]) {
      has_repeated = 1;
      break;
    }
  }
  if (has_repeated) {
    score -= 10;
  }

  // Check for common passwords
  char *common_passwords[] = {"password", "123456", "12345678", "123456789", "qwerty",
                               "1234567", "abc123", "111111", "123123", "iloveyou"};
  int is_common = 0;
  for (int i = 0; i < sizeof(common_passwords) / sizeof(char *
); i++) {
    if (strcmp(password, common_passwords[i]) == 0) {
      is_common = 1;
      break;
    }
  }
  if (is_common) {
    score -= 20;
  }

  return score;
}

int main() {
  char password[MAX_PASS_LEN];

  printf("Enter your password: ");
  scanf("%s", password);

  int score = check_password_strength(password);

  if (score >= 80) {
    printf("Your password is very strong.\n");
  } else if (score >= 60) {
    printf("Your password is strong.\n");
  } else if (score >= 40) {
    printf("Your password is weak.\n");
  } else {
    printf("Your password is very weak.\n");
  }

  return 0;
}