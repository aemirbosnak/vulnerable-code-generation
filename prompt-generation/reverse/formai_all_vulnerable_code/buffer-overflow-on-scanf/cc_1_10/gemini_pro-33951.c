//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to calculate the strength of a password
int passwordStrength(char *password) {
  int strength = 0;

  // Check for password length
  if (strlen(password) < 8) {
    strength += 1;
  } else if (strlen(password) >= 8 && strlen(password) < 12) {
    strength += 2;
  } else if (strlen(password) >= 12) {
    strength += 3;
  }

  // Check for uppercase letters
  int hasUpper = 0;
  for (int i = 0; i < strlen(password); i++) {
    if (isupper(password[i])) {
      hasUpper = 1;
      break;
    }
  }
  if (hasUpper) {
    strength += 1;
  }

  // Check for lowercase letters
  int hasLower = 0;
  for (int i = 0; i < strlen(password); i++) {
    if (islower(password[i])) {
      hasLower = 1;
      break;
    }
  }
  if (hasLower) {
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
  int hasSpecial = 0;
  for (int i = 0; i < strlen(password); i++) {
    if (ispunct(password[i])) {
      hasSpecial = 1;
      break;
    }
  }
  if (hasSpecial) {
    strength += 1;
  }

  // Return the strength of the password
  return strength;
}

// Function to print the strength of a password
void printPasswordStrength(char *password) {
  int strength = passwordStrength(password);

  printf("Password strength: ");
  switch (strength) {
    case 1:
      printf("Weak");
      break;
    case 2:
      printf("Fair");
      break;
    case 3:
      printf("Good");
      break;
    case 4:
      printf("Strong");
      break;
    case 5:
      printf("Excellent");
      break;
  }
  printf("\n");
}

// Main function
int main() {
  // Get the password from the user
  char password[100];
  printf("Enter a password: ");
  scanf("%s", password);

  // Print the strength of the password
  printPasswordStrength(password);

  return 0;
}