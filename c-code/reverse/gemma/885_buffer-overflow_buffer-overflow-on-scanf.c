#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char password[256];
  int password_length = 0;
  int has_upper = 0;
  int has_lower = 0;
  int has_digit = 0;
  int has_special = 0;

  printf("Enter your password: ");
  scanf("%s", password);
  password_length = strlen(password);

  if (password_length < 8) {
    printf("Password too short. Minimum 8 characters required.\n");
  } else if (!has_upper) {
    printf("Password lacks upper case letter.\n");
  } else if (!has_lower) {
    printf("Password lacks lower case letter.\n");
  } else if (!has_digit) {
    printf("Password lacks digits.\n");
  } else if (!has_special) {
    printf("Password lacks special characters.\n");
  } else {
    printf("Password meets all requirements.\n");
  }

  return 0;
}
