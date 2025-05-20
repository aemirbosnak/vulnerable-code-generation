//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: interoperable
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAX_LENGTH 100

int is_lowercase(char c) {
  return (c >= 'a' && c <= 'z');
}

int is_uppercase(char c) {
  return (c >= 'A' && c <= 'Z');
}

int is_digit(char c) {
  return (c >= '0' && c <= '9');
}

int is_special(char c) {
  return (!is_lowercase(c) && !is_uppercase(c) && !is_digit(c));
}

int password_strength(char *s) {
  int length = strlen(s);
  int strength = 0;
  int contains_lower = 0, contains_upper = 0, contains_digit = 0, contains_special = 0;

  if (length >= 8 && length <= MAX_LENGTH) {
    strength++;
  }

  for (int i = 0; i < length; i++) {
    if (is_lowercase(s[i])) {
      contains_lower = 1;
    } else if (is_uppercase(s[i])) {
      contains_upper = 1;
    } else if (is_digit(s[i])) {
      contains_digit = 1;
    } else if (is_special(s[i])) {
      contains_special = 1;
    }
  }

  if (contains_lower && contains_upper) {
    strength++;
  }

  if (contains_digit && contains_special) {
    strength++;
  }

  return strength;
}

int main() {
  char password[MAX_LENGTH];
  printf("Enter your password: ");
  scanf("%s", password);

  int strength = password_strength(password);

  switch (strength) {
    case 0:
      printf("Your password is too weak. Please choose a stronger password.\n");
      break;
    case 1:
      printf("Your password is weak. Please consider choosing a stronger password.\n");
      break;
    case 2:
      printf("Your password is moderately strong. Good job!\n");
      break;
    case 3:
      printf("Your password is very strong. Keep up the great work!\n");
      break;
    default:
      printf("Error: Invalid password strength.\n");
      break;
  }

  return 0;
}