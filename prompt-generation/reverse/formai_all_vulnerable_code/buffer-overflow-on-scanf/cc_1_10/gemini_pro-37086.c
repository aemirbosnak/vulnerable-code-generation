//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Some constants
#define MIN_PASSWORD_LENGTH 8
#define MAX_PASSWORD_LENGTH 64
#define NUM_PASSWORD_CATEGORIES 4

// Some data structures
typedef struct {
  char *category;
  int score;
} PasswordCategory;

PasswordCategory password_categories[] = {
  {"Too short", 0},
  {"Weak", 1},
  {"Medium", 2},
  {"Strong", 3}
};

// Some function prototypes
int get_password_length(char *password);
int get_password_score(char *password);
void print_password_strength(int score);

// The main function
int main() {
  // Get the password from the user
  char password[MAX_PASSWORD_LENGTH + 1];
  printf("Enter your password: ");
  scanf("%s", password);

  // Check the password length
  int length = get_password_length(password);
  if (length < MIN_PASSWORD_LENGTH) {
    printf("Your password is too short. It must be at least %d characters long.\n", MIN_PASSWORD_LENGTH);
    return 1;
  }

  // Check the password score
  int score = get_password_score(password);
  print_password_strength(score);

  return 0;
}

// Get the password length
int get_password_length(char *password) {
  return strlen(password);
}

// Get the password score
int get_password_score(char *password) {
  int score = 0;

  // Check for uppercase letters
  for (int i = 0; i < strlen(password); i++) {
    if (password[i] >= 'A' && password[i] <= 'Z') {
      score++;
    }
  }

  // Check for lowercase letters
  for (int i = 0; i < strlen(password); i++) {
    if (password[i] >= 'a' && password[i] <= 'z') {
      score++;
    }
  }

  // Check for digits
  for (int i = 0; i < strlen(password); i++) {
    if (password[i] >= '0' && password[i] <= '9') {
      score++;
    }
  }

  // Check for symbols
  for (int i = 0; i < strlen(password); i++) {
    if (password[i] >= '!' && password[i] <= '~') {
      score++;
    }
  }

  // Check for repeated characters
  for (int i = 0; i < strlen(password); i++) {
    for (int j = i + 1; j < strlen(password); j++) {
      if (password[i] == password[j]) {
        score--;
      }
    }
  }

  // Return the score
  return score;
}

// Print the password strength
void print_password_strength(int score) {
  if (score < 0) {
    printf("Your password is very weak.\n");
  } else if (score < 2) {
    printf("Your password is weak.\n");
  } else if (score < 4) {
    printf("Your password is medium.\n");
  } else {
    printf("Your password is strong.\n");
  }
}