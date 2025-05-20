//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if a character is uppercase
int isUppercase(char c) {
  return (c >= 'A' && c <= 'Z');
}

// Function to check if a character is lowercase
int isLowercase(char c) {
  return (c >= 'a' && c <= 'z');
}

// Function to check if a character is a digit
int isDigit(char c) {
  return (c >= '0' && c <= '9');
}

// Function to check if a character is a special character
int isSpecialCharacter(char c) {
  return (!isUppercase(c) && !isLowercase(c) && !isDigit(c));
}

// Function to check the strength of a password
int checkPasswordStrength(char *password) {
  int strength = 0;

  // Check the length of the password
  if (strlen(password) < 8) {
    strength++;
  }

  // Check if the password contains at least one uppercase character
  if (!isUppercase(*password)) {
    strength++;
  }

  // Check if the password contains at least one lowercase character
  if (!isLowercase(*password)) {
    strength++;
  }

  // Check if the password contains at least one digit
  if (!isDigit(*password)) {
    strength++;
  }

  // Check if the password contains at least one special character
  if (!isSpecialCharacter(*password)) {
    strength++;
  }

  return strength;
}

int main() {
  char password[100];
  int strength;

  printf("Enter your password: ");
  scanf("%s", password);

  strength = checkPasswordStrength(password);

  switch (strength) {
    case 0:
      printf("Your password is very strong!");
      break;
    case 1:
      printf("Your password is strong!");
      break;
    case 2:
      printf("Your password is moderate!");
      break;
    case 3:
      printf("Your password is weak!");
      break;
    case 4:
      printf("Your password is very weak!");
      break;
    default:
      printf("Invalid password!");
      break;
  }

  return 0;
}