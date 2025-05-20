//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char password[50]; // assume maximum password length is 50 characters
  int length, has_uppercase, has_lowercase, has_number, has_special, score;

  // prompt the user to input a password
  printf("Enter a password: ");
  scanf("%s", password);

  // calculate the length of the password
  length = strlen(password);

  // check if the password contains at least one uppercase letter
  has_uppercase = 0;
  for (int i = 0; i < length; i++) {
    if (password[i] >= 'A' && password[i] <= 'Z') {
      has_uppercase = 1;
      break;
    }
  }

  // check if the password contains at least one lowercase letter
  has_lowercase = 0;
  for (int i = 0; i < length; i++) {
    if (password[i] >= 'a' && password[i] <= 'z') {
      has_lowercase = 1;
      break;
    }
  }

  // check if the password contains at least one number
  has_number = 0;
  for (int i = 0; i < length; i++) {
    if (password[i] >= '0' && password[i] <= '9') {
      has_number = 1;
      break;
    }
  }

  // check if the password contains at least one special character
  has_special = 0;
  for (int i = 0; i < length; i++) {
    if (!(password[i] >= 'A' && password[i] <= 'Z') &&
        !(password[i] >= 'a' && password[i] <= 'z') &&
        !(password[i] >= '0' && password[i] <= '9')) {
      has_special = 1;
      break;
    }
  }

  // calculate a score for the password based on its strength
  score = 0;
  if (length >= 8 && length <= 15) {
    score += 1;
  } else if (length > 15) {
    score += 2;
  }
  if (has_uppercase) {
    score += 2;
  }
  if (has_lowercase) {
    score += 2;
  }
  if (has_number) {
    score += 2;
  }
  if (has_special) {
    score += 2;
  }

  // print the strength of the password based on its score
  if (score < 6) {
    printf("The password is weak.\n");
  } else if (score < 10) {
    printf("The password is medium.\n");
  } else {
    printf("The password is strong.\n");
  }

  return 0;
}