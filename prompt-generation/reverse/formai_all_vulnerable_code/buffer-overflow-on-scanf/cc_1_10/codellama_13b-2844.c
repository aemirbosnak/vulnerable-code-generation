//Code Llama-13B DATASET v1.0 Category: Password Strength Checker ; Style: romantic
// Romantic C Password Strength Checker
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 16

void check_password_strength(char *password) {
  int password_length = strlen(password);
  if (password_length < 8) {
    printf("Your password is too short!\n");
    return;
  }

  int num_lowercase = 0, num_uppercase = 0, num_numbers = 0, num_special = 0;
  for (int i = 0; i < password_length; i++) {
    char c = password[i];
    if (c >= 'a' && c <= 'z') {
      num_lowercase++;
    } else if (c >= 'A' && c <= 'Z') {
      num_uppercase++;
    } else if (c >= '0' && c <= '9') {
      num_numbers++;
    } else {
      num_special++;
    }
  }

  if (num_lowercase == 0) {
    printf("Your password is too lacking in lowercase letters!\n");
  }
  if (num_uppercase == 0) {
    printf("Your password is too lacking in uppercase letters!\n");
  }
  if (num_numbers == 0) {
    printf("Your password is too lacking in numbers!\n");
  }
  if (num_special == 0) {
    printf("Your password is too lacking in special characters!\n");
  }

  printf("Your password is strong enough!\n");
}

int main() {
  char password[MAX_PASSWORD_LENGTH];
  printf("Enter your password: ");
  scanf("%s", password);
  check_password_strength(password);
  return 0;
}