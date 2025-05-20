//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: enthusiastic
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PASSWORD_LENGTH 64
#define MIN_PASSWORD_LENGTH 8

#define IS_LOWER(c) ((c) >= 'a' && (c) <= 'z')
#define IS_UPPER(c) ((c) >= 'A' && (c) <= 'Z')
#define IS_NUMBER(c) ((c) >= '0' && (c) <= '9')

#define CHECK_LOWER 1
#define CHECK_UPPER 2
#define CHECK_NUMBER 4
#define CHECK_SPECIAL 8

int check_password_strength(char* password, int strength_checks) {
  int length = strlen(password);
  int has_lower = 0;
  int has_upper = 0;
  int has_number = 0;
  int has_special = 0;

  if (length < MIN_PASSWORD_LENGTH) {
    printf("Password is too short.\n");
    return 0;
  }

  if (strength_checks & CHECK_LOWER) {
    has_lower = 1;
  }

  if (strength_checks & CHECK_UPPER) {
    has_upper = 1;
  }

  if (strength_checks & CHECK_NUMBER) {
    has_number = 1;
  }

  if (strength_checks & CHECK_SPECIAL) {
    has_special = 1;
  }

  if ((strength_checks & CHECK_LOWER) &&!has_lower) {
    printf("Password must contain at least one lowercase letter.\n");
    return 0;
  }

  if ((strength_checks & CHECK_UPPER) &&!has_upper) {
    printf("Password must contain at least one uppercase letter.\n");
    return 0;
  }

  if ((strength_checks & CHECK_NUMBER) &&!has_number) {
    printf("Password must contain at least one number.\n");
    return 0;
  }

  if ((strength_checks & CHECK_SPECIAL) &&!has_special) {
    printf("Password must contain at least one special character.\n");
    return 0;
  }

  printf("Password is strong!\n");
  return 1;
}

int main() {
  char password[MAX_PASSWORD_LENGTH];
  int strength_checks = CHECK_LOWER | CHECK_UPPER | CHECK_NUMBER | CHECK_SPECIAL;

  printf("Enter your password: ");
  scanf("%s", password);

  int result = check_password_strength(password, strength_checks);

  if (result == 1) {
    printf("Password strength: Very Strong\n");
  } else {
    printf("Password strength: Weak\n");
  }

  return 0;
}