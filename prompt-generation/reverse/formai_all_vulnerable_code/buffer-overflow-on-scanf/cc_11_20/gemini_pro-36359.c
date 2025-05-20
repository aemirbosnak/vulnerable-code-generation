//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN_LENGTH 8

int checkStrength(char *password, int len) {
  if (len < MIN_LENGTH) {
    return 0;
  }

  int score = 0;

  // Check for uppercase characters
  for (int i = 0; i < len; i++) {
    if (password[i] >= 'A' && password[i] <= 'Z') {
      score++;
    }
  }

  // Check for lowercase characters
  for (int i = 0; i < len; i++) {
    if (password[i] >= 'a' && password[i] <= 'z') {
      score++;
    }
  }

  // Check for digits
  for (int i = 0; i < len; i++) {
    if (password[i] >= '0' && password[i] <= '9') {
      score++;
    }
  }

  // Check for special characters
  for (int i = 0; i < len; i++) {
    if (password[i] == '!' || password[i] == '@' || password[i] == '#' || password[i] == '$' || password[i] == '%') {
      score++;
    }
  }

  // Check for consecutive characters
  for (int i = 0; i < len - 1; i++) {
    if (password[i] == password[i + 1]) {
      score--;
    }
  }

  // Check for repeated characters
  for (int i = 0; i < len; i++) {
    for (int j = i + 1; j < len; j++) {
      if (password[i] == password[j]) {
        score--;
      }
    }
  }

  // Check for common passwords
  char *commonPasswords[] = {"password", "123456", "qwerty", "12345678", "abc123", "12345", "iloveyou", "princess", "admin", "welcome"};
  int numCommonPasswords = sizeof(commonPasswords) / sizeof(commonPasswords[0]);
  for (int i = 0; i < numCommonPasswords; i++) {
    if (strcmp(password, commonPasswords[i]) == 0) {
      score -= 10;
    }
  }

  return score;
}

int main() {
  char password[100];
  printf("Enter your password: ");
  scanf("%s", password);

  int len = strlen(password);

  int score = checkStrength(password, len);

  printf("Your password strength is: %d\n", score);

  return 0;
}