//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: Ada Lovelace
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
  char password[30];
  int length, i;
  int upper = 0, lower = 0, digit = 0, special = 0;

  printf("Enter a password to check its strength: ");
  fgets(password, 30, stdin);

  // remove newline character from input string
  length = strlen(password);
  if (password[length - 1] == '\n') {
    password[length - 1] = '\0';
  }

  // check password length
  if (length < 8) {
    printf("Password is too short.\n");
    return 0;
  }

  // check password contents
  for (i = 0; i < length; i++) {
    if (isupper(password[i])) {
      upper = 1;
    }
    else if (islower(password[i])) {
      lower = 1;
    }
    else if (isdigit(password[i])) {
      digit = 1;
    }
    else {
      special = 1;
    }
  }

  // print output based on password strength
  printf("\nPassword strength: ");
  if (upper && lower && digit && special) {
    printf("STRONG\n");
  }
  else if ((upper || lower) && digit && special) {
    printf("MODERATE\n");
  }
  else {
    printf("WEAK\n");
  }

  return 0;
}