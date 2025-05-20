//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN_LENGTH 8

int check_length(char *password) {
  return strlen(password) >= MIN_LENGTH;
}

int check_uppercase(char *password) {
  int has_uppercase = 0;
  for (int i = 0; i < strlen(password); i++) {
    if (password[i] >= 'A' && password[i] <= 'Z') {
      has_uppercase = 1;
      break;
    }
  }
  return has_uppercase;
}

int check_lowercase(char *password) {
  int has_lowercase = 0;
  for (int i = 0; i < strlen(password); i++) {
    if (password[i] >= 'a' && password[i] <= 'z') {
      has_lowercase = 1;
      break;
    }
  }
  return has_lowercase;
}

int check_digit(char *password) {
  int has_digit = 0;
  for (int i = 0; i < strlen(password); i++) {
    if (password[i] >= '0' && password[i] <= '9') {
      has_digit = 1;
      break;
    }
  }
  return has_digit;
}

int check_special(char *password) {
  int has_special = 0;
  for (int i = 0; i < strlen(password); i++) {
    if ((password[i] >= '!' && password[i] <= '/') || (password[i] >= ':' && password[i] <= '@') || (password[i] >= '[' && password[i] <= '`') || (password[i] >= '{' && password[i] <= '~')) {
      has_special = 1;
      break;
    }
  }
  return has_special;
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
  if (check_digit(password)) {
    score++;
  }
  if (check_special(password)) {
    score++;
  }
  return score;
}

int main() {
  char password[100];
  printf("Enter your password: ");
  scanf("%s", password);
  int strength = check_strength(password);
  switch (strength) {
    case 0:
      printf("Your password is very weak.\n");
      break;
    case 1:
      printf("Your password is weak.\n");
      break;
    case 2:
      printf("Your password is moderate.\n");
      break;
    case 3:
      printf("Your password is strong.\n");
      break;
    case 4:
      printf("Your password is very strong.\n");
      break;
    case 5:
      printf("Your password is excellent.\n");
      break;
  }
  return 0;
}