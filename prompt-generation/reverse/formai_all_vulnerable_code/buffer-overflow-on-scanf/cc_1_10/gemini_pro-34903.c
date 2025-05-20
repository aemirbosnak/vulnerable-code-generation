//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if the password is strong
int is_strong_password(char *password) {
  int length = strlen(password);
  int has_uppercase = 0;
  int has_lowercase = 0;
  int has_digit = 0;
  int has_special_character = 0;

  // Check if the password is at least 8 characters long
  if (length < 8) {
    return 0;
  }

  // Check if the password contains at least one uppercase letter
  for (int i = 0; i < length; i++) {
    if (password[i] >= 'A' && password[i] <= 'Z') {
      has_uppercase = 1;
      break;
    }
  }

  // Check if the password contains at least one lowercase letter
  for (int i = 0; i < length; i++) {
    if (password[i] >= 'a' && password[i] <= 'z') {
      has_lowercase = 1;
      break;
    }
  }

  // Check if the password contains at least one digit
  for (int i = 0; i < length; i++) {
    if (password[i] >= '0' && password[i] <= '9') {
      has_digit = 1;
      break;
    }
  }

  // Check if the password contains at least one special character
  for (int i = 0; i < length; i++) {
    if (!isalnum(password[i])) {
      has_special_character = 1;
      break;
    }
  }

  // If the password meets all the criteria, return 1
  if (has_uppercase && has_lowercase && has_digit && has_special_character) {
    return 1;
  }

  // Otherwise, return 0
  return 0;
}

// Function to check if the password is weak
int is_weak_password(char *password) {
  if (strlen(password) < 8) {
    return 1;
  }

  for (int i = 0; i < strlen(password); i++) {
    if (!isalnum(password[i])) {
      return 0;
    }
  }

  return 1;
}

// Function to get the strength of the password
int get_password_strength(char *password) {
  if (is_strong_password(password)) {
    return 3;
  } else if (is_weak_password(password)) {
    return 1;
  } else {
    return 2;
  }
}

// Function to print the password strength
void print_password_strength(char *password) {
  int strength = get_password_strength(password);

  switch (strength) {
    case 1:
      printf("Weak password\n");
      break;
    case 2:
      printf("Medium password\n");
      break;
    case 3:
      printf("Strong password\n");
      break;
  }
}

int main() {
  char password[100];

  printf("Please enter a password: ");
  scanf("%s", password);

  print_password_strength(password);

  return 0;
}