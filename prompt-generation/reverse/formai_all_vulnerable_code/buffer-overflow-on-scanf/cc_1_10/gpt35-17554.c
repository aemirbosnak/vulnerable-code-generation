//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: real-life
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
  char password[50];
  int length, is_alpha, is_digit, is_special, i, strength;

  printf("Enter a password: ");
  scanf("%s", password);

  length = strlen(password);

  // check password length
  if (length < 8) {
      printf("Password must contain at least 8 characters\n");
      return 0;
  }

  // check password complexity
  is_alpha = is_digit = is_special = 0;
  for (i = 0; password[i] != '\0'; i++) {
      if (isalpha(password[i]))
          is_alpha = 1;
      else if (isdigit(password[i]))
          is_digit = 1;
      else
          is_special = 1;
  }

  // calculate password strength
  strength = 0;
  if (is_alpha)
      strength += 1;
  if (is_digit)
      strength += 1;
  if (is_special)
      strength += 1;

  // print password strength
  printf("Password strength is: ");
  if (strength == 1)
      printf("Weak\n");
  else if (strength == 2)
      printf("Moderate\n");
  else
      printf("Strong\n");

  return 0;
}