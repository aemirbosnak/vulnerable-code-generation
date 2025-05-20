//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: scientific
#include <stdio.h>
#include <string.h>

int main(void) {
  char password[100];
  int length, num_digits, num_uppercase, num_lowercase, num_special, strength = 0;

  printf("Enter a password: ");
  scanf("%s", password);

  length = strlen(password);

  for (int i = 0; i < length; i++) {
    if (isdigit(password[i])) {
      num_digits++;
    } else if (isupper(password[i])) {
      num_uppercase++;
    } else if (islower(password[i])) {
      num_lowercase++;
    } else {
      num_special++;
    }
  }

  if (length < 8) {
    printf("Password must be at least 8 characters long.\n");
  } else {
    strength++;

    if (num_digits < 2) {
      printf("Password must contain at least 2 digits.\n");
    } else {
      strength++;
    }

    if (num_uppercase < 2) {
      printf("Password must contain at least 2 uppercase letters.\n");
    } else {
      strength++;
    }

    if (num_lowercase < 2) {
      printf("Password must contain at least 2 lowercase letters.\n");
    } else {
      strength++;
    }

    if (num_special < 2) {
      printf("Password must contain at least 2 special characters.\n");
    } else {
      strength++;
    }

    printf("Password strength: %d/5\n", strength);
  }

  return 0;
}