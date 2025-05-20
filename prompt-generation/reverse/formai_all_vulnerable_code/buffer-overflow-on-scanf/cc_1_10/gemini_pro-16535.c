//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN_LENGTH 8
#define MAX_LENGTH 64

typedef enum {
  WEAK,
  OK,
  STRONG
} PasswordStrength;

PasswordStrength check_password_strength(const char *password) {
  int length = strlen(password);
  if (length < MIN_LENGTH || length > MAX_LENGTH) {
    return WEAK;
  }

  int has_uppercase = 0;
  int has_lowercase = 0;
  int has_digit = 0;
  int has_symbol = 0;

  for (int i = 0; i < length; i++) {
    char c = password[i];
    if (c >= 'A' && c <= 'Z') {
      has_uppercase = 1;
    } else if (c >= 'a' && c <= 'z') {
      has_lowercase = 1;
    } else if (c >= '0' && c <= '9') {
      has_digit = 1;
    } else {
      has_symbol = 1;
    }
  }

  if (has_uppercase + has_lowercase + has_digit + has_symbol < 3) {
    return WEAK;
  } else if (has_uppercase + has_lowercase + has_digit + has_symbol == 3) {
    return OK;
  } else {
    return STRONG;
  }
}

int main() {
  char password[MAX_LENGTH + 1];
  printf("Enter your password: ");
  scanf("%s", password);

  PasswordStrength strength = check_password_strength(password);

  switch (strength) {
    case WEAK:
      printf("Your password is weak. Please choose a stronger password.\n");
      break;
    case OK:
      printf("Your password is OK. It could be stronger, but it's not bad.\n");
      break;
    case STRONG:
      printf("Your password is strong. Good job!\n");
      break;
  }

  return 0;
}