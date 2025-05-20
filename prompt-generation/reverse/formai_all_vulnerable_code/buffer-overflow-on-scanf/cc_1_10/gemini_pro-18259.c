//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: inquisitive
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to check if a character is a digit
int isDigit(char c) {
  return (c >= '0' && c <= '9');
}

// Function to check if a character is a lowercase letter
int isLower(char c) {
  return (c >= 'a' && c <= 'z');
}

// Function to check if a character is an uppercase letter
int isUpper(char c) {
  return (c >= 'A' && c <= 'Z');
}

// Function to check if a character is a special character
int isSpecial(char c) {
  return (!isDigit(c) && !isLower(c) && !isUpper(c));
}

// Function to check the strength of a password
int passwordStrength(char *password) {
  int score = 0;
  int length = strlen(password);

  // Check the length of the password
  if (length < 8) {
    score += 1;
  } else if (length >= 8 && length <= 12) {
    score += 2;
  } else if (length > 12) {
    score += 3;
  }

  // Check the number of different character types
  int numDigits = 0;
  int numLower = 0;
  int numUpper = 0;
  int numSpecial = 0;
  for (int i = 0; i < length; i++) {
    if (isDigit(password[i])) {
      numDigits++;
    } else if (isLower(password[i])) {
      numLower++;
    } else if (isUpper(password[i])) {
      numUpper++;
    } else if (isSpecial(password[i])) {
      numSpecial++;
    }
  }
  if (numDigits > 0) {
    score += 1;
  }
  if (numLower > 0) {
    score += 1;
  }
  if (numUpper > 0) {
    score += 1;
  }
  if (numSpecial > 0) {
    score += 1;
  }

  // Check the number of repeating characters
  int numRepeating = 0;
  for (int i = 0; i < length; i++) {
    for (int j = i + 1; j < length; j++) {
      if (password[i] == password[j]) {
        numRepeating++;
      }
    }
  }
  if (numRepeating > 0) {
    score -= 1;
  }

  // Return the password strength score
  return score;
}

int main() {
  // Get the password from the user
  char password[101];
  printf("Enter your password: ");
  scanf("%s", password);

  // Check the strength of the password
  int score = passwordStrength(password);

  // Print the password strength score
  printf("Your password strength score is: %d\n", score);

  // Print a message based on the password strength score
  if (score < 3) {
    printf("Your password is weak. Please choose a stronger password.\n");
  } else if (score >= 3 && score < 6) {
    printf("Your password is moderately strong. You could make it stronger by adding more character types or making it longer.\n");
  } else if (score >= 6) {
    printf("Your password is strong. Good job!\n");
  }

  return 0;
}