//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: Cyberpunk
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 20
#define MIN_PASSWORD_LENGTH 8

int main() {

  char password[MAX_PASSWORD_LENGTH + 1];
  int length;
  int uppercase_count = 0;
  int lowercase_count = 0;
  int digit_count = 0;
  int special_count = 0;

  printf("Please enter your password:\n");
  scanf("%s", password);

  length = strlen(password);

  if (length < MIN_PASSWORD_LENGTH) {
    printf("ERROR: Password is too short. Must be at least %d characters long.\n", MIN_PASSWORD_LENGTH);
    return 1;
  }

  if (length > MAX_PASSWORD_LENGTH) {
    printf("ERROR: Password is too long. Must be at most %d characters long.\n", MAX_PASSWORD_LENGTH);
    return 1;
  }

  for (int i = 0; i < length; i++) {
    char c = password[i];

    if (isupper(c)) {
      uppercase_count++;
    } else if (islower(c)) {
      lowercase_count++;
    } else if (isdigit(c)) {
      digit_count++;
    } else {
      special_count++;
    }
  }

  if (uppercase_count < 1) {
    printf("ERROR: Password must contain at least one uppercase letter.\n");
    return 1;
  }

  if (lowercase_count < 1) {
    printf("ERROR: Password must contain at least one lowercase letter.\n");
    return 1;
  }

  if (digit_count < 1) {
    printf("ERROR: Password must contain at least one digit.\n");
    return 1;
  }

  if (special_count < 1) {
    printf("ERROR: Password must contain at least one special character.\n");
    return 1;
  }

  printf("Password is strong. Proceed with caution.\n");

  return 0;
}