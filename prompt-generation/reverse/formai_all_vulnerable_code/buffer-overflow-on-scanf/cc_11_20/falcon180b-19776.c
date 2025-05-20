//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: systematic
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define LENGTH 16

int main() {
  char password[LENGTH];
  int length, i, has_uppercase, has_lowercase, has_number, has_special;

  printf("Enter a password: ");
  scanf("%s", password);

  length = strlen(password);

  has_uppercase = has_lowercase = has_number = has_special = 0;

  for (i = 0; i < length; i++) {
    if (isupper(password[i])) {
      has_uppercase = 1;
    } else if (islower(password[i])) {
      has_lowercase = 1;
    } else if (isdigit(password[i])) {
      has_number = 1;
    } else if (isalnum(password[i]) == 0) {
      has_special = 1;
    }
  }

  if (length >= LENGTH) {
    printf("Password is strong.\n");
  } else {
    printf("Password is weak.\n");
  }

  if (has_uppercase) {
    printf("Password contains an uppercase letter.\n");
  } else {
    printf("Password does not contain an uppercase letter.\n");
  }

  if (has_lowercase) {
    printf("Password contains a lowercase letter.\n");
  } else {
    printf("Password does not contain a lowercase letter.\n");
  }

  if (has_number) {
    printf("Password contains a number.\n");
  } else {
    printf("Password does not contain a number.\n");
  }

  if (has_special) {
    printf("Password contains a special character.\n");
  } else {
    printf("Password does not contain a special character.\n");
  }

  return 0;
}