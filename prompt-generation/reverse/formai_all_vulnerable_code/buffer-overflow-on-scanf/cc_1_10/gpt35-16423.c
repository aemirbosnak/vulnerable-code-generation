//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool isLowerCase(char ch) {
  return ch >= 'a' && ch <= 'z'; // Check if the character is a lower case letter
}

bool isUpperCase(char ch) {
  return ch >= 'A' && ch <= 'Z'; // Check if the character is an upper case letter
}

bool isNumeric(char ch) {
  return ch >= '0' && ch <= '9'; // Check if the character is a number
}

bool isSpecialChar(char ch) {
  return ch >= 32 && ch <= 47 || ch >= 58 && ch <= 64 || ch >= 91 && ch <= 96 || ch >= 123 && ch <= 126; // Check if the character is a special character
}

int getPasswordStrength(char *password, int len, int strength) {
  if (len == 0) {
    return strength; // Return the strength when we reach the end of the string
  }

  char firstChar = password[0];

  if (isLowerCase(firstChar)) { // If first character is lower case letter
    strength++;
  } else if (isUpperCase(firstChar)) { // If first character is upper case letter
    strength++;
  } else if (isNumeric(firstChar)) { // If first character is a number
    strength++;
  } else if (isSpecialChar(firstChar)) { // If first character is a special character
    strength += 2;
  }

  return getPasswordStrength(password + 1, len - 1, strength); // Call recursively with remaining string
}

int main() {
  char password[100];
  int strength = 0, len;

  printf("Enter your password: ");
  scanf("%s", password);

  len = strlen(password);

  if (len < 6) {
    printf("Your password is too weak. It must be at least 6 characters long.\n"); // Check if password is at least 6 characters long
    return 0;
  }

  strength = getPasswordStrength(password, len, strength); // Get the password strength

  if (strength <= 2) { // If strength is not good enough
    printf("Your password is weak.\n"); 
  } else if (strength <= 4) {
    printf("Your password is average.\n");
  } else {
    printf("Your password is strong.\n");
  }

  return 0;
}