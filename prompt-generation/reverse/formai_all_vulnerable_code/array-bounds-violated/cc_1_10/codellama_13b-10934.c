//Code Llama-13B DATASET v1.0 Category: Password Strength Checker ; Style: secure
/*
 * Password Strength Checker
 *
 * This program checks the strength of a given password and returns an appropriate message
 * indicating the password's strength.
 *
 * Author: [Your Name]
 */

#include <stdio.h>
#include <string.h>

#define PASSWORD_LEN 128

// Define the strength levels
#define LOW_STRENGTH 0
#define MEDIUM_STRENGTH 1
#define HIGH_STRENGTH 2
#define EXTREME_STRENGTH 3

// Function to check the password strength
int check_password_strength(const char *password) {
  // Check if the password is empty
  if (strlen(password) == 0) {
    return LOW_STRENGTH;
  }

  // Check if the password is less than 8 characters
  if (strlen(password) < 8) {
    return LOW_STRENGTH;
  }

  // Check if the password contains at least one digit
  if (!strpbrk(password, "0123456789")) {
    return LOW_STRENGTH;
  }

  // Check if the password contains at least one uppercase letter
  if (!strpbrk(password, "ABCDEFGHIJKLMNOPQRSTUVWXYZ")) {
    return MEDIUM_STRENGTH;
  }

  // Check if the password contains at least one lowercase letter
  if (!strpbrk(password, "abcdefghijklmnopqrstuvwxyz")) {
    return MEDIUM_STRENGTH;
  }

  // Check if the password contains at least one special character
  if (!strpbrk(password, "!@#$%^&*()_+-=[]{}|;':\"<>,./?")) {
    return HIGH_STRENGTH;
  }

  // Check if the password contains at least one non-alphanumeric character
  if (!strpbrk(password, "!@#$%^&*()_+-=[]{}|;':\"<>,./?")) {
    return EXTREME_STRENGTH;
  }

  return EXTREME_STRENGTH;
}

int main(void) {
  // Declare the password and its length
  char password[PASSWORD_LEN];
  int password_len;

  // Prompt the user to enter a password
  printf("Enter a password: ");
  fgets(password, PASSWORD_LEN, stdin);

  // Remove the newline character from the end of the password
  password_len = strlen(password);
  password[password_len - 1] = '\0';

  // Check the password strength
  int strength = check_password_strength(password);

  // Print the password strength
  switch (strength) {
    case LOW_STRENGTH:
      printf("Password strength: Low\n");
      break;
    case MEDIUM_STRENGTH:
      printf("Password strength: Medium\n");
      break;
    case HIGH_STRENGTH:
      printf("Password strength: High\n");
      break;
    case EXTREME_STRENGTH:
      printf("Password strength: Extreme\n");
      break;
  }

  return 0;
}