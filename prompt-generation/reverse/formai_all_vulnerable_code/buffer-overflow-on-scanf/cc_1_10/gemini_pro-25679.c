//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: irregular
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Declare the function to check the password strength
int checkPasswordStrength(char* password);

// Main function
int main() {
  // Initialize the password variable
  char password[100];

  // Get the password from the user
  printf("Enter your password: ");
  scanf("%s", password);

  // Check the password strength
  int strength = checkPasswordStrength(password);

  // Print the password strength
  printf("Password strength: %d\n", strength);

  return 0;
}

// Function to check the password strength
int checkPasswordStrength(char* password) {
  // Initialize the strength variable
  int strength = 0;

  // Check the length of the password
  if (strlen(password) >= 8) {
    strength += 1;
  }

  // Check for uppercase letters
  int hasUppercase = 0;
  for (int i = 0; i < strlen(password); i++) {
    if (isupper(password[i])) {
      hasUppercase = 1;
      break;
    }
  }
  if (hasUppercase) {
    strength += 1;
  }

  // Check for lowercase letters
  int hasLowercase = 0;
  for (int i = 0; i < strlen(password); i++) {
    if (islower(password[i])) {
      hasLowercase = 1;
      break;
    }
  }
  if (hasLowercase) {
    strength += 1;
  }

  // Check for digits
  int hasDigit = 0;
  for (int i = 0; i < strlen(password); i++) {
    if (isdigit(password[i])) {
      hasDigit = 1;
      break;
    }
  }
  if (hasDigit) {
    strength += 1;
  }

  // Check for special characters
  int hasSpecialCharacter = 0;
  for (int i = 0; i < strlen(password); i++) {
    if (!isalnum(password[i])) {
      hasSpecialCharacter = 1;
      break;
    }
  }
  if (hasSpecialCharacter) {
    strength += 1;
  }

  // Return the password strength
  return strength;
}