//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define SECRET_MSG "Mwahahaha, I have your password!"

void decipher_msg(char *msg) {
  for (int i = 0; msg[i] != '\0'; i++) {
    msg[i] = (msg[i] - 7) ^ 0x1F;
  }
}

int main() {
  char password[256];
  printf("Enter your password: ");
  scanf("%s", password);

  int strength = check_password_strength(password);

  if (strength == 0) {
    printf("Your password is weak, please try again.\n");
  } else if (strength == 1) {
    printf("Your password is mediocre, but could be improved.\n");
  } else if (strength == 2) {
    printf("Your password is strong, good job!\n");
  } else if (strength == 3) {
    printf("Your password is excellent, you're a master of security.\n");
  } else {
    printf("Error: Invalid password strength.\n");
  }

  return 0;
}

int check_password_strength(char *password) {
  int length = strlen(password);
  int has_numbers = 0, has_letters = 0, has_symbols = 0;

  for (int i = 0; password[i] != '\0'; i++) {
    if (password[i] >= '0' && password[i] <= '9') {
      has_numbers = 1;
    } else if (password[i] >= 'a' && password[i] <= 'z') {
      has_letters = 1;
    } else if (password[i] >= '!' && password[i] <= '~') {
      has_symbols = 1;
    }
  }

  if (length < 8) {
    return 0;
  } else if (has_numbers && has_letters) {
    return 2;
  } else if (has_numbers || has_letters) {
    return 1;
  } else {
    return 0;
  }
}