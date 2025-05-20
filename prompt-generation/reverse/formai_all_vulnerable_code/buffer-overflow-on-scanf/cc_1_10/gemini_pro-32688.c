//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to check if a character is an alphabet
int isAlphabet(char ch) {
  return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

// Function to check if a character is a digit
int isDigit(char ch) {
  return (ch >= '0' && ch <= '9');
}

// Function to check if a character is a special character
int isSpecialCharacter(char ch) {
  return !(isAlphabet(ch) || isDigit(ch));
}

// Function to check the strength of a password
int checkPasswordStrength(char *password) {
  int strength = 0;
  int length = strlen(password);

  // Check for length
  if (length < 8) {
    strength += 1;
  } else if (length >= 8 && length <= 12) {
    strength += 2;
  } else if (length > 12) {
    strength += 3;
  }

  // Check for alphabets
  int countAlphabets = 0;
  for (int i = 0; i < length; i++) {
    if (isAlphabet(password[i])) {
      countAlphabets++;
    }
  }
  if (countAlphabets == 0) {
    strength += 1;
  } else if (countAlphabets >= 1 && countAlphabets <= 2) {
    strength += 2;
  } else if (countAlphabets > 2) {
    strength += 3;
  }

  // Check for digits
  int countDigits = 0;
  for (int i = 0; i < length; i++) {
    if (isDigit(password[i])) {
      countDigits++;
    }
  }
  if (countDigits == 0) {
    strength += 1;
  } else if (countDigits >= 1 && countDigits <= 2) {
    strength += 2;
  } else if (countDigits > 2) {
    strength += 3;
  }

  // Check for special characters
  int countSpecialCharacters = 0;
  for (int i = 0; i < length; i++) {
    if (isSpecialCharacter(password[i])) {
      countSpecialCharacters++;
    }
  }
  if (countSpecialCharacters == 0) {
    strength += 1;
  } else if (countSpecialCharacters >= 1 && countSpecialCharacters <= 2) {
    strength += 2;
  } else if (countSpecialCharacters > 2) {
    strength += 3;
  }

  return strength;
}

int main() {
  // Get the password from the user
  char password[256];
  printf("Enter your password: ");
  scanf("%s", password);

  // Check the strength of the password
  int strength = checkPasswordStrength(password);

  // Print the strength of the password
  printf("Strength of your password: ");
  switch (strength) {
    case 1:
      printf("Weak");
      break;
    case 2:
      printf("Moderate");
      break;
    case 3:
      printf("Strong");
      break;
    default:
      printf("Invalid");
      break;
  }

  return 0;
}