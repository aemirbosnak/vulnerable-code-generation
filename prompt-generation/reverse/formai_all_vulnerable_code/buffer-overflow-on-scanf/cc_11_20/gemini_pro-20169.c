//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: shocked
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
  char password[101];
  int strength, i;
  printf("Enter your password: ");
  scanf("%s", password);

  strength = 0;

  if (strlen(password) < 8) {
    printf("Your password is too short! It must be at least 8 characters long.\n");
  } else {
    strength++;
  }

  for (i = 0; i < strlen(password); i++) {
    if (isupper(password[i])) {
      strength++;
    }
  }

  for (i = 0; i < strlen(password); i++) {
    if (islower(password[i])) {
      strength++;
    }
  }

  for (i = 0; i < strlen(password); i++) {
    if (isdigit(password[i])) {
      strength++;
    }
  }

  for (i = 0; i < strlen(password); i++) {
    if (!isalnum(password[i])) {
      strength++;
    }
  }

  switch (strength) {
    case 0:
      printf("Your password is very weak! It must contain at least one uppercase letter, one lowercase letter, one digit, and one special character.\n");
      break;
    case 1:
      printf("Your password is weak! It must contain at least one uppercase letter, one lowercase letter, one digit, and one special character.\n");
      break;
    case 2:
      printf("Your password is fairly strong! It must contain at least one uppercase letter, one lowercase letter, one digit, and one special character.\n");
      break;
    case 3:
      printf("Your password is strong! It contains at least one uppercase letter, one lowercase letter, one digit, and one special character.\n");
      break;
    case 4:
      printf("Your password is very strong! It contains at least one uppercase letter, one lowercase letter, one digit, and one special character.\n");
      break;
    case 5:
      printf("Your password is extremely strong! It contains at least one uppercase letter, one lowercase letter, one digit, and one special character.\n");
      break;
  }

  return 0;
}