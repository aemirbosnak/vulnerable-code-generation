//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool isLowercase(char ch) {
  if (ch >= 'a' && ch <= 'z') {
    return true;
  }
  return false;
}

bool isUppercase(char ch) {
  if (ch >= 'A' && ch <= 'Z') {
    return true;
  }
  return false;
}

bool isSpecialChar(char ch) {
  if ((ch >= '!' && ch <= '/') || (ch >= ':' && ch <= '@') || (ch >= '[' && ch <= '`') || (ch >= '{' && ch <= '~')) {
    return true;
  }
  return false;
}

bool isDigit(char ch) {
  if (ch >= '0' && ch <= '9') {
    return true;
  }
  return false;
}

int passwordStrength(char password[]) {
  int len = strlen(password);
  int strength = 0;

  if (len >= 8 && len <= 16) {
    strength++;
    int lowercaseCount = 0, uppercaseCount = 0, specialCharCount = 0, digitCount = 0;
    for (int i = 0; i < len; i++) {
      if (isLowercase(password[i])) {
        lowercaseCount++;
      } else if (isUppercase(password[i])) {
        uppercaseCount++;
      } else if (isSpecialChar(password[i])) {
        specialCharCount++;
      } else if (isDigit(password[i])) {
        digitCount++;
      }
    }

    if ((lowercaseCount >= 1 && uppercaseCount >= 1) || (lowercaseCount >= 1 && specialCharCount >= 1) || (lowercaseCount >= 1 && digitCount >= 1)) {
      strength++;
      if (uppercaseCount >= 1 && specialCharCount >= 1 && digitCount >= 1) {
        strength++;
      }
    }
  }

  return strength;
}

int main() {
  char password[50];
  printf("Enter your password: ");
  scanf("%s", password);
  int strength = passwordStrength(password);

  switch(strength) {
    case 0:
      printf("Your password is too short. It must be between 8 and 16 characters.\n");
      break;
    case 1:
      printf("Your password is weak.\n");
      break;
    case 2:
      printf("Your password is moderate.\n");
      break;
    case 3:
      printf("Your password is strong.\n");
      break;
    default:
      printf("Invalid password.\n");
  }

  return 0;
}