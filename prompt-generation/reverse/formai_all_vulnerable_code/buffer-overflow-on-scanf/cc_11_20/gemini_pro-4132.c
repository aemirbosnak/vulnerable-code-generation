//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if the password is strong
int check_password_strength(char *password) {
  int strength = 0;
  int length = strlen(password);

  // Check for minimum length
  if (length < 8) {
    strength += 1;
  }

  // Check for uppercase letters
  for (int i = 0; i < length; i++) {
    if (password[i] >= 'A' && password[i] <= 'Z') {
      strength += 1;
      break;
    }
  }

  // Check for lowercase letters
  for (int i = 0; i < length; i++) {
    if (password[i] >= 'a' && password[i] <= 'z') {
      strength += 1;
      break;
    }
  }

  // Check for digits
  for (int i = 0; i < length; i++) {
    if (password[i] >= '0' && password[i] <= '9') {
      strength += 1;
      break;
    }
  }

  // Check for special characters
  for (int i = 0; i < length; i++) {
    if (password[i] == '!' || password[i] == '@' || password[i] == '#' || password[i] == '$' || password[i] == '%') {
      strength += 1;
      break;
    }
  }

  return strength;
}

// Main function
int main() {
  // Declare the password variable
  char password[100];

  // Prompt the user to enter a password
  printf("Enter a password: ");
  scanf("%s", password);

  // Check the password strength
  int strength = check_password_strength(password);

  // Print the password strength
  switch (strength) {
    case 0:
      printf("Weak password! Please try again.\n");
      break;
    case 1:
      printf("Fair password! Could be stronger.\n");
      break;
    case 2:
      printf("Good password! Keep it up.\n");
      break;
    case 3:
      printf("Strong password! You're a security expert.\n");
      break;
    case 4:
      printf("Excellent password! You're a password ninja.\n");
      break;
    default:
      printf("Invalid password! Please try again.\n");
  }

  return 0;
}