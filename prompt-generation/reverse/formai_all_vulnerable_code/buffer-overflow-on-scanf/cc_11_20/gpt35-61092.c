//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: shape shifting
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {
  char password[100];
  int i, upper = 0, lower = 0, digit = 0, symbol = 0, length, score = 0;

  printf("Enter password: ");
  scanf("%s", password);

  length = strlen(password);

  for (i = 0; i < length; i++) {
    if (isupper(password[i])) {
      upper = 1;
    }

    if (islower(password[i])) {
      lower = 1;
    }

    if (isdigit(password[i])) {
      digit = 1;
    }

    if (ispunct(password[i])) {
      symbol = 1;
    }
  }

  if (upper && lower) {
    score++;
  }

  if (digit) {
    score++;
  }

  if (symbol) {
    score++;
  }

  if (length >= 8 && length <= 12) {
    score++;
  } else if (length > 12) {
    score += 2;
  }

  switch(score) {
    case 0:
      printf("Password is very weak!\n");
      break;

    case 1:
      printf("Password is weak!\n");
      break;

    case 2:
      printf("Password is moderate!\n");
      break;

    case 3:
      printf("Password is strong!\n");
      break;

    case 4:
      printf("Password is very strong!\n");
      break;
  }

  return 0;
}