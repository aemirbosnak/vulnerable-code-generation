//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define the password strength levels
#define PASSWORD_STRENGTH_WEAK  1
#define PASSWORD_STRENGTH_MEDIUM 2
#define PASSWORD_STRENGTH_STRONG 3

// Define the password complexity requirements
#define PASSWORD_MIN_LENGTH 8
#define PASSWORD_MAX_LENGTH 32
#define PASSWORD_REQUIRED_UPPERCASE_LETTERS 1
#define PASSWORD_REQUIRED_LOWERCASE_LETTERS 1
#define PASSWORD_REQUIRED_DIGITS 1
#define PASSWORD_REQUIRED_SPECIAL_CHARACTERS 1

// Define the password complexity check functions
int check_password_length(char *password);
int check_password_uppercase_letters(char *password);
int check_password_lowercase_letters(char *password);
int check_password_digits(char *password);
int check_password_special_characters(char *password);

// Define the main function
int main() {
  // Declare the password variable
  char password[PASSWORD_MAX_LENGTH + 1];

  // Get the password from the user
  printf("Enter your password: ");
  scanf("%s", password);

  // Check the password strength
  int password_strength = check_password_strength(password);

  // Print the password strength
  switch (password_strength) {
    case PASSWORD_STRENGTH_WEAK:
      printf("Your password is weak.\n");
      break;
    case PASSWORD_STRENGTH_MEDIUM:
      printf("Your password is medium.\n");
      break;
    case PASSWORD_STRENGTH_STRONG:
      printf("Your password is strong.\n");
      break;
  }

  // Return 0 to indicate success
  return 0;
}

// Define the password strength check function
int check_password_strength(char *password) {
  // Check the password length
  if (!check_password_length(password)) {
    return PASSWORD_STRENGTH_WEAK;
  }

  // Check the password uppercase letters
  if (!check_password_uppercase_letters(password)) {
    return PASSWORD_STRENGTH_MEDIUM;
  }

  // Check the password lowercase letters
  if (!check_password_lowercase_letters(password)) {
    return PASSWORD_STRENGTH_MEDIUM;
  }

  // Check the password digits
  if (!check_password_digits(password)) {
    return PASSWORD_STRENGTH_MEDIUM;
  }

  // Check the password special characters
  if (!check_password_special_characters(password)) {
    return PASSWORD_STRENGTH_MEDIUM;
  }

  // Return strong password strength
  return PASSWORD_STRENGTH_STRONG;
}

// Define the password length check function
int check_password_length(char *password) {
  // Check if the password length is within the required range
  return strlen(password) >= PASSWORD_MIN_LENGTH && strlen(password) <= PASSWORD_MAX_LENGTH;
}

// Define the password uppercase letters check function
int check_password_uppercase_letters(char *password) {
  // Check if the password contains at least one uppercase letter
  for (int i = 0; i < strlen(password); i++) {
    if (isupper(password[i])) {
      return 1;
    }
  }

  // Return false if no uppercase letters are found
  return 0;
}

// Define the password lowercase letters check function
int check_password_lowercase_letters(char *password) {
  // Check if the password contains at least one lowercase letter
  for (int i = 0; i < strlen(password); i++) {
    if (islower(password[i])) {
      return 1;
    }
  }

  // Return false if no lowercase letters are found
  return 0;
}

// Define the password digits check function
int check_password_digits(char *password) {
  // Check if the password contains at least one digit
  for (int i = 0; i < strlen(password); i++) {
    if (isdigit(password[i])) {
      return 1;
    }
  }

  // Return false if no digits are found
  return 0;
}

// Define the password special characters check function
int check_password_special_characters(char *password) {
  // Check if the password contains at least one special character
  for (int i = 0; i < strlen(password); i++) {
    if (!isalnum(password[i])) {
      return 1;
    }
  }

  // Return false if no special characters are found
  return 0;
}