//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to check if the password is strong
int check_password_strength(char *password) {
  int score = 0;
  int len = strlen(password);

  // Check the length of the password
  if (len < 8) {
    score += 1;
  } else if (len >= 8 && len <= 12) {
    score += 2;
  } else if (len > 12) {
    score += 3;
  }

  // Check for uppercase and lowercase characters
  int has_uppercase = 0;
  int has_lowercase = 0;
  for (int i = 0; i < len; i++) {
    if (isupper(password[i])) {
      has_uppercase = 1;
    } else if (islower(password[i])) {
      has_lowercase = 1;
    }
  }
  if (has_uppercase && has_lowercase) {
    score += 2;
  }

  // Check for digits
  int has_digits = 0;
  for (int i = 0; i < len; i++) {
    if (isdigit(password[i])) {
      has_digits = 1;
    }
  }
  if (has_digits) {
    score += 2;
  }

  // Check for special characters
  int has_special_characters = 0;
  for (int i = 0; i < len; i++) {
    if (!isalnum(password[i])) {
      has_special_characters = 1;
    }
  }
  if (has_special_characters) {
    score += 3;
  }

  return score;
}

// Function to print the password strength
void print_password_strength(int score) {
  if (score < 5) {
    printf("Weak password\n");
  } else if (score >= 5 && score < 7) {
    printf("Medium password\n");
  } else {
    printf("Strong password\n");
  }
}

// Driver code
int main() {
  char password[100];

  printf("Enter your password: ");
  scanf("%s", password);

  int score = check_password_strength(password);

  printf("Password strength: ");
  print_password_strength(score);

  return 0;
}