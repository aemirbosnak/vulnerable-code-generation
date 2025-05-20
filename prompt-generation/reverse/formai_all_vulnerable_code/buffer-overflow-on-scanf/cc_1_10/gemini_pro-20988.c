//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MIN_LEN 6
#define MAX_LEN 20
#define LOWERCASE_A 97
#define LOWERCASE_Z 122
#define UPPERCASE_A 65
#define UPPERCASE_Z 90
#define NUMBER_0 48
#define NUMBER_9 57
#define SPECIAL_CHARACTERS "!@#$%^&*()"

int check_length(char *password) {
  return strlen(password) >= MIN_LEN && strlen(password) <= MAX_LEN;
}

int check_lowercase(char *password) {
  int count = 0;
  for (int i = 0; i < strlen(password); i++) {
    if (password[i] >= LOWERCASE_A && password[i] <= LOWERCASE_Z) {
      count++;
    }
  }
  return count > 0;
}

int check_uppercase(char *password) {
  int count = 0;
  for (int i = 0; i < strlen(password); i++) {
    if (password[i] >= UPPERCASE_A && password[i] <= UPPERCASE_Z) {
      count++;
    }
  }
  return count > 0;
}

int check_number(char *password) {
  int count = 0;
  for (int i = 0; i < strlen(password); i++) {
    if (password[i] >= NUMBER_0 && password[i] <= NUMBER_9) {
      count++;
    }
  }
  return count > 0;
}

int check_special_character(char *password) {
  int count = 0;
  for (int i = 0; i < strlen(password); i++) {
    if (strchr(SPECIAL_CHARACTERS, password[i]) != NULL) {
      count++;
    }
  }
  return count > 0;
}

int check_strength(char *password) {
  int score = 0;
  if (check_length(password)) {
    score++;
  }
  if (check_lowercase(password)) {
    score++;
  }
  if (check_uppercase(password)) {
    score++;
  }
  if (check_number(password)) {
    score++;
  }
  if (check_special_character(password)) {
    score++;
  }
  return score;
}

void print_strength(int score) {
  switch (score) {
    case 0:
      printf("Weak\n");
      break;
    case 1:
      printf("Fair\n");
      break;
    case 2:
      printf("Good\n");
      break;
    case 3:
      printf("Strong\n");
      break;
    case 4:
      printf("Very Strong\n");
      break;
    case 5:
      printf("Excellent\n");
      break;
  }
}

int main() {
  char password[MAX_LEN + 1];
  printf("Enter a password: ");
  scanf("%s", password);
  int score = check_strength(password);
  printf("Password strength: ");
  print_strength(score);
  return 0;
}