//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: automated
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_PASS_LEN 255

void check_password_strength(char *pass) {
  int min_score = 0, score = 0, has_upper = 0, has_num = 0, has_symbol = 0;
  char lower_pass[MAX_PASS_LEN];

  // Normalize the password to lowercase
  strcpy(lower_pass, pass);
  pass = lower_pass;

  // Check for minimum length
  if (strlen(pass) < 8) {
    min_score--;
  }

  // Check for uppercase letter
  for (int i = 0; i < strlen(pass); i++) {
    if (isupper(pass[i])) {
      has_upper = 1;
      score++;
    }
  }

  // Check for numeric character
  for (int i = 0; i < strlen(pass); i++) {
    if (isdigit(pass[i])) {
      has_num = 1;
      score++;
    }
  }

  // Check for special character
  for (int i = 0; i < strlen(pass); i++) {
    if (!isalnum(pass[i])) {
      has_symbol = 1;
      score++;
    }
  }

  // Calculate final score
  score = min_score + has_upper + has_num + has_symbol;

  // Print score
  printf("Password Strength Score: %d/%d\n", score, MAX_PASS_LEN);
}

int main() {
  char pass[MAX_PASS_LEN];

  // Get the password from the user
  printf("Enter your password: ");
  scanf("%s", pass);

  // Check the password strength
  check_password_strength(pass);

  return 0;
}