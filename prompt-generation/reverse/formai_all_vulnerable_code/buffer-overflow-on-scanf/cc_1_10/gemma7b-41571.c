//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: unmistakable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

#define PASSWORD_MAX_LENGTH 255

char *generate_random_string(int length) {
  char *str = malloc(length);
  for (int i = 0; i < length; i++) {
    str[i] = rand() % 26 + 97;
  }
  return str;
}

int main() {
  char password[PASSWORD_MAX_LENGTH];

  printf("Enter a password: ");
  scanf("%s", password);

  int password_strength = check_password_strength(password);

  switch (password_strength) {
    case 0:
      printf("Your password is extremely weak. Please use a stronger password.\n");
      break;
    case 1:
      printf("Your password is weak. Please use a stronger password.\n");
      break;
    case 2:
      printf("Your password is moderate. It could be stronger.\n");
      break;
    case 3:
      printf("Your password is strong. It meets the recommended criteria.\n");
      break;
    case 4:
      printf("Your password is very strong. It is highly unlikely to be cracked.\n");
      break;
  }

  return 0;
}

int check_password_strength(char *password) {
  int password_length = strlen(password);
  int has_numbers = 0;
  int has_letters = 0;
  int has_symbols = 0;

  for (int i = 0; i < password_length; i++) {
    if (password[i] >= '0' && password[i] <= '9') {
      has_numbers = 1;
    } else if (password[i] >= 'a' && password[i] <= 'z') {
      has_letters = 1;
    } else if (password[i] >= '!' && password[i] <= '~') {
      has_symbols = 1;
    }
  }

  if (password_length < 8) {
    return 0;
  } else if (has_numbers && has_letters) {
    return 3;
  } else if (has_numbers || has_letters) {
    return 2;
  } else {
    return 1;
  }
}