//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: medieval
#include <stdio.h>
#include <string.h>

// Define the minimum password length
#define MIN_PASSWORD_LENGTH 8

// Define the maximum password length
#define MAX_PASSWORD_LENGTH 32

// Define the character set for the password
#define PASSWORD_CHARSET "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+=-"

// Define the strength levels for the password
#define WEAK "Weak"
#define MEDIUM "Medium"
#define STRONG "Strong"

// Check if the password is weak
int is_weak(char *password) {
  // Check if the password is less than the minimum length
  if (strlen(password) < MIN_PASSWORD_LENGTH) {
    return 1;
  }

  // Check if the password does not contain any uppercase letters
  int has_uppercase = 0;
  for (int i = 0; i < strlen(password); i++) {
    if (password[i] >= 'A' && password[i] <= 'Z') {
      has_uppercase = 1;
      break;
    }
  }
  if (!has_uppercase) {
    return 1;
  }

  // Check if the password does not contain any lowercase letters
  int has_lowercase = 0;
  for (int i = 0; i < strlen(password); i++) {
    if (password[i] >= 'a' && password[i] <= 'z') {
      has_lowercase = 1;
      break;
    }
  }
  if (!has_lowercase) {
    return 1;
  }

  // Check if the password does not contain any digits
  int has_digit = 0;
  for (int i = 0; i < strlen(password); i++) {
    if (password[i] >= '0' && password[i] <= '9') {
      has_digit = 1;
      break;
    }
  }
  if (!has_digit) {
    return 1;
  }

  // Check if the password does not contain any special characters
  int has_special = 0;
  for (int i = 0; i < strlen(password); i++) {
    if (strchr(PASSWORD_CHARSET, password[i])) {
      has_special = 1;
      break;
    }
  }
  if (!has_special) {
    return 1;
  }

  // The password is not weak
  return 0;
}

// Check if the password is medium
int is_medium(char *password) {
  // Check if the password is not weak
  if (!is_weak(password)) {
    return 1;
  }

  // Check if the password is longer than the maximum length
  if (strlen(password) > MAX_PASSWORD_LENGTH) {
    return 0;
  }

  // Check if the password contains at least one uppercase letter, one lowercase letter, one digit, and one special character
  int has_uppercase = 0;
  int has_lowercase = 0;
  int has_digit = 0;
  int has_special = 0;
  for (int i = 0; i < strlen(password); i++) {
    if (password[i] >= 'A' && password[i] <= 'Z') {
      has_uppercase = 1;
    } else if (password[i] >= 'a' && password[i] <= 'z') {
      has_lowercase = 1;
    } else if (password[i] >= '0' && password[i] <= '9') {
      has_digit = 1;
    } else if (strchr(PASSWORD_CHARSET, password[i])) {
      has_special = 1;
    }
  }
  if (!has_uppercase || !has_lowercase || !has_digit || !has_special) {
    return 0;
  }

  // The password is medium
  return 1;
}

// Check if the password is strong
int is_strong(char *password) {
  // Check if the password is not medium
  if (!is_medium(password)) {
    return 0;
  }

  // Check if the password is at least 12 characters long
  if (strlen(password) < 12) {
    return 0;
  }

  // The password is strong
  return 1;
}

// Get the strength of the password
char *get_strength(char *password) {
  // Check if the password is weak
  if (is_weak(password)) {
    return WEAK;
  }

  // Check if the password is medium
  if (is_medium(password)) {
    return MEDIUM;
  }

  // The password is strong
  return STRONG;
}

// Main function
int main() {
  // Get the password from the user
  char password[MAX_PASSWORD_LENGTH + 1];
  printf("Enter your password: ");
  scanf("%s", password);

  // Get the strength of the password
  char *strength = get_strength(password);

  // Print the strength of the password
  printf("Your password is %s.\n", strength);

  return 0;
}