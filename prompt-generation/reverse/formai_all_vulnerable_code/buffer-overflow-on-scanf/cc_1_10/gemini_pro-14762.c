//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* Function to check if a character is a digit. */
int is_digit(char c) {
  return c >= '0' && c <= '9';
}

/* Function to check if a character is an uppercase letter. */
int is_upper(char c) {
  return c >= 'A' && c <= 'Z';
}

/* Function to check if a character is a lowercase letter. */
int is_lower(char c) {
  return c >= 'a' && c <= 'z';
}

/* Function to check if a character is a symbol. */
int is_symbol(char c) {
  return !is_digit(c) && !is_upper(c) && !is_lower(c);
}

/* Function to check the strength of a password. */
int check_password_strength(char *password) {
  int score = 0;
  int len = strlen(password);

  // Check the length of the password.
  if (len < 8) {
    score += 1;
  } else if (len >= 8 && len <= 12) {
    score += 2;
  } else if (len > 12) {
    score += 3;
  }

  // Check the variety of characters in the password.
  int has_digit = 0;
  int has_upper = 0;
  int has_lower = 0;
  int has_symbol = 0;
  for (int i = 0; i < len; i++) {
    if (is_digit(password[i])) {
      has_digit = 1;
    } else if (is_upper(password[i])) {
      has_upper = 1;
    } else if (is_lower(password[i])) {
      has_lower = 1;
    } else if (is_symbol(password[i])) {
      has_symbol = 1;
    }
  }
  if (has_digit) {
    score += 2;
  }
  if (has_upper) {
    score += 2;
  }
  if (has_lower) {
    score += 2;
  }
  if (has_symbol) {
    score += 3;
  }

  // Check if the password contains any common words or phrases.
  char *common_words[] = {"password", "123456", "qwerty", "abc123", "iloveyou"};
  int num_common_words = sizeof(common_words) / sizeof(char *);
  for (int i = 0; i < num_common_words; i++) {
    if (strstr(password, common_words[i]) != NULL) {
      score -= 5;
    }
  }

  // Return the password strength score.
  return score;
}

//Main Function
int main() {
  // Declare variables.
  char password[100];
  int score;

  // Get the password from the user.
  printf("Enter your password: ");
  scanf("%s", password);

  // Check the password strength.
  score = check_password_strength(password);

  // Print the password strength score.
  printf("Your password strength score is: %d\n", score);

  // Return 0 to indicate success.
  return 0;
}