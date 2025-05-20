//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to check if the password is strong
int check_password_strength(char *password) {
  int strength = 0;
  int length = strlen(password);

  // Check for minimum length
  if (length < 8) {
    strength--;
  }

  // Check for uppercase letters
  int has_uppercase = 0;
  for (int i = 0; i < length; i++) {
    if (isupper(password[i])) {
      has_uppercase = 1;
      break;
    }
  }
  if (!has_uppercase) {
    strength--;
  }

  // Check for lowercase letters
  int has_lowercase = 0;
  for (int i = 0; i < length; i++) {
    if (islower(password[i])) {
      has_lowercase = 1;
      break;
    }
  }
  if (!has_lowercase) {
    strength--;
  }

  // Check for digits
  int has_digit = 0;
  for (int i = 0; i < length; i++) {
    if (isdigit(password[i])) {
      has_digit = 1;
      break;
    }
  }
  if (!has_digit) {
    strength--;
  }

  // Check for special characters
  int has_special = 0;
  for (int i = 0; i < length; i++) {
    if (!isalnum(password[i])) {
      has_special = 1;
      break;
    }
  }
  if (!has_special) {
    strength--;
  }

  // Check for repeated characters
  int has_repeated = 0;
  for (int i = 0; i < length - 1; i++) {
    if (password[i] == password[i + 1]) {
      has_repeated = 1;
      break;
    }
  }
  if (has_repeated) {
    strength--;
  }

  // Calculate the final strength
  if (strength < 0) {
    strength = 0;
  } else if (strength > 5) {
    strength = 5;
  }

  return strength;
}

// Main function
int main() {
  // Get the password from the user
  char password[100];
  printf("Enter your password: ");
  scanf("%s", password);

  // Check the password strength
  int strength = check_password_strength(password);

  // Print the result
  switch (strength) {
    case 0:
      printf("Your password is very weak.\n");
      break;
    case 1:
      printf("Your password is weak.\n");
      break;
    case 2:
      printf("Your password is OK.\n");
      break;
    case 3:
      printf("Your password is strong.\n");
      break;
    case 4:
      printf("Your password is very strong.\n");
      break;
    case 5:
      printf("Your password is extremely strong.\n");
      break;
    default:
      printf("Invalid password.\n");
  }

  return 0;
}