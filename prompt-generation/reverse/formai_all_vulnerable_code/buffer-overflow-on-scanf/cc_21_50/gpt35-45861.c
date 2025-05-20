//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

  char password[52];
  int length, i, lower, upper, digit, special;
  int score = 0;

  printf("Enter your password (must be at least 8 characters): ");
  scanf("%s", password);

  length = strlen(password);

  if(length < 8) {
    printf("Password is too short. It should be at least 8 characters long.");
    exit(0);
  }

  for(i = 0; i < length; i++) {
    if(password[i] >= 'a' && password[i] <= 'z') {
      lower = 1;
    }
    else if(password[i] >= 'A' && password[i] <= 'Z') {
      upper = 1;
    }
    else if(password[i] >= '0' && password[i] <= '9') {
      digit = 1;
    }
    else {
      special = 1;
    }

    // Calculate password score based on complexity
    if(lower && upper && digit && special) {
      score = 5;
    }
    else if(lower && upper && digit) {
      score = 4;
    }
    else if(lower && upper) {
      score = 3;
    }
    else if(lower && digit) {
      score = 2;
    }
    else if(upper && digit) {
      score = 2;
    }

    // Output password complexity score and suggestions
    printf("\nPassword Complexity Score: %d\n", score);
    if(score >= 4) {
      printf("Your password is STRONG.");
    }
    else if(score == 3) {
      printf("Your password is MEDIUM.");
      printf("\nConsider including special characters to add additional complexity.");
    }
    else {
      printf("Your password is WEAK.");
      printf("\nConsider including uppercase letters, lowercase letters, numbers, and special characters to improve its complexity.");
    }

  }

  return 0;

}