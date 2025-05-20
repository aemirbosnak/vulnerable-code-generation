//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MIN_LEN 6
#define MAX_LEN 256

// Function to check if the password is strong enough
int check_password_strength(char *password) {
  int score = 0;
  int len = strlen(password);

  // Check if the password is the minimum length
  if (len < MIN_LEN) {
    printf("Password is too short. Minimum length is %d characters.\n", MIN_LEN);
    return 0;
  }

  // Check if the password is the maximum length
  if (len > MAX_LEN) {
    printf("Password is too long. Maximum length is %d characters.\n", MAX_LEN);
    return 0;
  }

  // Check if the password contains at least one uppercase letter
  int has_uppercase = 0;
  for (int i = 0; i < len; i++) {
    if (isupper(password[i])) {
      has_uppercase = 1;
      break;
    }
  }
  if (!has_uppercase) {
    printf("Password must contain at least one uppercase letter.\n");
    return 0;
  }

  // Check if the password contains at least one lowercase letter
  int has_lowercase = 0;
  for (int i = 0; i < len; i++) {
    if (islower(password[i])) {
      has_lowercase = 1;
      break;
    }
  }
  if (!has_lowercase) {
    printf("Password must contain at least one lowercase letter.\n");
    return 0;
  }

  // Check if the password contains at least one digit
  int has_digit = 0;
  for (int i = 0; i < len; i++) {
    if (isdigit(password[i])) {
      has_digit = 1;
      break;
    }
  }
  if (!has_digit) {
    printf("Password must contain at least one digit.\n");
    return 0;
  }

  // Check if the password contains at least one special character
  int has_special_char = 0;
  char special_chars[] = "!@#$%^&*()_-+={}[]:;',<.>/?";
  for (int i = 0; i < len; i++) {
    for (int j = 0; j < strlen(special_chars); j++) {
      if (password[i] == special_chars[j]) {
        has_special_char = 1;
        break;
      }
    }
    if (has_special_char) {
      break;
    }
  }
  if (!has_special_char) {
    printf("Password must contain at least one special character.\n");
    return 0;
  }

  // Calculate the password score
  score += len;
  if (has_uppercase) {
    score += 10;
  }
  if (has_lowercase) {
    score += 10;
  }
  if (has_digit) {
    score += 10;
  }
  if (has_special_char) {
    score += 10;
  }

  return score;
}

int main() {
  char password[MAX_LEN];

  printf("Enter a password: ");
  scanf("%s", password);

  int score = check_password_strength(password);

  printf("Password strength: %d\n", score);

  return 0;
}