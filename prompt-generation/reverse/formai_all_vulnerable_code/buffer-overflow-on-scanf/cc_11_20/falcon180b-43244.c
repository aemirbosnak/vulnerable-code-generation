//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORD_LENGTH 32

int main() {
  char password[MAX_PASSWORD_LENGTH];
  int length;

  printf("Enter a password: ");
  scanf("%s", password);

  length = strlen(password);

  if (length < 8) {
    printf("Password is too short.\n");
    return 1;
  }

  int has_uppercase = 0, has_lowercase = 0, has_digit = 0, has_special_char = 0;

  for (int i = 0; i < length; i++) {
    char c = tolower(password[i]);

    if (isalpha(c)) {
      if (isupper(c)) {
        has_uppercase = 1;
      } else {
        has_lowercase = 1;
      }
    } else if (isdigit(c)) {
      has_digit = 1;
    } else if (strchr("!@#$%^&*()_+-=[]{}|;:,.<>?/", c)!= NULL) {
      has_special_char = 1;
    }
  }

  if (!has_uppercase) {
    printf("Password must contain at least one uppercase letter.\n");
    return 1;
  }

  if (!has_lowercase) {
    printf("Password must contain at least one lowercase letter.\n");
    return 1;
  }

  if (!has_digit) {
    printf("Password must contain at least one digit.\n");
    return 1;
  }

  if (!has_special_char) {
    printf("Password must contain at least one special character.\n");
    return 1;
  }

  printf("Password is strong.\n");
  return 0;
}