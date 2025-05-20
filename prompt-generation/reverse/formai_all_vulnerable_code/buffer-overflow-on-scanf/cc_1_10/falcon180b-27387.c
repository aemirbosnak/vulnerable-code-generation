//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: curious
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 100
#define MIN_PASSWORD_LENGTH 8
#define MAX_PASSWORD_LENGTH_WITH_SPECIAL_CHARS 50

int is_password_strong(char* password) {
  int has_uppercase = 0;
  int has_lowercase = 0;
  int has_digit = 0;
  int has_special_char = 0;
  int password_length = strlen(password);

  if (password_length < MIN_PASSWORD_LENGTH) {
    return 0;
  }

  for (int i = 0; i < password_length; i++) {
    if (isupper(password[i])) {
      has_uppercase = 1;
    } else if (islower(password[i])) {
      has_lowercase = 1;
    } else if (isdigit(password[i])) {
      has_digit = 1;
    } else if (!isalnum(password[i])) {
      has_special_char = 1;
    }
  }

  if (has_uppercase && has_lowercase && has_digit && has_special_char) {
    return 1;
  } else {
    return 0;
  }
}

int is_password_strong_with_special_chars(char* password) {
  int has_uppercase = 0;
  int has_lowercase = 0;
  int has_digit = 0;
  int has_special_char = 0;
  int password_length = strlen(password);

  if (password_length < MIN_PASSWORD_LENGTH) {
    return 0;
  }

  for (int i = 0; i < password_length; i++) {
    if (isupper(password[i])) {
      has_uppercase = 1;
    } else if (islower(password[i])) {
      has_lowercase = 1;
    } else if (isdigit(password[i])) {
      has_digit = 1;
    } else if (!isalnum(password[i])) {
      has_special_char = 1;
    }
  }

  if (has_uppercase && has_lowercase && has_digit && has_special_char) {
    return 1;
  } else {
    return 0;
  }
}

int main() {
  char password[MAX_PASSWORD_LENGTH];
  printf("Enter your password: ");
  scanf("%s", password);

  if (is_password_strong(password)) {
    printf("Your password is strong.\n");
  } else {
    printf("Your password is not strong.\n");
  }

  if (is_password_strong_with_special_chars(password)) {
    printf("Your password is strong with special characters.\n");
  } else {
    printf("Your password is not strong with special characters.\n");
  }

  return 0;
}