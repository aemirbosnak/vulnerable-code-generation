//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  // Define the password strength requirements
  int minLength = 8;
  int minUppercase = 1;
  int minLowercase = 1;
  int minDigits = 1;
  int minSpecialChars = 1;

  // Get the password from the user
  char password[100];
  printf("Enter your password: ");
  scanf("%s", password);

  // Check the password length
  if (strlen(password) < minLength) {
    printf("Your password must be at least %d characters long.\n", minLength);
    return 1;
  }

  // Check the password for uppercase letters
  int uppercaseCount = 0;
  for (int i = 0; i < strlen(password); i++) {
    if (password[i] >= 'A' && password[i] <= 'Z') {
      uppercaseCount++;
    }
  }
  if (uppercaseCount < minUppercase) {
    printf("Your password must contain at least %d uppercase letters.\n", minUppercase);
    return 1;
  }

  // Check the password for lowercase letters
  int lowercaseCount = 0;
  for (int i = 0; i < strlen(password); i++) {
    if (password[i] >= 'a' && password[i] <= 'z') {
      lowercaseCount++;
    }
  }
  if (lowercaseCount < minLowercase) {
    printf("Your password must contain at least %d lowercase letters.\n", minLowercase);
    return 1;
  }

  // Check the password for digits
  int digitCount = 0;
  for (int i = 0; i < strlen(password); i++) {
    if (password[i] >= '0' && password[i] <= '9') {
      digitCount++;
    }
  }
  if (digitCount < minDigits) {
    printf("Your password must contain at least %d digits.\n", minDigits);
    return 1;
  }

  // Check the password for special characters
  int specialCharCount = 0;
  for (int i = 0; i < strlen(password); i++) {
    if (!((password[i] >= 'A' && password[i] <= 'Z') || (password[i] >= 'a' && password[i] <= 'z') || (password[i] >= '0' && password[i] <= '9'))) {
      specialCharCount++;
    }
  }
  if (specialCharCount < minSpecialChars) {
    printf("Your password must contain at least %d special characters.\n", minSpecialChars);
    return 1;
  }

  // The password meets all the requirements
  printf("Your password is strong.\n");
  return 0;
}