//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: creative
#include <stdio.h>
#include <string.h>

// This program checks the strength of a password using various criteria

int main() {
  char password[100];
  int len, upper, lower, num, special;

  printf("Enter your password: ");
  scanf("%s", password);

  len = strlen(password);
  upper = lower = num = special = 0;

  // Check if the password meets the length requirement
  if (len >= 8 && len <= 20) {
    for (int i = 0; i < len; i++) {
      // Check if the password has at least one uppercase letter
      if (password[i] >= 'A' && password[i] <= 'Z') {
        upper = 1;
      }
      // Check if the password has at least one lowercase letter
      else if (password[i] >= 'a' && password[i] <= 'z') {
        lower = 1;
      }
      // Check if the password has at least one digit
      else if (password[i] >= '0' && password[i] <= '9') {
        num = 1;
      }
      // Check if the password has at least one special character
      else {
        special = 1;
      }
    }

    // Check if the password meets all the criteria
    if (upper && lower && num && special) {
      printf("Password is strong!\n");
    }
    else {
      printf("Password is weak!\n");
    }
  }
  else {
    printf("Password must be between 8 and 20 characters!\n");
  }

  return 0;
}