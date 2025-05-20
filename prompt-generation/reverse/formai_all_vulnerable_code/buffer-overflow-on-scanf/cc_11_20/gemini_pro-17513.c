//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if the password is strong
int check_password_strength(char *password) {
  int strength = 0;

  // Check the length of the password
  if (strlen(password) < 8) {
    strength += 1;
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
    strength += 1;
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
    strength += 1;
  }

  // Check for digits
  int has_digits = 0;
  for (int i = 0; i < strlen(password); i++) {
    if (password[i] >= '0' && password[i] <= '9') {
      has_digits = 1;
      break;
    }
  }
  if (!has_digits) {
    strength += 1;
  }

  // Check for special characters
  int has_special_characters = 0;
  for (int i = 0; i < strlen(password); i++) {
    if (password[i] == '!' || password[i] == '@' || password[i] == '#' || password[i] == '$' || password[i] == '%') {
      has_special_characters = 1;
      break;
    }
  }
  if (!has_special_characters) {
    strength += 1;
  }

  // Return the strength of the password
  return strength;
}

// Main function
int main() {
  // Get the password from the user
  char password[100];
  printf("Enter your password: ");
  scanf("%s", password);

  // Check the strength of the password
  int strength = check_password_strength(password);

  // Print the strength of the password
  if (strength == 0) {
    printf("Your password is very strong!\n");
  } else if (strength == 1) {
    printf("Your password is strong.\n");
  } else if (strength == 2) {
    printf("Your password is OK.\n");
  } else {
    printf("Your password is weak.\n");
  }

  return 0;
}