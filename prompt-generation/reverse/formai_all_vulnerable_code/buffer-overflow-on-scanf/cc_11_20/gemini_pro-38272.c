//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constants for password strength levels
#define WEAK 0
#define MEDIUM 1
#define STRONG 2

// Function to check password strength
int checkPasswordStrength(char* password) {
  // Initialize strength level to WEAK
  int strength = WEAK;

  // Check password length
  if (strlen(password) >= 8) {
    strength++;
  }

  // Check for uppercase letters
  for (int i = 0; i < strlen(password); i++) {
    if (password[i] >= 'A' && password[i] <= 'Z') {
      strength++;
      break;
    }
  }

  // Check for lowercase letters
  for (int i = 0; i < strlen(password); i++) {
    if (password[i] >= 'a' && password[i] <= 'z') {
      strength++;
      break;
    }
  }

  // Check for digits
  for (int i = 0; i < strlen(password); i++) {
    if (password[i] >= '0' && password[i] <= '9') {
      strength++;
      break;
    }
  }

  // Check for special characters
  for (int i = 0; i < strlen(password); i++) {
    if (password[i] >= '!' && password[i] <= '/' || password[i] >= ':' && password[i] <= '@' || password[i] >= '[' && password[i] <= '`') {
      strength++;
      break;
    }
  }

  // Return password strength level
  return strength;
}

// Main function
int main() {
  // Get password from user
  char password[100];
  printf("Enter password: ");
  scanf("%s", password);

  // Check password strength
  int strength = checkPasswordStrength(password);

  // Print password strength level
  switch (strength) {
    case WEAK:
      printf("Your password is WEAK.\n");
      break;
    case MEDIUM:
      printf("Your password is MEDIUM.\n");
      break;
    case STRONG:
      printf("Your password is STRONG.\n");
      break;
  }

  return 0;
}