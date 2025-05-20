//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN_LENGTH 8
#define MAX_LENGTH 64

// Function to check if the password is strong enough
int check_password_strength(char *password) {
  int score = 0;

  // Check the length of the password
  if (strlen(password) < MIN_LENGTH) {
    printf("Password is too short. It must be at least %d characters long.\n", MIN_LENGTH);
    return 0;
  } else if (strlen(password) > MAX_LENGTH) {
    printf("Password is too long. It must be at most %d characters long.\n", MAX_LENGTH);
    return 0;
  }

  // Check for uppercase letters
  int has_uppercase = 0;
  for (int i = 0; i < strlen(password); i++) {
    if (password[i] >= 'A' && password[i] <= 'Z') {
      has_uppercase = 1;
      break;
    }
  }
  if (!has_uppercase) {
    printf("Password must contain at least one uppercase letter.\n");
    return 0;
  }

  // Check for lowercase letters
  int has_lowercase = 0;
  for (int i = 0; i < strlen(password); i++) {
    if (password[i] >= 'a' && password[i] <= 'z') {
      has_lowercase = 1;
      break;
    }
  }
  if (!has_lowercase) {
    printf("Password must contain at least one lowercase letter.\n");
    return 0;
  }

  // Check for digits
  int has_digit = 0;
  for (int i = 0; i < strlen(password); i++) {
    if (password[i] >= '0' && password[i] <= '9') {
      has_digit = 1;
      break;
    }
  }
  if (!has_digit) {
    printf("Password must contain at least one digit.\n");
    return 0;
  }

  // Check for special characters
  int has_special_char = 0;
  for (int i = 0; i < strlen(password); i++) {
    if (password[i] < 'A' || password[i] > 'Z' && password[i] < 'a' || password[i] > 'z' && password[i] < '0' || password[i] > '9') {
      has_special_char = 1;
      break;
    }
  }
  if (!has_special_char) {
    printf("Password must contain at least one special character.\n");
    return 0;
  }

  // Calculate the score
  score += strlen(password) * 4;
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
  // Get the password from the user
  char password[MAX_LENGTH];
  printf("Enter the password: ");
  scanf("%s", password);

  // Check the strength of the password
  int score = check_password_strength(password);

  // Print the score
  printf("The strength of the password is %d.\n", score);

  return 0;
}