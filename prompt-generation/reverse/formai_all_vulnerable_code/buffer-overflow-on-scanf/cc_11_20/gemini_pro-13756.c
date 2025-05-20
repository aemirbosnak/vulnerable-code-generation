//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if the password is strong
int check_password_strength(char* password) {
  int strength = 0;

  // Check the length of the password
  if (strlen(password) < 8) {
    strength += 1;
  } else if (strlen(password) >= 12) {
    strength += 3;
  } else {
    strength += 2;
  }

  // Check if the password contains uppercase letters
  int has_uppercase = 0;
  for (int i = 0; i < strlen(password); i++) {
    if (password[i] >= 'A' && password[i] <= 'Z') {
      has_uppercase = 1;
      break;
    }
  }
  if (has_uppercase) {
    strength += 1;
  }

  // Check if the password contains lowercase letters
  int has_lowercase = 0;
  for (int i = 0; i < strlen(password); i++) {
    if (password[i] >= 'a' && password[i] <= 'z') {
      has_lowercase = 1;
      break;
    }
  }
  if (has_lowercase) {
    strength += 1;
  }

  // Check if the password contains digits
  int has_digits = 0;
  for (int i = 0; i < strlen(password); i++) {
    if (password[i] >= '0' && password[i] <= '9') {
      has_digits = 1;
      break;
    }
  }
  if (has_digits) {
    strength += 1;
  }

  // Check if the password contains special characters
  int has_special_characters = 0;
  for (int i = 0; i < strlen(password); i++) {
    if (password[i] == '!' || password[i] == '@' || password[i] == '#' || password[i] == '$' || password[i] == '%' || password[i] == '^' || password[i] == '&' || password[i] == '*') {
      has_special_characters = 1;
      break;
    }
  }
  if (has_special_characters) {
    strength += 1;
  }

  // Return the strength of the password
  return strength;
}

// Function to test the password strength checker
int main() {
  // Get the password from the user
  char password[100];
  printf("Enter your password: ");
  scanf("%s", password);

  // Check the strength of the password
  int strength = check_password_strength(password);

  // Print the strength of the password
  printf("The strength of your password is: %d\n", strength);

  return 0;
}