//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check the strength of a password
int checkPasswordStrength(char* password) {
  int strength = 0;

  // Check the length of the password
  if (strlen(password) < 8) {
    strength += 1;
  } else if (strlen(password) >= 8 && strlen(password) < 12) {
    strength += 2;
  } else if (strlen(password) >= 12) {
    strength += 3;
  }

  // Check the number of uppercase characters in the password
  int uppercaseCount = 0;
  for (int i = 0; i < strlen(password); i++) {
    if (password[i] >= 'A' && password[i] <= 'Z') {
      uppercaseCount++;
    }
  }
  if (uppercaseCount == 0) {
    strength += 1;
  } else if (uppercaseCount >= 1 && uppercaseCount < 3) {
    strength += 2;
  } else if (uppercaseCount >= 3) {
    strength += 3;
  }

  // Check the number of lowercase characters in the password
  int lowercaseCount = 0;
  for (int i = 0; i < strlen(password); i++) {
    if (password[i] >= 'a' && password[i] <= 'z') {
      lowercaseCount++;
    }
  }
  if (lowercaseCount == 0) {
    strength += 1;
  } else if (lowercaseCount >= 1 && lowercaseCount < 3) {
    strength += 2;
  } else if (lowercaseCount >= 3) {
    strength += 3;
  }

  // Check the number of digits in the password
  int digitCount = 0;
  for (int i = 0; i < strlen(password); i++) {
    if (password[i] >= '0' && password[i] <= '9') {
      digitCount++;
    }
  }
  if (digitCount == 0) {
    strength += 1;
  } else if (digitCount >= 1 && digitCount < 3) {
    strength += 2;
  } else if (digitCount >= 3) {
    strength += 3;
  }

  // Check the number of special characters in the password
  int specialCharacterCount = 0;
  for (int i = 0; i < strlen(password); i++) {
    if (password[i] == '!' || password[i] == '@' || password[i] == '#' || password[i] == '$' || password[i] == '%' || password[i] == '^' || password[i] == '&' || password[i] == '*') {
      specialCharacterCount++;
    }
  }
  if (specialCharacterCount == 0) {
    strength += 1;
  } else if (specialCharacterCount >= 1 && specialCharacterCount < 3) {
    strength += 2;
  } else if (specialCharacterCount >= 3) {
    strength += 3;
  }

  // Return the password strength
  return strength;
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
  printf("The strength of your password is: %d\n", strength);

  return 0;
}