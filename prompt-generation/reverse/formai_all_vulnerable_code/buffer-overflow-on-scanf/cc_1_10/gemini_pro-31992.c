//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if a character is uppercase
int isUppercase(char ch) {
  return (ch >= 'A' && ch <= 'Z');
}

// Function to check if a character is lowercase
int isLowercase(char ch) {
  return (ch >= 'a' && ch <= 'z');
}

// Function to check if a character is a digit
int isDigit(char ch) {
  return (ch >= '0' && ch <= '9');
}

// Function to check if a character is a special character
int isSpecial(char ch) {
  return (!isUppercase(ch) && !isLowercase(ch) && !isDigit(ch));
}

// Function to check the strength of a password
int checkPasswordStrength(char *password) {
  int strength = 0;

  // Check the length of the password
  if (strlen(password) < 8) {
    strength += 1;
  } else if (strlen(password) < 12) {
    strength += 2;
  } else {
    strength += 3;
  }

  // Check the number of uppercase characters
  int numUppercase = 0;
  for (int i = 0; i < strlen(password); i++) {
    if (isUppercase(password[i])) {
      numUppercase++;
    }
  }
  if (numUppercase == 0) {
    strength += 1;
  } else if (numUppercase < 3) {
    strength += 2;
  } else {
    strength += 3;
  }

  // Check the number of lowercase characters
  int numLowercase = 0;
  for (int i = 0; i < strlen(password); i++) {
    if (isLowercase(password[i])) {
      numLowercase++;
    }
  }
  if (numLowercase == 0) {
    strength += 1;
  } else if (numLowercase < 3) {
    strength += 2;
  } else {
    strength += 3;
  }

  // Check the number of digits
  int numDigits = 0;
  for (int i = 0; i < strlen(password); i++) {
    if (isDigit(password[i])) {
      numDigits++;
    }
  }
  if (numDigits == 0) {
    strength += 1;
  } else if (numDigits < 3) {
    strength += 2;
  } else {
    strength += 3;
  }

  // Check the number of special characters
  int numSpecial = 0;
  for (int i = 0; i < strlen(password); i++) {
    if (isSpecial(password[i])) {
      numSpecial++;
    }
  }
  if (numSpecial == 0) {
    strength += 1;
  } else if (numSpecial < 3) {
    strength += 2;
  } else {
    strength += 3;
  }

  return strength;
}

int main() {
  char password[100];

  printf("Enter your password: ");
  scanf("%s", password);

  int strength = checkPasswordStrength(password);

  printf("The strength of your password is: %d\n", strength);

  return 0;
}