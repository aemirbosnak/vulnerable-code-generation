//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the password strength levels
#define WEAK 0
#define MEDIUM 1
#define STRONG 2

// Define the minimum length of a strong password
#define MIN_LENGTH 8

// Define the minimum number of uppercase characters in a strong password
#define MIN_UPPERCASE 1

// Define the minimum number of lowercase characters in a strong password
#define MIN_LOWERCASE 1

// Define the minimum number of digits in a strong password
#define MIN_DIGITS 1

// Define the minimum number of special characters in a strong password
#define MIN_SPECIAL 1

// Define the array of special characters
const char specialCharacters[] = "!@#$%^&*()_+=-`~";

// Function to check the strength of a password
int checkPasswordStrength(const char *password) {
  // Check the length of the password
  if (strlen(password) < MIN_LENGTH) {
    return WEAK;
  }

  // Check the number of uppercase characters in the password
  int numUppercase = 0;
  for (int i = 0; i < strlen(password); i++) {
    if (isupper(password[i])) {
      numUppercase++;
    }
  }

  if (numUppercase < MIN_UPPERCASE) {
    return WEAK;
  }

  // Check the number of lowercase characters in the password
  int numLowercase = 0;
  for (int i = 0; i < strlen(password); i++) {
    if (islower(password[i])) {
      numLowercase++;
    }
  }

  if (numLowercase < MIN_LOWERCASE) {
    return WEAK;
  }

  // Check the number of digits in the password
  int numDigits = 0;
  for (int i = 0; i < strlen(password); i++) {
    if (isdigit(password[i])) {
      numDigits++;
    }
  }

  if (numDigits < MIN_DIGITS) {
    return WEAK;
  }

  // Check the number of special characters in the password
  int numSpecial = 0;
  for (int i = 0; i < strlen(password); i++) {
    for (int j = 0; j < strlen(specialCharacters); j++) {
      if (password[i] == specialCharacters[j]) {
        numSpecial++;
      }
    }
  }

  if (numSpecial < MIN_SPECIAL) {
    return WEAK;
  }

  // If all the checks pass, the password is strong
  return STRONG;
}

// Main function
int main() {
  // Get the password from the user
  char password[100];
  printf("Enter your password: ");
  scanf("%s", password);

  // Check the strength of the password
  int strength = checkPasswordStrength(password);

  // Print the password strength
  switch (strength) {
    case WEAK:
      printf("Your password is weak.\n");
      break;
    case MEDIUM:
      printf("Your password is medium.\n");
      break;
    case STRONG:
      printf("Your password is strong.\n");
      break;
  }

  return 0;
}