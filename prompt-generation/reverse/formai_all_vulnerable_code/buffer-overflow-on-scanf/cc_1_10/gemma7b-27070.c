//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: lively
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWD_LEN 1024

int main() {
  char passwd[MAX_PASSWD_LEN];

  printf("Welcome to the Password Strength Checker!\n");
  printf("Please enter a password: ");

  scanf("%s", passwd);

  int password_strength = check_password_strength(passwd);

  switch (password_strength) {
    case 0:
      printf("Your password is very weak. Please try again.\n");
      break;
    case 1:
      printf("Your password is weak. It could be improved.\n");
      break;
    case 2:
      printf("Your password is moderate. It is acceptable, but could be stronger.\n");
      break;
    case 3:
      printf("Your password is strong. It is difficult to crack.\n");
      break;
    case 4:
      printf("Your password is very strong. It is highly unlikely to be cracked.\n");
      break;
  }

  return 0;
}

int check_password_strength(char *passwd) {
  int strength = 0;

  if (strlen(passwd) >= 8) {
    strength++;
  }

  for (int i = 0; i < strlen(passwd); i++) {
    if (!isalnum(passwd[i]) && passwd[i] != '_') {
      strength++;
    }
  }

  if (has_upper(passwd)) {
    strength++;
  }

  if (has_number(passwd)) {
    strength++;
  }

  return strength;
}

int has_upper(char *passwd) {
  for (int i = 0; i < strlen(passwd); i++) {
    if (isupper(passwd[i])) {
      return 1;
    }
  }

  return 0;
}

int has_number(char *passwd) {
  for (int i = 0; i < strlen(passwd); i++) {
    if (isdigit(passwd[i])) {
      return 1;
    }
  }

  return 0;
}