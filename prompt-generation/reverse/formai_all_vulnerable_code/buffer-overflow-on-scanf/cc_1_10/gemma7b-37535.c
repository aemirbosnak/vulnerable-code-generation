//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: curious
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PASSWD_LENGTH 100

int main() {
  char password[MAX_PASSWD_LENGTH];
  int password_length;

  printf("Please enter your password: ");
  scanf("%s", password);
  password_length = strlen(password);

  if (password_length < 8) {
    printf("Password too short, minimum 8 characters.\n");
  } else if (password_length >= 8 && password_length < 16) {
    printf("Password length is acceptable.\n");
  } else if (password_length >= 16) {
    printf("Password too long, maximum 100 characters.\n");
  }

  if (hasUppercase(password)) {
    printf("Password has uppercase letter(s).\n");
  } else {
    printf("Password does not have any uppercase letter(s).\n");
  }

  if (hasNumber(password)) {
    printf("Password has number(s).\n");
  } else {
    printf("Password does not have any number(s).\n");
  }

  if (hasSymbol(password)) {
    printf("Password has symbol(s).\n");
  } else {
    printf("Password does not have any symbol(s).\n");
  }

  return 0;
}

int hasUppercase(char *password) {
  for (int i = 0; password[i] != '\0'; i++) {
    if (password[i] >= 'A' && password[i] <= 'Z') {
      return 1;
    }
  }

  return 0;
}

int hasNumber(char *password) {
  for (int i = 0; password[i] != '\0'; i++) {
    if (password[i] >= '0' && password[i] <= '9') {
      return 1;
    }
  }

  return 0;
}

int hasSymbol(char *password) {
  for (int i = 0; password[i] != '\0'; i++) {
    if (password[i] >= '!' && password[i] <= '~') {
      return 1;
    }
  }

  return 0;
}