//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define PASSWORD_LENGTH 16

typedef struct Password {
  char *password;
  int strength;
} Password;

int main() {
  Password password;
  password.password = malloc(PASSWORD_LENGTH);
  printf("Enter your password: ");
  scanf("%s", password.password);

  password.strength = check_password_strength(password.password);

  switch (password.strength) {
    case 0:
      printf("Your password is very weak. Please use a stronger password.\n");
      break;
    case 1:
      printf("Your password is weak. Please use a stronger password.\n");
      break;
    case 2:
      printf("Your password is moderate. It could be stronger.\n");
      break;
    case 3:
      printf("Your password is strong. It meets all the criteria.\n");
      break;
    case 4:
      printf("Your password is very strong. It is highly unlikely to be cracked.\n");
      break;
  }

  free(password.password);

  return 0;
}

int check_password_strength(char *password) {
  int strength = 0;
  int length = strlen(password);

  if (length >= PASSWORD_LENGTH) {
    strength++;
  }

  for (int i = 0; i < length; i++) {
    if (isupper(password[i]) || islower(password[i]) || isdigit(password[i]) || password[i] == '$' || password[i] == '#') {
      strength++;
    }
  }

  return strength;
}