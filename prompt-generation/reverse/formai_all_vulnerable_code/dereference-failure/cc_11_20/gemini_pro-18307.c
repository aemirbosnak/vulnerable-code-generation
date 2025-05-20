//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if the password is strong enough
int check_password(char *password) {
  int score = 0;
  int length = strlen(password);

  // Check for length
  if (length < 8) {
    score += 1;
  } else if (length >= 8 && length <= 12) {
    score += 2;
  } else if (length > 12) {
    score += 3;
  }

  // Check for uppercase characters
  int upper_count = 0;
  for (int i = 0; i < length; i++) {
    if (password[i] >= 'A' && password[i] <= 'Z') {
      upper_count++;
    }
  }
  if (upper_count == 0) {
    score += 1;
  } else if (upper_count >= 1 && upper_count <= 2) {
    score += 2;
  } else if (upper_count > 2) {
    score += 3;
  }

  // Check for lowercase characters
  int lower_count = 0;
  for (int i = 0; i < length; i++) {
    if (password[i] >= 'a' && password[i] <= 'z') {
      lower_count++;
    }
  }
  if (lower_count == 0) {
    score += 1;
  } else if (lower_count >= 1 && lower_count <= 2) {
    score += 2;
  } else if (lower_count > 2) {
    score += 3;
  }

  // Check for digits
  int digit_count = 0;
  for (int i = 0; i < length; i++) {
    if (password[i] >= '0' && password[i] <= '9') {
      digit_count++;
    }
  }
  if (digit_count == 0) {
    score += 1;
  } else if (digit_count >= 1 && digit_count <= 2) {
    score += 2;
  } else if (digit_count > 2) {
    score += 3;
  }

  // Check for special characters
  int special_count = 0;
  for (int i = 0; i < length; i++) {
    if (password[i] >= '!' && password[i] <= '/') {
      special_count++;
    } else if (password[i] >= ':' && password[i] <= '@') {
      special_count++;
    } else if (password[i] >= '[' && password[i] <= '`') {
      special_count++;
    } else if (password[i] >= '{' && password[i] <= '~') {
      special_count++;
    }
  }
  if (special_count == 0) {
    score += 1;
  } else if (special_count >= 1 && special_count <= 2) {
    score += 2;
  } else if (special_count > 2) {
    score += 3;
  }

  return score;
}

// Function to get the password from the user
char *get_password() {
  char *password = malloc(100);
  printf("Enter your password: ");
  scanf("%s", password);
  return password;
}

// Function to print the password strength
void print_password_strength(int score) {
  if (score < 5) {
    printf("Your password is weak.\n");
  } else if (score >= 5 && score < 8) {
    printf("Your password is medium.\n");
  } else if (score >= 8) {
    printf("Your password is strong.\n");
  }
}

int main() {
  char *password = get_password();
  int score = check_password(password);
  print_password_strength(score);
  free(password);
  return 0;
}