//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: all-encompassing
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_PASSWORD_LENGTH 64

/* Function to check if a character is a letter */
bool is_letter(char c) {
  return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

/* Function to check if a character is a digit */
bool is_digit(char c) {
  return c >= '0' && c <= '9';
}

/* Function to check if a character is a special character */
bool is_special_char(char c) {
  return!is_letter(c) &&!is_digit(c);
}

/* Function to check the strength of a password */
int check_password_strength(char *password) {
  int length = strlen(password);
  int has_letters = 0;
  int has_digits = 0;
  int has_special_chars = 0;

  if (length > MAX_PASSWORD_LENGTH) {
    return -1;
  }

  for (int i = 0; i < length; i++) {
    char c = tolower(password[i]);

    if (is_letter(c)) {
      has_letters = 1;
    } else if (is_digit(c)) {
      has_digits = 1;
    } else if (is_special_char(c)) {
      has_special_chars = 1;
    }
  }

  if (has_letters && has_digits && has_special_chars) {
    return 3;
  } else if (has_letters && has_digits) {
    return 2;
  } else if (has_letters || has_digits) {
    return 1;
  } else {
    return 0;
  }
}

int main() {
  char password[MAX_PASSWORD_LENGTH];
  printf("Enter a password: ");
  scanf("%s", password);

  int strength = check_password_strength(password);

  switch (strength) {
    case 3:
      printf("Strong password\n");
      break;
    case 2:
      printf("Moderate password\n");
      break;
    case 1:
      printf("Weak password\n");
      break;
    case 0:
      printf("Very weak password\n");
      break;
    default:
      printf("Invalid password\n");
      break;
  }

  return 0;
}