//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN_LENGTH 8
#define MAX_LENGTH 32

// Function to check if the password is strong enough
int check_password_strength(char *password) {
  int score = 0;
  int length = strlen(password);

  // Check the length of the password
  if (length < MIN_LENGTH) {
    score += 1;
  } else if (length > MAX_LENGTH) {
    score += 2;
  }

  // Check if the password contains any uppercase letters
  int has_uppercase = 0;
  for (int i = 0; i < length; i++) {
    if (password[i] >= 'A' && password[i] <= 'Z') {
      has_uppercase = 1;
      break;
    }
  }
  if (!has_uppercase) {
    score += 1;
  }

  // Check if the password contains any lowercase letters
  int has_lowercase = 0;
  for (int i = 0; i < length; i++) {
    if (password[i] >= 'a' && password[i] <= 'z') {
      has_lowercase = 1;
      break;
    }
  }
  if (!has_lowercase) {
    score += 1;
  }

  // Check if the password contains any digits
  int has_digit = 0;
  for (int i = 0; i < length; i++) {
    if (password[i] >= '0' && password[i] <= '9') {
      has_digit = 1;
      break;
    }
  }
  if (!has_digit) {
    score += 1;
  }

  // Check if the password contains any special characters
  int has_special = 0;
  char special_chars[] = "!@#$%^&*()-_=+";
  for (int i = 0; i < length; i++) {
    for (int j = 0; j < strlen(special_chars); j++) {
      if (password[i] == special_chars[j]) {
        has_special = 1;
        break;
      }
    }
    if (has_special) {
      break;
    }
  }
  if (!has_special) {
    score += 1;
  }

  // Return the score
  return score;
}

// Function to get the password from the user
char *get_password() {
  char *password = malloc(MAX_LENGTH + 1);
  printf("Enter your password: ");
  scanf("%s", password);
  return password;
}

// Function to print the result
void print_result(int score) {
  if (score == 0) {
    printf("Your password is strong.\n");
  } else if (score == 1) {
    printf("Your password is moderately strong.\n");
  } else if (score == 2) {
    printf("Your password is weak.\n");
  } else {
    printf("Your password is very weak.\n");
  }
}

// Main function
int main() {
  char *password = get_password();
  int score = check_password_strength(password);
  print_result(score);
  free(password);
  return 0;
}