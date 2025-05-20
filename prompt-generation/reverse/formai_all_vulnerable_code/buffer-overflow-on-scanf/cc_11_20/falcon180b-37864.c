//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: synchronous
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 50

int main() {
  char password[MAX_LEN];
  int length, uppercase, lowercase, digit, special;

  printf("Enter a password: ");
  scanf("%s", password);

  length = strlen(password);

  uppercase = 0;
  lowercase = 0;
  digit = 0;
  special = 0;

  for (int i = 0; i < length; i++) {
    if (isupper(password[i])) {
      uppercase = 1;
    } else if (islower(password[i])) {
      lowercase = 1;
    } else if (isdigit(password[i])) {
      digit = 1;
    } else if (password[i] == '!' || password[i] == '@' || password[i] == '#' || password[i] == '$' || password[i] == '%' || password[i] == '&' || password[i] == '*' || password[i] == '?') {
      special = 1;
    }
  }

  if (length < 8) {
    printf("Password is too short.\n");
    return 0;
  } else if (length > 20) {
    printf("Password is too long.\n");
    return 0;
  } else if (!uppercase) {
    printf("Password must contain at least one uppercase letter.\n");
    return 0;
  } else if (!lowercase) {
    printf("Password must contain at least one lowercase letter.\n");
    return 0;
  } else if (!digit) {
    printf("Password must contain at least one digit.\n");
    return 0;
  } else if (!special) {
    printf("Password must contain at least one special character.\n");
    return 0;
  } else {
    printf("Password is strong.\n");
    return 0;
  }
}