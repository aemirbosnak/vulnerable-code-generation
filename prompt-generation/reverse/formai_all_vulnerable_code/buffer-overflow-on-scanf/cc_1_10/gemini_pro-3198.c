//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN_LENGTH 8
#define MAX_LENGTH 32
#define MIN_UPPERCASE 1
#define MIN_LOWERCASE 1
#define MIN_DIGITS 1
#define MIN_SYMBOLS 1

int check_length(char *password) {
  int length = strlen(password);
  return (length >= MIN_LENGTH && length <= MAX_LENGTH);
}

int check_uppercase(char *password) {
  int count = 0;
  for (int i = 0; i < strlen(password); i++) {
    if (password[i] >= 'A' && password[i] <= 'Z') {
      count++;
    }
  }
  return (count >= MIN_UPPERCASE);
}

int check_lowercase(char *password) {
  int count = 0;
  for (int i = 0; i < strlen(password); i++) {
    if (password[i] >= 'a' && password[i] <= 'z') {
      count++;
    }
  }
  return (count >= MIN_LOWERCASE);
}

int check_digits(char *password) {
  int count = 0;
  for (int i = 0; i < strlen(password); i++) {
    if (password[i] >= '0' && password[i] <= '9') {
      count++;
    }
  }
  return (count >= MIN_DIGITS);
}

int check_symbols(char *password) {
  int count = 0;
  char symbols[] = "!@#$%^&*()-_=+`~";
  for (int i = 0; i < strlen(password); i++) {
    for (int j = 0; j < strlen(symbols); j++) {
      if (password[i] == symbols[j]) {
        count++;
      }
    }
  }
  return (count >= MIN_SYMBOLS);
}

int check_strength(char *password) {
  int score = 0;
  if (check_length(password)) {
    score++;
  }
  if (check_uppercase(password)) {
    score++;
  }
  if (check_lowercase(password)) {
    score++;
  }
  if (check_digits(password)) {
    score++;
  }
  if (check_symbols(password)) {
    score++;
  }
  return score;
}

int main() {
  char password[MAX_LENGTH + 1];
  printf("Enter a password: ");
  scanf("%s", password);

  int strength = check_strength(password);

  switch (strength) {
    case 0:
      printf("Very weak password\n");
      break;
    case 1:
      printf("Weak password\n");
      break;
    case 2:
      printf("Moderate password\n");
      break;
    case 3:
      printf("Strong password\n");
      break;
    case 4:
      printf("Very strong password\n");
      break;
    case 5:
      printf("Excellent password\n");
      break;
    default:
      printf("Invalid password\n");
  }

  return 0;
}