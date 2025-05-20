//Code Llama-13B DATASET v1.0 Category: Password Strength Checker ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define PASSWORD_LENGTH 8
#define UPPERCASE_CHARS 26
#define LOWERCASE_CHARS 26
#define DIGITS 10
#define SPECIAL_CHARS 33

int check_password_strength(char *password) {
  int password_length = strlen(password);
  if (password_length < PASSWORD_LENGTH) {
    return 0;
  }

  int uppercase_count = 0;
  int lowercase_count = 0;
  int digit_count = 0;
  int special_count = 0;

  for (int i = 0; i < password_length; i++) {
    if (isupper(password[i])) {
      uppercase_count++;
    } else if (islower(password[i])) {
      lowercase_count++;
    } else if (isdigit(password[i])) {
      digit_count++;
    } else if (ispunct(password[i])) {
      special_count++;
    }
  }

  int total_count = uppercase_count + lowercase_count + digit_count + special_count;
  if (total_count < PASSWORD_LENGTH) {
    return 0;
  }

  int score = 0;
  if (uppercase_count >= UPPERCASE_CHARS) {
    score += 2;
  }
  if (lowercase_count >= LOWERCASE_CHARS) {
    score += 2;
  }
  if (digit_count >= DIGITS) {
    score += 2;
  }
  if (special_count >= SPECIAL_CHARS) {
    score += 2;
  }

  return score;
}

int main() {
  char password[100];
  printf("Enter password: ");
  scanf("%s", password);
  int score = check_password_strength(password);
  if (score == 0) {
    printf("Password is too weak\n");
  } else if (score == 4) {
    printf("Password is strong\n");
  } else {
    printf("Password is moderate\n");
  }
  return 0;
}